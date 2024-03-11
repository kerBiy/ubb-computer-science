CPP := g++
CPPVERSION := -std=c++2b
CPPFLAGS := -I../include -I../tests

OPTIONS := -Wall -g -o
LEAKS_OPTIONS := --atExit --list

sourceFiles := ../src/*.cpp ../tests/*.cpp
appName := app

all:
	$(CPP) $(CPPVERSION) $(CPPFLAGS) $(OPTIONS) $(appName) $(sourceFiles)
leaks:
	leaks $(LEAKS_OPTIONS) -- ./$(appName)
run:
	./$(appName)