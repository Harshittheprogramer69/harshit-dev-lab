#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

#define MAX 100

int main() {
    int array[MAX], size;
    printf("Enter size of array: ");
    scanf("%d",&size);

    printf("\nEnter %d elements:\n",size);
    for(int i = 0; i <size; i++) {
        printf("Enter element[%d]: ",i);
        scanf("%d",&array[i]);
    }

    for(int i = 0; i<size-1; i++) {
        for(int j = 0; j<size-1-i; j++) {
            if(array[j] > array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }

    printf("Sorted Array(Asceding Order): ");
    printf("{");
    for(int i = 0; i<size; i++) {
        printf("%d",array[i]);
        if(i<size-1) {
            printf(",");
        }
    }
    printf("}");

    return 0;
}