#include <iostream>
#include <string>
#include <vector>

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

const int hashSize = 64;

int main() {
  string input = "9vbrJPPrMqhnt7Vv1ixd3QuQElP2MBfSJoiFXsyWMne88ILpxP6ajw7iRdara6g3U9baiqLg8snDQ6bRPeUDg53fuGdQEg7xXF2rwuseYrHe6OEJURnp8Fip7jr2Ofob11";
  vector<string> inputSections;

  int i = 0;
  while(i < input.size()) {
    string buffer = input.substr(i, hashSize);
    inputSections.push_back(buffer);
    i+=hashSize;
  }
  
  if(inputSections.back().length() < hashSize) {
    size_t missingCharNr = hashSize - inputSections.back().size();
    inputSections.back().append(string(missingCharNr, '#'));
  } 

  for(string section : inputSections) {
    cout<<section<<"       "<<section.size()<<endl;
  }
}
