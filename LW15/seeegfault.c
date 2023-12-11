#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("input.txt", "r");
    int min_val = 2147483647; 
    int min_row = -1;
    int n;

    fscanf(file, "%d", &n);
    int arr[n][n];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &arr[i][j]);
            if(arr[i][j] < min_val) {
                min_val = arr[i][j];
                min_row = i;
            }
        }
    }
    fclose(file);
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int temp = arr[min_row][start];
        arr[min_row][start] = arr[min_row][end];
        arr[min_row][end] = temp;

        start++;
        end--;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}