#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void PUSH(int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Element pushed successfully\n");
}

void POP() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct node *temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void PEEK() {
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

void DISPLAY() {
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node *temp = top;
    printf("Stack elements:\n");

    while(temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {

    int choice, value;

    while(1) {
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            PUSH(value);
        } else if(choice == 2) {
            POP();
        } else if(choice == 3) {
            PEEK();
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