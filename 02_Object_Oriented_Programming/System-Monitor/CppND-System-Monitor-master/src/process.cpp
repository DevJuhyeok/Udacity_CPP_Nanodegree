#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid){
    pid_ = pid;
}

int Process::Pid() { return pid_; }

float Process::CpuUtilization() { 
    float act_time = float(LinuxParser::ActiveJiffies(Pid()))/100.f;
    float up_time = float(LinuxParser::UpTime(Pid()));
    float cpu_util = act_time / up_time;
    return cpu_util; 
}

string Process::Command() { return LinuxParser::Command(Pid()); }

string Process::Ram() { return LinuxParser::Ram(Pid()); }

string Process::User() { return LinuxParser::User(Pid()); }

long int Process::UpTime() { return LinuxParser::UpTime(Pid()); }