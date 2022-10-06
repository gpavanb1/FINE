# FINE

**F**ast **IN**verse **E**xponentiation

Compute `x^(1/n)` and `x^n` faster than standard methods


## How to install and execute?

Make sure you are using at least `C++20` standard for this library 

Just clone, compile and run using
```
g++ -std=c++2a -O2 -Wall -pedantic test.cpp && ./test.out
```

The following program illustrates a basic example
```cpp
#include "FINE.h"
#include "FINEd.h"
#include <cmath>
#include <cstdio>

int main(int argc, char *argv[]) {

    float a = 19.2f;
    int n = 2;

    printf("FINE Value: %f\n", Q_exp(a, n));
    printf("FINEd Value: %f\n", Q_exp_double(a, n));
    printf("C value: %f\n", pow(a, n));
    printf("\n");
    printf("FINE Value: %f\n", Q_nroot(a, n));
    printf("FINEd Value: %f\n", Q_nroot_double(a, n));
    printf("Quake 3 Value: %f\n", Quake(a));
    printf("C value: %f\n", pow(a, -1./n));
    
    return 0;
}
```

## Results

For a trial run with the above program,

```
Exponent
FINE Value: 369.421783
FINEd Value: 369.421772
C value: 368.640029


Inverse-Root
FINE Value: 0.226177
FINEd Value: 0.226177
Quake 3 Value: 0.228213
C value: 0.228218
```

When the computations were repeated with different values for N=50,000 times (in microseconds)

```
Exponent
Times (float, double, C): 390, 387, 2306

Inverse-Root
Times (float, double, Quake, C): 1291, 1629, 658, 2069
```

The `Quake` method supports only inverse square roots

## How does this work?

This work takes inspiration from the [Fast Inverse Square Root](https://en.wikipedia.org/wiki/Fast_inverse_square_root) from the [Quake 3 Engine](https://en.wikipedia.org/wiki/Quake_III_Arena) (although sources mention it is older) and generalizes it to both `32-bit` and `64-bit` floating-point values.

Note that fast computation of inverse n-th root requires fast exponentiation (`x^n`) as well and is included.


## Whom to contact?

Please direct your queries to [gpavanb1](http://github.com/gpavanb1)
for any questions.
