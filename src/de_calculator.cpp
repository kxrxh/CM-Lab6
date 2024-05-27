#include "de_calculator.hpp"
#include <cmath>
#include <functional>
#include <limits>
#include <qstring.h>
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
  double target_y = y0;
  double x = x0;
  double best_c = 0.0;
  double min_error = std::numeric_limits<double>::max();

  // Iterate over a range of possible C values
  for (int i = -1000; i <= 1000; i++) {
    double c = i * 0.1; // Adjust range and step as needed
    double y = equation.evaluate_solution(x, c);
    double _error = std::fabs(y - target_y);

    if (_error <= min_error) {
      min_error = _error;
      best_c = c;

      if (_error <=
          this->error) { // Utilize the given tolerance to possibly exit early
        break;
      }
    }
  }

  return best_c;
}

std::vector<std::pair<double, double>>
DifferentialEquationCalculator::rungeKutta4() const {
  std::vector<std::pair<double, double>> results;
  double x = x0;
  double y = y0;
  results.emplace_back(x, y);

  while (x < xn) {
    double k1 = h * equation.evaluate(x, y);
    double k2 = h * equation.evaluate(x + h / 2.0, y + k1 / 2.0);
    double k3 = h * equation.evaluate(x + h / 2.0, y + k2 / 2.0);
    double k4 = h * equation.evaluate(x + h, y + k3);

    y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    x += h;

    results.emplace_back(x, y);
  }

  return results;
}

std::vector<std::pair<double, double>>
DifferentialEquationCalculator::adams() const {
  std::vector<std::pair<double, double>> results;
  std::vector<double> x_values;
  std::vector<double> y_values;
  double x = x0;
  double y = y0;

  // Initializing with Runge-Kutta to get the first few values
  for (int i = 0; i < 4; ++i) {
    results.emplace_back(x, y);
    x_values.push_back(x);
    y_values.push_back(y);

    double k1 = h * equation.evaluate(x, y);
    double k2 = h * equation.evaluate(x + h / 2.0, y + k1 / 2.0);
    double k3 = h * equation.evaluate(x + h / 2.0, y + k2 / 2.0);
    double k4 = h * equation.evaluate(x + h, y + k3);

    y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    x += h;
  }

  // Adams-Bashforth method
  while (x < xn) {
    double f0 = equation.evaluate(x_values[3], y_values[3]);
    double f1 = equation.evaluate(x_values[2], y_values[2]);
    double f2 = equation.evaluate(x_values[1], y_values[1]);
    double f3 = equation.evaluate(x_values[0], y_values[0]);

    y += h * (55 * f0 - 59 * f1 + 37 * f2 - 9 * f3) / 24.0;
    x += h;

    results.emplace_back(x, y);

    // Shift the values for the next iteration
    for (int i = 0; i < 3; ++i) {
      x_values[i] = x_values[i + 1];
      y_values[i] = y_values[i + 1];
    }
    x_values[3] = x;
    y_values[3] = y;
  }

  return results;
}

// Function to perform the improved Euler's method (Heun's method)
std::vector<std::pair<double, double>>
DifferentialEquationCalculator::extendedEuler() const {
  std::vector<std::pair<double, double>> points;
  std::vector<std::pair<double, double>> results;
  double x = x0;
  double y = y0;
  results.emplace_back(x, y);

  while (x < xn) {
    double y_next =
        y +
        h * equation.evaluate(
                x, y); // Euler's method to find the approximate next value of y
    y += h / 2.0 *
         (equation.evaluate(x, y) +
          equation.evaluate(x + h,
                            y_next)); // Correcting using the average of slopes
    x += h;

    results.emplace_back(x, y);
  }

  return results;
}

std::string DifferentialEquationCalculator::getEquationForC() const {
  double c = findConstantC();
  std::string result;
  switch (equation.getType()) {
  case Equation::Fraction:
    result = std::to_string(c) + "\\\\exp(x / 3) - 12x - 36";
    break;
  case Equation::Linear:
    result = std::to_string(c) + "* \\\\exp(x) - x^{2} - 2 * x - 2";
    break;
  case Equation::Triganometric:
    result = std::to_string(c) + " \\\\times \\\\exp(\\\\sin(x))";
    break;
  default:
    throw std::runtime_error("Unknown equation type");
  }

  std::replace(result.begin(), result.end(), ',', '.');

  return result;
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