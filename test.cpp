#include "FINE.h"
#include "FINEd.h"
#include <cmath>
#include <cstdio>

int main(int argc, char *argv[]) {

    float a = 14.0f;
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