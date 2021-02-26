

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>
#define SIZE 100

// rpn
void insert(char qu[], int* q, char a)
{
    qu[*q] = a;
    *q = *q + 1;;
}

void push(char stack[], int* s, char a)
{
    stack[*s] = a;
    *s = *s + 1;;
}

void pop(char stack[], char qu[], int* q, int* s)
{
    qu[*q] = stack[*s - 1];
    *q = *q + 1;
    *s = *s - 1;
}

float schet(int arr[], int a, int indpoint)
{
    double  sum, q;
    int s, b, b1;
    sum = 0;
    s = 0;
    q = 1;
    if (indpoint == 0)
    {
        for (a; a > 0; a--)
        {
            b = a - 1;
            while (b > 0)
            {
                q = q * 10;
                b--;
            }
            sum = sum + arr[s] * q;
            s++;
            q = 1;
        }
    }
    else
    {
        for (int m = indpoint; m > 0; m--)
        {
            b = m - 1;
            while (b > 0)
            {
                q = q * 10;
                b--;
            }
            sum = sum + arr[s] * q;
            s++;
            q = 1;
        }
        s = indpoint + 1;
        b = 1;
        for (; s < a;)
        {
            b1 = b;
            while (b1 > 0)
            {
                q = q / 10;
                b1--;
            }
            sum = sum + arr[s] * q;
            s++;
            q = 1;
            b++;
        }
    }
    return sum;
}

int priority(char a) {
    switch (a) {
    case '(':
        return 0;
        break;

    case '+':
    case '-':
        return 1;
        break;

    case '*':
    case '/':
        return 2;
        break;

    case '#':
        return 3;
        break;

    case '^':
        return 4;
        break;
    }
}

double r(double a[], int o, char znak)
{
    float cons;
    switch (znak)
    {
    case '+':
        a[o - 2] = a[o - 2] + a[o - 1];
        return a[o - 2];
        break;

    case '-':
        a[o - 2] = a[o - 2] - a[o - 1];
        return a[o - 2];
        break;

    case '*':
        a[o - 2] = a[o - 2] * a[o - 1];
        return a[o - 2];
        break;

    case '/':
        a[o - 2] = a[o - 2] / a[o - 1];
        return a[o - 2];
        break;

    case '^':
        a[o - 2] = pow(a[o - 2], a[o - 1]);
        return a[o - 2];
        break;

    case '#':
        a[o - 1] = a[o - 1] - 2 * a[o - 1];
        return a[o - 1];
        break;
    }
}

typedef struct var
{
    int mar; // формула
    char name[SIZE];
    char formula[SIZE];
    double re;
    double im;
    double val;
} var;

double find(var var[], char per[], int lenght) {
    int f = 0, j = 0, comp = 0;
    while (f == 0)
    {
        for (int i = 0; i < lenght; i++)
            if (var[j].name[i] == per[i])
                comp++;
        if (comp == lenght)
        {
            f = 1;
            return var[j].val;
        }
        else
        {
            j++;
            comp = 0;
        }
    }
}

double func(char f, double value) {
    if (f == 'c')
        return cos(value);
    if (f == 's')
        return sin(value);
    if (f == 'n')
        return log(value);
    if (f == 'l')
        return log10(value);
    if (f == 'a')
        return fabs(value);
    if (f == 'e')
        return exp(value);
    if (f == 't')
        return tan(value);
    if (f == 'q')
        return sqrt(value);
}

double rpn(char str[], var variables[]) {

    char  stack[SIZE], queue[SIZE], queue1[SIZE], str1[SIZE], str2[SIZE], f;
    int prip = -1, pric, s = 0, i, q = 0, j = 0, q1 = 0, q2 = 0, ai = 0, o = 0, indpoint = 0;
    double out[SIZE], val_func = 0;
    int a[SIZE], mini_stack = 0;
    /*for (i = 0; str[i]!=' '; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' && str[i + 1] == '(')
        {
            j = i + 2;
            while (str[j] != ')' || mini_stack != 0)
            {
                q = 0;
                if (str[j] == ')')
                    mini_stack--;
                if (str[j] == '(')
                    mini_stack++;
                str1[q] = str[j];
                q++;
                j++;
            }
            if (str[i - 1] == 'q' || str[i - 1] == 'n')
                f = str[i - 1];
            else
                f = str[i - 2];
            i = j;
            j++;
            str1[q] = ' ';
            val_func = rpn(str1, variables);
            val_func = func(f, val_func);
            out[o] = val_func;
            o++;
        }
    }*/
    i = j;
    q = 0;
    for (i; str[i] != ' ';)
    {
        if (str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'z')
        {
            while (str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'z' || str[i] == '(' || str[i] == '#')
            {
                if (str[i] == '(')
                {
                    int ministack = 0;
                    while (str[i] != ')' || ministack != 1)
                    {
                        if (str[i] == '(')
                            ministack++;
                        if (str[i] == ')')
                            ministack--;
                        insert(queue, &q, str[i]);
                        i++;
                    }
                }
                insert(queue, &q, str[i]);
                i++;
            }
            if (str[i] == '.')
            {
                insert(queue, &q, '.');
                i++;
                while (str[i] >= '0' && str[i] <= '9')
                {
                    insert(queue, &q, str[i]);
                    i++;
                }
            }
            queue[q] = ' ';
            q++;
        }
        else
        {

            if (str[i] == '(')
            {
                push(stack, &s, str[i]);
                i++;
                prip = 0;
            }
            else
                if (str[i] == ')')
                {
                    while (stack[s - 1] != '(')
                    {
                        pop(stack, queue, &q, &s);
                        queue[q] = ' ';
                        q++;
                    }
                    s--;
                    if (s == 0)
                        prip = 0;
                    else
                        prip = priority(stack[s - 1]);
                    i++;
                }
                else
                {
                    pric = priority(str[i]);
                    if (pric > prip || (stack[s - 1] == '#' && str[i] == '#'))
                    {
                        push(stack, &s, str[i]);
                        prip = pric;
                    }
                    else
                    {
                        while (pric <= prip && stack[s - 1] != '(' && s - 1 >= 0)
                        {
                            pop(stack, queue, &q, &s);
                            queue[q] = ' ';
                            q++;
                            push(stack, &s, str[i]);
                            if (s == 0)
                                prip = 0;
                            else
                                prip = priority(stack[s - 1]);
                            s--;
                        }
                        s++;
                    }
                    i++;
                }
        }
    }
    while (s - 1 != -1)
    {
        pop(stack, queue, &q, &s);
        queue[q] = ' ';
        q++;
    }
    i = 0;
    while (i < q - 1)
    {
        if (queue[i] == ' ')
            i++;
        if (queue[i] >= '0' && queue[i] <= '9')
        {
            ai = 0;
            while (queue[i] >= '0' && queue[i] <= '9')
            {
                a[ai] = queue[i] - '0';
                i++;
                ai++;
            }
            if (queue[i] == '.')
            {
                indpoint = ai;
                a[ai] = '.';
                i++;
                ai++;
                while (queue[i] >= '0' && queue[i] <= '9')
                {
                    a[ai] = queue[i] - '0';
                    i++;
                    ai++;
                }
            }
            out[o] = schet(a, ai, indpoint);
            ai = 0;
            o++;
            i++;
        }
        else
            if (queue[i] >= 'a' && queue[i] <= 'z')
            {
                ai = 0;
                int metka = 0;
                while (queue[i] >= 'a' && queue[i] <= 'z' || queue[i] >= '0' && queue[i] <= '9' || queue[i] == '(' || queue[i] == ')' || queue[i] == '#' || queue[i] == '+' || queue[i] == '-' || queue[i] == '*' || queue[i] == '/' || queue[i] == '^')
                {
                    if (queue[i] == '(')
                        metka = 1;
                    str2[ai] = queue[i];
                    ai++;
                    i++;
                }
                if (metka == 1)
                {
                    for (int m = 0; m < 15; m++)
                    {
                        if (str2[m] >= 'a' && str2[m] <= 'z' && str2[m + 1] == '(')
                        {
                            int t = 0;
                            j = m + 2;
                            while (str2[j] != ')' || mini_stack != 0)
                            {
                                if (str2[j] == ')')
                                    mini_stack--;
                                if (str2[j] == '(')
                                    mini_stack++;
                                str1[t] = str2[j];
                                t++;
                                j++;
                            }
                            if (str2[m - 1] == 'q' || str2[m - 1] == 'n')
                                f = str2[m - 1];
                            else
                                f = str2[m - 2];
                            m = j;
                            j++;
                            str1[t] = ' ';
                            val_func = rpn(str1, variables);
                            val_func = func(f, val_func);
                            out[o] = val_func;
                            o++;
                        }
                    }
                }
                else
                {
                    str2[ai] = ' ';
                    out[o] = find(variables, str2, ai);
                    ai = 0;
                    o++;
                    i++;
                }
            }
            else
            {
                if (queue[i] == '#')
                    out[o - 1] = r(out, o, queue[i]);
                else
                {
                    if (queue[i] == ' ')
                        i++;
                    out[o - 2] = r(out, o, queue[i]);
                    o = o - 1;
                }
                i += 2;
            }
    }
    return out[0];
}

// rpn





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


int main()
{
    var variables[SIZE];
    char formula[SIZE];
    FILE* inp = fopen("C:/Server/data/htdocs/calculator/uploades/1.txt", "r");
    int n;
    variables[0].name[0] = 'e';
    variables[0].val = 2.718281828459045235;
    variables[1].name[0] = 'p';
    variables[1].name[1] = 'i';
    variables[1].val = 3.1415926535897932384;
    fscanf(inp, "%d", &n);
    fscanf(inp, "%s", formula);
    printf("%s", formula);
    printf(" = ");
    for (int i = 0; i < n - 1; i++) {
        fscanf(inp, "%s = %s", variables[i + 2].name, variables[i + 2].formula);
        parser(&variables[i + 2]);
    }
    for (int i = n + 1; i >= 2; i--) {
        if (variables[i].mar == 1) {
            variables[i].val = rpn(strcat(variables[i].formula, " "), variables);
        }
    }
    //variables[2].val = rpn(strcat(variables[2].formula," "), variables);
    //variables[1].val = rpn(strcat(variables[1].formula," "), variables);
    //variables[0].val = rpn(strcat(variables[0].formula," "), variables);

    double itog = rpn(strcat(formula, " "), variables);
    if (itog == -0)
        itog = 0;
    printf("%f", itog);
}