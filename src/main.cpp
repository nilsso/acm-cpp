#include <iostream>

#include "acm/acm.h" // TODO: Non-absolute path (included via CMake)

/// Temporary QOL vector printing
std::ostream& operator<<(std::ostream& os, std::vector<int> obj)
{
  return os << join(obj, ", ");
}

int main(int argc, char **argv)
{
  using ACM = ArithmeticalCongruenceMonoid;
  ACM a(1, 4);

  std::cout << a << '\n';
  std::cout << a.factorizations(144) << '\n';

  return 0;
}
