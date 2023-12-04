#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum _kState {
	START,
    NUMBER,
    CHECKNUM,
    BADNUM
} kState;

int isPartOfNumber(int ch);
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
    char prevChar = '\0';

    while (*str) {
        char currentChar = *str;

    
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