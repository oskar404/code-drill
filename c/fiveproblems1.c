/* 
Write three functions that compute the sum of the numbers in a given list
using a for-loop, a while-loop, and recursion.
*/
#include <stdio.h>

int forloop(const int* buf, int len)
{
    int sum = 0;
    for (int i = 0; i < len; ++i)
        sum += buf[i];
    return sum;
}

int whileloop(const int* buf, int len)
{
    int sum = 0;
    while (len > 0)
        sum += buf[--len];
    return sum;
}

int recursion(const int* buf, int len)
{
    if (len == 0)
        return 0;
    --len;
    return buf[len] + recursion(buf, len);
}

int main(int argc, char* argv[])
{
    int buf[10] = {1,2,3,4,5,-4,-1,8,9,-17};
    printf("forloop(): %d\n", forloop(buf, 10));
    printf("whileloop(): %d\n", whileloop(buf, 10));
    printf("recursion(): %d\n", recursion(buf, 10));
    return 0;
}
