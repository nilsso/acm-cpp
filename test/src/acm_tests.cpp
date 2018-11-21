#include <utility>
#include <set>
#include <vector>

#include <acm.h>
#include "gtest/gtest.h"

using std::pair;
using std::set;
using std::vector;

using ACM = ArithmeticalCongruenceMonoid;

constexpr pair<int,int> HILBERT = {1,4};

class ACMTest : public ::testing::Test {};

inline void
test_divisors(pair<int,int> ab, int n, set<int> ds)
{
  EXPECT_EQ(ACM{ab}.divisors(n), ds)
    << "  where n is " << n;
}

inline void
test_factorizations(pair<int,int> ab, int n, set<vector<int>> fsr)
{
  EXPECT_EQ(ACM{ab}.factorizations(n), fsr)
    << "  where n is " << n;
}

inline void
test_irreducible(pair<int,int> ab, int n, bool irreducible)
{
  EXPECT_EQ(ACM{ab}.irreducible(n), irreducible)
    << "  where n is " << n;
}

namespace DivisorTests {
  int i = 0;
  TEST(ACMTest, HilbertDivisors1) {
    test_divisors(HILBERT, 1, {1});
  }
  TEST(ACMTest, HilbertDivisors2) {
    test_divisors(HILBERT, 2, {1});
  }
  TEST(ACMTest, HilbertDivisors5) {
    test_divisors(HILBERT, 5, {1, 5});
  }
  TEST(ACMTest, HilbertDivisors10) {
    test_divisors(HILBERT, 10, {1, 5});
  }
  TEST(ACMTest, HilbertDivisors15) {
    test_divisors(HILBERT, 15, {1, 5});
  }
  TEST(ACMTest, HilbertDivisors25) {
    test_divisors(HILBERT, 25, {1, 5, 25});
  }
  TEST(ACMTest, HilbertDivisors45) {
    test_divisors(HILBERT, 45, {1, 5, 9, 45});
  }
  TEST(ACMTest, HilbertDivisors49) {
    test_divisors(HILBERT, 49, {1, 49});
  }
  TEST(ACMTest, HilbertDivisors441) {
    test_divisors(HILBERT, 441, {1, 9, 21, 49, 441});
  }
  TEST(ACMTest, HilbertDivisors449) {
    test_divisors(HILBERT, 449, {1, 449});
  }
}

namespace FactorizationTests {
  TEST(ACMTest, HilbertFactorizations1) {
    test_factorizations(HILBERT, 1, {});
  }
  TEST(ACMTest, HilbertFactorizations2) {
    test_factorizations(HILBERT, 2, {});
  }
  TEST(ACMTest, HilbertFactorizations5) {
    test_factorizations(HILBERT, 5, {{5}});
  }
  TEST(ACMTest, HilbertFactorizations10) {
    test_factorizations(HILBERT, 10, {});
  }
  TEST(ACMTest, HilbertFactorizations15) {
    test_factorizations(HILBERT, 15, {});
  }
  TEST(ACMTest, HilbertFactorizations25) {
    test_factorizations(HILBERT, 25, {{5, 5}});
  }
  TEST(ACMTest, HilbertFactorizations45) {
    test_factorizations(HILBERT, 45, {{5, 9}});
  }
  TEST(ACMTest, HilbertFactorizations49) {
    test_factorizations(HILBERT, 49, {{49}});
  }
  TEST(ACMTest, HilbertFactorizations441) {
    test_factorizations(HILBERT, 441, {{9, 49}, {21, 21}});
  }
  TEST(ACMTest, HilbertFactorizations449) {
    test_factorizations(HILBERT, 449, {{449}});
  }
  TEST(ACMTest, HilbertFactorizations117645) {
    test_factorizations(HILBERT, 117645, {{5, 33, 713}, {5, 69, 341}, {5, 93, 253}});
  }
  TEST(ACMTest, HilbertFactorizations5764797) {
    test_factorizations(HILBERT, 5764797, {{9, 89, 7197}});
  }
  TEST(ACMTest, HilbertFactorizations10594881) {
    test_factorizations({1, 4}, 10594881, {{9, 33, 141, 253}, {9, 69, 121, 141}, {33, 33, 69, 141}, {9, 33, 69, 517}, {9, 9, 253, 517}, {9, 33, 33, 1081}, {9, 9, 121, 1081}});
  }
}

namespace IrreducibleTests {
  int i = 0;
  TEST(ACMTest, HilbertIrreducible1) {
    test_irreducible(HILBERT, 1, true);
  }
  TEST(ACMTest, HilbertIrreducible2) {
    test_irreducible(HILBERT, 2, true);
  }
  TEST(ACMTest, HilbertIrreducible5) {
    test_irreducible(HILBERT, 5, true);
  }
  TEST(ACMTest, HilbertIrreducible10) {
    test_irreducible(HILBERT, 10, true);
  }
  TEST(ACMTest, HilbertIrreducible15) {
    test_irreducible(HILBERT, 15, true);
  }
  TEST(ACMTest, HilbertIrreducible25) {
    test_irreducible(HILBERT, 25, false);
  }
  TEST(ACMTest, HilbertIrreducible45) {
    test_irreducible(HILBERT, 45, false);
  }
  TEST(ACMTest, HilbertIrreducible49) {
    test_irreducible(HILBERT, 49, true);
  }
  TEST(ACMTest, HilbertIrreducible441) {
    test_irreducible(HILBERT, 441, false);
  }
  TEST(ACMTest, HilbertIrreducible449) {
    test_irreducible(HILBERT, 449, true);
  }
  TEST(ACMTest, HilbertIrreducible117645) {
    test_irreducible(HILBERT, 117645, false);
  }
  TEST(ACMTest, HilbertIrreducible5764797) {
    test_irreducible(HILBERT, 5764797, false);
  }
  TEST(ACMTest, HilbertIrreducible10594881) {
    test_irreducible(HILBERT, 10594881, false);
  }
}
