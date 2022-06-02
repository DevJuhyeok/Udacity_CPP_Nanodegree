#include "processor.h"
#include <string>
#include <vector>
#include "linux_parser.h"

using std::string;
using std::vector;

float Processor::Utilization() { 
    
    long total = LinuxParser::Jiffies();
    long active = LinuxParser::ActiveJiffies();

    return active * (1.f / total);
}