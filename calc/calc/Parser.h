#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>
#define SIZE 100
typedef struct var
{
    int mar; // формула
    char name[SIZE];
    char formula[SIZE];
    double re;
    double im;
    double val;
} var;

void parser(var* variables) {
    int cmp = 0; int k = 0; char tmp1[10] = { 0 }; char tmp2[10] = { 0 };// double re; double im; ->  double complex x = re + im * I;
    for (int i = 0; variables->formula[i] != '\0' && variables->formula[i] != '\n' && variables->formula[i] != EOF; i++) {
        if (variables->formula[i] == 'j') {
            cmp = 1; break; // комплексное ли число
        }
    }
    if (cmp == 1) { // парсит комл число
        for (int i = 0; ; i++) {
            if (variables->formula[i] == '+' || (variables->formula[i] == '-' && variables->formula[i - 1] >= 48 && variables->formula[i - 1] <= 57)) break;
            tmp1[k] = variables->formula[i];
            k++;
        }
        variables->re = atof(tmp1); int j = 0;
        for (int i = k; variables->formula[i] != 'j'; i++) {

            tmp2[j] = variables->formula[i];
            j++;
            k++;
        }
        variables->im = atof(tmp2);
        //variables->x = variables->re + variables->im * I;
    } // парсит комл число
    else {
        int mar = 0;
        for (int i = 0; variables->formula[i] != '\0' && variables->formula[i] != '\n' && variables->formula[i] != EOF; i++) {
            if (variables->formula[i] >= 48 && variables->formula[i] <= 57 || variables->formula[i] == 45 || variables->formula[i] == 46) {// просто ли число это?
                mar = 0;
            }
            else { mar = 1; variables->mar = 1; break; }

        }
        if (mar == 0) {
            variables->val = atof(variables->formula);
            variables->re = atof(variables->formula);
            variables->im = 0;
        }
    }
}