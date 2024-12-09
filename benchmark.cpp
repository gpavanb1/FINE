#include <cstdio>
#include <chrono>
#include "FINE.h"
#include "FINEd.h"
#include <cmath>

using namespace std::chrono;

int main(int argc, char *argv[])
{
    float a = 19.2f;
    int n = 2;
    int i;
    int LOOP_COUNT = 50000;
    double val = 0;

    // Exponent computation (Q_exp, Q_exp_double, and pow)
    printf("Exponent\n");

    // Start timing for the Exponent calculations
    auto start = high_resolution_clock::now();
    for (i = 1; i < LOOP_COUNT; i++)
        val = Q_exp(a + i, n);
    auto stop_a = high_resolution_clock::now();

    for (i = 1; i < LOOP_COUNT; i++)
        val = Q_exp_double(a + i, n);
    auto stop_f = high_resolution_clock::now();

    for (i = 1; i < LOOP_COUNT; i++)
        val = pow(a + i, n);
    auto stop_c = high_resolution_clock::now();

    // Print computed values (last computed value will be the result of the last loop)
    printf("FINE Value: %f\n", Q_exp(a, n));
    printf("FINEd Value: %f\n", Q_exp_double(a, n));
    printf("C value: %f\n", pow(a, n));

    // Print execution times for Exponent computations (in microseconds)
    printf("Times (float, double, C): %lld, %lld, %lld\n",
           duration_cast<microseconds>(stop_a - start).count(),
           duration_cast<microseconds>(stop_f - stop_a).count(),
           duration_cast<microseconds>(stop_c - stop_f).count());

    printf("\n");

    // Inverse-Root computation (Q_nroot, Q_nroot_double, Quake, and pow)
    printf("Inverse-Root\n");

    start = high_resolution_clock::now();
    for (i = 1; i < LOOP_COUNT; i++)
        val = Q_nroot(a + i, n);
    stop_f = high_resolution_clock::now();

    for (i = 1; i < LOOP_COUNT; i++)
        val = Q_nroot_double(a + i, n);
    auto stop_d = high_resolution_clock::now();

    for (i = 1; i < LOOP_COUNT; i++)
        val = Quake(a + i);
    auto stop_q = high_resolution_clock::now();

    for (i = 1; i < LOOP_COUNT; i++)
        val = pow(a + i, -1. / n);
    stop_c = high_resolution_clock::now();

    // Print computed values for Inverse-Root
    printf("FINE Value: %f\n", Q_nroot(a, n));
    printf("FINEd Value: %f\n", Q_nroot_double(a, n));
    printf("Quake 3 Value: %f\n", Quake(a));
    printf("C value: %f\n", pow(a, -1. / n));

    // Print execution times for Inverse-Root computations (in microseconds)
    printf("Times (float, double, Quake, C): %lld, %lld, %lld, %lld\n",
           duration_cast<microseconds>(stop_f - start).count(),
           duration_cast<microseconds>(stop_d - stop_f).count(),
           duration_cast<microseconds>(stop_q - stop_d).count(),
           duration_cast<microseconds>(stop_c - stop_q).count());

    return 0;
}
