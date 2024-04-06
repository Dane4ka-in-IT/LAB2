#include <stdio.h>
#include <stdlib.h>

#include "student.h"


#include "student.h"
#include <string.h>

int student_read_txt(Student *s, FILE *in) {
    fscanf(in, "%s", s->surname);
    fscanf(in, "%s", s->initials);
    fscanf(in, " %c", &(s->gender));
    fscanf(in, "%d", &(s->classNumber));
    fscanf(in, " %c", &(s->classLetter)); 
    fscanf(in, "%s", s->university);
    fscanf(in, "%s", s->workplace);
    fscanf(in, "%s", s->militaryService);

    return !feof(in);
}

int student_read_bin(Student *s, FILE *in)
{
    fread(s->surname, sizeof(char), STR_SIZE, in);
    fread(s->initials, sizeof(char), INIT_SIZE, in);
    fread(&(s->gender), sizeof(char), 1, in);
    fread(&(s->classNumber), sizeof(int), 1, in);
    fread(&(s->classLetter), sizeof(char), 1, in);
    fread(s->university, sizeof(char), UNI_SIZE, in);
    fread(s->workplace, sizeof(char), WORK_SIZE, in);
    fread(s->militaryService, sizeof(char), SERVICE_SIZE, in);

    return !feof(in);
}

void student_write_bin(Student *s, FILE *out)
{
    fwrite(s->surname, sizeof(char), STR_SIZE, out);
    fwrite(s->initials, sizeof(char), INIT_SIZE, out);
    fwrite(&(s->gender), sizeof(char), 1, out);
    fwrite(&(s->classNumber), sizeof(int), 1, out);
    fwrite(&(s->classLetter), sizeof(char), 1, out);
    fwrite(s->university, sizeof(char), UNI_SIZE, out);
    fwrite(s->workplace, sizeof(char), WORK_SIZE, out);
    fwrite(s->militaryService, sizeof(char), SERVICE_SIZE, out);
}

void student_print(Student *s)
{
    printf("Surname: %s\n", s->surname);
    printf("Initials: %s\n", s->initials);
    printf("Gender: %c\n", s->gender);
    printf("Class Number: %d\n", s->classNumber);
    printf("Class Letter: %c\n", s->classLetter);
    printf("University: %s\n", s->university);
    printf("Workplace: %s\n", s->workplace);
    printf("Military Service: %s\n", s->militaryService);
    printf("\n");
}
