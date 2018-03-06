#
# FILE:         Makefile
# DESCRIPTION:  Build file for the Haskell stuff
#

GHC := ghc

all: helloworld

helloworld:  helloworld.hs
	$(GHC) $^

clean:
	@rm -f *~ *.o *.hi helloworld
