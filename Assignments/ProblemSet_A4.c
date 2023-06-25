/*Write a program that will input student’s information (i.e. name, id, cgpa) who have enrolled
for CSE-207 course in Summer 2020. You have to declare a pointer variable to input the
information and dynamically allocate memory for storing information of each students. After
taking input find out the student name who has obtained highest cgpa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    char name[50];
    int id;
    float cgpa;
};

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student *students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    for (int i = 0; i < numStudents; i++) {
        printf("Enter information for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("ID: ");
        scanf("%d", &(students[i].id));
        printf("CGPA: ");
        scanf("%f", &(students[i].cgpa));
        printf("\n");
    }

    float maxCGPA = students[0].cgpa;
    int maxIndex = 0;
    for (int i = 1; i < numStudents; i++) {
        if (students[i].cgpa > maxCGPA) {
            maxCGPA = students[i].cgpa;
            maxIndex = i;
        }
    }

    printf("Student with the highest CGPA:\n");
    printf("Name: %s\n", students[maxIndex].name);
    printf("ID: %d\n", students[maxIndex].id);
    printf("CGPA: %.2f\n", students[maxIndex].cgpa);

    free(students);

    return 0;
}
