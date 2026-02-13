#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    int array[100], size, MinIndex;
    printf("Enter Size of Array: ");
    scanf("%d",&size);

    printf("Enter %d elements: ",size);
    for(int i = 0; i<size; i++) {
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