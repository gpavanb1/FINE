#include <cstdio>
#include <chrono>
#include "FINE.h"
#include "FINEd.h"

using namespace std::chrono;

int main(int argc, char *argv[]) {

    float a = 19.2f;
    int n = 2;
    int i;
    int LOOP_COUNT = 50000;
    double val = 0;

    printf("Start..%f\n", val);
    auto start = high_resolution_clock::now();
    printf("\n");
    
    auto stop_a = high_resolution_clock::now();
    for (i=1; i < LOOP_COUNT; i++)
    val = Q_exp(a+i, n);
    auto stop_f = high_resolution_clock::now();
    for (i=1; i < LOOP_COUNT; i++)
    val = Q_exp_double(a+i, n);
    auto stop_d = high_resolution_clock::now();
    for (i=1; i < LOOP_COUNT; i++)
    val = pow(a+i, n);
    auto stop_c = high_resolution_clock::now();
    printf("Times (float, double, C): %ld, %ld, %ld\n", 
    duration_cast<microseconds>(stop_f-stop_a).count(), 
    duration_cast<microseconds>(stop_d-stop_f).count(), 
    duration_cast<microseconds>(stop_c-stop_d).count()
    );
    
    printf("\n");
    
    start = high_resolution_clock::now();
    
    for (i=1; i < LOOP_COUNT; i++)
    val = Q_nroot(a+i, n);
    stop_f = high_resolution_clock::now();
    for (i=1; i < LOOP_COUNT; i++)
    val = Q_nroot_double(a+i, n);
    stop_d = high_resolution_clock::now();
    for (i=1; i < LOOP_COUNT; i++)
    val = Quake(a+i);
    auto stop_q = high_resolution_clock::now();
    for (i=1; i < LOOP_COUNT; i++)
    val = pow(a+i, -1./n);
    stop_c = high_resolution_clock::now();
    printf("Times (float, double, Quake, C): %ld, %ld, %ld, %ld\n", 
    duration_cast<microseconds>(stop_f-start).count(), 
    duration_cast<microseconds>(stop_d-stop_f).count(),
    duration_cast<microseconds>(stop_q-stop_d).count(),
    duration_cast<microseconds>(stop_c-stop_q).count()
    );
    
    return 0;
}
