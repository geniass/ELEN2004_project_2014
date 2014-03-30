/*
 * Ari Croock 718005
 * 30/03/2014
 *
 * DataPoint.cpp
 * A class representing one datapoint, consisting of the datapoint's date-time,
 * voltage, current, frequency and power. Also has some convenience functions
 * for dealing with DataPoint objects.
 */

#include "DataPoint.h"

using namespace std;

DataPoint::DataPoint()
{
    valid = true;
}

DataPoint::DataPoint(string dataString)
{

}

int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    double getSecond();
    double getVoltage();
    double getCurrent();
    double getFrequency();
    double getPower();


bool DataPoint::is_valid()
{
    return valid;
}
