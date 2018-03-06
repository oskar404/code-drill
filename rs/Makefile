#
# FILE:         Makefile
# DESCRIPTION:  Build file for the Rust stuff
#

RUSTC := rustc

all: helloworld

helloworld: helloworld.rs
	$(RUSTC) -o $@ $^

clean:
	@rm -f *~ helloworld
