#include <cmath>
#include <utility>

#include <string>
#include <iostream>
#include <sstream>

class ArithmeticalCongruenceMonoid
{
public:
  ArithmeticalCongruenceMonoid(int a, int b);

  int a() const { return m_a; }
  int b() const { return m_b; }

  explicit operator std::string() const;

private:
  int m_a, m_b;

  ArithmeticalCongruenceMonoid() = delete;
};

std::ostream& operator<<(
    std::ostream& os,
    const ArithmeticalCongruenceMonoid& obj);
