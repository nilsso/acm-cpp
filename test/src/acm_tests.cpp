#include <utility>
#include <set>
#include <vector>

#include <acm.h>
#include "gtest/gtest.h"

using std::pair;
using std::set;
using std::vector;

using ACM = ArithmeticalCongruenceMonoid;

class ACMTest : public ::testing::Test {};

inline void test_divisors(pair<int,int> ab, int n, set<int> ds)
{
  EXPECT_EQ(ACM{ab}.divisors(n), ds) << "  where n is " << n;
}

inline void test_factorizations(pair<int,int> ab, int n, vector<vector<int>> fs)
{
  EXPECT_EQ(ACM{ab}.factorizations(n), fs) << "  where n is " << n;
}

// Divisor tests

TEST(ACMTest, HilbertDivisors1) {
  test_divisors({1,4}, 1, {1});
}
TEST(ACMTest, HilbertDivisors2) {
  test_divisors({1,4}, 2, {1});
}
TEST(ACMTest, HilbertDivisors5) {
  test_divisors({1,4}, 5, {1, 5});
}
TEST(ACMTest, HilbertDivisors10) {
  test_divisors({1,4}, 10, {1, 5});
}
TEST(ACMTest, HilbertDivisors15) {
  test_divisors({1,4}, 15, {1, 5});
}
TEST(ACMTest, HilbertDivisors25) {
  test_divisors({1,4}, 25, {1, 5, 25});
}
TEST(ACMTest, HilbertDivisors45) {
  test_divisors({1,4}, 45, {1, 5, 9, 45});
}
TEST(ACMTest, HilbertDivisors441) {
  test_divisors({1,4}, 441, {1, 9, 21, 49, 441});
}

// Factorization tests

TEST(ACMTest, HilbertFactorizations1) {
  test_factorizations({1,4}, 1, {});
}
TEST(ACMTest, HilbertFactorizations2) {
  test_factorizations({1,4}, 2, {});
}
TEST(ACMTest, HilbertFactorizations5) {
  test_factorizations({1,4}, 5, {{5}});
}
TEST(ACMTest, HilbertFactorizations10) {
  test_factorizations({1,4}, 10, {});
}
TEST(ACMTest, HilbertFactorizations15) {
  test_factorizations({1,4}, 15, {});
}
TEST(ACMTest, HilbertFactorizations25) {
  test_factorizations({1,4}, 25, {{5, 5}});
}
TEST(ACMTest, HilbertFactorizations45) {
  test_factorizations({1,4}, 45, {{5, 9}});
}
TEST(ACMTest, HilbertFactorizations441) {
  test_factorizations({1,4}, 441, {{9, 49}, {21, 21}});
}
TEST(ACMTest, HilbertFactorizations117645) {
  test_factorizations({1,4}, 117645, {{5, 33, 713}, {5, 69, 341}, {5, 93, 253}});
}
TEST(ACMTest, HilbertFactorizations5764797) {
  test_factorizations({1,4}, 5764797, {{9, 89, 7197}});
}
