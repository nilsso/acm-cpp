#include <iostream>
#include <getopt.h>

#include "acm/acm.h" // TODO: Non-absolute path (included via CMake)

using ACM = ArithmeticalCongruenceMonoid;

/// Temporary QOL vector printing
std::ostream& operator<<(std::ostream& os, std::vector<int> obj)
{
  return os << join(obj, ", ");
}

int main(int argc, char **argv)
{
  int a, b;
  ACM *acm;

  for (char c; (c = getopt(argc, argv, "hHa:b:")) != -1;) {
    switch (c) {
      case 'h':
        std::cout << "Help!\n";
        return 0;

      case 'H':
        a = 1;
        b = 4;
        break;

      case 'a':
        a = std::stoi(optarg);
        break;

      case 'b':
        b = std::stoi(optarg);
        break;

      default:
        std::cout
          << "Error!\n";
        return 1;
    }
  }

  assert(a && b);
  acm = new ACM(a, b);

  int n = std::stoi(argv[optind]);
  std::cout << acm->factorizations(n) << '\n';
  return 0;
}
