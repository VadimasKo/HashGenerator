main: Main.cpp
	g++ Main.cpp -o HashGenerator

run: Main.cpp
	g++ Main.cpp -o HashGenerator && ./HashGenerator

runControlledTests: Main.cpp
	g++ Main.cpp -o HashGenerator
	#---------------------------------------
	#       Running Controlled tests
	#    1) file containing only a
	#    2) file containing only b
	#    3) empty file
	#    4) 1000 char random generated string
	#    5) char used in 4 test with 1st char changed 
	#---------------------------------------
	./HashGenerator ControlledTestFiles/a.txt
	#---------------------------------------
	./HashGenerator ControlledTestFiles/b.txt
	#---------------------------------------
	./HashGenerator ControlledTestFiles/emptyFile.txt
	#---------------------------------------
	./HashGenerator ControlledTestFiles/loremIpsum1.txt
	#---------------------------------------
	./HashGenerator ControlledTestFiles/loremIpsum2.txt