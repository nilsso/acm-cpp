#include "acm.h"

ArithmeticalCongruenceMonoid::ArithmeticalCongruenceMonoid(int a, int b)
{
  assert(a % b == (int)std::pow(a, 2) % b);
  m_b = b;
  m_a = a % b;
}

// -----------------------------------------------------------------------------
// ArithmeticalCongruenceMonoid: Public functions
// -----------------------------------------------------------------------------

ArithmeticalCongruenceMonoid::operator std::string() const
{
  std::stringstream ss;
  ss << m_a << ',' << m_b;
  return ss.str();
}

std::vector<int> ArithmeticalCongruenceMonoid::factorizations(int n)
{
  return factor(n);
}

// -----------------------------------------------------------------------------
// ArithmeticalCongruenceMonoid: Private functions
// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// Non-member functions
// -----------------------------------------------------------------------------

std::ostream& operator<<(
    std::ostream& os,
    const ArithmeticalCongruenceMonoid& obj)
{
  return (os << (std::string)obj);
}
