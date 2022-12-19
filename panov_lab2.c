////
//// Created by Yura Panov on 10.11.2022.
////(づ￣ 3￣)づ
#include <stdio.h>

int KalkulX(char *sign) {   //// Калькулятор для простейших уравнений.
    if (sign[0] == 'x') {
        if (sign[1] == '=') { //// для уравнений вида x = 4 + 2.
            return (sign[3] == '+' ? (sign[2] - '0') + (sign[4] - '0') :
                    sign[3] == '-' ? (sign[2] - '0') - (sign[4] - '0') :
                    sign[3] == '*' ? (sign[2] - '0') * (sign[4] - '0') :
                    sign[3] == '/' ? (sign[2] - '0') / (sign[4] - '0') : 0);
        } else {              //// для уравнений вида x + 4 = 2.
            return (sign[1] == '+' ? (sign[4] - '0') - (sign[2] - '0') :
                    sign[1] == '-' ? (sign[4] - '0') + (sign[2] - '0') :
                    sign[1] == '*' ? (sign[4] - '0') / (sign[2] - '0') :
                    sign[1] == '/' ? (sign[4] - '0') * (sign[2] - '0') : 0);
        }
    }
    if (sign[2] == 'x') {
        if (sign[3] == '=') { //// для уравнений вида 4 + x = 2
            return (sign[1] == '+' ? (-1 * (sign[0] - '0')) + (sign[4] - '0') :
                    sign[1] == '-' ? (sign[0] - '0') - (sign[4] - '0') :
                    sign[1] == '*' ? (sign[0] - '0') / (sign[4] - '0') :
                    sign[1] == '/' ? (sign[0] - '0') / (sign[4] - '0') : 0);
        } else {              //// для уравнений вида 4 = x + 2
            return (sign[3] == '+' ? (sign[0] - '0') - (sign[4] - '0') :
                    sign[3] == '-' ? (sign[0] - '0') + (sign[4] - '0') :
                    sign[3] == '*' ? (sign[0] - '0') / (sign[4] - '0') :
                    sign[3] == '/' ? (sign[0] - '0') * (sign[4] - '0') : 0);
        }
    }
    if (sign[4] == 'x') {
        if (sign[3] == '=') { //// для уравнений вида 4 + 2 = x
            return (sign[1] == '+' ? (sign[0] - '0') + (sign[2] - '0') :
                    sign[1] == '-' ? (sign[0] - '0') - (sign[2] - '0') :
                    sign[1] == '*' ? (sign[0] - '0') * (sign[2] - '0') :
                    sign[1] == '/' ? (sign[0] - '0') / (sign[2] - '0') : 0);
        } else {              //// для уравнений вида 4 = 2 + x
            return (sign[3] == '+' ? (sign[0] - '0') - (sign[2] - '0') :
                    sign[3] == '-' ? (sign[0] - '0') - (sign[2] - '0') :
                    sign[3] == '*' ? (sign[0] - '0') / (sign[2] - '0') :
                    sign[3] == '/' ? (sign[0] - '0') / (sign[2] - '0') : 0);
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char *expression[] = {"2+x=5",
                          "x+2=5",
                          "2+x=5",
                          "x-5=2",
                          "5-x=2",
                          "x=5*2",
                          "x*5=9",
                          "9*9=x",
                          "x=9/3",
                          "x/2=5",
                          "4=x*2",
                          "4=x/2",
                          "9/x=5"};
    int len = sizeof(expression) / sizeof(char *);
    for (int i = 0; i < len; i++)
        printf("%s x=%d\n", expression[i], KalkulX(expression[i]));
}