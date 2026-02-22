#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void ENQUEUE(int value) {
    if((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("Element inserted successfully\n");
}

void DEQUEUE() {
    if(front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if(front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}

void DISPLAY() {
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");

    int i = front;
    while(1) {
        printf("%d\n", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
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