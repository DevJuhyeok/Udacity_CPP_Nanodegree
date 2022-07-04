#include "processor.h"
#include <string>
#include <vector>
#include "linux_parser.h"

using std::string;
using std::vector;

float Processor::Utilization() { 
    vector<string> values = LinuxParser::CpuUtilization();
    // Sum of active time units / sum of total time units
    return (float)(0.0);
}