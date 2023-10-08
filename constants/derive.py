# Sigma value used is same as in Wikipedia
# https://en.wikipedia.org/wiki/Fast_inverse_square_root#
sigma = 0.04303

# Get bias and exponent for single and double precision
def float_data(precision):
    if precision == "single":
        return 23, 127
    elif precision == "double":
        return 52, 1023

# Evaluate the constant offset for the approximation
def constant(n, precision="single"):
    L, B = float_data(precision)
    return hex(int((1. + 1./n)*(B - sigma) * pow(2,L)))

# List out the values for single and double precision
print('Single Precision Offsets')
for i in range(1, 10):
    print(i, constant(i))

print('')

print('Double Precision Offsets')
for i in range(1, 5):
    print(i, constant(i, "double"))
