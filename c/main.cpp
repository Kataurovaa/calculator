#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define SIZE 100

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

	int schet(int arr[], int a)
	{
		int s, sum, q, b;
		sum = 0;
		s = 0;
		q = 1;
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

		case '1':
		case '^':
			return 3;
			break;
		}
	}

	int r(int a[], int o, char znak)
	{
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
			int cons = a[o - 2];
			while (a[o - 1] > 1)
			{
				a[o - 2] = a[o - 2] * cons;
				a[o - 1] = a[o - 1] - 1;
			}
			return a[o - 2];
			break;

		case '>':
			a[o - 1] = a[o - 1] - 2 * a[o - 1];
			return a[o - 1];
			break;
		}
	}


	int main() {
		char str[SIZE], stack[SIZE], queue[SIZE];
		int prip = -1, pric, s = 0, i, q = 0, ai = 0, o = 0, a[SIZE], out[SIZE];
		fgets(str, SIZE, stdin);
		printf("Expression:\n");
		for (i = 0; i < strlen(str); i++)
			printf("%c", str[i]);
		for (i = 0; i < strlen(str);)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				while (str[i] >= '0' && str[i] <= '9')
				{
					insert(queue, &q, str[i]);
					i++;
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
				{
					if (str[i] == '(' && i + 1 < strlen(str) + 1 && str[i + 1] == '-')

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
				if (pric > prip)
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
							prip = priority(stack[s - 2]);
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
		while (i < q)
		{
			if (queue[i] >= '0' && queue[i] <= '9')
			{
				while (queue[i] >= '0' && queue[i] <= '9')
				{
					a[ai] = queue[i] - '0';
					i++;
					ai++;
				}
				out[o] = schet(a, ai);
				ai = 0;
				o++;
				i++;
			}
			else
			{
				out[o - 2] = r(out, o, queue[i]);
				o = o - 1;
				i += 2;
			}
		}


    return 0;
}

