#
# FILE:         Makefile
# DESCRIPTION:  Build file for the C language
#

LIBS :=
INCLUDES := -I.
CCFLAGS := -Wall -Werror -ansi -pedantic --std=c11
CC := gcc $(CCFLAGS)
PRGS := helloworld fiveproblems1 fiveproblems2 fibonacci arrange

all: $(PRGS)

%.o: %.c
	$(CC) -c $< -o $@ $(INCLUDES)

helloworld: helloworld.o
	$(CC) $^ -o $@ $(LIBS)

fiveproblems1: fiveproblems1.o
	$(CC) $^ -o $@ $(LIBS)

fiveproblems2: fiveproblems2.o
	$(CC) $^ -o $@ $(LIBS)

fibonacci: fibonacci.o
	$(CC) $^ -o $@ $(LIBS)

arrange: arrange.o
	$(CC) $^ -o $@ $(LIBS)

clean:
	@rm -f *~ *.o $(PRGS)
