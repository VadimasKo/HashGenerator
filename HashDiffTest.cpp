#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

string pipeCommand(string command);
vector<string> getPairs(string filePath);
vector<string> getHashes(vector<string> pairs);

int main() {
  getHashes(getPairs("./RandomTestFiles/10.txt"));

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
    lineStream>>pair;
    pairs.push_back(pair);
  }
  pairs.pop_back();
  pairs.pop_back();
  return pairs;
}

vector<string> getHashes(vector<string> pairs) {
  string command = "./HashGenerator.exe  test ";
  vector<string> hashes;

  for(string pair : pairs) {
    cout<<(pipeCommand(command+ '\"' + pair + '\"'));
  }
  for(string hash : hashes) {
    cout<<hash<<endl;
  }
  return hashes;
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
