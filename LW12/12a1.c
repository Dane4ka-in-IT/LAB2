#include <stdio.h>
#include <stdlib.h>

int hasSameAdjacentDigits(int number) {
    number = abs(number);  // Применяем модуль для учета отрицательных чисел
    int prevDigit = number % 10;
    number /= 10;

    while (number > 0) {
        int currentDigit = number % 10;
        if (currentDigit == prevDigit) {
            return 1;
        }

        prevDigit = currentDigit;
        number /= 10;
    }

    return 0;
}

int main() {
    int inputNumber;

    while (scanf("%d", &inputNumber) != EOF) {
        int result = hasSameAdjacentDigits(inputNumber);

        if (result) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
