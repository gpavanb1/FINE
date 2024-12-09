#ifndef BIT_CAST_H
#define BIT_CAST_H

#include <cstring>
#include <type_traits>

template <typename To, typename From>
typename std::enable_if<sizeof(To) == sizeof(From) && std::is_trivially_copyable<From>::value &&
                            std::is_trivially_copyable<To>::value,
                        To>::type
bit_cast(const From &src) noexcept
{
    To dst;
    std::memcpy(&dst, &src, sizeof(To));
    return dst;
}

#endif