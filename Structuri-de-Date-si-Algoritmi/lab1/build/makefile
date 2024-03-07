CXX := g++
CXXFLAGS := -std=c++2a
CPPFLAGS := -I../include -I../tests
OPTIONS := -Wall -g -o

sourceFiles := ../src/*.cpp ../tests/*.cpp
appName := app


all:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPTIONS) $(appName) $(sourceFiles)
run:
	./app