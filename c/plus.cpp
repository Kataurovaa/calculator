#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100


int main()
{
    FILE* inp = fopen("input.txt", "r");
    int a, b;
    fscanf(inp, "%d + %d", &a, &b);
    printf("%d", a + b);
    return 0;
}