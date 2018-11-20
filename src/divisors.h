#pragma once

#include <set>
#include <iostream>

#include "pfactor.h"
#include "util.h"

using std::set;
using std::cout;

inline set<int> divisors(int n)
{
  set<int> ds{1};
  auto pfactors = pfactor(n);
  for (auto pfP: pfactors) {
    auto b{std::move(ds)}; // by moving instead of copying we work with the same pointers
    ds.clear();
    for (int p = 0; p <= pfP.second; ++p) {
      for (auto d: b) {
        ds.insert(d*pow(pfP.first, p));
      }
    }
  }
  return ds;
}

