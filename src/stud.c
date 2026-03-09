/* Author: Maria Basarimova */

/* This file implements server-side logic for student management:
 * - Input students
 * - Sort by name
 * - Calculate average grade
 * - Filter by high average
 * - Sort by average
 * - Print filtered students
 */

#include "stud.h"

/* Input 10 students from keyboard */
void input_students(STUD arr[]) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Name (surname initials): ");
        scanf("%s", arr[i].name);
        printf("  Group: ");
        scanf("%s", arr[i].group);
        printf("  Grades (4 values): ");
        for (int j = 0; j < 4; j++) {
            scanf("%f", &arr[i].ses[j]);
        }
    }
}

/* Sort array by name alphabetically (bubble sort) */
void sort_by_name(STUD arr[]) {
    for (int i = 0; i < MAX_STUDENTS - 1; i++) {
        for (int j = 0; j < MAX_STUDENTS - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                STUD temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* Calculate average grade */
float calculate_avg(float grades[]) {
    float sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += grades[i];
    }
    return sum / 4;
}

/* Filter students with avg > 4.2, store with original index */
int filter_high_avg(STUD arr[], FilteredStudent filtered[]) {
    int count = 0;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        float avg = calculate_avg(arr[i].ses);
        if (avg > 4.2) {
            filtered[count].student = arr[i];
            filtered[count].original_index = i + 1; /* 1-based index */
            filtered[count].avg_grade = avg;
            count++;
        }
    }
    return count;
}

/* Sort filtered array by increasing avg (bubble sort) */
void sort_by_avg(FilteredStudent arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].avg_grade > arr[j + 1].avg_grade) {
                FilteredStudent temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* Print filtered students with original position */
void print_filtered(FilteredStudent arr[], int size) {
    if (size == 0) {
        printf("No students with average grade > 4.2.\n");
        return;
    }
    printf("\nStudents with avg > 4.2 (sorted by avg):\n");
    for (int i = 0; i < size; i++) {
        printf("Original pos: %d, Name: %s, Group: %s, Avg: %.2f\n",
               arr[i].original_index, arr[i].student.name,
               arr[i].student.group, arr[i].avg_grade);
        printf("  Grades: %.1f %.1f %.1f %.1f\n",
               arr[i].student.ses[0], arr[i].student.ses[1],
               arr[i].student.ses[2], arr[i].student.ses[3]);
    }
}
