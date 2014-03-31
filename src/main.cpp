#include <iostream>
#include "DataPoint.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream dataFile("data.txt");
    string line;

    int lineCount = 0;
    double totalPower = 0.0;
    double maxPower = 0.0;
    double totalEnergy = 0.0;

    DataPoint previousDataPoint;

    if(dataFile.is_open())
    {
        while (getline(dataFile, line))
        {
            DataPoint currentDataPoint(line);
            if(currentDataPoint.is_valid())
            {
                lineCount++;
                totalPower += currentDataPoint.getPower();

                if(lineCount > 0 && previousDataPoint.is_valid())
                {
                    cout << "previous: " << previousDataPoint.getPower() << endl;
                    cout << "Current: " << currentDataPoint.getPower() << endl;
                    //TODO: Integrate and whatnot
                }

                // if we're on the first line, skip the integration (since it
                // requires 2 datapoints) and move to the next line
                previousDataPoint = currentDataPoint;
            }
            else
            {
                // ignore current datapoint
                // The datapoint constructor has already printed errors
                continue;
            }
        }
    }
    else
    {
        cerr << "ERROR: Can't open file data.txt" << endl;
        return 1;
    }

    return 0;
}
