#pragma once

#include <cmath>
#include <vector>
#include <string>
#include <sstream>

#include "../util.h" // TODO: Non-absolute path (included via CMake)

class ArithmeticalCongruenceMonoid
{
public:
  ArithmeticalCongruenceMonoid(int a, int b);

  int a() const { return m_a; }
  int b() const { return m_b; }

  std::vector<int> factorizations(int n);

  explicit operator std::string() const;

private:
  int m_a, m_b;

  ArithmeticalCongruenceMonoid() = delete;
};

std::ostream& operator<<(
    std::ostream& os,
    const ArithmeticalCongruenceMonoid& obj);
