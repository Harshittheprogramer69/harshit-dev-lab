#include <stdio.h>

int main() {
    int array[50];
    int n, i;
    int position, value;
    int choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        printf("Enter Element[%d]: ",i);
        scanf("%d", &array[i]);
    }

    printf("Options are as Follows: \n");
    printf("\n1. Insertion\n2. Deletion\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter position to insert: ");
        scanf("%d", &position);

        printf("Enter value: ");
        scanf("%d", &value);

        for (i = n - 1; i >= position; i--) {
            array[i + 1] = array[i];
        }

        array[position] = value;
        n++;

        printf("Array after insertion:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
    } else if (choice == 2) {
        printf("Enter position to delete: ");
        scanf("%d", &position);

        for (i = position; i < n - 1; i++) {
            array[i] = array[i + 1];
        }

        n--;

        printf("Array after deletion:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
    } else {
        printf("Invalid choice");
    }

    return 0;
}
