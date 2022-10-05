#include "FINE.h"
#include <cmath>
#include <cstdio>

int main(int argc, char *argv[]) {

    float a = 14.0f;
    int n = 2;

    printf("FINE Value: %f\n", Q_nroot(a, n));
    printf("FINE Value: %f\n", Q_exp(a, n));
    printf("FINE Value double: %f\n", Q_exp_double(a, n));
    printf("C value: %f\n", pow(a, 1./n));
    printf("C value: %f\n", pow(a, n));

    return 0;
}