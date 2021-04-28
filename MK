sources = *.cpp
CXX =g++
cxxflags = -std=c++20 -Wall -g -fsanitize=address
target = *.out

all:
	$(CXX)	$(sources)	$(cxxflags)	-o $(target) 

