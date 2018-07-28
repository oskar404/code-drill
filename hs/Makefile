#
# FILE:         Makefile
# DESCRIPTION:  Build file for the Haskell stuff
#

GHC := ghc
PRGS := helloworld fiveproblems1 fiveproblems2

all: $(PRGS)

helloworld: helloworld.hs
	$(GHC) $^

fiveproblems1: fiveproblems1.hs
	$(GHC) $^

fiveproblems2: fiveproblems2.hs
	$(GHC) $^

clean:
	@rm -f *~ *.o *.hi $(PRGS)
