// 718005
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
    EXPECT_FALSE(d.isValid());
}

TEST(DataPoint, StringCtor)
{
    string data = "2014 03 11 17 32 42.525674 231.503 0.016 50.062";
    DataPoint d(data);

    EXPECT_TRUE(d.isValid());
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
TEST(DataPoint, BoundryData)
{
    string data = "2014 12 31 23 59 59.99999 231.503 0.016 50.062";
    DataPoint d(data);

    EXPECT_TRUE(d.isValid());
    EXPECT_EQ(2014, d.getYear());
    EXPECT_EQ(12, d.getMonth());
    EXPECT_EQ(31, d.getDay());
    EXPECT_EQ(23, d.getHour());
    EXPECT_EQ(59, d.getMinute());
    EXPECT_DOUBLE_EQ(59.99999, d.getSecond());
    EXPECT_DOUBLE_EQ(231.503, d.getVoltage());
    EXPECT_DOUBLE_EQ(0.016, d.getCurrent());
    EXPECT_DOUBLE_EQ(50.062, d.getFrequency());
    EXPECT_DOUBLE_EQ(3.704048, d.getPower());
}

TEST(DataPoint, MoarBoundryData)
{
    string data = "2014 1 1 00 00 00.000001 231.503 0.016 0";
    DataPoint d(data);

    EXPECT_TRUE(d.isValid());
    EXPECT_EQ(2014, d.getYear());
    EXPECT_EQ(1, d.getMonth());
    EXPECT_EQ(1, d.getDay());
    EXPECT_EQ(0, d.getHour());
    EXPECT_EQ(0, d.getMinute());
    EXPECT_DOUBLE_EQ(0.000001, d.getSecond());
    EXPECT_DOUBLE_EQ(231.503, d.getVoltage());
    EXPECT_DOUBLE_EQ(0.016, d.getCurrent());
    EXPECT_DOUBLE_EQ(0, d.getFrequency());
    EXPECT_DOUBLE_EQ(3.704048, d.getPower());
}

TEST(DataPoint, InvalidData)
{
    string data = "-4 40 42 27 60 60.000001 -231.503 -0.016 -70 Hello";
    DataPoint d(data);

    EXPECT_FALSE(d.isValid());
}

TEST(DataPoint, Integrate)
{
    DataPoint d0("2014 12 31 23 58 59.0 100 1 50.062");
    DataPoint d1("2014 12 31 23 59 59.0 110 1 50.062");

    EXPECT_EQ(6300, DataPoint::integrate(d0, d1));
}

TEST(DataPoint, Integrate1)
{
    DataPoint d0("2014 12 31 22 58 59.0 100 1 50.062");
    DataPoint d1("2014 12 31 23 59 59.0 110 1 50.062");

    EXPECT_EQ(384300, DataPoint::integrate(d0, d1));
}

TEST(DataPoint, Integrate2)
{
    DataPoint d0("2014 12 31 23 59 59.0 100 1 50.062");
    DataPoint d1("2014 12 31 22 59 59.0 110 1 50.062");

    EXPECT_EQ(-378000, DataPoint::integrate(d0, d1));
}
