main: Main.cpp
	g++ Main.cpp -o HashGenerator

run: Main.cpp
	g++ Main.cpp -o HashGenerator && ./HashGenerator