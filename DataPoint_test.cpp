/*
 * Ari Croock 718005
 * 30/03/2014
 *
 * DataPoint_test.cpp
 * GTest Unit test for the DataPoint class
 */

#include "DataPoint.h"
#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST(DataPoint, DefaultCTor)
{
    DataPoint d;
    EXPECT_FALSE(d.is_valid());
}

TEST(DataPoint, StringCtor)
{
    string data = "2014 03 11 17 32 42.525674 231.503 0.016 50.062";
    DataPoint d(data);

    EXPECT_TRUE(d.is_valid());
    EXPECT_EQ(2014, d.getYear());
    EXPECT_EQ(3, d.getMonth());
    EXPECT_EQ(11, d.getDay());
    EXPECT_EQ(17, d.getHour());
    EXPECT_EQ(32, d.getMinute());
    EXPECT_DOUBLE_EQ(42.525674, d.getSecond());
    EXPECT_DOUBLE_EQ(231.503, d.getVoltage());
    EXPECT_DOUBLE_EQ(0.016, d.getCurrent());
    EXPECT_DOUBLE_EQ(50.062, d.getFrequency());
}
