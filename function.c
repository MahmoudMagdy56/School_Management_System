#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node* createNode(struct Data data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, struct Data data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Student List:\n");
    while (current != NULL) {
        printf("Name: %s %s\n", current->data.name.first, current->data.name.last);
        printf("Date of Birth: %d/%d/%d\n", current->data.dateofbirth.month, current->data.dateofbirth.day, current->data.dateofbirth.year);
        printf("ID: %d\n", current->data.ID);
        printf("Address: %s\n", current->data.Address);
        printf("Phone Number: %d\n", current->data.PhoneNumber);
        printf("\n");
        current = current->next;
    }
}

// Function to create a new student account
void NEW_STUDENT(struct Node** head) {
    struct Data newStudent;
    printf("Enter student details:\n");
    printf("First Name: ");
    scanf("%s", newStudent.name.first);
    printf("Last Name: ");
    scanf("%s", newStudent.name.last);
    printf("Date of Birth (MM DD YYYY): ");
    scanf("%d %d %d", &newStudent.dateofbirth.month, &newStudent.dateofbirth.day, &newStudent.dateofbirth.year);
    printf("ID: ");
    scanf("%d", &newStudent.ID);
    printf("Address: ");
    scanf("%s", newStudent.Address);
    printf("Phone Number: ");
    scanf("%d", &newStudent.PhoneNumber);
    printf("Computer Science Score: ");
    scanf("%d",&newStudent.score);
    insertAtBeginning(head, newStudent);
    printf("New student account created.\n");
}

// Function to delete a student account by ID
void DELETE_STUDENT(struct Node** head, int targetID) {
    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current != NULL && current->data.ID != targetID) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with ID %d not found.\n", targetID);
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Student with ID %d deleted.\n", targetID);
}

// Function to compare two names for sorting
int compareNames(const void* a, const void* b) {
    struct Data* studentA = (struct Data*)a;
    struct Data* studentB = (struct Data*)b;
    return strcmp(studentA->name.last, studentB->name.last);
}

// Function to display student information in a table
void STUDENT_LIST(struct Node* head) {
    int numStudents = 0;
    struct Node* current = head;

    // Count the number of students
    while (current != NULL) {
        numStudents++;
        current = current->next;
    }

    // Create an array to store student data for sorting
    struct Data* studentArray = (struct Data*)malloc(numStudents * sizeof(struct Data));
    if (studentArray == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Copy student data to the array
    current = head;
    int i = 0;
    while (current != NULL) {
        studentArray[i] = current->data;
        current = current->next;
        i++;
    }

    // Sort the array of students by last name
    qsort(studentArray, numStudents, sizeof(struct Data), compareNames);

    // Display the sorted student information
    printf("Student List (Sorted by Last Name):\n");
    printf("%-20s %-20s %-8s %-12s %-50s %-15s %-15s\n", "First Name", "Last Name", "ID", "Date of Birth", "Address", "Phone Number", "Computer Science Score");
    printf("=================================================================================================================\n");
    for (i = 0; i < numStudents; i++) {
        printf("%-20s %-20s %-8d %02d/%02d/%d %-50s %-15d %-15d\n",
               studentArray[i].name.first, studentArray[i].name.last,
               studentArray[i].ID,
               studentArray[i].dateofbirth.month, studentArray[i].dateofbirth.day, studentArray[i].dateofbirth.year,
               studentArray[i].Address, studentArray[i].PhoneNumber, studentArray[i].score);
    }

    free(studentArray);
}

// Function to find a student by ID and return a pointer to the node
struct Node* findStudentByID(struct Node* head, int targetID) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data.ID == targetID) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to update student information
void STUDENT_EDIT(struct Node* head, int targetID) {
    struct Node* studentNode = findStudentByID(head, targetID);
    if (studentNode == NULL) {
        printf("Student with ID %d not found.\n", targetID);
        return;
    }

    printf("Editing student with ID %d:\n", targetID);

    printf("Enter new First Name: ");
    scanf("%s", &studentNode->data.name.first);

    printf("Enter new Last Name: ");
    scanf("%s", &studentNode->data.name.last);

    printf("Enter new Date of Birth (MM DD YYYY): ");
    scanf("%d %d %d", &studentNode->data.dateofbirth.month, &studentNode->data.dateofbirth.day, &studentNode->data.dateofbirth.year);

    printf("Enter new Address: ");
    scanf("%s", &studentNode->data.Address);

    printf("Enter new Phone Number: ");
    scanf("%d", &studentNode->data.PhoneNumber);

    printf("Enter new Computer Science Score: ");
    scanf("%d",&studentNode->data.score);

    printf("Student information updated.\n");
}
// Function to update the score of student
void STUDENT_SCORE(struct Node* head, int targetID, int newScore) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data.ID == targetID) {
            current->data.score = newScore;
            printf("Score of student with ID %d updated to %d.\n", targetID, newScore);
            return;
        }
        current = current->next;
    }

    printf("Student with ID %d not found.\n", targetID);
}
// Function to compare between Scores
int compareScores(const void* a, const void* b) {
    const struct Data* studentA = (const struct Data*)a;
    const struct Data* studentB = (const struct Data*)b;

    if (studentA->score > studentB->score) {
        return -1; // Student A has a higher score (descending order)
    } else if (studentA->score < studentB->score) {
        return 1; // Student B has a higher score
    } else {
        return 0; // Scores are equal
    }
}
// Function to rank students by computer science score (descending order)
void RANK_STUDENT(struct Node* head) {
    int numStudents = 0;
    struct Node* current = head;

    // Count the number of students
    while (current != NULL) {
        numStudents++;
        current = current->next;
    }

    // Create an array to store student data for sorting
    struct Data* studentArray = (struct Data*)malloc(numStudents * sizeof(struct Data));
    if (studentArray == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Copy student data to the array
    current = head;
    int i = 0;
    while (current != NULL) {
        studentArray[i] = current->data;
        current = current->next;
        i++;
    }

    // Sort the array of students by computer science score (descending order)
    qsort(studentArray, numStudents, sizeof(struct Data), compareScores);

    // Display the ranked student information
    printf("Ranked Student List (By Computer Science Score - Descending Order):\n");
    printf("%-20s %-20s %-8s %-12s %-50s %-15s %-15s\n", "First Name", "Last Name", "ID", "Date of Birth", "Address", "Phone Number", "Computer Science Score");
    printf("=============================================================================================================================\n");
    for (i = 0; i < numStudents; i++) {
        printf("%-20s %-20s %-8d %02d/%02d/%d %-50s %-15d %-15d\n",
               studentArray[i].name.first, studentArray[i].name.last,
               studentArray[i].ID,
               studentArray[i].dateofbirth.month, studentArray[i].dateofbirth.day, studentArray[i].dateofbirth.year,
               studentArray[i].Address, studentArray[i].PhoneNumber, studentArray[i].score);
    }

    free(studentArray);
}



