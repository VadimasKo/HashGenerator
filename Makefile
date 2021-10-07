main: Main.cpp
	g++ Main.cpp -o HashGenerator.exe

run: Main.cpp
	g++ Main.cpp -o HashGenerator.exe && ./HashGenerator.exe

generateRandom: GenerateRandom.cpp
	g++ GenerateRandom.cpp -o GenerateRandom.exe && ./GenerateRandom.exe

runControlledTests: Main.cpp
	g++ Main.cpp -o HashGenerator.exe
	#---------------------------------------
	#       Running Controlled tests
	#    1) file containing only a
	#    2) file containing only b
	#    3) empty file
	#    4) 1000 char random generated string
	#    5) char used in 4 test with 1st char changed 
	#---------------------------------------
	./HashGenerator.exe ControlledTestFiles/a.txt
	#---------------------------------------
	./HashGenerator.exe ControlledTestFiles/b.txt
	#---------------------------------------
	./HashGenerator.exe ControlledTestFiles/emptyFile.txt
	#---------------------------------------
	./HashGenerator.exe ControlledTestFiles/loremIpsum1.txt
	#---------------------------------------
	./HashGenerator.exe ControlledTestFiles/loremIpsum2.txt

runLineTest: LineTest.cpp
	g++ LineTest.cpp -o LineTest.exe
	./LineTest.exe ./ControlledTestFiles/konstitucija.txt

runDifferenceTest:	HashDiffTest.cpp
	g++ HashDiffTest.cpp -o HashDiffTest.exe
	./HashDiffTest.exe