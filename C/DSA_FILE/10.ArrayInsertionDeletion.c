#include <stdio.h>

int main() {
    int arr[50];
    int n, i;
    int pos, value;
    int choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 1; i <= n; i++) {
        printf("Enter Element[%d]: ",i);
        scanf("%d", &arr[i]);
    }

    printf("Options are as Follows: \n");
    printf("\n1. Insertion\n2. Deletion\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter position to insert: ");
        scanf("%d", &pos);

        printf("Enter value: ");
        scanf("%d", &value);

        for (i = n; i >= pos; i--) {
            arr[i + 1] = arr[i];
        }

        arr[pos] = value;
        n++;

        printf("Array after insertion:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else if (choice == 2) {
        printf("Enter position to delete: ");
        scanf("%d", &pos);

        for (i = pos; i < n; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        printf("Array after deletion:\n");
        for (i = 1; i <= n; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Invalid choice");
    }

    return 0;
}
