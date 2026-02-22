#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void ENQUEUE(int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Element inserted successfully\n");
}

void DEQUEUE() {
    if(front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

void DISPLAY() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;

    printf("Queue elements:\n");
    while(temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {

    int choice, value;

    while(1) {
        printf("\n1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            ENQUEUE(value);
        } else if(choice == 2) {
            DEQUEUE();
        } else if(choice == 3) {
            DISPLAY();
        } else if(choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}