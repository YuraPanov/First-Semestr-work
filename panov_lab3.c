//
// Created by yura0 on 18.11.2022.
//
#include <stdio.h>
int PEREVOD_ABBA(int c, int i) {
    int b = (c >> (32 - ((i + 1) * 4)));
    int cur = b & 0xF;
    return (cur == 10) ? ('A') : (cur == 11) ? ('B') : (0);
}
int ABBA(int A[8][8],int i, int j,int vhod) {
    int s = 0;
    switch (vhod) {
        case 1:
            if ((j + 1 <= 7) && (A[i][j + 1] == 'B'))
                s += ABBA(A, i, j + 1, 2);
            if ((j - 1 >= 0) && (A[i][j - 1] == 'B'))
                s += ABBA(A, i, j - 1, 2);
            if ((i + 1 <= 7) && (A[i + 1][j] == 'B'))
                s += ABBA(A, i + 1, j, 2);
            if ((i - 1 >= 0) && (A[i - 1][j] == 'B'))
                s += ABBA(A, i - 1, j, 2);
            return s;
        case 2:
            if ((j + 1 <= 7) && (A[i][j + 1] == 'B'))
                s += ABBA(A, i, j + 1, 3);
            if ((j - 1 >= 0) && (A[i][j - 1] == 'B'))
                s += ABBA(A, i, j - 1, 3);
            if ((i + 1 <= 7) && (A[i + 1][j] == 'B'))
                s += ABBA(A, i + 1, j, 3);
            if ((i - 1 >= 0) && (A[i - 1][j] == 'B'))
                s += ABBA(A, i - 1, j, 3);
            return s;
        case 3:
            if ((j + 1 <= 7) && (A[i][j + 1] == 'A'))
                s += 1;
            if ((j - 1 >= 0) && (A[i][j - 1] == 'A'))
                s += 1;
            if ((i + 1 <= 7) && (A[i + 1][j] == 'A'))
                s += 1;
            if ((i - 1 >= 0) && (A[i - 1][j] == 'A'))
                s += 1;
            return s;
    }
}
int main() {
    int colvo = 0; int A[8][8];
    int sample1[8] = {-1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592};
    int sample2[8] = {-1430650880, -1157627904, 3145728, -1442185216, 184549376, 11534336, 655360, 3840};
    //// перевод чисел в 16-ричную систему
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            A[i][j] = PEREVOD_ABBA(sample1[i], j);
        }
    }
    //// отрисовка матрицы
    for (int i = 0; i != 8; i++){
        for(int j = 0; j != 8; j++){
            printf("%s ", (A[i][j] == 65 ? "A" : (A[i][j] == 66 ? "B" : "-")));
        }
        printf("\n");
    }
    //// подсчёт кол-во ABBA
    for (int i = 0; i != 8; i++){
        for(int j = 0; j != 8; j++) {
            if(A[i][j] == 'A')
                colvo += ABBA(A, i, j, 1);
        }
    }
   printf("%d",  colvo / 2);
}