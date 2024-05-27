#include "equation.hpp"
#include <cmath>
#include <stdexcept>

Equation::EquationType Equation::getType() const { return type; }

double Equation::evaluate(double x, double y) const {
  switch (this->type) {
  case EquationType::Fraction:
    return 4 * x + y / 3;
  case EquationType::Linear:
    return std::pow(x, 2) + y;
  case EquationType::Triganometric:
    return y * std::cos(x);
  default:
    throw std::runtime_error("Unknown equation type");
  }
}

double Equation::evaluate_solution(double x, double c) const {
  switch (this->type) {
  case EquationType::Fraction:
    return c * std::exp(x / 3) - 12 * x - 36;
  case EquationType::Linear:
    return c * std::exp(x) - std::pow(x, 2) - 2 * x - 2;
  case EquationType::Triganometric:
    return c * std::exp(std::sin(x));
  default:
    throw std::runtime_error("Unknown equation type");
  }
}
