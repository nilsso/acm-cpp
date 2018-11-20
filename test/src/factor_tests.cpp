#include <vector>
#include <utility>

#include <gtest/gtest.h>
#include <util.h>
#include <pfactor.h>

using std::vector;
using std::pair;

class FactorTest : public::testing::Test {};

inline void test_pfactor(int n, vector<pair<int,int>> pfactors)
{
  EXPECT_EQ(pfactor(n), pfactors) << "  where n is " << n;
}

// Primes
TEST_F(FactorTest, PFactors_2) {
  test_pfactor(2, { {2,1} });
}
TEST_F(FactorTest, PFactors_5) {
  test_pfactor(5, { {5,1} });
}

// Factorables
TEST_F(FactorTest, PFactors_4) {
  test_pfactor(4, { {2,2} });
}
TEST_F(FactorTest, PFactors_12) {
  test_pfactor(12, { {2,2}, {3,1} });
}
TEST_F(FactorTest, PFactors_60) {
  test_pfactor(60, { {2,2}, {3,1}, {5, 1} });
}
TEST_F(FactorTest, PFactors_420) {
  test_pfactor(420, { {2,2}, {3,1}, {5, 1}, {7, 1} } );
}

