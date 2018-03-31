#
# FILE:         Makefile
# DESCRIPTION:  Build file for the Rust stuff
#

RUSTC := rustc
PRGS := helloworld fiveproblems1

all: $(PRGS)

helloworld: helloworld.rs
	$(RUSTC) $^

fiveproblems1: fiveproblems1.rs
	$(RUSTC) $^

clean:
	@rm -f *~ $(PRGS)
