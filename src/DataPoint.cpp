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
    }
    else
    {
        cout << error_message << endl;
    }
}

void DataPoint::setYear(int y)
{
    validateGreaterThan(year, y, 0);
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
    }
}

void DataPoint::setHour(int h)
{
    if(h > 0 & h <= 24)
    {
        hour = h;
    }
    else
    {
        valid = false;
    }
}

void DataPoint::setMinute(int m)
{
    if(m > 0 & m <= 60)
    {
        minute = m;
    }
    else
    {
        valid = false;
    }
}

void DataPoint::setSecond(double s)
{
    if(s > 0 && islessequal(s, 60.0))
    {
        second = s;
    }
    else
    {
        valid = false;
    }
}

void DataPoint::setVoltage(double v)
{
    if(v > 0)
    {
        voltage = v;
    }
    else
    {
        valid = false;
    }
}

void DataPoint::setCurrent(double c)
{
    if(c > 0)
    {
        current = c;
    }
    else
    {
        valid = false;
    }
}

void DataPoint::setFrequency(double f)
{
    if(f > 0)
    {
        frequency = f;
    }
    else
    {
        valid = false;
    }
}

// check that variable > val and set member = variable if true
bool DataPoint::validateGreaterThan(int& member, int variable, int val)
{
    if(variable > val)
    {
        member = variable;
    }
    else
    {
        member = 0;
        valid = false;
    }

    return valid;
}

// check that variable > val and set member = variable if true
bool DataPoint::validateLessThan(int& member, int variable, int val)
{
    if(variable < val)
    {
        member = variable;
    }
    else
    {
        member = 0;
        valid = false;
    }

    return valid;
}

int DataPoint::compareDoubles(double d1, double d2)
{
    double diff = d2 - d1;
    if (d1 == d2 || abs(diff) < EPSILON)
    {
        // Doubles are equal, or close enough
        return 0;
    }

    if(diff < 0)
    {
        return 1;
    }

    // less than
    return -1;
}
