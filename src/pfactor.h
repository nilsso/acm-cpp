#pragma once

#include <cmath>
#include <vector>
#include <utility>

using std::vector;
using std::pair;

/**
 * @tparam T Numeric type
 * @param n Number to factor
 * @return Vector of pairs of prime factors and their powers
 *
 * For example factor(441) will return [(3, 2), (7, 2)] equivalently.
 */
inline vector<pair<int,int>> pfactor(int n)
{
  vector<pair<int,int>> pfactors;
  int d = 2;
  int m = (int)sqrt(n);
  while (n > 1) {
    while (n % d != 0)
      ++d;
    int dd = n/d;
    int i = 1;
    while (dd % d == 0) {
      dd /= d;
      ++i;
    }
    pfactors.push_back({d, i});
    n /= pow(d,i);
    if (d == m)
      d = n;
  }
  return pfactors;
}

