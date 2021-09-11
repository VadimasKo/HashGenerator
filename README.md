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
    make runTests
  ```
  ### How to compile?
  * Linux OS - make 
  * Other OS - g++ Main.cpp -o HashGenerator
  