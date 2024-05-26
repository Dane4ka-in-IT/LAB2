#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int key;
    char value[100];
} Table;

void swap(Table *a, Table *b) {
    Table temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(Table arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j].key < arr[min_idx].key)
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

int binarySearch(Table arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid].key == x)
            return mid;

        if (arr[mid].key > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int countLinesInFile(char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening %s\n", filename);
        return -1;
    }

    int count = 0;
    char c;
    for (c = getc(file); c != EOF; c = getc(file)) {
        if (c == '\n') {
            count = count + 1;
        }
    }

    fclose(file);
    return count;
}

void readAsciiArtFromFile(char* filename, char asciiArt[][100], int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening %s\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        if (fgets(asciiArt[i], 100, file) == NULL) {
            break;
        }

        asciiArt[i][strcspn(asciiArt[i], "\n")] = 0;
    }

    fclose(file);
}

void printTable(Table arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Key: %d, Value: %s\n", arr[i].key, arr[i].value); 
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    int size = countLinesInFile(filename);
    if (size == -1) {
        return 1;
    }

    char asciiArt[size][100];
    readAsciiArtFromFile(filename, asciiArt, size);

    Table arr[size];
    srand(time(0));

    int choice;
    printf("Select a case:\n1. Elements are ordered\n2. Elements are in reverse order\n3. Elements are unordered\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            for (int i = 0; i < 8; i++) {
                arr[i].key = i; 
                strncpy(arr[i].value, asciiArt[i], 100);
            }
            break;
        case 2:
            for (int i = 0; i < 8; i++) {
                arr[i].key = 8 - i; 
                strncpy(arr[i].value, asciiArt[i], 100);
            }
            break;
        case 3:
            for (int i = 0; i < 8; i++) {
                arr[i].key = rand() % 100;
                strncpy(arr[i].value, asciiArt[i], 100);
            }
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("Initial table:\n");
    printTable(arr, 8);

    selectionSort(arr, 8);

    printf("Sorted table:\n");
    printTable(arr, 8);

    int searchKey;
    printf("Enter a search key: ");
    scanf("%d", &searchKey); 
    int result = binarySearch(arr, 0, 7, searchKey);

    if (result != -1) {
        printf("Element found at index %d\n", result);
        printf("Key: %d, Value: %s\n", arr[result].key, arr[result].value);
    } else {
        printf("Element not found in array\n");
    }

    return 0;
}
