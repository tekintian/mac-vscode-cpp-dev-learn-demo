#include <Equals>
#include <array>
#include <iostream>

using namespace std;
template <typename T> constexpr T OddNumber(size_t i) noexcept {
  return i * 2 + 1;
}

template <typename T> constexpr T Fibonacci(size_t i) noexcept {
  if (i <= 1) {
    return 1;
  }
  return Fibonacci<T>(i - 1) + Fibonacci<T>(i - 2);
}

template <typename T, size_t N, typename F, size_t... I>
constexpr array<std::remove_cv_t<T>, N>
GenerateArrayImpl(F f, std::index_sequence<I...>) noexcept {
  return {{f(I)...}};
}

template <size_t N, typename F, typename T = invoke_result_t<F, size_t>>
constexpr array<T, N> GenerateArray(F f) noexcept {
  return GenerateArrayImpl<T, N>(f, std::make_index_sequence<N>{});
}

int main() {
  constexpr auto oddNumbers = GenerateArray<5>(OddNumber<uint8_t>);
  static_assert(Equals(oddNumbers, {1, 3, 5, 7, 9}));
  constexpr auto fiboNumbers = GenerateArray<5>(Fibonacci<uint32_t>);
  static_assert(Equals(fiboNumbers, {1, 1, 2, 3, 5}));

  // 甚至可以传入lambda来定制要生成的数字序列（限定C++17）
  constexpr auto specified = GenerateArray<3>([](size_t i) { return i + 10; });
  static_assert(Equals(specified, {10, 11, 12}));
  return 0;
}