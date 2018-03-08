#
# FILE:         Makefile
# DESCRIPTION:  Build file for the C++ language
#

LIBS :=
INCLUDES := -I.
CXXFLAGS := -Wall -Werror -std=c++11
CXX := g++ $(CXXFLAGS)
PRGS := helloworld fiveproblems1 fiveproblems2 fibonacci arrange

all: $(PRGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(INCLUDES)

helloworld: helloworld.o
	$(CXX) $^ -o $@ $(LIBS)

fiveproblems1: fiveproblems1.o
	$(CXX) $^ -o $@ $(LIBS)

fiveproblems2: fiveproblems2.o
	$(CXX) $^ -o $@ $(LIBS)

fibonacci: fibonacci.o
	$(CXX) $^ -o $@ $(LIBS)

arrange: arrange.o
	$(CXX) $^ -o $@ $(LIBS)

clean:
	@rm -f *~ *.o $(PRGS)
