#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float scores[MAX_SUBJECTS];
    int subject_count;
    float average;
    float highest;
    float lowest;
} Student;

void inputStudentData(Student *student) {
    printf("Enter student name: ");
    scanf(" %[^\n]", student->name);
    
    printf("Enter number of subjects: ");
    scanf("%d", &student->subject_count);
    
    student->highest = -1.0; // Initialize to a low value
    student->lowest = 101.0; // Initialize to a high value
    float total = 0.0;

    for (int i = 0; i < student->subject_count; i++) {
        printf("Enter score for subject %d: ", i + 1);
        scanf("%f", &student->scores[i]);
        
        // Update total, highest, and lowest
        total += student->scores[i];
        if (student->scores[i] > student->highest) {
            student->highest = student->scores[i];
        }
        if (student->scores[i] < student->lowest) {
            student->lowest = student->scores[i];
        }
    }
    
    student->average = total / student->subject_count;
}

void displayStudentData(const Student *student) {
    printf("\nStudent Name: %s\n", student->name);
    printf("Scores: ");
    for (int i = 0; i < student->subject_count; i++) {
        printf("%.2f ", student->scores[i]);
    }
    printf("\nAverage Score: %.2f\n", student->average);
    printf("Highest Score: %.2f\n", student->highest);
    printf("Lowest Score: %.2f\n", student->lowest);
}

int main() {
    Student students[MAX_STUDENTS];
    int student_count = 0;
    char choice;

    do {
        if (student_count >= MAX_STUDENTS) {
            printf("Maximum number of students reached.\n");
            break;
        }
        
        inputStudentData(&students[student_count]);
        student_count++;

        printf("Do you want to enter another student? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nSummary of Student Performance:\n");
    for (int i = 0; i < student_count; i++) {
        displayStudentData(&students[i]);
    }

    return 0;
}
