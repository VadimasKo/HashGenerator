# Hash Generator
  ### *A function which given input  as string or .txt file outputs a hash*
  ```
   ./HashGenerator file.txt  result---TODO
  ```
 
 ## Properties:
  *  **Input** can be of any size
  *  **Output** is always a 64 char string 
  *  Same Input always produces same Output
  *  Has **complexity** of ?     <--I hope < O(n^2)
  *  It is hard to infer Input out of Output
  *  Is **collision resistant** (no 2 inputs produce same output)
  *  Output is **highly sensitive** to changes of Input
  
  ---
  ## Analysis:
  ### Comparison with md5 algorith (3)
  ```
  Duration of mine hash generator 0.898975
  Duration of md5 hash generator 1.83263
  ``` 
  ### Running tests on randomly generated pairs of strings (5)
  * length of pairs = 10
  ```
  Min Hex | Max Hex | Min Bool | Max Bool | Avg Hex | Avg Bool 
  4.83871 | 91.8033 | 41.5254  | 96.6667  | 33.7455 | 62.9132
  ```
  * length of pairs = 100
  ```
  Min Hex | Max Hex | Min Bool | Max Bool | Avg Hex | Avg Bool 
  1.51515 | 23.8095 | 37.0968 | 65.5172 | 8.33723 | 49.7182
  ```
  * length of pairs = 500

  ```
  Min Hex | Max Hex | Min Bool | Max Bool | Avg Hex | Avg Bool 
  1.51515 | 23.8095 | 35.8871 | 62.5 | 8.33556 | 49.6701
  ```

  ### Running tests on randomly generated pairs of string with a 1 char difference between relative pairs (6)
  * length of pairs = 10
  ```
  Min Hex | Max Hex | Min Bool | Max Bool | Avg Hex | Avg Bool 
  4.83871 | 100     | 42.6724  | 100      | 87.9385 | 93.5955

  ```
  * length of pairs = 100
  ```
  Min Hex | Max Hex | Min Bool | Max Bool | Avg Hex | Avg Bool 
  1.53846 | 100 | 37.9032 | 100 | 80.8218 | 89.8687
  ```

  ## Results
  * My hash function does not work properly
  * Works marginaly better on longer inputs
  * To improve this algorith i should include some kind of sort based on input

  ---
  ## Instructions:
  ### How to run?
  * using .txt file as a Input
  ```
    ./HashGenerator /relativeDirectory/input.txt
  ```
  * using custom string as a Input 
  ```
   ./HashGenerator 
    interfaceQuestion?: answer
    output:             output 
  ```
  ### How to run tests?:
  ``` 
    make runControlledTests
    make runLineTests
    make runDifferenceTests
  ```
  ### How to compile?
  * Linux OS - make 
  * Other OS - g++ Main.cpp -o HashGenerator
  