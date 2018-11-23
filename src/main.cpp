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

//*  ---------------------------------------------------------------------------
// ACM test program
//
// Mandatory arguments:
//   -H : Hilbert ACM
//   -a : a component of ACM (required if not -H)
//   -b : b component of ACM (required if not -H)
//
// Optional arguments:
//   -A : All ACM functions of argument n
//   -d : ACM divisors of argument n
//   -f : ACM factorizations of argument n
//   -i : ACM irreducibility of argument n
//   -n : ACM irreducible elements up to argument n
// -----------------------------------------------------------------------------
int main(int argc, char **argv)
{
  ACM acm{3,6};
  cout << acm.factorizations(999) << '\n';

/*
 *  int a, b, n, s;
 *  char o;
 *
 *  for (char c; (c = getopt(argc, argv, "hHa:b:Adfinl")) != -1;) {
 *    switch (c) {
 *      case 'h':
 *        std::cout << "Help!\n";
 *        return 0;
 *
 *      case 'H':
 *        a = 1;
 *        b = 4;
 *        break;
 *
 *      case 'a':
 *        a = std::stoi(optarg);
 *        break;
 *
 *      case 'b':
 *        b = std::stoi(optarg);
 *        break;
 *
 *      case 'A':
 *      case 'd':
 *      case 'f':
 *      case 'i':
 *      case 'n':
 *      case 'l':
 *        o = c;
 *        break;
 *
 *      default:
 *        std::cout
 *          << "Error!\n";
 *        return 1;
 *    }
 *  }
 *
 *  n = std::stoi(argv[optind]);
 *
 *  if (!((bool)a && (bool)b)) {
 *    std::cout
 *      << "Error!\n";
 *    return 1;
 *  }
 *
 *  ACM acm{a, b};
 *
 *  cout << "acm=" << acm << " n=" << n << '\n';
 *
 *  switch (o) {
 *    case 'A':
 *      cout
 *        << acm.divisors(n) << '\n'
 *        //<< acm.factorizations(n) << '\n'
 *        << acm.irreducible(n) << '\n'
 *        << acm.irreducibles_up_to(n) << '\n';
 *      break;
 *    case 'd':
 *      cout << acm.divisors(n) << '\n';
 *      break;
 *    case 'f':
 *      cout << acm.factorizations(n) << '\n';
 *      break;
 *    case 'i':
 *      cout << acm.irreducible(n) << '\n';
 *      break;
 *    case 'n':
 *      cout << acm.irreducibles_up_to(n) << '\n';
 *      break;
 *    case 'l':
 *      cout << acm.atomic_density_list(n) << '\n';
 *  }
 */
  return 0;
}
