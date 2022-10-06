#include <bit>
#include <limits>
#include <cstdint>


constexpr uint32_t root_map[10] = {0, 0x7ef4fa6e, 0x5f37bbd3, 0x54a3519f, 0x4f591c85, 0x4c2c9642, 0x4a0ee76b, 0x488bfcd1, 0x4769ccde, 0x46881959};

constexpr uint32_t exp_map[6] = {0x0, 0x0, 0x3f7a7d37, 0x7ef4fa6e, 0xbe6f77a6, 0xfde9f4dd};

float Q_exp(float number, int n)
{
    static_assert(std::numeric_limits<float>::is_iec559); // (enable only on IEEE 754)
    
    return std::bit_cast<float>(
		(std::bit_cast<std::uint32_t>(number) * n) - exp_map[n]);
    
}

float Quake(float number) {
    static_assert(std::numeric_limits<float>::is_iec559); // (enable only on IEEE 754)

    float const y = std::bit_cast<float>(
		0x5f3759df - (std::bit_cast<std::uint32_t>(number) >> 1));
    return y * (1.5f - (number * 0.5f * y * y));   
}

float Q_nroot(float number, int n)
{

    static_assert(std::numeric_limits<float>::is_iec559); // (enable only on IEEE 754)

    const float one_over_n = (1.0f/n);
    float const y = std::bit_cast<float>(
		root_map[n] - (std::bit_cast<std::uint32_t>(number) / n));
    return y * ((1.0f + one_over_n) - ( number * one_over_n * Q_exp(y, n)));
}

constexpr uint64_t root_map_d[10] = {0x0, 0x7fde9f4dd8d0e800, 0x5fe6f77a629cb000, 0x553f14de908b4400, 0x4feb2390a7829000, 0x4cb8c5fb8216f000, 0x4a973242be79dc00, 0x49117f9a32c08400, 0x47ed399bc9f58400, 0x4709e6b978741000};

constexpr uint64_t exp_map_d[5] = {0x0, 0x0, 0x3fef4fa6ec687400, 0x7fde9f4dd8d0e800, 0xbfcdeef4c5396000};

double Q_exp_double(double number, int n)
{
    static_assert(std::numeric_limits<double>::is_iec559); // (enable only on IEEE 754)
    
    return std::bit_cast<double>(
		(std::bit_cast<std::uint64_t>(number) * n) - exp_map_d[n]);
    
}

double Q_nroot_double(double number, int n)
{

    static_assert(std::numeric_limits<double>::is_iec559); // (enable only on IEEE 754)

    const float one_over_n = (1.0f/n);
    double const y = std::bit_cast<double>(
		root_map_d[n] - (std::bit_cast<std::uint64_t>(number) / n));
    return y * ((1.0f + one_over_n) - ( number * one_over_n * Q_exp_double(y, n)));
}


#include <cmath>
#include <cstdio>
#include <chrono>

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
