/*
Write a function that combines two lists by alternatingly taking elements.
For example: given the two lists [a, b, c] and [1, 2, 3], the function should
return [a, 1, b, 2, c, 3].
*/
#include <stdio.h>

void alternate(char* v1[], char* v2[], int len)
{
    printf("[");
    for (int i = 0; i < len; ++i)
    {
        if (i != 0)
            printf(", ");
        printf("%s, %s", v1[i], v2[i]);
    }
    printf("]\n");
}

int main(int argc, char* argv[])
{
    char* v1[4] = {"A", "B", "C", "D"};
    char* v2[4] = {"1", "2", "3", "4"};
    alternate(v1, v2, 4);
    alternate(v2, v1, 4);
    return 0;
}
