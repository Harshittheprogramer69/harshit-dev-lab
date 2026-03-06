#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("Element added sucessfully.\n");
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow.\n");
        return;
    }
    printf("Element Popped: %d",stack[top]);
    top--;
}

void peek() {
    if(top == -1) {
        printf("Stack Underflow.\n");
        return;
    }
    printf("Element Peek: %d",stack[top]);
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for(int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {

    int choice, value;

    do {
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
            push(value);
        } else if(choice == 2) {
            pop();
        } else if(choice == 3) {
            peek();
        } else if(choice == 4) {
            display();
        } else if(choice == 5) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}