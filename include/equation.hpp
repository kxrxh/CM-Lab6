#ifndef EA96E7D1_4B61_4AD2_A108_7DCADA99290A
#define EA96E7D1_4B61_4AD2_A108_7DCADA99290A

/**
 * @brief Represents a differential equation.
 *
 * The Equation class defines a differential equation and provides methods to
 * evaluate the equation and its solution.
 */
class Equation {
public:
  /**
   * @brief Enum representing the types of equations.
   */
  enum EquationType { Linear, Fraction, Triganometric };

  /**
   * @brief Constructor for the Equation class.
   *
   * @param type The type of the equation.
   */
  Equation(EquationType type) : type(type){};

  /**
   * @brief Gets the type of the equation.
   *
   * @return The type of the equation.
   */
  EquationType getType() const;

  /**
   * @brief Evaluates the differential equation at a given point.
   *
   * @param x The value of the independent variable.
   * @param y The value of the dependent variable.
   * @return The value of the derivative at the given point.
   */
  double evaluate(double x, double y) const;

  /**
   * @brief Evaluates the solution of the differential equation at a given
   * point.
   *
   * @param x The value of the independent variable.
   * @param c The constant 'c' in the solution.
   * @return The value of the solution at the given point.
   */
  double evaluate_solution(double x, double c) const;

private:
  EquationType type; /**< The type of the equation. */
};

#endif /* EA96E7D1_4B61_4AD2_A108_7DCADA99290A */
