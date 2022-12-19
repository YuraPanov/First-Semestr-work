//
// Created by Панов Юрий on 21.10.2022.
//
#define N 6
#include <stdio.h>

int main(int argc, char *argv[]) {
    int matr[N][N] = {0};
    int i = 1; int j = 0; int num = 2; int FL = 0; int numstl = 1;
    matr[0][0] = 1; matr[1][0] = 2;
    while (num <= N * N) {
        num++;
        if (N % 2 != 0) { //// Для нечётных матриц
            if ((numstl % 2 != 0) && (FL == 0) && (i > 0) && (j != N - 1)) { //// движение по нечетной диагонали
                j++; i--; matr[i][j] = num;
            } else if ((i == 0) && (j > 0) && (FL == 0)) { //// переход вправо в Левой части матрицы
                j++; matr[i][j] = num; FL = 1; numstl = j;
            } else if ((numstl % 2 == 0) && (FL == 1) && (j > 0) && (i != N - 1)) { //// движение по четной диагонали
                i++; j--; matr[i][j] = num;
            } else if ((j == 0) && (i > 0) && (FL == 1) && (i <= N - 2)) { //// переход вниз в Левой части матрицы
                i++; matr[i][j] = num; FL = 0; numstl = i;
            } else if ((i == N - 1) && (FL == 1)) { //// переход вправо в Правой части матрицы
                j++; matr[i][j] = num; FL = 0; numstl = j;
            } else if ((i % 2 != 0) && (FL == 0)) { //// переход вниз в Правой части матрицы
                i++; matr[i][j] = num; FL = 1; numstl = i;
            }
        }
        else { //// Для чётных матриц
            if ((numstl % 2 != 0) && (FL == 0) && (i > 0) && (j != N - 1)) { //// движение по нечетной диагонали
                j++; i--; matr[i][j] = num;
            }
            else if ((i == 0) && (j > 0) && (FL == 0) && (j != N - 1)) { //// переход вправо в Левой части матрицы
                j++; matr[i][j] = num; FL = 1; numstl = j;
            }
            else if ((numstl % 2 == 0) && (FL == 1) && (j > 0) && (i != N - 1)) { //// движение по четной диагонали
                i++; j--; matr[i][j] = num;
            }
            else if ((j == 0) && (i > 0) && (FL == 1) && (i <= N - 2)) { //// переход вниз в Левой части матрицы
                i++; matr[i][j] = num; FL = 0; numstl = i;
            }
            else if ((i % 2 == 0) && (FL == 0)) { //// переход вниз в Правой части матрицы
                i++; matr[i][j] = num; FL = 1; numstl = j;
            }
            else if ((numstl % 2 != 0) && (FL == 1) && (i != N - 1)){ //// движение по Чётной диагонали
                i++; j--; matr[i][j] = num;
            }
            else if ((i == N - 1) && (FL == 1)) { //// переход вправо в Правой части матрицы
                j++; matr[i][j] = num; FL = 0; numstl = i;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", matr[i][j]);
        printf("\n");
        }
}