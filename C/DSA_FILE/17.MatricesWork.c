#include <stdio.h>

int main() {
    int rows_1, columns_1, rows_2, columns_2;

    printf("Enter rows and columns for matrix_1: ");
    scanf("%d %d", &rows_1, &columns_1);

    printf("Enter rows and columns for matrix_2: ");
    scanf("%d %d", &rows_2, &columns_2);

    int matrix_1[rows_1][columns_1];
    int matrix_2[rows_2][columns_2];

    printf("\nEnter elements of matrix_1:\n");
    for(int i = 0; i < rows_1; i++) {
        for(int j = 0; j < columns_1; j++) {
            scanf("%d", &matrix_1[i][j]);
        }
    }

    printf("\nEnter elements of matrix_2:\n");
    for(int i = 0; i < rows_2; i++) {
        for(int j = 0; j < columns_2; j++) {
            scanf("%d", &matrix_2[i][j]);
        }
    }

    int choice;

    printf("\n1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1 || choice == 2) {

        if(rows_1 != rows_2 || columns_1 != columns_2) {
            printf("Operation not possible");
            return 0;
        }

        int result_matrix[rows_1][columns_1];

        for(int i = 0; i < rows_1; i++) {
            for(int j = 0; j < columns_1; j++) {
                if(choice == 1)
                    result_matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
                else
                    result_matrix[i][j] = matrix_1[i][j] - matrix_2[i][j];
            }
        }

        printf("\nResult Matrix:\n\n");
        for(int i = 0; i < rows_1; i++) {
            for(int j = 0; j < columns_1; j++) {
                printf("%5d", result_matrix[i][j]);
            }
            printf("\n");
        }
    } else if(choice == 3) {

        if(columns_1 != rows_2) {
            printf("Multiplication not possible");
            return 0;
        }

        int result_matrix[rows_1][columns_2];

        for(int i = 0; i < rows_1; i++) {
            for(int j = 0; j < columns_2; j++) {
                result_matrix[i][j] = 0;
                for(int k = 0; k < columns_1; k++) {
                    result_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
                }
            }
        }

        printf("\nResult Matrix:\n\n");
        for(int i = 0; i < rows_1; i++) {
            for(int j = 0; j < columns_2; j++) {
                printf("%5d", result_matrix[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Invalid choice");
    }

    return 0;
}