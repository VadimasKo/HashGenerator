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



int main() {
  string input = "9vbrJPPrMqhnt7Vv1ixd3QuQElP2MBfSJoiFXsyWMne88ILpxP6ajw7iRdara6g3U9baiqLg8snDQ6bRPeUDg53fuGdQEg7xXF2rwuseYrHe6OEJURnp8Fip7jr2Ofob";
  vector<string> inputSections;
  for(int i = 0; i <= input.length()-1; i+=64 ) {
    inputSections.push_back(input.substr(i,i+64));
  }
  
  for(string section : inputSections) {
    cout<<section<<endl;
  }
}