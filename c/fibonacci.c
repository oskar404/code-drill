/*
Write a function that computes the list of the first 100 Fibonacci numbers.
By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
and each subsequent number is the sum of the previous two. As an example,
here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.
*/
#include <stdio.h>
#include <stdlib.h>

int fibonacci(unsigned long buf[3], int count)
{
    if (count > 0)
        printf("%lu\n", buf[0]);
    if (count > 1)
        printf("%lu\n", buf[1]);
    count -= 2;
    while (count > 0)
    {
        buf[2] = buf[1] + buf[0];
        if (buf[2] < buf[1])
            return 1;
        printf("%lu\n", buf[2]);
        buf[0] = buf[1];
        buf[1] = buf[2];
        --count;
    }
    return 0;
}

int readargs(int argc, char* argv[], int* count)
{
    if (argc > 2)
        return 1;
    if (argc == 2)
    {
        int val = atoi(argv[1]);
        if (val <= 0)
            return 1;
        *count = val;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    int count = 100;
    if (readargs(argc, argv, &count))
    {
        fprintf(stderr, "usage: %s <count>\n", argv[0]);
        return 1;
    }

    unsigned long buf[3] = {0,1,1};
    if (fibonacci(buf, count))
    {
        fprintf(stderr, "Integer overflow\n");
        return 2;
    }

    return 0;
}
