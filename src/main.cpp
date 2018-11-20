#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <getopt.h>

#include "acm/acm.h"
#include "util.h"

#include "divisors.h"

using std::string;
using std::vector;
using std::pair;
using std::cout;

using ACM = ArithmeticalCongruenceMonoid;

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

  int n = std::stoi(argv[optind]);

  cout
    << "n=" << n << '\n'
    << "divisors=" << divisors(n) << '\n'
    << "pfactor=" << pfactor(n) << '\n'
    ;

  ACM acm{a, b};
  auto divisors = acm.divisors(n);
  auto factorizations = acm.factorizations(n);

  cout
    << "acm=" << acm << '\n'
    << "acm.divisors=" << divisors << '\n'
    << "acm.factorizations=" << factorizations << '\n'
    ;

  pair<int,int> ab{a,b};
  ACM{a,b}.divisors(1);
  ACM{ab}.divisors(1);

  cout << "next elements: " << acm.elements(n, 3) << '\n';

  return 0;
}
