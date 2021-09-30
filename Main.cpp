#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


/* Plan:
  1) Divide string into 64 char sections
  2) Convert Sections into binary strings
  3) (Optional) Shift binary values
  4) Merge Sections using AND gate
  5) (Optional) Shift binary balues
  6) Convert binary string into HEX string

  Later: 
  1) Create userInterface
  2) Allow passing props by txt && then calling function
  3) Measure
  4+) BLA BLA BLA
*/

const int splitSize = 32;

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



vector<string> splitString(string input) {
  vector<string> inputSections;

  int i = 0;
  while(i < input.size()) {
    string buffer = input.substr(i, splitSize);
    inputSections.push_back(buffer);
    i+=splitSize;
  }
  
  if(inputSections.back().length() < splitSize) {
    size_t missingCharNr = splitSize - inputSections.back().size();
    inputSections.back().append(string(missingCharNr, '#'));
  } 

  return inputSections;
}

string stringToBinary (string input) {
  string binaryString = "";
  for(char symbol : input) {
     binaryString += bitset<8>(symbol).to_string();
  }
  return binaryString;
}

string andGate (string input1, string input2) {
  string binaryString = "";
  for(int i = 0; i<input1.size(); i++) {
    binaryString.push_back(
      (input1[i] == input2[i] && input1[i] == '1') ? '1' : '0' 
    );
  } 
  return binaryString;
}

string bitShiftRight (string input) {
  string output;
  output.push_back(input[input.length()-1]);
  output.append(string(input.begin(), input.end()-1));
  return  output;
}

int main() {
  string input = "b";
  vector<string> inputSections = splitString(input);
  string binaryString;
  string hexString;

  for(string section : inputSections) {
    string buffer = stringToBinary(section);
    binaryString = (binaryString.length() > 0) ? 
      andGate(buffer, binaryString) :
      buffer;
    binaryString;
  }

  binaryString = bitShiftRight(binaryString);
  binaryString = bitShiftRight(binaryString);


  for(int i = 0; i < binaryString.length(); i+=4) {
    hexString.append(hexMap[binaryString.substr(i,4)]);
  }
  cout<<hexString.length()<<endl;
  cout<<hexString<<endl;
}
