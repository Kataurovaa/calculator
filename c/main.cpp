#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define SIZE 100
// :*


float parser(char formula[SIZE])
{

}

typedef struct var
{
    char name[SIZE];
    char formula[SIZE];
    int val;
} var;

int main()
{
    var variables[SIZE]; 
    char formula[SIZE]; 
    FILE* inp = fopen("input.txt", "r");
    int n;
    fscanf(inp, "%d", &n);
    fscanf(inp, "%s", &formula);
    for (int i = 0; i < n - 1; ++i)
    {
        fscanf(inp, "%s = %s", &variables[i].name, &variables[i].formula);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        variables[i].val = parser(variables[i].formula);///only for real digit
    }



    return 0;
}

