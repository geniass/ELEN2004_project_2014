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

class DataPoint
{
public:
    // creates an empty DataPoint. is_valid() will return true
    DataPoint();
    // attempts to parse a space-delimited string of data of the form:
    // (YYYY MM DD HH MM Seconds Volts Current Frequency)
    DataPoint(std::string);

    // calculates and sets power from voltage and current. These must be set
    // before calling this method.
    double calculatePower();

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
    bool is_valid();

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
};

#endif
