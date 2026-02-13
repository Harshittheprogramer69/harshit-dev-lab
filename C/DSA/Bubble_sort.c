#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    int array[100], size;
    printf("Enter size of array: ");
    scanf("%d",&size);

    printf("Enter %d elements:\n",size);
    for(int i = 0; i <size; i++) {
        scanf("%d",&array[i]);
    }

    for(int i = 0; i<size-1; i++) {
        for(int j = 0; j<size-1-i; j++) {
            if(array[j] > array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }

    printf("Sorted Array: ");
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