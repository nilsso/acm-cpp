#include <iostream>

#include "acm/acm.h" // TODO: Non-absolute path (included via CMake)

using ACM = ArithmeticalCongruenceMonoid;

/// Temporary QOL vector printing
std::ostream& operator<<(std::ostream& os, std::vector<int> obj)
{
  return os << join(obj, ", ");
}

int main(int argc, char **argv)
{
  ACM hilbert(1, 4);

  std::cout << hilbert << '\n';
  std::cout << hilbert.factorizations(144) << '\n';

  return 0;
}
