#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

map<char, string> hexMap {
  {'1', "0001"},
  {'2', "0010"},
  {'3', "0011"},
  {'4', "0100"},
  {'5', "0101"},
  {'6', "0110"},
  {'7', "0111"},
  {'8', "1000"},
  {'9', "1001"},
  {'A', "1010"},
  {'B', "1011"},
  {'C', "1100"},
  {'D', "1101"},
  {'E', "1110"},
  {'F', "1111"},
};

string pipeCommand(string command);
vector<string> getPairs(string filePath);
void getStats(string filePath);
double comparePairs(string pair1, string pair2);
string getHash(string pair);
string hexToBinary(string hex);


int main() {
  getStats("./RandomTestFiles/10.txt");
  getStats("./RandomTestFiles/m10.txt");
  getStats("./RandomTestFiles/100.txt");
  getStats("./RandomTestFiles/m100.txt");
  getStats("./RandomTestFiles/500.txt");
  getStats("./RandomTestFiles/m500.txt");
  getStats("./RandomTestFiles/1000.txt");
  getStats("./RandomTestFiles/m1000.txt");
}


void getStats(string filePath) {
  double max      = 0.0;
  double maxBool  = 0.0;
  double min      = 100.0;
  double minBool  = 100.0;
  double avrg     = 0.0;
  double avrgBool = 0.0;

  vector<string> pairs = (getPairs(filePath));
  for(int i=0; i<pairs.size(); i++) {
    string pair1 = getHash(pairs[i]);
    string pair2 = getHash(pairs[++i]);
    double holder = comparePairs(pair1, pair2);
    if (holder > max) max = holder;
    if (holder < min) min = holder;
    avrg+=holder;
    //BINARY strings comparison
    pair1 = hexToBinary(pair1);
    pair2 = hexToBinary(pair2);
    holder = comparePairs(pair1, pair2);
    if (holder > maxBool) maxBool = holder;
    if (holder < minBool) minBool = holder;
    avrgBool+=holder;
  }
  cout<<filePath<<endl;
  cout<<"Min Hex | Max Hex | Min Bool | Max Bool | Avg Hex | Avg Bool \n";
  cout<<min<<" | "<<max<<" | "<<minBool<<" | "<<maxBool<<" | "<<avrg*2/pairs.size()<<" | "<<avrgBool*2/pairs.size()<<"\n\n";
}

double comparePairs(string pair1, string pair2) {
  string matchString;
  for(int i = 0; i < pair1.size(); i++) {
    if(pair1[i] == pair2[i]) matchString.push_back(1);
  }
  return matchString.size() * 100.0 / pair1.size();
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

string getHash(string pair) {
  string command = "./HashGenerator.exe test ";
  string hash    = pipeCommand(command+ "\"" + pair + "\"");

  return hash;
}

string hexToBinary(string hex) {
  string binary;
  for(char symbol : hex) {
    binary.append(hexMap[symbol]);
  }
  return binary;
}

string pipeCommand(string command) {
  FILE *pipe = popen(command.c_str(), "r");
  string result;
  char line[80];
 
  while (fgets(line, 80, pipe)) {
    result += line;
  }
  pclose(pipe);
  return result;
} 
