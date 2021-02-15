#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100


int main()
{
    FILE* inp = fopen("C:/Server/data/htdocs/calculator/uploades/1.txt", "r");
    int a, b, tmp;
    fscanf(inp, "%d", &tmp);
    fscanf(inp, "%d + %d", &a, &b);
    printf("%d + %d = %d",a,b,a + b);
    fclose(inp);
    return 0;
}