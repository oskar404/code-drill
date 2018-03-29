#
# FILE:         Makefile
# DESCRIPTION:  Build file for the Go language
#

PRGS := helloworld fiveproblems1 fiveproblems2 fibonacci arrange

all: $(PRGS)

helloworld: helloworld.go
	go build $^

fiveproblems1: fiveproblems1.go
	go build $^

fiveproblems2: fiveproblems2.go
	go build $^

fibonacci: fibonacci.go
	go build $^

arrange: arrange.go
	go build $^

clean:
	go clean
