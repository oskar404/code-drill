#
# FILE:         Makefile
# DESCRIPTION:  Build file for the C language
#

LIBS :=
INCLUDES := -I.
CCFLAGS := -Wall -Werror -ansi -pedantic --std=c11
CC := gcc $(CCFLAGS)
PRGS := helloworld fiveproblems1 fiveproblems2

all: $(PRGS)

%.o: %.c
	$(CC) -c $< -o $@ $(INCLUDES)

helloworld: helloworld.o
	$(CC) $^ -o $@ $(LIBS)

fiveproblem1: fiveproblem1.o
	$(CC) $^ -o $@ $(LIBS)

fiveproblem2: fiveproblem2.o
	$(CC) $^ -o $@ $(LIBS)

clean:
	@rm -f *~ *.o $(PRGS)
