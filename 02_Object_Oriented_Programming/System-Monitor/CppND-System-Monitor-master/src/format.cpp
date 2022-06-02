#include <string>

#include "format.h"

using std::string;

string Format::ElapsedTime(long seconds) { 
    string time = "00:00:00";
    int hours = 0;
    int minutes = 0;
    int sec = 0;
    if(seconds > 0)
    {
        hours = seconds / 3600;
        minutes = (seconds % 3600) / 60;
        sec = (seconds % 3600) % 60;

        time = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(sec);
    }
    return time; 
}