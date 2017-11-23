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

.PHONY: setup
setup:
	@mkdir $(Q) && touch $(Q)/sol.cpp $(Q)/input.txt

.PHONY: clean
clean:
	@rm -rf $(Q)


