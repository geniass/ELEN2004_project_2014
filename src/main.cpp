// 718005
/*
 * Ari Croock 718005
 * 30/03/2014
 *
 * main.cpp
 * The main method of the project along with other supporting methods.
 * Contains the logic for reading in the data files, processing lines using
 * DataPoint objects and writing the output to files.
 */

#include <iostream>
#include <fstream>
#include <map>
#include "DataPoint.h"

using namespace std;

void initialiseHourMap(map<int, double>&);
void writeStatsFile(double, double, double);
void writeHourFile(const map<int, double>&);

int main()
{
    ifstream dataFile("data.txt");
    string line;

    int lineCount = 0;
    double totalPower = 0.0;
    double maxPower = 0.0;
    double totalEnergy = 0.0;

    double hourEnergy = 0.0; // total energy for current hour
    int hourCounter = 0; // current hour
    map<int, double> hourMap;
    initialiseHourMap(hourMap);

    DataPoint previousDataPoint;

    if(dataFile.is_open())
    {
        while (getline(dataFile, line))
        {
            DataPoint currentDataPoint(line);
            if(currentDataPoint.isValid())
            {
                lineCount++;
                totalPower += currentDataPoint.getPower();

                if(currentDataPoint.getPower() > maxPower)
                {
                    maxPower = currentDataPoint.getPower();
                }

                if(lineCount > 0 && previousDataPoint.isValid())
                {
                    double energy = DataPoint::integrate(previousDataPoint, currentDataPoint);
                    totalEnergy += energy;

                    int deltaHour = DataPoint::compareHours(currentDataPoint, previousDataPoint);
                    if(deltaHour > 0)
                    {
                        hourMap.at(hourCounter) = hourEnergy;
                        hourCounter++;
                        hourEnergy = energy;
                    }
                    else if(deltaHour == 0)
                    {
                        hourEnergy += energy;
                    }
                }

                // if we're on the first line, skip the integration (since it
                // requires 2 datapoints) and move to the next line
                previousDataPoint = currentDataPoint;
            }
            else
            {
                // ignore current invalid datapoint
                // The datapoint constructor has already printed errors
                continue;
            }
        }

        if(hourCounter == 0)
        {
            // hourCounter wasn't incremented, implying that there's only
            // 1 hour in the file. THerefore energy for this hour is just
            // totalEnergy
            hourMap.at(hourCounter) = totalEnergy;
        }

        cout << "Lines: " << lineCount << endl << "Power: " << totalPower << endl << "Max: " << maxPower << endl << "energie: " << totalEnergy << endl;
        cout << hourMap.at(1) << endl;

        writeStatsFile(totalEnergy / (3.6e6),            // 1 kWh = 3.6MJ
                       totalPower / lineCount,           // compute the average
                       maxPower);
        writeHourFile(hourMap);
    }
    else
    {
        cerr << "ERROR: Can't open file data.txt" << endl;
        return 1;
    }

    dataFile.close();

    return 0;
}

void initialiseHourMap(map<int, double>& hourMap)
{
    for(int i = 0; i < 24; i++)
    {
        // Initialise the map to have 24 pairs (0..23) initialised to 0.0
        hourMap.insert(pair<int,double>(i, 0.0));
    }
}

void writeStatsFile(double kWh, double meanPower, double maxPower)
{
    ofstream statsFile("stats.txt");
    if(statsFile.is_open())
    {
        statsFile << kWh << endl;
        statsFile << meanPower << endl;
        statsFile << maxPower << endl;
    }
    else
    {
        cerr << "ERROR: Could not open stats.txt" << endl;
    }
    statsFile.close();
}

void writeHourFile(const map<int,double>& hourMap)
{
    ofstream hourFile("byhour.txt");
    if(hourFile.is_open())
    {
        for(map<int,double>::const_iterator i = hourMap.begin(); i != hourMap.end(); i++)
        {
            hourFile << i->first << " " << i->second << endl;
        }
    }
    else
    {
        cerr << "ERROR: Could not open byhour.txt" << endl;
    }
    hourFile.close();
}
