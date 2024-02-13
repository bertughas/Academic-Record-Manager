#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[25];
    char surname[25];
    int midterm;
    int final;
};

void addNewRecord(struct Student **stuPtr, int *recordCount, int newRecords) {
    *stuPtr = (struct Student*)realloc(*stuPtr, (*recordCount + newRecords) * sizeof(struct Student));
    for (int i = *recordCount; i < *recordCount + newRecords; i++) {
        printf("\nStudent ID:");
        scanf("%d", &((*stuPtr)[i].id));
        printf("Student Name:");
        scanf("%s", (*stuPtr)[i].name);
        printf("Student Surname:");
        scanf("%s", (*stuPtr)[i].surname);
        printf("Student Midterm Grade:");
        scanf("%d", &((*stuPtr)[i].midterm));
        printf("Student Final Grade:");
        scanf("%d", &((*stuPtr)[i].final));
    }
    *recordCount += newRecords;
}

void listRecords(struct Student *stuPtr, int *recordCount) {
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < *recordCount; i++) {
        printf("Student ID: %d\n", stuPtr[i].id);
        printf("Student Name: %s\n", stuPtr[i].name);
        printf("Student Surname: %s\n", stuPtr[i].surname);
        printf("Student Midterm Grade: %d\n", stuPtr[i].midterm);
        printf("Student Final Grade: %d\n", stuPtr[i].final);
        printf("******************\n\n");
    }
}

void updateRecord(struct Student **stuPtr, int *recordCount, int studentID) {
    int found = 0;
    printf("\nStudent ID to update: %d\n", studentID);
    for (int i = 0; i < *recordCount; i++) {
        if ((*stuPtr)[i].id == studentID) {
            printf("New student ID:");
            scanf("%d", &((*stuPtr)[i].id));
            printf("New student Name:");
            scanf("%s", (*stuPtr)[i].name);
            printf("New student Surname:");
            scanf("%s", (*stuPtr)[i].surname);
            printf("New student Midterm Grade:");
            scanf("%d", &((*stuPtr)[i].midterm));
            printf("New student Final Grade:");
            scanf("%d", &((*stuPtr)[i].final));
            printf("******************\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Student with given ID not found.\n");
    }
}

float calculateAverage(struct Student *stuPtr, int *recordCount) {
    float total = 0;
    for (int i = 0; i < *recordCount; i++) {
        total += (stuPtr[i].midterm * 0.4) + (stuPtr[i].final * 0.6);
    }
    return total / (*recordCount);
}

void findBestStudent(struct Student *stuPtr, int *recordCount) {
    int bestGrade = (stuPtr[0].midterm * 0.4) + (stuPtr[0].final * 0.6);
    int bestIndex = 0;
    for (int i = 1; i < *recordCount; i++) {
        int grade = (stuPtr[i].midterm * 0.4) + (stuPtr[i].final * 0.6);
        if (grade > bestGrade) {
            bestGrade = grade;
            bestIndex = i;
        }
    }
    printf("Best Student Information:\n");
    printf("Student ID: %d\n", stuPtr[bestIndex].id);
    printf("Student Name: %s\n", stuPtr[bestIndex].name);
    printf("Student Surname: %s\n", stuPtr[bestIndex].surname);
    printf("Student Average Grade: %.2f\n", (float)(bestGrade));
}

int main() {
    struct Student *studentRecords = NULL;
    int recordCount = 0;

    while (1) {
        int choice;
        printf("\n1-Add New Record\n");
        printf("2-List Records\n");
        printf("3-Update Record\n");
        printf("4-Calculate Class Average\n");
        printf("5-Find Best Student\n");
        printf("6-Exit\n");
        printf("Your Choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                printf("How many new records do you want to add?");
                int newRecords;
                scanf("%d", &newRecords);
                addNewRecord(&studentRecords, &recordCount, newRecords);
                break;
            case 2:
                system("cls");
                listRecords(studentRecords, &recordCount);
                break;
            case 3:
                system("cls");
                printf("Enter the student ID to update:");
                int studentID;
                scanf("%d", &studentID);
                updateRecord(&studentRecords, &recordCount, studentID);
                break;
            case 4:
                system("cls");
                printf("Class Average: %.2f\n", calculateAverage(studentRecords, &recordCount));
                break;
            case 5:
                system("cls");
                findBestStudent(studentRecords, &recordCount);
                break;
            case 6:
                system("cls");
                printf("Exiting the program...\n");
                exit(0);
            default:
                system("cls");
                printf("Invalid choice. Try again.\n");
        }
    }

    free(studentRecords);
    return 0;
}
