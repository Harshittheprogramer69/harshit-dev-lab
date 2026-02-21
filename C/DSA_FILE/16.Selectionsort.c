#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

#define MAX 100

int main() {
    int array[MAX], size, MinIndex;
    printf("Enter Size of Array: ");
    scanf("%d",&size);

    printf("\nEnter %d elements: \n",size);
    for(int i = 0; i<size; i++) {
        printf("Enter element %d: ",i);
        scanf("%d",&array[i]);
    }

    for(int i = 0; i<size-1; i++) {
        MinIndex = i;
        for(int j = i+1; j<size; j++) {
            if(array[j] < array[MinIndex]) {
                MinIndex = j;
            }
        } 
        if(MinIndex != i) {
            swap(&array[i],&array[MinIndex]);
        }
    }

    printf("Sorted Array: ");
    printf("{");
    for(int i = 0; i<size;i++) {
        printf("%d",array[i]);
        if(i<size-1) {
            printf(",");
        }
    }
    printf("}");
    return 0;
}