#include <stdio.h>
#include <string.h>
double polynom(const char *expr, double x){
    double y = 0, Vir = 0, Arg = 1;
    int PointN = 0, FL = 0, FLM = 0, len = strlen(expr);
    for(int i = 0; expr[i] != 0; i++) {
        if (expr[i] == '-')
            FLM = 1;
        if ((((expr[i] != ' ') && (expr[i] != '-') && (expr[i] != '+')) && ((expr[i - 1] == '-') || (expr[i - 1] == '+') || (expr[i - 1] == ' '))) || (i - 1 < 0))
            PointN = i, FL = 1;
        if ((FL == 1) && (((expr[i] != ' ') && (expr[i] != '-') && (expr[i] != '+')) && ((expr[i + 1] == '-') || (expr[i + 1] == '+') || (expr[i + 1] == ' ')) || (i + 1 == len))) {
            for (PointN; PointN <= i; PointN++) {
                double x1 = x;
                if(expr[PointN] == '*')
                    Arg = Vir;
                if(expr[PointN] == 'x'){
                    if(expr[PointN + 1] == '^')
                        x1 =  expr[PointN + 2] == '4' ? (x * x * x * x) :expr[PointN + 2] == '3' ? (x * x * x) :expr[PointN + 2] == '2' ? (x * x) :expr[PointN + 2] == '0' ? (1):x;
                    FLM ? (y += x1 * Arg * -1):(y += x1 * Arg);
                    FLM = 0, Vir = 0, Arg = 1;
                    break;
                }
                else
                    Vir = Vir * 10 + (expr[PointN] - '0');
            }
            FLM ? (y += Vir * -1):(y += Vir);
            FLM = 0, Vir = 0, FL = 0;
        }
    }
    return y;
}
int main() {
    const char *expr[] = {"-x^4 + 5", "x^4 + 15*x^3 - 3*x^2 + x - 2", "-22 + 5*x^3 + x", "-45 - 21", "-72*x^4 + 14*x + 6 - x^3 + 2*x"};
    double x = 1;
    for (int i = 0; i < 100; i++)
        printf("y(%f)=%s returns %f\n", x, expr[i], polynom(expr[i], x));
}