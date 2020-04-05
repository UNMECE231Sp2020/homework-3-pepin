FNS = GeneralList.hpp
Main = main.cpp $(FNS)

all:
	g++ $(MAIN) -o run_tests

clean:
	rm run_tests
