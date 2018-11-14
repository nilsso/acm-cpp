#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
//#include "acm-cpp.h"

/**
 * @tparam T An iterable object
 * @param obj The iterable object
 * @param delim String delimiter
 */
template<typename T>
std::string join(const T& obj, const std::string& delim)
{
  std::stringstream ss;
  for (auto i = obj.begin(); i != std::prev(obj.end()); ++i)
    ss << *i << delim;
  ss << obj.back();
  return ss.str();
}

/**
 * @tparam T Numeric type
 * @param n Number to factor
 */
template<typename T>
std::vector<T> factor(T n)
{
  std::vector<T> factors;
  T d = 2;
  T m = (T)std::sqrt(n);
  while (n > 1) {
    while (n % d) {
      ++d;
      if (d == m)
        d = n;
    }
    factors.push_back(d);
    n /= d;
  }
  return factors;
}

int main(int argc, char **argv)
{
  //using ACM = ArithmeticalCongruenceMonoid;
  //ACM a(1, 4);
  //std::cout << a << '\n';

  std::cout << join(factor(144), ", ") << '\n';
  // [output]> 2, 2, 2, 2, 3, 3

  return 0;
}
