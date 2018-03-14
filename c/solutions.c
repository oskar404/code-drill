/*
Write a program that outputs all possibilities to put + or - or nothing
between the numbers 1, 2, ..., 9 (in this order) such that the result is
always 100. For example: 1 + 2 + 34 – 5 + 67 – 8 + 9 = 100.
*/
#include <stdio.h>
#include <stdlib.h>

static const int NUMBERS_SIZE = 9;
static const int NUMBERS[] = {1,2,3,4,5,6,7,8,9};
static const int SUM = 100;
static const int BUFFER_SIZE = 10;

void dump(int* buffer, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (i == 0)
            printf("%d", buffer[i]);
        else
            printf(" %s %d", (buffer[i] >= 0 ? "+" : "-"), abs(buffer[i]));
    }
    printf(" = %d\n", SUM);
}

void recurse(int* buffer, int idx, int size)
{
    // Check if we have recursed to depth
    if (idx >= NUMBERS_SIZE)
    {
        int result = 0;
        for (int i = 0; i < size; ++i)
            result += buffer[i];
        if (result == SUM)
            dump(buffer, size);
        return;
    }

    // Branch 1: Add number to previous
    buffer[size] = NUMBERS[idx];
    recurse(buffer, idx+1, size+1);

    // Branch 2: Subtract number from previous
    buffer[size] = -1 * NUMBERS[idx];
    recurse(buffer, idx+1, size+1);

    // Branch 3: Concatenate number to previous
    int prev = buffer[size-1];
    buffer[size-1] = (10 * abs(prev) + NUMBERS[idx]) * (prev >= 0 ? 1 : -1);
    recurse(buffer, idx+1, size);
    buffer[size-1] = prev;
}

int main(int argc, char* argv[])
{
    int buffer[BUFFER_SIZE];
    buffer[0] = NUMBERS[0];
    recurse((int*)buffer, 1, 1);
    return 0;
}
