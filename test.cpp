#include "FINE.h"
#include "FINEd.h"
#include <cmath>
#include <gtest/gtest.h>

TEST(FINE_Tests, Exponentiation)
{
    float a = 14.0f;
    int n = 2;

    EXPECT_NEAR(Q_exp(a, n), pow(a, n), 2.000) << "FINE Q_exp failed.";
    EXPECT_NEAR(Q_exp_double(a, n), pow(a, n), 2.00) << "FINEd Q_exp_double failed.";
}

TEST(FINE_Tests, NthRoot)
{
    float a = 14.0f;
    int n = 2;

    EXPECT_NEAR(Q_nroot(a, n), pow(a, -1.0 / n), 0.005) << "FINE Q_nroot failed.";
    EXPECT_NEAR(Q_nroot_double(a, n), pow(a, -1.0 / n), 0.005) << "FINEd Q_nroot_double failed.";
    EXPECT_NEAR(Quake(a), pow(a, -0.5), 0.001) << "Quake approximation failed.";
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
