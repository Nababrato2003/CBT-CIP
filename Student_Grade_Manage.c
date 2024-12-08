#include <stdio.h>
#include <string.h>


#define MAX_STU 200
#define MAX_SUB 12

typedef struct {
    char name[30];
    float scores[MAX_SUB];
    double average;
    float highest;
    float lowest;
} Student;

void Performance(Student *student, int subjectno) {
    float sum = 0;

    // Initialization 
    student->highest = student->scores[0];
    student->lowest = student->scores[0];

    
    for (int i = 0; i < subjectno; i++) {
        sum += student->scores[i];

        if (student->scores[i] > student->highest)
            student->highest = student->scores[i];

        if (student->scores[i] < student->lowest)
            student->lowest = student->scores[i];
    }

    student->average = sum / subjectno;
}

void Summary(Student students[], int studentCount, int subjectCount) {
    printf("\nSummary of Student's Performance\n");
    for (int i = 0; i < studentCount; i++) {
        printf("\nStudent Name: %s\n", students[i].name);
        printf("Average Score of the student: %.2f\n", students[i].average);
        printf("Highest Score of the student: %.2f\n", students[i].highest);
        printf("Lowest Score of the student: %.2f\n", students[i].lowest);
    }
}



int main() {
    Student students[MAX_STU];
    int studentCount, subjectCount;

    
    printf("Enter the number of students: ");
    scanf("%d", &studentCount);

    
    if (studentCount <= 0 || studentCount > MAX_STU) {
        printf("Error: Invalid number of students.\n");
        return 1;
    }
    printf("Enter the number of subjects: ");
    scanf("%d", &subjectCount);
    if (subjectCount <= 0 || subjectCount > MAX_SUB) {
        printf("Error: Invalid number of subjects.\n");
        return 1;
    }

    for (int i = 0; i < studentCount; i++) {
        printf("\nEnter the name of student %d: ", i + 1);
        getchar(); 
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; 

        printf("Enter scores for %d subjects of the student :- \n", subjectCount);
        printf("\n");
        for (int j = 0; j < subjectCount; j++) {
            printf("Score for subject %d: ", j + 1);
            scanf("%f", &students[i].scores[j]);
        }
        Performance(&students[i], subjectCount);
    }


    Summary(students, studentCount, subjectCount);

    return 0;
}
