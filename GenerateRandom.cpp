#include <string>
#include <fstream>
#include <random>
#include <iostream>

using namespace std;

class RandInt{
  private:
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<int> dist;

    public:
      RandInt(int low, int high) : mt{rd()}, dist{low,high} {}
      int operator ()() {return dist(mt);}
};

RandInt rnd {21,127};

void generateUniquePairs(int size, string fileName) {
  ofstream file;
  string values;
  for(int i = 0; i < 25000;  i++) {
    
    for(int j = 0; j<size; j++) {
      values.push_back(static_cast<char>(rnd()));
    }
    values.push_back('\t');
    for(int j = 0; j<size; j++) {
      values.push_back(static_cast<char>(rnd()));
    }
     values.push_back('\n');
  }
  file.open(fileName);
  file<<values;
  file.close();
}

void generatingMinDifPairs(int size, string fileName) {
  ofstream file;
  string values;
  for(int i = 0; i < 25000;  i++) {
    string randString;
    for(int j = 0; j<size; j++) {
      randString.push_back(static_cast<char>(rnd()));
    }
    randString.push_back('\t');
    randString += randString;
    randString.pop_back();
    randString.push_back('\n');
    randString[0] = static_cast<char>(rnd());

    values.append(randString);
  }
  file.open(fileName);
  file<<values;
  file.close();
}

int main() {
//   genereate 100k of string pairs
//   25k = 10
//   25k = 100
//   25k = 500
//   25k = 1000
  cout<<"\n Generating pairs of length 10... \n";
  generateUniquePairs(10,"./RandomTestFiles/10.txt");
  cout<<" Generating pairs of length 100... \n";
  generateUniquePairs(100,"./RandomTestFiles/100.txt");
  cout<<" Generating pairs of length 500... \n";
  generateUniquePairs(500,"./RandomTestFiles/500.txt");
  cout<<" Generating pairs of length 1000... \n";
  generateUniquePairs(1000,"./RandomTestFiles/1000.txt");

  cout<<"\n Generating min dif pairs of length 10... \n";
  generatingMinDifPairs(10,"./RandomTestFiles/m10.txt");
  cout<<" Generating min dif pairs of length 100... \n";
  generatingMinDifPairs(100,"./RandomTestFiles/m100.txt");
  cout<<" Generating min dif pairs of length 500... \n";
  generatingMinDifPairs(500,"./RandomTestFiles/m500.txt");
  cout<<" Generating min dif pairs of length 1000... \n";
  generatingMinDifPairs(1000,"./RandomTestFiles/m1000.txt");
}

