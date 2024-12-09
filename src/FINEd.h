#ifndef FINED
#define FINED

#include <bit>
#include <limits>
#include <cstdint>
#include <stdexcept>
#include "bit_cast.h"

constexpr uint64_t root_map_d[10] = {0x0, 0x7fde9f4dd8d0e800, 0x5fe6f77a629cb000, 0x553f14de908b4400, 0x4feb2390a7829000, 0x4cb8c5fb8216f000, 0x4a973242be79dc00, 0x49117f9a32c08400, 0x47ed399bc9f58400, 0x4709e6b978741000};

constexpr uint64_t exp_map_d[5] = {0x0, 0x0, 0x3fef4fa6ec687400, 0x7fde9f4dd8d0e800, 0xbfcdeef4c5396000};

double Q_exp_double(double number, int n)
{
  static_assert(std::numeric_limits<double>::is_iec559); // (enable only on IEEE 754)
  if (n < 2 || n > 4)
    throw std::invalid_argument("n must be 2, 3 or 4");
  if (number < 0)
    throw std::invalid_argument("Only positive numbers");

  return bit_cast<double>(
      (bit_cast<std::uint64_t>(number) * n) - exp_map_d[n]);
}

double Q_nroot_double(double number, int n)
{

  static_assert(std::numeric_limits<double>::is_iec559); // (enable only on IEEE 754)
  if (n < 2 || n > 4)
    throw std::invalid_argument("n must be 2, 3 or 4");
  if (number < 0)
    throw std::invalid_argument("Only positive numbers");

  const float one_over_n = (1.0f / n);
  double const y = bit_cast<double>(
      root_map_d[n] - (bit_cast<std::uint64_t>(number) / n));
  return y * ((1.0f + one_over_n) - (number * one_over_n * Q_exp_double(y, n)));
}

#endif