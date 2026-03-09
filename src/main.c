/* Author: Maria Basarimova */

/* Client file: Demonstrates usage of stud module.
 * Inputs students, processes them, and outputs results.
 */

#include "stud.h"

int main(void) {
    STUD students[MAX_STUDENTS];
    FilteredStudent filtered[MAX_STUDENTS];
    int filtered_count;

    /* Input students */
    input_students(students);

    /* Sort by name (alphabetically) */
    sort_by_name(students);

    /* Filter and get count */
    filtered_count = filter_high_avg(students, filtered);

    /* Sort filtered by avg */
    sort_by_avg(filtered, filtered_count);

    /* Print results */
    print_filtered(filtered, filtered_count);

    return 0;
}
