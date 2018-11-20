#include <set>

#include <gtest/gtest.h>
#include <util.h>
#include <divisors.h>

using std::set;

class DivisorsTest : public::testing::Test {};

inline void test_divisors(int n, set<int> ids)
{
  EXPECT_EQ(divisors(n), ids) << "  where n is " << n;
}

// Primes
TEST(DivisorsTest, IntegerDivisors2) {
  test_divisors(2, {1, 2});
}
TEST(DivisorsTest, IntegerDivisors5) {
  test_divisors(5, {1, 5});
}

// Factorables
TEST(DivisorsTest, IntegerDivisors4) {
  test_divisors(4, {1, 2, 4});
}
TEST(DivisorsTest, IntegerDivisors12) {
  test_divisors(12, {1, 2, 3, 4, 6, 12});
}
TEST(DivisorsTest, IntegerDivisors60) {
  test_divisors(60, {1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60});
}
TEST(DivisorsTest, IntegerDivisors420) {
  test_divisors(420,
      {1, 2, 3, 4, 5, 6, 7, 10, 12, 14, 15, 20, 21,
      28, 30, 35, 42, 60, 70, 84, 105, 140, 210, 420});
}

