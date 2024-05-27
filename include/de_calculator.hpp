#ifndef A5F3C481_C139_4236_B0FA_69C97E727A6B
#define A5F3C481_C139_4236_B0FA_69C97E727A6B

#include "equation.hpp"
#include <string>
#include <vector>

/**
 * @brief A class for solving ordinary differential equations (ODEs).
 **/
class DifferentialEquationCalculator {
public:
  /**
   * @brief Enum representing the types of calculation methods.
   */
  enum CalculationMethodType {
    Adams,
    ExtendedEuler,
    RungeKutta4,
  };

private:
  Equation equation;            /**< The equation to solve */
  CalculationMethodType method; /**< The method used for solving */
  double error;                 /**< The maximum error allowed */
  double x0; /**< The initial value of the independent variable */
  double y0; /**< The initial value of the dependent variable */
  double xn; /**< The final value of the independent variable */
  double h;  /**< The step size */

  /**
   * @brief Finds the constant 'c' for the given initial condition.
   *
   * @return The constant 'c'.
   */
  double findConstantC() const;

public:
  /**
   * @brief Constructor for the DifferentialEquationCalculator class.
   *
   * @param eq The equation to solve.
   * @param method The method used for solving.
   * @param err The maximum error allowed.
   * @param _x0 The initial value of the independent variable.
   * @param _y0 The initial value of the dependent variable.
   * @param _xn The final value of the independent variable.
   * @param _h The step size.
   */
  DifferentialEquationCalculator(Equation eq, CalculationMethodType method,
                                 double err, double _x0, double _y0, double _xn,
                                 double _h);

  /**
   * @brief Solves the differential equation using Extended Euler's method.
   *
   * @return A vector of pairs representing the solution points.
   */
  std::vector<std::pair<double, double>> extendedEuler() const;

  std::vector<std::pair<double, double>> adams() const;

  std::vector<std::pair<double, double>> rungeKutta4() const;
  /**
   * @brief Solves the differential equation using the specified method.
   *
   * @return A vector of pairs representing the solution points.
   */
  std::vector<std::pair<double, double>> solve();

  /**
   * @brief Gets the equation for finding the constant 'c'.
   *
   * @return The equation for finding 'c' in LaTeX format.
   */
  std::string getEquationForC() const;
};

#endif /* A5F3C481_C139_4236_B0FA_69C97E727A6B */
