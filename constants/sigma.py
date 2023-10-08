import numpy as np
from scipy.integrate import quad
from scipy.optimize import minimize_scalar
import matplotlib.pyplot as plt

# Define the function for the integral
def integrand(x, s):
    return (np.log2(1 + x) - (x + s))**2.

# Define the objective function
obj = lambda s: quad(lambda x: integrand(x, s), 0, 1, epsabs=1e-15)[0]


# Define a Python function for the objective function
result = minimize_scalar(obj, (0, 0.05), tol=1e-10)
print(result)

# Plot of how error varies with Sigma
x = np.linspace(-0.5, 0.5, 50)
y = [obj(y) for y in x]
plt.plot(x, y)
plt.title('Variation of 2-norm error with $\sigma$')
plt.xlabel('Tuning constant ($\sigma$)')
plt.ylabel('Uniform-norm error')
plt.show()
