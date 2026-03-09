/* Author: Maria Basarimova */

#ifndef STUD_H
#define STUD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define maximum array size per requirement */
#define MAX_STUDENTS 10

/* Structure declaration for student data */
typedef struct {
    char name[50];      /* Surname and initials */
    char group[20];     /* Group name (faculty, course, number) */
    float ses[4];       /* Grades array (4 elements) */
} STUD;

/* Extended structure for filtered students with original index */
typedef struct {
    STUD student;
    int original_index;
    float avg_grade;
} FilteredStudent;

/* Function declarations */
void input_students(STUD arr[]);
void sort_by_name(STUD arr[]);
float calculate_avg(float grades[]);
int filter_high_avg(STUD arr[], FilteredStudent filtered[]);
void sort_by_avg(FilteredStudent arr[], int size);
void print_filtered(FilteredStudent arr[], int size);

#endif /* STUD_H */
