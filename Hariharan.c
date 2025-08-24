#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for assignment submission
struct Node {
    int studentID;
    char assignmentTitle[50];
    char submissionDate[15];
    char status[15];   // Submitted / Pending
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int id, char title[], char date[], char status[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->studentID = id;
    strcpy(newNode->assignmentTitle, title);
    strcpy(newNode->submissionDate, date);
    strcpy(newNode->status, status);
    newNode->next = NULL;
    return newNode;
}

// Add record at beginning
void addRecord(int id, char title[], char date[], char status[]) {
    struct Node* newNode = createNode(id, title, date, status);
    newNode->next = head;
    head = newNode;
    printf("Record Added!\n");
}

// Display all records
void displayRecords() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("No Records!\n");
        return;
    }
    while (temp != NULL) {
        printf("ID: %d | Title: %s | Date: %s | Status: %s\n",
               temp->studentID, temp->assignmentTitle,
               temp->submissionDate, temp->status);
        temp = temp->next;
    }
}

// Search by Student ID
void searchRecord(int id) {
    struct Node* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->studentID == id) {
            printf("ID: %d | Title: %s | Date: %s | Status: %s\n",
                   temp->studentID, temp->assignmentTitle,
                   temp->submissionDate, temp->status);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("No records for ID %d\n", id);
}

// Main menu
int main() {
    int choice, id;
    char title[50], date[15], status[15];

    do {
        printf("\n--- Assignment Submission Tracker ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search by Student ID\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Assignment Title: ");
                scanf(" %[^\n]", title);   // allows spaces
                printf("Enter Date: ");
                scanf("%s", date);
                printf("Enter Status (Submitted/Pending): ");
                scanf("%s", status);
                addRecord(id, title, date, status);
                break;

            case 2:
                displayRecords();
                break;

            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchRecord(id);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
