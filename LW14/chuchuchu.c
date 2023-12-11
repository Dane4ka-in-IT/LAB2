#include <stdio.h>

int main() {
    int matrix[7][7];
    int n;
    scanf("%d", &n);
    if (n == 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int rot = 0;
    int vert2 = n-1;
    int hor2 = n-1;

    int vert = n-1;
    int vert3;
    int hor3;
    int ii;
    int loop = 0;
    printf("%d ", matrix[vert2][hor2]);
    int prints = 1;
    // (；￣Д￣)
    while (loop <= n) {
        loop++;
        if (prints == n*n) {
            return 0;
        }
        if (rot == 0) {
            printf("%d ", matrix[vert-1][vert2]);
            prints++;
            if (prints == n*n) {
                return 0;
            }
            vert3 = vert - 1;
            for (int i = 1; i <= loop; i++) {
                printf("%d ", matrix[vert3][hor2-i]);
                prints++;
                if (prints == n*n) {
                    return 0;
                }
                hor3 = hor2-i;
            }
            for (int i = 1; i <= loop; i++) {
                printf("%d ", matrix[vert3+i][hor3]);
                prints++;
                if (prints == n*n) {
                    return 0;
                }
                ii = i;
            }
            printf("%d ", matrix[vert3+ii][hor3-1]);
            prints++;
            if (prints == n*n) {
                return 0;
            }
            rot = 1;
        } else {
            for (int i = 0; i <= loop-1; i++) {
                printf("%d ", matrix[vert3-i+loop-2][hor3-1]);
                prints++;
                if (prints == n*n) {
                    return 0;
                }
                vert = vert3-i+loop-2;
            }
            for (int i = 1; i <= loop; i++) {
                printf("%d ", matrix[vert][hor3-1+i]);
                prints++;
                if (prints == n*n) {
                    return 0;
                }
            }
            rot = 0;
        }
    }

    return 0;
}