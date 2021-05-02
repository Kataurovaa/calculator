
#include "Parser.h";
#include "rpn.h";

int main()
{
    var variables[SIZE];
    char formula[SIZE];
    FILE* inp = fopen("C:/Server/data/htdocs/calculator/uploades/1.txt", "r");
    FILE* out = fopen("C:/Server/data/htdocs/calculator/calc/Release/out.txt", "w");
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
    fprintf(out,"%s", formula);
    fprintf(out," = ");
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
    fprintf(out, "%f", itog);
    for (int i = 0; i < n - 1; i++) {
        printf("\n%s = %s = %f", variables[i + 2].name, variables[i + 2].formula, variables[i + 2].val);
        fprintf(out, "\n%s = %s = %f", variables[i + 2].name, variables[i + 2].formula, variables[i + 2].val);
    }
}