#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <getopt.h>

#include "util.h"
#include "acm/acm.h"

using ACM = ArithmeticalCongruenceMonoid;

/// Temporary QOL printing functions
std::ostream& operator<<(std::ostream& os, std::vector<std::pair<int,int>> obj)
{
  std::stringstream ss;
  std::vector<std::string> strings;
  for (auto p: obj) {
    ss.str("");
    ss << '(' << p.first << ',' << p.second << ')';
    strings.push_back(ss.str());
  }
  return os << util::join(strings, ", ");
}

// -----------------------------------------------------------------------------
// acm-main Entry point
// -----------------------------------------------------------------------------
int main(int argc, char **argv)
{
  int a, b;

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

  assert(a && b && b > a);
  ACM acm{a, b};

  int n = std::stoi(argv[optind]);
  std::cout << acm.factorizations(n) << '\n';
  return 0;
}
