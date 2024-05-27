/********************************************************************************
** Form generated from reading UI file 'designerRuZfxD.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGNERRUZFXD_H
#define DESIGNERRUZFXD_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
  QWidget *centralwidget;
  QVBoxLayout *verticalLayout;
  QFrame *frame_2;
  QHBoxLayout *horizontalLayout;
  QFrame *frame_3;
  QVBoxLayout *verticalLayout_4;
  QLabel *label;
  QDoubleSpinBox *x0_sb;
  QLabel *label_2;
  QDoubleSpinBox *y_0_sb;
  QLabel *label_3;
  QSpinBox *xn_sb;
  QLabel *label_4;
  QDoubleSpinBox *h_sb;
  QLabel *label_5;
  QDoubleSpinBox *eps_b;
  QPushButton *calc_btn;
  QFrame *frame_4;
  QVBoxLayout *verticalLayout_5;
  QLabel *label_6;
  QFrame *frame_5;
  QVBoxLayout *verticalLayout_8;
  QFrame *frame_6;
  QHBoxLayout *horizontalLayout_2;
  QRadioButton *first_eq;
  QLabel *label_7;
  QFrame *frame_7;
  QHBoxLayout *horizontalLayout_3;
  QRadioButton *sec_eq;
  QLabel *label_8;
  QFrame *frame_8;
  QHBoxLayout *horizontalLayout_4;
  QRadioButton *thrd_eq;
  QLabel *label_9;
  QFrame *frame_9;
  QVBoxLayout *verticalLayout_9;
  QLabel *label_10;
  QTextEdit *file_edit_text;
  QFrame *frame_10;
  QHBoxLayout *horizontalLayout_5;
  QPushButton *browse_btn;
  QPushButton *load_btn;
  QFrame *frame;
  QVBoxLayout *verticalLayout_3;
  QTabWidget *tabWidget;
  QWidget *tab;
  QVBoxLayout *verticalLayout_2;
  QWebEngineView *graph_view;
  QWidget *tab_2;
  QVBoxLayout *verticalLayout_6;
  QTabWidget *tabWidget_2;
  QWidget *tab_3;
  QVBoxLayout *verticalLayout_7;
  QTextBrowser *adams_text_browse;
  QWidget *tab_4;
  QVBoxLayout *verticalLayout_10;
  QTextBrowser *euler_text_browser;
  QWidget *tab_5;
  QVBoxLayout *verticalLayout_11;
  QTextBrowser *runge_kutta_text_browser;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(971, 928);
    MainWindow->setMinimumSize(QSize(971, 928));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    frame_2 = new QFrame(centralwidget);
    frame_2->setObjectName(QString::fromUtf8("frame_2"));
    frame_2->setFrameShape(QFrame::StyledPanel);
    frame_2->setFrameShadow(QFrame::Raised);
    horizontalLayout = new QHBoxLayout(frame_2);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    frame_3 = new QFrame(frame_2);
    frame_3->setObjectName(QString::fromUtf8("frame_3"));
    frame_3->setMinimumSize(QSize(200, 0));
    frame_3->setFrameShape(QFrame::StyledPanel);
    frame_3->setFrameShadow(QFrame::Raised);
    verticalLayout_4 = new QVBoxLayout(frame_3);
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    label = new QLabel(frame_3);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font;
    font.setPointSize(15);
    font.setBold(true);
    font.setWeight(75);
    label->setFont(font);

    verticalLayout_4->addWidget(label);

    x0_sb = new QDoubleSpinBox(frame_3);
    x0_sb->setObjectName(QString::fromUtf8("x0_sb"));
    x0_sb->setMinimum(-1000.000000000000000);
    x0_sb->setMaximum(1000.000000000000000);
    x0_sb->setSingleStep(0.100000000000000);

    verticalLayout_4->addWidget(x0_sb);

    label_2 = new QLabel(frame_3);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setFont(font);

    verticalLayout_4->addWidget(label_2);

    y_0_sb = new QDoubleSpinBox(frame_3);
    y_0_sb->setObjectName(QString::fromUtf8("y_0_sb"));
    y_0_sb->setMinimum(-1000.000000000000000);
    y_0_sb->setMaximum(1000.000000000000000);
    y_0_sb->setSingleStep(0.100000000000000);

    verticalLayout_4->addWidget(y_0_sb);

    label_3 = new QLabel(frame_3);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setFont(font);

    verticalLayout_4->addWidget(label_3);

    xn_sb = new QSpinBox(frame_3);
    xn_sb->setObjectName(QString::fromUtf8("xn_sb"));
    xn_sb->setMinimum(1);
    xn_sb->setMaximum(1000);
    xn_sb->setValue(1);

    verticalLayout_4->addWidget(xn_sb);

    label_4 = new QLabel(frame_3);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setFont(font);

    verticalLayout_4->addWidget(label_4);

    h_sb = new QDoubleSpinBox(frame_3);
    h_sb->setObjectName(QString::fromUtf8("h_sb"));
    h_sb->setMinimum(0.010000000000000);
    h_sb->setSingleStep(0.010000000000000);

    verticalLayout_4->addWidget(h_sb);

    label_5 = new QLabel(frame_3);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setFont(font);

    verticalLayout_4->addWidget(label_5);

    eps_b = new QDoubleSpinBox(frame_3);
    eps_b->setObjectName(QString::fromUtf8("eps_b"));
    eps_b->setDecimals(4);
    eps_b->setMaximum(1.000000000000000);
    eps_b->setSingleStep(0.010000000000000);

    verticalLayout_4->addWidget(eps_b);

    calc_btn = new QPushButton(frame_3);
    calc_btn->setObjectName(QString::fromUtf8("calc_btn"));

    verticalLayout_4->addWidget(calc_btn);

    horizontalLayout->addWidget(frame_3);

    frame_4 = new QFrame(frame_2);
    frame_4->setObjectName(QString::fromUtf8("frame_4"));
    frame_4->setFrameShape(QFrame::StyledPanel);
    frame_4->setFrameShadow(QFrame::Raised);
    verticalLayout_5 = new QVBoxLayout(frame_4);
    verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
    label_6 = new QLabel(frame_4);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setMinimumSize(QSize(0, 0));
    label_6->setMaximumSize(QSize(16777215, 25));
    label_6->setFont(font);

    verticalLayout_5->addWidget(label_6);

    frame_5 = new QFrame(frame_4);
    frame_5->setObjectName(QString::fromUtf8("frame_5"));
    frame_5->setFrameShape(QFrame::StyledPanel);
    frame_5->setFrameShadow(QFrame::Raised);
    verticalLayout_8 = new QVBoxLayout(frame_5);
    verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
    frame_6 = new QFrame(frame_5);
    frame_6->setObjectName(QString::fromUtf8("frame_6"));
    frame_6->setFrameShape(QFrame::StyledPanel);
    frame_6->setFrameShadow(QFrame::Raised);
    horizontalLayout_2 = new QHBoxLayout(frame_6);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    first_eq = new QRadioButton(frame_6);
    first_eq->setObjectName(QString::fromUtf8("first_eq"));
    first_eq->setMaximumSize(QSize(20, 16777215));
    first_eq->setChecked(true);

    horizontalLayout_2->addWidget(first_eq);

    label_7 = new QLabel(frame_6);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    QFont font1;
    font1.setPointSize(13);
    label_7->setFont(font1);

    horizontalLayout_2->addWidget(label_7);

    verticalLayout_8->addWidget(frame_6);

    frame_7 = new QFrame(frame_5);
    frame_7->setObjectName(QString::fromUtf8("frame_7"));
    frame_7->setFrameShape(QFrame::StyledPanel);
    frame_7->setFrameShadow(QFrame::Raised);
    horizontalLayout_3 = new QHBoxLayout(frame_7);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    sec_eq = new QRadioButton(frame_7);
    sec_eq->setObjectName(QString::fromUtf8("sec_eq"));
    sec_eq->setMaximumSize(QSize(20, 16777215));

    horizontalLayout_3->addWidget(sec_eq);

    label_8 = new QLabel(frame_7);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setFont(font1);

    horizontalLayout_3->addWidget(label_8);

    verticalLayout_8->addWidget(frame_7);

    frame_8 = new QFrame(frame_5);
    frame_8->setObjectName(QString::fromUtf8("frame_8"));
    frame_8->setFrameShape(QFrame::StyledPanel);
    frame_8->setFrameShadow(QFrame::Raised);
    horizontalLayout_4 = new QHBoxLayout(frame_8);
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    thrd_eq = new QRadioButton(frame_8);
    thrd_eq->setObjectName(QString::fromUtf8("thrd_eq"));
    thrd_eq->setMaximumSize(QSize(20, 16777215));

    horizontalLayout_4->addWidget(thrd_eq);

    label_9 = new QLabel(frame_8);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setFont(font1);

    horizontalLayout_4->addWidget(label_9);

    verticalLayout_8->addWidget(frame_8);

    verticalLayout_5->addWidget(frame_5);

    frame_9 = new QFrame(frame_4);
    frame_9->setObjectName(QString::fromUtf8("frame_9"));
    frame_9->setFrameShape(QFrame::StyledPanel);
    frame_9->setFrameShadow(QFrame::Raised);
    verticalLayout_9 = new QVBoxLayout(frame_9);
    verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
    label_10 = new QLabel(frame_9);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    QFont font2;
    font2.setPointSize(16);
    font2.setBold(true);
    font2.setWeight(75);
    label_10->setFont(font2);

    verticalLayout_9->addWidget(label_10);

    file_edit_text = new QTextEdit(frame_9);
    file_edit_text->setObjectName(QString::fromUtf8("file_edit_text"));
    file_edit_text->setMaximumSize(QSize(16777215, 30));
    file_edit_text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    verticalLayout_9->addWidget(file_edit_text);

    frame_10 = new QFrame(frame_9);
    frame_10->setObjectName(QString::fromUtf8("frame_10"));
    frame_10->setFrameShape(QFrame::StyledPanel);
    frame_10->setFrameShadow(QFrame::Raised);
    horizontalLayout_5 = new QHBoxLayout(frame_10);
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    browse_btn = new QPushButton(frame_10);
    browse_btn->setObjectName(QString::fromUtf8("browse_btn"));

    horizontalLayout_5->addWidget(browse_btn);

    load_btn = new QPushButton(frame_10);
    load_btn->setObjectName(QString::fromUtf8("load_btn"));

    horizontalLayout_5->addWidget(load_btn);

    verticalLayout_9->addWidget(frame_10);

    verticalLayout_5->addWidget(frame_9);

    horizontalLayout->addWidget(frame_4);

    verticalLayout->addWidget(frame_2);

    frame = new QFrame(centralwidget);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);
    verticalLayout_3 = new QVBoxLayout(frame);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    tabWidget = new QTabWidget(frame);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    verticalLayout_2 = new QVBoxLayout(tab);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    graph_view = new QWebEngineView(tab);
    graph_view->setObjectName(QString::fromUtf8("graph_view"));
    graph_view->setUrl(QUrl(QString::fromUtf8("about:blank")));

    verticalLayout_2->addWidget(graph_view);

    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    verticalLayout_6 = new QVBoxLayout(tab_2);
    verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
    tabWidget_2 = new QTabWidget(tab_2);
    tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
    tab_3 = new QWidget();
    tab_3->setObjectName(QString::fromUtf8("tab_3"));
    verticalLayout_7 = new QVBoxLayout(tab_3);
    verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
    adams_text_browse = new QTextBrowser(tab_3);
    adams_text_browse->setObjectName(QString::fromUtf8("adams_text_browse"));

    verticalLayout_7->addWidget(adams_text_browse);

    tabWidget_2->addTab(tab_3, QString());
    tab_4 = new QWidget();
    tab_4->setObjectName(QString::fromUtf8("tab_4"));
    verticalLayout_10 = new QVBoxLayout(tab_4);
    verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
    euler_text_browser = new QTextBrowser(tab_4);
    euler_text_browser->setObjectName(QString::fromUtf8("euler_text_browser"));

    verticalLayout_10->addWidget(euler_text_browser);

    tabWidget_2->addTab(tab_4, QString());
    tab_5 = new QWidget();
    tab_5->setObjectName(QString::fromUtf8("tab_5"));
    verticalLayout_11 = new QVBoxLayout(tab_5);
    verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
    runge_kutta_text_browser = new QTextBrowser(tab_5);
    runge_kutta_text_browser->setObjectName(
        QString::fromUtf8("runge_kutta_text_browser"));

    verticalLayout_11->addWidget(runge_kutta_text_browser);

    tabWidget_2->addTab(tab_5, QString());

    verticalLayout_6->addWidget(tabWidget_2);

    tabWidget->addTab(tab_2, QString());

    verticalLayout_3->addWidget(tabWidget);

    verticalLayout->addWidget(frame);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 971, 30));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    tabWidget->setCurrentIndex(0);
    tabWidget_2->setCurrentIndex(2);

    QMetaObject::connectSlotsByName(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "Lab 6", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "x_0", nullptr));
    label_2->setText(QCoreApplication::translate("MainWindow", "y_0", nullptr));
    label_3->setText(QCoreApplication::translate("MainWindow", "x_n", nullptr));
    label_4->setText(QCoreApplication::translate("MainWindow", "h", nullptr));
    label_5->setText(
        QCoreApplication::translate("MainWindow", "epsilon", nullptr));
    calc_btn->setText(
        QCoreApplication::translate("MainWindow", "Calculate", nullptr));
    label_6->setText(QCoreApplication::translate(
        "MainWindow", "\320\236\320\224\320\243", nullptr));
    first_eq->setText(QString());
    label_7->setText(
        QCoreApplication::translate("MainWindow", "x^2 + y", nullptr));
    sec_eq->setText(QString());
    label_8->setText(
        QCoreApplication::translate("MainWindow", "4x + y/3", nullptr));
    thrd_eq->setText(QString());
    label_9->setText(
        QCoreApplication::translate("MainWindow", "y * cos(x)", nullptr));
    label_10->setText(QCoreApplication::translate(
        "MainWindow", "Load data from file", nullptr));
    browse_btn->setText(
        QCoreApplication::translate("MainWindow", "Browse", nullptr));
    load_btn->setText(
        QCoreApplication::translate("MainWindow", "Load", nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(tab),
        QCoreApplication::translate("MainWindow", "Graph", nullptr));
    tabWidget_2->setTabText(
        tabWidget_2->indexOf(tab_3),
        QCoreApplication::translate("MainWindow", "Adams", nullptr));
    tabWidget_2->setTabText(
        tabWidget_2->indexOf(tab_4),
        QCoreApplication::translate("MainWindow", "Euler", nullptr));
    tabWidget_2->setTabText(
        tabWidget_2->indexOf(tab_5),
        QCoreApplication::translate("MainWindow", "Runge Kutta 4", nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(tab_2),
        QCoreApplication::translate("MainWindow", "Points", nullptr));
  } // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNERRUZFXD_H
