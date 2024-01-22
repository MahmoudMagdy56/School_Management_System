#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
int main() {
	
    struct Node* head = NULL;

    int choice;
    int targetID;

    while (1) {
        printf("MAIN MENU:\n");
        printf("1. New Student Account\n");
        printf("2. Delete Student Account\n");
        printf("3. Student List (Sorted by Last Name)\n");
        printf("4. Edit Student Information\n");
        printf("5. Update Student Score\n");
		printf("6. Rank Students by Computer Science Score\n");
		printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                NEW_STUDENT(&head);
                break;
            case 2:
                printf("Enter the ID of the student to delete: ");
                scanf("%d", &targetID);
                DELETE_STUDENT(&head, targetID);
                break;
            case 3:
                STUDENT_LIST(head);
                break;
            case 4:
                printf("Enter the ID of the student to edit: ");
                scanf("%d", &targetID);
                STUDENT_EDIT(head, targetID);
                break;
            case 5:
                printf("Enter the ID of the student to update score: ");
                scanf("%d", &targetID);
                int newScore;
                printf("Enter the new score: ");
                scanf("%d", &newScore);
                STUDENT_SCORE(head, targetID, newScore);
                break;
			case 6:
                RANK_STUDENT(head);
                break;
			case 7:
                // Free memory and exit
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}



