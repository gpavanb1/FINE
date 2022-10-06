#ifndef FINE
#define FINE

#include <bit>
#include <limits>
#include <cstdint>
#include <stdexcept>


constexpr uint32_t root_map[10] = {0, 0x7ef4fa6e, 0x5f37bbd3, 0x54a3519f, 0x4f591c85, 0x4c2c9642, 0x4a0ee76b, 0x488bfcd1, 0x4769ccde, 0x46881959};

constexpr uint32_t exp_map[6] = {0x0, 0x0, 0x3f7a7d37, 0x7ef4fa6e, 0xbe6f77a6, 0xfde9f4dd};

float Q_exp(float number, int n)
{
    static_assert(std::numeric_limits<float>::is_iec559); // (enable only on IEEE 754)
    if (n < 2 || n > 5)
      throw std::invalid_argument("n must be 2, 3, 4 or 5");
    if (number < 0)
      throw std::invalid_argument("Only positive numbers");

    return std::bit_cast<float>(
		(std::bit_cast<std::uint32_t>(number) * n) - exp_map[n]);
    
}

float Quake(float number) {
    static_assert(std::numeric_limits<float>::is_iec559); // (enable only on IEEE 754)

    if (number < 0)
      throw std::invalid_argument("Only positive numbers");

  	float const y = std::bit_cast<float>(
		0x5f3759df - (std::bit_cast<std::uint32_t>(number) >> 1));
    return y * (1.5f - (number * 0.5f * y * y));   
}

float Q_nroot(float number, int n)
{

    static_assert(std::numeric_limits<float>::is_iec559); // (enable only on IEEE 754)
    if (n < 2 || n > 5)
      throw std::invalid_argument("n must be 2, 3, 4 or 5");
    if (number < 0)
      throw std::invalid_argument("Only positive numbers");

    const float one_over_n = (1.0f/n);
    float const y = std::bit_cast<float>(
		root_map[n] - (std::bit_cast<std::uint32_t>(number) / n));
    return y * ((1.0f + one_over_n) - ( number * one_over_n * Q_exp(y, n)));
}

#endif