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

const double DataPoint::EPSILON = 0.0000001;

DataPoint::DataPoint()
{
    valid = false;
}

// This constructor takes a space-delimited string of 9 columns
DataPoint::DataPoint(string dataString)
{
    valid = true;

    string error_message = "ERROR: Data string must have exactly 9 space-delimited columns.";
    vector<string> columns(9); // we expect 9 columns of data
    istringstream iss(dataString);

    string token;
    int column_count = 0;
    while(iss >> token )
    {
        if(column_count < 9)
        {
            columns.at(column_count) = token;;
            column_count++;
        }
        else
        {
            // stop parsing the string, we knows it's invalid
            cerr << error_message << endl;
            valid = false;
            break;
        }
    }

    // if the vector size is already 9 at this point, there are more than
    // 9 columns
    if(column_count == 9)
    {
        // data string has 9 colummns
        setYear(stoi(columns.at(0)));
        setMonth(stoi(columns.at(1)));
        setDay(stoi(columns.at(2)));
        setHour(stoi(columns.at(3)));
        setMinute(stoi(columns.at(4)));
        setSecond(stod(columns.at(5)));
        setVoltage(stod(columns.at(6)));
        setCurrent(stod(columns.at(7)));
        setFrequency(stod(columns.at(8)));
        calculatePower();
    }
    else if(column_count != 9)
    {
        cout << error_message << endl;
    }
    if(!valid)
    {
        cerr << "Invalid Data: " << dataString << endl << endl;
    }
}

// Integrates between dp0 and dp1 using the trapezoidal integration rule.
double DataPoint::integrate(const DataPoint& dp0, const DataPoint& dp1)
{
    if(dp0.isValid() && dp1.isValid())
    {
        // t0's and t1's difference in hours, minutes and seconds is
        // calculated, then converted to seconds and finally added. This
        // potentially avoids the unecessary multiplication of huge numbers.
        // Only hours,minutes and seconds are considered because we assume that
        // there is never more than 24 hours in one data file. This could be
        // extended to consider years etc as well to be further decoupled from main
        double deltaT = compareHours(dp1, dp0) * 3600;
        deltaT += compareMinutes(dp1, dp0) * 60;
        deltaT += compareSeconds(dp1, dp0);

        // And plug it into the trapezoidal rule:
        // E = 0.5 * (t1 - t2) * (P(t1) + P(t2))
        return 0.5 * deltaT * (dp0.getPower() + dp1.getPower());
    }

    //TODO: Throw an exception
    return 0;
}

int DataPoint::compareHours(const DataPoint& dp0, const DataPoint& dp1)
{
    return dp0.getHour() - dp1.getHour();
}

int DataPoint::compareMinutes(const DataPoint& dp0, const DataPoint& dp1)
{
    return dp0.getMinute() - dp1.getMinute();
}

double DataPoint::compareSeconds(const DataPoint& dp0, const DataPoint& dp1)
{
    return dp0.getSecond() - dp1.getSecond();
}

void DataPoint::setYear(int y)
{
    if(y > 0)
    {
        year = y;
    }
    else
    {
        valid = false;
        cerr << "ERROR: Year must be greater than 0" << endl;
    }
}

void DataPoint::setMonth(int m)
{
    if(m > 0 & m <= 12)
    {
        month = m;
    }
    else
    {
        valid = false;
        cerr << "ERROR: Month must be between 1 and 12" << endl;
    }
}

void DataPoint::setDay(int d)
{
    if(d > 0 & d <= 31)
    {
        day = d;
    }
    else
    {
        valid = false;
        cerr << "ERROR: Day must be between 1 and 31" << endl;
    }
}

void DataPoint::setHour(int h)
{
    if(h >= 0 & h <= 23)
    {
        hour = h;
    }
    else
    {
        valid = false;
        cerr << "ERROR: Hour must be between 0 and 23" << endl;
    }
}

void DataPoint::setMinute(int m)
{
    if(m >= 0 & m <= 59)
    {
        minute = m;
    }
    else
    {
        valid = false;
        cerr << "ERROR: Minute must be between 0 and 59" << endl;
    }
}

void DataPoint::setSecond(double s)
{
    if(s >= 0 && isless(s, 60.0))
    {
        second = s;
    }
    else
    {
        valid = false;
        cerr << "ERROR: Second must be between 0 and less than 60" << endl;
    }
}

void DataPoint::setVoltage(double v)
{
    if(v >= 0)
    {
        voltage = v;
    }
    else
    {
        valid = false;
        cerr << "ERROR: Voltage must be positive." << endl;
    }
}

void DataPoint::setCurrent(double c)
{
    if(c >= 0)
    {
        current = c;
    }
    else
    {
        valid = false;
        cerr << "ERROR: Current must be positive." << endl;
    }
}

void DataPoint::setFrequency(double f)
{
    // freq=0 would be DC
    if(f >= 0)
    {
        frequency = f;
    }
    else
    {
        valid = false;
        cerr << "ERROR: Frequency must be positive." << endl;
    }
}

double DataPoint::calculatePower()
{
    if(valid)
    {
        power = voltage * current;
    }
    else
    {
        cerr << "ERROR: This DataPoint instance is invalid. Please initialise it with valid data" << endl;
    }
    return power;
}
