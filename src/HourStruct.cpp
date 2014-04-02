#include "HourStruct.h"

using namespace std;

void HourStruct::initMap()
{
    for(int i = 0; i < 24; i++)
    {
        // Initialise the map to have 24 pairs (0..23) initialised to 0.0
        hourMap.insert(pair<int,double>(i, 0.0));
    }
}

// Given the change in hours and the energy from the previous datapoint to
// the current one, update the map accordingly
void HourStruct::update(int deltaHour, double energy)
{
    if(deltaHour > 0)
    {
        hourMap.at(hourCounter) = JtokWh(hourEnergy);
        // If there is a gap in the measurements, this prevents
        // the gap from being ignored, ie, there will also be
        // an appropriate gap in the byhour.txt file
        hourCounter += deltaHour;
        hourEnergy = energy;
    }
    else if(deltaHour == 0)
    {
        hourEnergy += energy;
    }

}

// checks if the map has ever been updated (more than 0 hours have passed).
void HourStruct::finalUpdate(double totalEnergy)
{
    if(hourCounter == 0)
    {
        // hourCounter wasn't incremented, implying that there's only
        // 1 hour in the file. THerefore energy for this hour is just
        // totalEnergy
        hourMap.at(hourCounter) = JtokWh(totalEnergy);
    }
    else if(hourEnergy != 0) // maybe at(hourCounter) == 0
    {
        // If we're on the last datapoint but in the same hour, the last hour
        // in the map won't have its value set. Do it here
        hourMap.at(hourCounter) = JtokWh(hourEnergy);
    }
}

void HourStruct::writeHourFile()
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
