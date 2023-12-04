# Отчет по лабораторной работе № 11
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Нургалиев Даниэль Ильдарович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Системы программирования на языке Си
2. **Цель работы**: выделить все 11-ричные числа с лексиграфическим возрастанием цифр
3. **Задание**: 11 вариант
4. **Идея, метод, алгоритм решения задачи**: написать программу, разделённую на 2 части: 1 содержит условия, которые покажут нам имена существительные. 2 содержит ввод и вывод данных.
5. **Сценарий выполнения работы**: выполнить программу через терминал
6. **Протокол**: 

```
rombica@DESKTOP-C383C55 MINGW64 ~
$ cd GIT-projekt/LW11 && ls
laba11.exe*  laba11.md  mian.c

rombica@DESKTOP-C383C55 MINGW64 ~/GIT-projekt/LW11 (master)
$ echo Код && cat mian.c && echo && echo Вывод && gcc --std=c99 --pedantic -o laba11 mian.c && ./laba11.exe
Код
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum _kState {
        START,
    NUMBER,
    CHECKNUM,
    BADNUM
} kState;

int isSpace(int ch);
int isPartOfNumber(int ch);
void addFinal(int ***dynamicArray, int *newArray, int *size);
void addCharacter(char **str, char ch);
void appendElement(char ***array, const char *newElement, int *size);
int isIncreasingInLexOrder(char* str);

int main(void) {
    int ch;
    char *number = NULL;
    char **dynamicArray = NULL;
    int size = 0;
        kState state = START;
    while ((ch = getchar()) != EOF) {
        switch(state) {
            case START: {
                addCharacter(&number, ch);
                state = NUMBER;
            }
            break;

            case NUMBER: {
                if (isPartOfNumber(ch)) {
                    addCharacter(&number, ch);
                } else if (ch == '\n' || ch == ' ') {
                    state = CHECKNUM;
                } else {
                    state = BADNUM;
                }
            }
            break;

            case CHECKNUM: {
                addCharacter(&number, '\0');

                if (isIncreasingInLexOrder(number)) {
                    appendElement(&dynamicArray, number, &size);
                }
                number = NULL;
                addCharacter(&number, ch);

                state = NUMBER;
            }
            break;

            case BADNUM: {
                number = NULL;
                if (ch == '\n' || ch == ' ') {
                    state = NUMBER;
                }
            }
        }
    }
    addCharacter(&number, '\0');

    if (isIncreasingInLexOrder(number)) {
        appendElement(&dynamicArray, number, &size);
    }
    number = NULL;
    for (int i = 0; i < size; i++) {
        printf("%s\n", dynamicArray[i]);
    }
}
int isIncreasingInLexOrder(char* str) {
    char prevChar = '\0'; // Initialize prevChar with a character outside the valid range

    while (*str) {
        char currentChar = *str;

        // Check if characters are in increasing order
        if (currentChar <= prevChar) {
            return 0;
        }

        prevChar = currentChar;
        str++;
    }

    return 1;
}
void appendElement(char ***array, const char *newElement, int *size) {
    (*size)++;
    *array = (char **)realloc(*array, *size * sizeof(char *));

    (*array)[*size - 1] = (char *)malloc((strlen(newElement) + 1) * sizeof(char));
    strcpy((*array)[*size - 1], newElement);
}

void addCharacter(char **str, char ch) {
    int len = (*str) ? strlen(*str) : 0;
    *str = (char *)realloc(*str, len + 2);
    (*str)[len] = ch;
    (*str)[len + 1] = '\0';
}

int isPartOfNumber(int ch) {
    return ((ch >= '0' && ch <= '9') || ch == '-' || ch == '-' || ch == 'A');
}

int isSpace(int ch) {
        return (ch == ' ' || ch == ',' || ch == '\t');
}
Вывод
12345 246 689 0987 6543

12345
246
689

```
8. **Выводы**: Работа расширила мои знания в языке С.
