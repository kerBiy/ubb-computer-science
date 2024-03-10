C := gcc
CFLAGS := -I../include
OPTIONS := -Wall -g -o
LEAKS_OPTIONS := --atExit --list

sourceFiles := ../src/*.c
appName := app

all:
	$(C) $(CFLAGS) $(OPTIONS) $(appName) $(sourceFiles)
leaks:
	leaks $(LEAKS_OPTIONS) -- ./$(appName)
run:
	./$(appName)