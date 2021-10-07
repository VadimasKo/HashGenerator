#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

string pipeCommand(string command);
vector<string> getPairs(string filePath);

int main() {
  string command = "./HashGenerator.exe ./RandomTestFiles/10.txt";
  string buffer = pipeCommand(command);
  cout<<buffer.length()<<buffer;
  getPairs("./RandomTestFiles/10.txt");
  return 0;
}


vector<string> getPairs(string filePath) {
  vector<string> pairs;
  stringstream fileStream;
  ifstream file;
  file.open(filePath);
  fileStream<<file.rdbuf();
  file.close();

  
  while(!fileStream.eof()) {
    string line;
    string pair;
    getline(fileStream, line);
    stringstream lineStream(line);
    lineStream>>pair;
    pairs.push_back(pair);
    cout<<pair<<'\t';
    lineStream>>pair;
    cout<<pair<<'\n';
    pairs.push_back(pair);
  }

  return pairs;
}


string pipeCommand(string command) {
  FILE *pipe = popen(command.c_str(), "r");
  string result;
  char line[64];
 
  while (fgets(line, 64, pipe)) {
    result += line;
  }
  pclose(pipe);
  return result;
} 
