EMP_DIR := ../../tools/empirical_oee/Empirical/source# Needs to be the OEE branch of 
    #https://github.com/amlalejini/Empirical/
PARSER_DIR := ../../tools/csv-parser

CXX := g++-8 

CFLAGS := -Wall -Wno-unused-function -iquote $(EMP_DIR)/ -iquote $(PARSER_DIR) -std=c++17

OFLAGS_optim := -O3 -DNDEBUG
OFLAGS_debug := -O3 -g -pedantic -DEMP_TRACK_MEM  -Wnon-virtual-dtor -Wcast-align -Woverloaded-virtual

all: ./src/main.cc
	$(CXX) ./src/main.cc $(CFLAGS) $(OFLAGS_optim) -o gptp2019

debug: ./src/main.cc
	$(CXX) ./src/main.cc $(CFLAGS) $(OFLAGS_debug) -o gptp2019
pre: ./src/main.cc
	$(CXX) -E ./src/main.cc $(CFLAGS) $(OFLAGS_debug)

s: ./src/main.cc
	$(CXX) -S ./src/main.cc $(CFLAGS) $(OFLAGS_debug)

clean:
	rm ./gptp2019
