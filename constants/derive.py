sigma = 0.04303

def float_data(precision):
    if precision == "single":
        return 23, 127
    elif precision == "double":
        return 52, 1023

def constant(n, precision="single"):
    L, B = float_data(precision)
    return hex(int((1. + 1./n)*(B - sigma) * pow(2,L)))

if __name__ == "__main__":
    for i in range(1, 10):
        print(i, constant(i))

    print('')

    for i in range(1, 5):
        print(i, constant(i, "double"))
