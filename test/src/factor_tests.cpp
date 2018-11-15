#include <vector>
#include <utility>
#include <iostream>
#include <util.h>
#include <gtest/gtest.h>

class FactorTest : public ::testing::Test {};

inline void verify(int n, std::vector<std::pair<int,int>> factors) {
  EXPECT_EQ(util::factor(n), factors) << "  where n is " << n;
}

// Primes

TEST_F(FactorTest, 2) {
  verify(2, {{2,1}});
}

TEST_F(FactorTest, 5) {
  verify(5, {{5,1}});
}

// Factorables

TEST_F(FactorTest, 4) {
  verify(4, {{2,2}});
}
