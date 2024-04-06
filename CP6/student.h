#ifndef _STUDENT_H_
#define _STUDENT_H_

#define STR_SIZE 24
#define INIT_SIZE 2
#define UNI_SIZE 50
#define WORK_SIZE 100
#define SERVICE_SIZE 100

typedef struct {
    char surname[STR_SIZE];
    char initials[INIT_SIZE];
    char gender;
    int classNumber;
    char classLetter;
    char university[UNI_SIZE];
    char workplace[WORK_SIZE];
    char militaryService[SERVICE_SIZE];
} Student;

#endif
