#ifndef H_HOURSTRUCT
#define H_HOURSTRUCT

#include <map>
#include <fstream>
#include <iostream>
#include "Utils.h"

struct HourStruct
{
    double hourEnergy; // total energy for current hour
    int hourCounter; // current hour
    std::map<int, double> hourMap;

    void initMap();
    void update(int, double);
    void finalUpdate(double);
    void writeHourFile();

    HourStruct() : hourEnergy(0), hourCounter(0), hourMap() { initMap(); }
};

#endif
