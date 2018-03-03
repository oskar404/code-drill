#
# FILE:         Makefile
# DESCRIPTION:  Build file for the C++ language
#

LIBS :=
INCLUDES := -I.
CXXFLAGS := -Wall -Werror -std=c++11
CXX := g++ $(CXXFLAGS)

all: helloworld

%.o: %.cpp
	$(CXX) -c $< -o $@ $(INCLUDES)

helloworld:  helloworld.o
	$(CXX) $^ -o $@ $(LIBS)

clean:
	@rm -f *~ *.o

distclean: clean
	@rm -f helloworld
