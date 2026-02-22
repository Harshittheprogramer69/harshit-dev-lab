#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void ENQUEUE(int value) {
    if(rear == MAX - 1) {
        printf("Stack Overflow.\n");
        return;
    }

    if(front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;

    printf("Element added successfully\n");
}

void DEQUEUE() {
    if(front == -1 || front > rear) {
        printf("Stack Underflow.\n");
        return;
    } 

    printf("Element Deleted: %d\n",queue[front]);
    front++;
}

void DISPLAY() {
    if(front == -1 || front > rear) {
        printf("QUEUE is empty.\n");
        return;
    } 

    printf("Queue Elements:\n");
    for(int i = front; i<=rear; i++) {
        printf("%d\n",queue[i]);
    }
}

int main() {

    int choice, value;

    while(1) {
        printf("\n1.ENQUEUE\n");
        printf("2.DEQUEUE\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice == 1) {
            printf("Enter Value: ");\
            scanf("%d",&value);
            ENQUEUE(value);
        } else if(choice == 2) {
            DEQUEUE();
        } else if(choice == 3) {
            DISPLAY();
        } else if(choice == 4) {
            break;
        } else {
            printf("Invalid Choice.\n");
        }
    }

    return 0;
}