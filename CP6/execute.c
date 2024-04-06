#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "student.h"

void count_students_difference(FILE *in, int p_class) {
    Student s;
    int count_p_classes = 0;
    int count_10_classes = 0;

    while (student_read_bin(&s, in)) {
        if (s.classNumber == p_class) {
            count_p_classes++;
        } else if (s.classNumber == 10) {
            count_10_classes++;
        }
    }

    if (p_class == 10) {
        printf("The number of students in class 10 is equal to the number in 10th class.\n");
    } else {
        int difference = count_p_classes - count_10_classes;
        if (difference > 0) {
            printf("There are %d more students in class %d than in 10th class.\n", difference, p_class);
        } else if (difference < 0) {
            printf("There are %d fewer students in class %d than in 10th class.\n", -difference, p_class);
        } else {
            printf("The number of students in class %d is equal to the number in 10th class.\n", p_class);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage:\n\t./execute DB_FILE P_CLASS\n");
        exit(0);
    }

    int p_class = atoi(argv[2]);
    FILE *in = fopen(argv[1], "rb");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    count_students_difference(in, p_class);

    fclose(in);

    return 0;
}

