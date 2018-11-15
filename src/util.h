#pragma once

#include <cmath>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>

namespace util
{
  /**
   * @param obj Vector of strings to join
   * @param delim String delimiter
   */
  inline std::string join(const std::vector<std::string>& obj, const std::string& delim)
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
   * @return Vector of pairs of factors and their powers
   *
   * For example factor(441) will return [(3, 2), (7, 2)] equivalently.
   */
  inline std::vector<std::pair<int,int>> factor(int n)
  {
    std::vector<std::pair<int,int>> factors;
    int d = 2;
    int m = (int)std::sqrt(n);
    while (n > 1) {
      while (n % d != 0) {
        ++d;
      }
      if (n % d == 0) {
        int dd = n/d;
        int i = 1;
        while (dd % d == 0) {
          dd /= d;
          ++i;
        }
        factors.push_back({d, i});
        n /= pow(d,i);
      }
      if (d == m)
        d = n;
    }
    return factors;
  }
}
