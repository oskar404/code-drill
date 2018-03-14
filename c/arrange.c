/*
Write a function that given a list of non negative integers, arranges them
such that they form the largest possible number. For example, given
[50, 2, 1, 9], the largest formed number is 95021.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE "usage: %s <number> [<number>]\n"
#define BUFFER_SIZE 256

void to_str(char* buf, int a, int b)
{
    char tmp[BUFFER_SIZE];
    sprintf(buf, "%d", a);
    sprintf(tmp, "%d", b);
    strcat(buf, tmp);
}

int comparator(const void* lhs, const void* rhs)
{
    int l = *(int*)lhs;
    int r = *(int*)rhs;
    if (l == r)
        return 0;
    char lbuf[BUFFER_SIZE];
    char rbuf[BUFFER_SIZE];
    to_str((char*)lbuf, l, r);
    to_str((char*)rbuf, r, l);
    return strcmp(rbuf, lbuf);
}

/* Returns the length of the buffer. On error return -1. */
int readargs(int argc, char* argv[], int* buffer)
{
    int len = argc-1;
    for (int i = 0; i < len; ++i)
    {
        int val = atoi(argv[i+1]);
        if (val < 0)
            return -1;
        buffer[i] = val;
    }
    return len;
}

int main(int argc, char* argv[])
{
    int buffer[BUFFER_SIZE];

    if (argc - 1 > BUFFER_SIZE)
    {
        fprintf(stderr, USAGE, argv[0]);
        fprintf(stderr, "\tToo many arguments. Max args: %d\n", BUFFER_SIZE);
        return 1;
    }
    if (readargs(argc, argv, buffer) <= 0)
    {
        fprintf(stderr, USAGE, argv[0]);
        fprintf(stderr, "\tInvalid input. Non-negative integers only\n");
        return 1;
    }

    qsort(buffer, argc-1, sizeof(int), comparator);

    for(int i = 0; i < argc-1; ++i)
        printf("%d", buffer[i]);
    printf("\n");

    return 0;
}
