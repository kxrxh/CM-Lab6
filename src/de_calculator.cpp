#include "de_calculator.hpp"
#include <cmath>
#include <functional>
#include <limits>
#include <stdexcept>
#include <vector>

// Constructor for DifferentialEquationCalculator
DifferentialEquationCalculator::DifferentialEquationCalculator(
    Equation eq, DifferentialEquationCalculator::CalculationMethodType method,
    double err, double _x0, double _y0, double _xn, double _h)
    : equation(eq), method(method), error(err), x0(_x0), y0(_y0), xn(_xn),
      h(_h) {}

// Function to find the constant 'c' for the given initial condition
double DifferentialEquationCalculator::findConstantC() const {
  double targetY = y0;
  double x = x0;
  double bestC = 0;
  double minError = std::numeric_limits<double>::infinity();

  // Loop through a range of values for 'c' to find the best fit
  for (int i = -1000; i < 1000; i++) {
    double c = i * 0.01;
    double y = equation.evaluate_solution(x, c);
    double calc_error = std::fabs(y - targetY);

    // Update 'bestC' and 'minError' if a better fit is found
    if (calc_error < minError) {
      minError = error;
      bestC = c;
      if (calc_error < this->error) {
        break;
      }
    }
  }

  return bestC;
}

std::vector<std::pair<double, double>>
DifferentialEquationCalculator::rungeKutta4() const {
  std::vector<std::pair<double, double>> result;
  double x = x0;
  double y = y0;

  result.push_back({x, y});

  while (x < xn) {
    double k1 = h * equation.evaluate(x, y);
    double k2 = h * equation.evaluate(x + h / 2, y + k1 / 2);
    double k3 = h * equation.evaluate(x + h / 2, y + k2 / 2);
    double k4 = h * equation.evaluate(x + h, y + k3);

    y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    x = x + h;

    result.push_back({x, y});
  }

  return result;
}

std::vector<std::pair<double, double>>
DifferentialEquationCalculator::adams() const {
  std::vector<std::pair<double, double>> result;
  std::vector<double> x = {x0};
  std::vector<double> y = {y0};
  std::vector<double> f = {equation.evaluate(x0, y0)};

  // Initial Runge-Kutta to start Adams-Bashforth
  while (x.size() < 4) {
    double lastX = x.back();
    double lastY = y.back();

    double k1 = h * equation.evaluate(lastX, lastY);
    double k2 = h * equation.evaluate(lastX + h / 2, lastY + k1 / 2);
    double k3 = h * equation.evaluate(lastX + h / 2, lastY + k2 / 2);
    double k4 = h * equation.evaluate(lastX + h, lastY + k3);

    double nextY = lastY + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    double nextX = lastX + h;

    x.push_back(nextX);
    y.push_back(nextY);
    f.push_back(equation.evaluate(nextX, nextY));
  }

  for (size_t i = 0; i < x.size(); i++) {
    result.push_back({x[i], y[i]});
  }

  // Adams-Bashforth 4-step method
  while (x.back() < xn) {
    double nextX = x.back() + h;
    double nextY =
        y.back() + h / 24 * (55 * f[3] - 59 * f[2] + 37 * f[1] - 9 * f[0]);

    x.push_back(nextX);
    y.push_back(nextY);
    f.push_back(equation.evaluate(nextX, nextY));

    // Remove the oldest value
    x.erase(x.begin());
    y.erase(y.begin());
    f.erase(f.begin());

    result.push_back({nextX, nextY});
  }

  return result;
}

// Function to perform the improved Euler's method (Heun's method)
std::vector<std::pair<double, double>>
DifferentialEquationCalculator::extendedEuler() const {
  std::vector<double> x = {x0};
  std::vector<double> y = {y0};

  double step = h;
  const double n = std::floor((xn - x0) / step);

  // Perform the improved Euler's method
  while (true) {
    for (int i = 1; i <= n; i++) {
      double k1 = equation.evaluate(x.back(), y.back());
      double k2 = equation.evaluate(x.back() + step, y.back() + k1 * step);

      x.push_back(x.back() + step);
      y.push_back(x.back() + step / 2 * (k1 + k2));
    }

    const double new_step = h / 2;

    std::vector<double> x1 = {x0};
    std::vector<double> y1 = {y0};

    double n1 = std::floor((xn - x0) / new_step);

    // Perform the improved Euler's method with a smaller step size
    for (int i = 1; i <= n1; i++) {
      double lastX = x1.back();
      double lastY = y1.back();

      double k1 = equation.evaluate(lastX, lastY);
      double k2 = equation.evaluate(lastX + new_step, lastY + k1 * new_step);

      y1.push_back(lastY + new_step / 2 * (k1 + k2));
      x1.push_back(lastX + new_step);
    }

    if (std::fabs(y[1] - y1[1]) / 3.0 <= error) {
      break;
    }

    step = new_step;
    x = x1;
    y = y1;
  }

  std::vector<std::pair<double, double>> result(x.size());
  for (int i = 0; i < x.size(); i++) {
    result[i] = std::make_pair(x[i], y[i]);
  }

  return result;
}

std::string DifferentialEquationCalculator::getEquationForC() const {
  double c = findConstantC();
  switch (equation.getType()) {
  case Equation::EquationType::Linear:
    return "\\frac{x^{2} - x}{2} + 0.25 + \\frac{" + std::to_string(c) +
           "}{\\exp(2.0 * x)}";
  case Equation::EquationType::Fraction:
    return "\\frac{x^3}{2.0} - \\frac{3x^2 + 3x}{4.0} - \\frac{3}{8.0} + "
           "\\exp(\\frac{" +
           std::to_string(c) + "}{\\left(2.0x\\right)})";
  case Equation::EquationType::Triganometric:
    return std::to_string(c) + " \\times \\exp(\\sin(x))";
  default:
    throw std::invalid_argument("Invalid equation");
  }
}

// Function to solve the differential equation using the specified method
std::vector<std::pair<double, double>> DifferentialEquationCalculator::solve() {
  switch (method) {
  case DifferentialEquationCalculator::RungeKutta4:
    return rungeKutta4();
  case DifferentialEquationCalculator::ExtendedEuler:
    return extendedEuler();
  case DifferentialEquationCalculator::Adams:
    return adams();
  default:
    throw std::invalid_argument("Invalid method");
  }
}