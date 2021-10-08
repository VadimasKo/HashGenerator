#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>

using namespace std;
using highResClock =   chrono::high_resolution_clock;
using timePoint =      chrono::time_point<highResClock>;
using durationDouble = chrono::duration<double>;
class Timer {
  private: 
    timePoint start;

  public:
    void startClock() {
      start = highResClock::now();
    }

    double calcDuration() {
      durationDouble duration = highResClock::now() - start;
      return duration.count();
    }
};

double runTests(string command, string fileString);
int callMd5(string line);


int main(int argc, char *argv[]) {
  string fileLoc = argc > 1 ? argv[1] : "./ControlledTestFiles/b.txt";

  stringstream fileStream;
  fstream file;
  file.open(fileLoc);
  fileStream<<file.rdbuf();
  file.close();
  string fileString = fileStream.str();

  double myDuration = runTests("./HashGenerator test ", fileString);
  double md5Duration = runTests("md5sum", fileString);
  system("clear");
  cout<<"Duration of mine hash generator "<<myDuration<<"\n";
  cout<<"Duration of md5 hash generator "<<md5Duration<<"\n"; 
}

double runTests(string command, string fileString) {
  stringstream fileStream(fileString);
  Timer timer;
  timer.startClock();
  string lineValue;
  while(!fileStream.eof()) {
    getline(fileStream, lineValue);
    lineValue.insert(lineValue.begin(),'\"');
    lineValue.push_back('\"');
    (command == "md5sum") ? callMd5(lineValue) : system((command + lineValue).c_str());
  }
  return timer.calcDuration();
}

int callMd5(string line) {
  system(("echo -n " +line + " | md5sum").c_str());
  return 1;
}