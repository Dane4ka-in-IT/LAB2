#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int x, int y) {
    return (x < y) ? x : y;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int mod(int a, int b) {
    return a - floor(a / b) * b;
}

int inArea(double x, double y) {
    double x1 = -10, y1 = 0;
    double x2 = 0, y2 = 10;
    double x3 = -10, y3 = 20;

    double denom = (y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3);
    double u = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / denom;
    double v = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / denom;
    double w = 1 - u - v;

    return (u >= 0 && v >= 0 && w >= 0 && u <= 1 && v <= 1 && w <= 1);
}

int main() {
    int i, j, l, k, hit;
    i = 29;
    j = -6;
    l = 1;
    hit = -1;

    for (k = 1; k <= 50; k++) {
        i = mod(min(max(min(i - j, i - l), j - l), i - k), 30);
        j = mod(max(min(max(i - j, i - l), j - l), i - k), 30);
        l = mod(i, 30) - mod(j, 30) + mod(l, 30) - mod(k, 30);

        if (inArea(i, j)) {
            printf("Точка %d: (%d, %d)\n", k, i, j);
            hit = k;
            break;
        }
    }

    printf("Время окончания движения: %d\n", hit);
    printf("Значение динамического параметра: %d\n", l);

    return 0;
}
