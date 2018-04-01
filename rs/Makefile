#
# FILE:         Makefile
# DESCRIPTION:  Build file for the Rust stuff
#

RUSTC := rustc
PRGS := helloworld fiveproblems1 fiveproblems2 fibonacci arrange

all: $(PRGS)

helloworld: helloworld.rs
	$(RUSTC) $^

fiveproblems1: fiveproblems1.rs
	$(RUSTC) $^

fiveproblems2: fiveproblems2.rs
	$(RUSTC) $^

fibonacci: fibonacci.rs
	$(RUSTC) $^

arrange: arrange.rs
	$(RUSTC) $^

clean:
	@rm -f *~ $(PRGS)
