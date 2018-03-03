#
# FILE:         Makefile
# DESCRIPTION:  Build file for the C language
#

LIBS :=
INCLUDES := -I.
CXXFLAGS := -Wall -Werror -ansi -pedantic
CXX := gcc $(CXXFLAGS)

all: helloworld

%.o: %.c
	$(CXX) -c $< -o $@ $(INCLUDES)

helloworld:  helloworld.o
	$(CXX) $^ -o $@ $(LIBS)

clean:
	@rm -f *~ *.o

distclean: clean
	@rm -f helloworld
