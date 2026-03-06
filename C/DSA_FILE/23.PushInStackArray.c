#include <stdio.h>
#define MAX 10

int Stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    top++;
    Stack[top] = value;
    printf("Element added sucessfully.\n");
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for(int i = top; i >= 0; i--) {
        printf("%d\n", Stack[i]);
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    display();
    return 0;
}