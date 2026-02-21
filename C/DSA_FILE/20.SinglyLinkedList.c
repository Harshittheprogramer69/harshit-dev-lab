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
}

void INSERTE(int value) {
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void SHOW() {
    struct node *temp = head;

    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    INSERTB(10);
    INSERTB(5);
    INSERTE(20);
    INSERTE(30);

    printf("Singly Linked List:\n");
    SHOW();

    return 0;
}