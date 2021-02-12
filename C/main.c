#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct pair()
{

};

int main()
{
    FILE *inp = fopen("input.txt", 'r');
    int n;
    fscanf(inp, "%d", &n);
    for (int i = 0; i < n; ++i)
    {
        fscanf(inp, "%d", &n);
    }




    return 0;
}