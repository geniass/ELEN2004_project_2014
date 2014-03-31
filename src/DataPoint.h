/*
 * Ari Croock 718005
 * 30/03/2014
 *
 * DataPoint.h
 * A class representing one datapoint, consisting of the datapoint's date-time,
 * voltage, current, frequency and power. Also has some convinience functions
 * for dealing with DataPoint objects.
 */

#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <string>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

class DataPoint
{
public:
    // creates an empty DataPoint. is_valid() will return true
    DataPoint();
    // attempts to parse a space-delimited string of data of the form:
    // (YYYY MM DD HH MM Seconds Volts Current Frequency)
    // NOTE: if the input string is invalid, is_valid() will return false and
    // this class's behaviour will be undefined.
    DataPoint(std::string);

    // Takes 2 valid DataPoints and integrates their power with respect to time
    static double integrate(const DataPoint&, const DataPoint&);

    // The time difference of the supplied Datapoint objects. Positive if the
    // first time is greater than the second, and vice-versa. 0 if they are
    // equal
    static int compareYears(const DataPoint, const DataPoint);
    static int compareMonths(const DataPoint, const DataPoint);
    static int compareDays(const DataPoint, const DataPoint);
    static int compareHours(const DataPoint, const DataPoint);
    static int compareMinutes(const DataPoint, const DataPoint);
    static double compareSeconds(const DataPoint, const DataPoint);

    // Returns 1 if the first Datapoint occurs before the second, -1 if the
    // second occurs before the first. 0 if they are equal
    static int compareDateTime(const DataPoint, const DataPoint);

    int getYear() { return year; };
    int getMonth() { return month; };
    int getDay() { return day; };
    int getHour() { return hour; };
    int getMinute() { return minute; };
    double getSecond() { return second; };
    double getVoltage() { return voltage; };
    double getCurrent() { return current; };
    double getFrequency() { return frequency; };
    double getPower() { return power; };
    bool is_valid() { return valid; };

private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    double second;
    double voltage;
    double current;
    double frequency;
    double power;
    bool valid;

    static const double EPSILON;

    // calculates and sets power from voltage and current. These must be set
    // before calling this method.
    double calculatePower();

    // setters that perform error-checking
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    void setHour(int);
    void setMinute(int);
    void setSecond(double);
    void setVoltage(double);
    void setCurrent(double);
    void setFrequency(double);

    // checks that int1 > int2. If true, sets int& = int1. Else sets 
    // valid = false and int& = 0
    bool validateGreaterThan(int&, int, int);
    bool validateLessThan(int&, int, int);

public:
    // Returns 1 if double1 > double2 and vice-versa. 0 if they are equal
    int compareDoubles(double, double);
};

#endif
