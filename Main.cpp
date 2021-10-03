#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

void getInputFromFile(string &input, string fileLocation);
void getInputByHand(string &input);
vector<string> stringSplit(string input);
void convertToBitStrings(vector<string> &splits);
string mergeBitStrings(vector<string> &splits);
string binaryToHex(string input);


const string initialKey = "1011110011011001010101101011001011000111001111110100101110010001011100000001011010101011010100111001001100011111010001000011111010101000000110010001110010110011010010101010010110001001110001001011110100000010110010000101110100100001101111010100011110001010";
map<string, string> hexMap {
    {"0001", "1"},
    {"0010", "2"},
    {"0011", "3"},
    {"0100", "4"},
    {"0101", "5"},
    {"0110", "6"},
    {"0111", "7"},
    {"1000", "8"},
    {"1001", "9"},
    {"1010", "A"},
    {"1011", "B"},
    {"1100", "C"},
    {"1101", "D"},
    {"1110", "E"},
    {"1111", "F"},
};

int main(int argc, char *argv[]) {
  string input;
  if(argc == 1 )     getInputByHand(input);
  else if(argc == 2) getInputFromFile(input, argv[1]);
  else if(argc == 3) input=argv[2];
  
  cout<<input;

  vector<string> splits = stringSplit(input);
  convertToBitStrings(splits);
  string hash = binaryToHex(mergeBitStrings(splits));
  cout<<"\t"<<hash<<endl;
}


void getInputFromFile(string &input, string fileLocation) {
  stringstream fileStream;
  ifstream file;
  file.open(fileLocation);
  fileStream<<file.rdbuf();
  
  input= fileStream.str();
}

void getInputByHand(string &input) {
  cout<<"input a string: ";
  cin>>input;
}

vector<string> stringSplit(string input) {
  int splitSize = 64;
  vector<string> splits;

  for(int i = 0; i < input.size(); i+=splitSize) {
    splits.push_back(input.substr(i,splitSize));
  }

  return splits;
}

void convertToBitStrings(vector<string> &splits) {
  vector<string> bufferVector;

  for(string split : splits) {
    string buffer;
    for(char symbol : split) {
      buffer.append(bitset<4>(symbol).to_string());
    }
    if(buffer.size() < 256) buffer.append(string(256 - buffer.size(),'0'));
    bufferVector.push_back(buffer);
  }

  splits = bufferVector;
}


string andGate(string input1, string input2) {
  string outPut;
  for(int i = 0; i<input1.size(); i++) {
    (input1[i] == input2[i] == 1) ? outPut.push_back('1') : outPut.push_back('0');
  }
  return outPut;
}

void shiftRight(string &input) {
  input.insert(input.begin(), input[input.size()-1]);
  input.pop_back();
}

string mergeBitStrings(vector<string> &splits) {
  if(splits.size() < 3) splits.push_back(initialKey);

  string mergedStrings = splits[0];
  for(string split: splits) {
    shiftRight(split);
    mergedStrings = andGate(mergedStrings, split);
  }
  shiftRight(mergedStrings);
  return mergedStrings;
}

string binaryToHex(string input) {
  string output;
  for(int i = 0; i < input.size(); i+=4) {
    output.append(hexMap[input.substr(i,4)]);
  }
  return output;
}
