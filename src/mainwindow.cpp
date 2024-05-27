#include "mainwindow.hpp"
#include "de_calculator.hpp"
#include "equation.hpp"
#include <QtWebEngineWidgets>
#include <memory>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  ui->setupUi(this);

  QString html = R"(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <script src="https://www.desmos.com/api/v1.8/calculator.js?apiKey=dcb31709b452b1cf9dc26972add0fda6"></script>
</head>
<body>
    <div id="calculator" style="height: 958px; width: 100%;"></div>
    <script>
        var elt = document.getElementById('calculator');
        var calculator = Desmos.GraphingCalculator(elt);
    </script>
</body>
</html>
)";
  ui->graph_view->setHtml(html);

  connect(ui->first_eq, &QRadioButton::clicked, this,
          &MainWindow::on_rb_clicked);
  connect(ui->sec_eq, &QRadioButton::clicked, this, &MainWindow::on_rb_clicked);
  connect(ui->thrd_eq, &QRadioButton::clicked, this,
          &MainWindow::on_rb_clicked);

  connect(ui->browse_btn, &QPushButton::clicked, this,
          &MainWindow::on_browse_clicked);

  connect(ui->load_btn, &QPushButton::clicked, this,
          &MainWindow::on_load_clicked);

  connect(ui->calc_btn, &QPushButton::clicked, this,
          &MainWindow::on_calculate_clicked);
}

void MainWindow::on_rb_clicked() {
  QRadioButton *senderButton = qobject_cast<QRadioButton *>(sender());

  senderButton->setChecked(true);
  if (senderButton == ui->first_eq) {
    ui->sec_eq->setChecked(false);
    ui->thrd_eq->setChecked(false);
  } else if (senderButton == ui->sec_eq) {
    ui->first_eq->setChecked(false);
    ui->thrd_eq->setChecked(false);
  } else if (senderButton == ui->thrd_eq) {
    ui->first_eq->setChecked(false);
    ui->sec_eq->setChecked(false);
  }
}

void MainWindow::on_browse_clicked() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                  tr("txt files (*.txt)"));
  if (!fileName.isEmpty()) {
    ui->file_edit_text->setText(fileName);
  }
}

void MainWindow::on_load_clicked() {
  QString fileName = ui->file_edit_text->toPlainText();
  QFile file(fileName);

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Cannot open file for reading: " << file.errorString();
    return;
  }

  QTextStream in(&file);
  QStringList lines;
  while (!in.atEnd()) {
    lines << in.readLine();
  }

  file.close();

  if (lines.size() < 6) {
    qDebug() << "File does not contain enough lines.";
    return;
  }

  int index = lines[0].toInt();
  double x0 = lines[1].toDouble();
  double y0 = lines[2].toDouble();
  int xn = lines[3].toInt();
  double h = lines[4].toDouble();
  double eps = lines[5].toDouble();

  // Set the radio button based on the index
  switch (index) {
  case 0:
    ui->first_eq->setChecked(true);
    ui->sec_eq->setChecked(false);
    ui->thrd_eq->setChecked(false);
    break;
  case 1:
    ui->sec_eq->setChecked(true);
    ui->first_eq->setChecked(false);
    ui->thrd_eq->setChecked(false);
    break;
  case 2:
    ui->thrd_eq->setChecked(true);
    ui->first_eq->setChecked(false);
    ui->sec_eq->setChecked(false);
    break;
  default:
    qDebug() << "Invalid index in file.";
    return;
  }

  // Set the values for the spin boxes
  ui->x0_sb->setValue(x0);
  ui->y_0_sb->setValue(y0);
  ui->xn_sb->setValue(xn);
  ui->h_sb->setValue(h);
  ui->eps_b->setValue(eps);
}

void MainWindow::on_calculate_clicked() {
  double x0 = ui->x0_sb->value();
  double y0 = ui->y_0_sb->value();
  int xn = ui->xn_sb->value();
  double h = ui->h_sb->value();
  double eps = ui->eps_b->value();
  Equation::EquationType type;
  if (ui->first_eq->isChecked()) {
    type = Equation::EquationType::Linear;
  } else if (ui->sec_eq->isChecked()) {
    type = Equation::EquationType::Fraction;
  } else {
    type = Equation::EquationType::Triganometric;
  }

  // Equation and DifferentialEquationCalculator setup
  auto eq = Equation(type);

  auto calculator = DifferentialEquationCalculator(
      eq, DifferentialEquationCalculator::Adams, eps, x0, y0, xn, h);
  auto result1 = calculator.solve();

  ui->adams_text_browse->clear();
  ui->adams_text_browse->append(
      "<table border=\"1\" cellspacing=\"0\" cellpadding=\"3\">");
  ui->adams_text_browse->append("<tr><th>x</th><th>y</th></tr>");
  for (auto [x, y] : result1) {
    ui->adams_text_browse->append("<tr><td>" + QString::number(x) +
                                  "</td><td>" + QString::number(y) +
                                  "</td></tr>");
  }

  auto calculator2 = DifferentialEquationCalculator(
      eq, DifferentialEquationCalculator::ExtendedEuler, eps, x0, y0, xn, h);
  auto result2 = calculator2.solve();

  ui->euler_text_browser->clear();
  ui->euler_text_browser->append(
      "<table border=\"1\" cellspacing=\"0\" cellpadding=\"3\">");
  ui->euler_text_browser->append("<tr><th>x</th><th>y</th></tr>");
  for (auto [x, y] : result2) {
    ui->euler_text_browser->append("<tr><td>" + QString::number(x) +
                                   "</td><td>" + QString::number(y) +
                                   "</td></tr>");
  }

  auto calculator3 = DifferentialEquationCalculator(
      eq, DifferentialEquationCalculator::RungeKutta4, eps, x0, y0, xn, h);
  auto result3 = calculator2.solve();

  ui->runge_kutta_text_browser->clear();
  ui->runge_kutta_text_browser->append(
      "<table border=\"1\" cellspacing=\"0\" cellpadding=\"3\">");
  ui->runge_kutta_text_browser->append("<tr><th>x</th><th>y</th></tr>");
  for (auto [x, y] : result2) {
    ui->runge_kutta_text_browser->append("<tr><td>" + QString::number(x) +
                                         "</td><td>" + QString::number(y) +
                                         "</td></tr>");
  }

  auto equ = calculator2.getEquationForC();

  QString js_query;
  js_query = QString("calculator.setBlank()");
  ui->graph_view->page()->runJavaScript(js_query);

  js_query = QString("calculator.setExpression({ id: 'graph', latex: '%1' })")
                 .arg(equ.c_str());
  qDebug() << js_query;
  ui->graph_view->page()->runJavaScript(js_query);

  int i = 0;
  for (auto [x, y] : result2) {
    js_query = QString("calculator.setExpression({ id: 'point%1', latex: '(%2, %3)' })")
                   .arg(i++)
                   .arg(x)
                   .arg(y);
    ui->graph_view->page()->runJavaScript(js_query);
  }
}