#pragma once

#include <cmath>
#include <utility>
#include <vector>
#include <string>
#include <sstream>

#include "../util.h"

class ArithmeticalCongruenceMonoid
{
public:
  ArithmeticalCongruenceMonoid(int a, int b);

  int a() const { return m_a; }
  int b() const { return m_b; }

  std::vector<std::pair<int,int>> factorizations(int n);

  explicit operator std::string() const;

private:
  int m_a, m_b;

  ArithmeticalCongruenceMonoid() = delete;
};

std::ostream& operator<<(
    std::ostream& os,
    const ArithmeticalCongruenceMonoid& obj);
