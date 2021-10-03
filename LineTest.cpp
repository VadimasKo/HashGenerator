#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;



int main(int argc, char *argv[]) {
  string fileLoc = argc > 1 ? argv[1] : "./ControlledTestFiles/b.txt";

  stringstream fileStream;
  fstream file;
  file.open(fileLoc);
  fileStream<<file.rdbuf();
  file.close();
  string lineValue;
  // while(!fileStream.eof()){
    getline(fileStream, lineValue);
    // const char *myFuncCall = ("time ./HashGenerator test " + lineValue).c_str();
    // system(myFuncCall);
    system(("./HashGenerator "+ lineValue).c_str());
    cout<<"abc"<<endl;
  // }

}