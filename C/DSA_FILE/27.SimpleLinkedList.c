#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void INSERTB(int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Inserted at beginning\n");
}

void INSERTE(int value) {
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        printf("Inserted as first node\n");
        return;
    }

    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    printf("Inserted at end\n");
}

void DELETEB() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    printf("Deleted element: %d\n", temp->data);

    head = head->next;
    free(temp);
}

void DISPLAY() {
    struct node *temp = head;

    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List:\n");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    int choice, value;

    while(1) {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            INSERTB(value);
        } else if(choice == 2) {
            printf("Enter value: ");
            scanf("%d", &value);
            INSERTE(value);
        } else if(choice == 3) {
            DELETEB();
        } else if(choice == 4) {
            DISPLAY();
        } else if(choice == 5) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}