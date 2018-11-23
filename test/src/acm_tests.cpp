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

namespace HilbertACMTests {
  namespace DivisorTests {
    TEST(ACMTest, HilbertDivisors1) {
      test_divisors(HILBERT, 1, {1});
    }
    TEST(ACMTest, HilbertDivisors45) {
      test_divisors(HILBERT, 45, {1,5,9,45});
    }
    TEST(ACMTest, HilbertDivisors49) {
      test_divisors(HILBERT, 49, {1,49});
    }
    TEST(ACMTest, HilbertDivisors441) {
      test_divisors(HILBERT, 441, {1,9,21,49,441});
    }
    TEST(ACMTest, HilbertDivisors10594881) {
      test_divisors(HILBERT, 10594881, {
          1,9,81,33,297,121,1089,9801,69,621,253,2277,20493,8349,75141,141,1269,
          517,4653,41877,17061,153549,1081,9729,87561,35673,321057,130801,
          1177209,10594881});
    }
  }
  namespace FactorizationTests {
    TEST(ACMTest, HilbertFactorizations1) {
      test_factorizations(HILBERT, 1, {{}});
    }
    TEST(ACMTest, HilbertFactorizations45) {
      test_factorizations(HILBERT, 45, {{5,9}});
    }
    TEST(ACMTest, HilbertFactorizations49) {
      test_factorizations(HILBERT, 49, {{49}});
    }
    TEST(ACMTest, HilbertFactorizations441) {
      test_factorizations(HILBERT, 441, {{9,49}, {21,21}});
    }
    TEST(ACMTest, HilbertFactorizations10594881) {
      test_factorizations({1,4}, 10594881, {
          {9,33,141,253},{9,69,121,141},{33,33,69,141},{9,33,69,517},
          {9,9,253,517},{9,33,33,1081},{9,9,121,1081}});
    }
  }
  namespace IrreducibleTests {
    TEST(ACMTest, HilbertIrreducible1) {
      test_irreducible(HILBERT, 1, true);
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
    TEST(ACMTest, HilbertIrreducible10594881) {
      test_irreducible(HILBERT, 10594881, false);
    }
  }
}

namespace OtherACMTests {
  namespace DivisorTests {
    TEST(ACMTest, M36Divisor1) {
      test_divisors({3,6}, 1, {1});
    }
    TEST(ACMTest, M36Divisor45) {
      test_divisors({3,6}, 45, {1,3,15,45});
    }
    TEST(ACMTest, M36Divisor49) {
      test_divisors({3,6}, 49, {});
    }
    TEST(ACMTest, M36Divisor441) {
      test_divisors({3,6}, 441, {1,3,21,147,441});
    }
    TEST(ACMTest, M36Divisor10594881) {
      test_divisors({3,6}, 10594881, {
          1,3,9,27,33,69,99,141,207,297,363,423,621,759,1089,1269,1551,2277,
          3243,3267,4653,6831,8349,9729,13959,17061,25047,29187,35673,51183,
          75141,107019,153549,321057,392403,1177209,3531627,10594881});
    }
  }
  namespace FactorizationTests {
    TEST(ACMTest, M36Factorization1) {
      test_factorizations({3,6}, 1, {{}});
    }
    TEST(ACMTest, M36Factorizations45) {
      test_factorizations({3,6}, 45, {{3,15}});
    }
    TEST(ACMTest, M36Factorizations49) {
      test_factorizations({3,6}, 49, {});
    }
    TEST(ACMTest, M36Factorizations441) {
      test_factorizations({3,6}, 441, {{3,147},{21,21}});
    }
    TEST(ACMTest, M36Factorizations10594881) {
      test_factorizations({3,6}, 10594881, {
          {3,3,3,392403},{3,3,33,35673},{3,3,69,17061},{3,3,141,8349},
          {3,3,363,3243},{3,3,759,1551},{3,33,33,3243},{3,33,69,1551},
          {3,33,141,759},{3,69,141,363},{33,33,69,141}});
    }
  }
  namespace IrreducibleTests {
    TEST(ACMTest, M36Irreducible1) {
      test_irreducible({3,6}, 1, true);
    }
    TEST(ACMTest, M36Irreducible45) {
      test_irreducible({3,6}, 45, false);
    }
    TEST(ACMTest, M36Irreducible49) {
      test_irreducible({3,6}, 49, true);
    }
    TEST(ACMTest, M36Irreducible441) {
      test_irreducible({3,6}, 441, false);
    }
    TEST(ACMTest, M36Irreducible10594881) {
      test_irreducible({3,6}, 10594881, false);
    }
  }
}
