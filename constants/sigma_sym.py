import sympy as sp

# Define symbolic variables
x, s = sp.symbols('x s')

# Define the integrand
integrand = (sp.log(1 + x, 2) - (x + s))**2

# Define the integral expression
total_integral = sp.integrate(integrand, (x, 0, 1))

# Simplify the total_integral
total_integral_simplified = sp.simplify(total_integral)

# Find the optimal s that minimizes the integral (minimization of a quadratic)
optimal_s = sp.solve(sp.diff(total_integral_simplified, s), s)

print("Optimal s:", optimal_s)
