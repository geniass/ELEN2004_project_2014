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
#include "DataPoint.h"
#include "HourStruct.h"
#include "Utils.h"

using namespace std;

const double MAX_TIME_GAP_SECONDS = 5; // max gap between 2 datapoints

void writeStatsFile(double, double, double);

int main()
{
    ifstream dataFile("data.txt");
    string line;

    int lineCount = 0;
    double totalPower = 0.0;
    double maxPower = 0.0;
    double totalEnergy = 0.0;

    HourStruct hourStruct;

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
                    double energy = 0;

                    // If the gap between the previous and current datapoints
                    // is too large, don't integrate between them.
                    if(DataPoint::timeDifference(currentDataPoint, previousDataPoint) < MAX_TIME_GAP_SECONDS)
                    {
                        energy = DataPoint::integrate(previousDataPoint, currentDataPoint);
                        totalEnergy += energy;
                    }

                    int deltaHour = DataPoint::compareHours(currentDataPoint, previousDataPoint);
                    hourStruct.update(deltaHour, energy);
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

        hourStruct.finalUpdate(totalEnergy);

        cout << "Lines: " << lineCount << endl
            << "Power (W): " << totalPower << endl
            << "Max power(W): " << maxPower << endl
            << "energy (J): " << totalEnergy << endl;

        writeStatsFile(JtokWh(totalEnergy),            // 1 kWh = 3.6MJ
                       average(totalPower, lineCount),           // compute the average
                       maxPower);
        hourStruct.writeHourFile();
    }
    else
    {
        cerr << "ERROR: Can't open file data.txt" << endl;
        return 1;
    }

    dataFile.close();

    return 0;
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
