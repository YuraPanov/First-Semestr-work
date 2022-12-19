#include <stdio.h>
#include <math.h>
float traverse_clockwise(float coord[], int n){
    float Perm = 0, CentrX = 0, CentrY = 0, Radius[2] = {0}, Ugli[51][3] = {{0,coord[0],coord[1]}};
    for(int i = 0;i < n * 2; i += 2)
        CentrX += coord[i], CentrY += coord[i + 1]; //// Координаты центра
    CentrX /= n ,CentrY /= n, Radius[0] = coord[0] - CentrX, Radius[1] = coord[1] - CentrY; //// находим Радиус векторы
    for(int j = 2; j < n * 2; j += 2) //// записываем массив векторов их углы координаты X и Y
        Ugli[j/2][0] = atan2f(Radius[0] + Radius[1], (coord[j] - CentrX) + (coord[j + 1] - CentrY)), Ugli[j / 2][1] = coord[j], Ugli[j / 2][2] = coord[j + 1];
    for (int x = 0; x < n; x++)   //// пузырьковая сортировка по углу
        for(int z = x; z < n; z++)
            if (Ugli[z][0] <= Ugli[x][0]){
                float Zapn[3] = {Ugli[x][0],Ugli[x][1],Ugli[x][2]};
                Ugli[x][0] = Ugli[z][0], Ugli[x][1] = Ugli[z][1], Ugli[x][2] = Ugli[z][2], Ugli[z][0] = Zapn[0], Ugli[z][1] = Zapn[1], Ugli[z][2] = Zapn[2];
            }
    for(int i = 0; i < n - 1; i++)
        Perm += sqrtf(powf(Ugli[i + 1][1] - Ugli[i][1],2) + powf(Ugli[i + 1][2] - Ugli[i][2],2)); //// находим периметр через длины векторов
    return Perm + sqrtf(powf(Ugli[0][1] - Ugli[n - 1][1],2) + powf(Ugli[0][2] - Ugli[n - 1][2],2)); //// добавляем к последней точек начальную
}
int main() {
    float rect[] = {1,5,7,1,7,5,1,1};
    float star[] = {3.97, 0.82, 2.26, 3.69, 5.39, 2.16, 2.03, 2.11, 5.36, 4.06};
    float enneagon[] = {76, 67.1, -8.3, 18, 55, 93.3, 77, 33, 21.3, 99, -20, 50, -8.3, 82, 55, 6.7, 21.3, 0.76};
    int n_rect = 4, n_star = 5, n_enne = 9;
    printf("Perimetr rect is %f\nPerimetr of star is %f\nPerimetr of enneagon is %f\n", traverse_clockwise(rect, n_rect), traverse_clockwise(star, n_star), traverse_clockwise(enneagon, n_enne));
}