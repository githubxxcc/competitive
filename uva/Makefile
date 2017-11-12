CXX=g++
CXXFLAGS=-std=+11

.PHONY: all
all: build test

.PHONY: build
build: 
	@cd $(Q); 	\
	$(CXX) sol.cpp

.PHONY: test
test:
	@cd $(Q) && ./a.out <input.txt


