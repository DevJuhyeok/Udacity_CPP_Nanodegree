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

Process::Process(int pid) : pid_(pid) {}

int Process::Pid() { return pid_; }

float Process::CpuUtilization() { 
  string line;
  string value;
  vector<string> values;
  std::ifstream stream(LinuxParser::kProcDirectory + std::to_string(pid_) + LinuxParser::kStatFilename);
  if(stream.is_open()){
    std::getline(stream, line);
    std::istringstream linestream(line);
    while(linestream >> value){
      values.push_back(value);
    }
  }
  long int uptime = LinuxParser::UpTime();
  long int utime = stol(values[13]);
  long int stime = stol(values[14]);
  long int cutime = stol(values[15]);
  long int cstime = stol(values[16]);
  long int starttime = stol(values[21]);
  
  long int totaltime = utime + stime + cutime + cstime;
  long int seconds = uptime - (starttime / sysconf(_SC_CLK_TCK));

  stream.close();
  return ((totaltime / sysconf(_SC_CLK_TCK) / seconds));
}

string Process::Command() { return LinuxParser::Command(Pid()).append("..."); }

string Process::Ram() { return LinuxParser::Ram(Pid()); }

string Process::User() { return LinuxParser::User(Pid()); }

long int Process::UpTime() { return (long int)(LinuxParser::UpTime() - LinuxParser::UpTime(Pid())); }

//bool Process::operator<(Process const& a) const { return true; }