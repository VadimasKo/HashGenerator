#include <iostream>
#include <array>

using namespace std;

void pipeCommand(string strCmd) {
  array<char, 80> buffer;
  FILE *pipe = popen(strCmd.c_str(), "r");
  if (!pipe) {
    cerr << "cannot open pipe to read \n";
    return;
  }
  int c=0;
  while(fgets(buffer.data(), 80, pipe) != NULL) {
      c++;
      std::cout<<c<<" "<< buffer.data();
  }
  pclose(pipe);
} 

int main() {
  string strCmd = "";
  while(1) {
    cout<<"enter a command \n";
    getline(cin, strCmd);
    pipeCommand(strCmd);
  }
  return 0;
}