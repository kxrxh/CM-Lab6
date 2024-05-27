#include "equation.hpp"
#include <cmath>
#include <stdexcept>

Equation::EquationType Equation::getType() const { return type; }

double Equation::evaluate(double x, double y) const {
  switch (this->type) {
  case EquationType::Linear:
    return -2 * y + std::pow(x, 2);
  case EquationType::Fraction:
    return std::pow(x, 3) - 2 * y;
  case EquationType::Triganometric:
    return y * std::cos(x);
  default:
    throw std::runtime_error("Unknown equation type");
  }
}

double Equation::evaluate_solution(double x, double c) const {
  switch (this->type) {
  case EquationType::Linear:
    return std::exp(std::pow(x, 2) - x) / 2.0 + 0.25 + c / (2.0 * x);
  case EquationType::Fraction:
    return std::pow(x, 3) / 2.0 - ((3.0 * std::pow(x, 2) + 3.0 * x) / 4.0) -
           (3.0 / 8.0) + (c / (2.0 * std::exp(x)));
  case EquationType::Triganometric:
    return c * std::exp(std::sin(x));
  default:
    throw std::runtime_error("Unknown equation type");
  }
}
