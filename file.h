/*
 * file.h
 *
 *  Created on: Sep 24, 2023
 *      Author: 20109
 */
#include <stdio.h>
#ifndef FILE_H_
#define FILE_H_

struct DateOfBirth {
    int day;
    int month;
    int year;
};

// Define the Data struct
struct Name {
    char first[50];
    char last[50];
};

struct Data {
    struct Name name;
    struct DateOfBirth dateofbirth;
    int ID;
    char Address[1000];
    int PhoneNumber;
	int score;
};

// Define a struct for a linked list node
struct Node {
    struct Data data;
    struct Node* next;
};


struct Node* createNode(struct Data data);
void insertAtBeginning(struct Node** head, struct Data data);
void displayList(struct Node* head);
void NEW_STUDENT(struct Node** head);
void DELETE_STUDENT(struct Node** head, int targetID);
int compareNames(const void* a, const void* b);
void STUDENT_LIST(struct Node* head);
struct Node* findStudentByID(struct Node* head, int targetID);
void STUDENT_EDIT(struct Node* head, int targetID);
void STUDENT_SCORE(struct Node* head, int targetID, int newScore);
int compareScores(const void* a, const void* b);
void RANK_STUDENT(struct Node* head);


#endif /* FILE_H_ */
