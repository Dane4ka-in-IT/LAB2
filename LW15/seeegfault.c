#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("input.txt", "r");
    int min_val = 2147483647; // Assuming integer range
    int min_row = -1;
    char ch;
    int n;

    // find matrix order
    while((ch = fgetc(file)) != '\n') {
        if (ch == ' ') {
            n++;
        }
    }
    n++;
    //printf("%d", n);

    rewind(file); // go back
    int arr[n][n];

    // Read from file and find minimal element and corresponding row
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

    // Reverse the row with the minimum element
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int temp = arr[min_row][start];
        arr[min_row][start] = arr[min_row][end];
        arr[min_row][end] = temp;

        start++;
        end--;
    }

    // Print the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
