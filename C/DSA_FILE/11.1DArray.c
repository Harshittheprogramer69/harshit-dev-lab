#include <stdio.h>

int main() {
    int size;
    printf("Enter Size of array");
    scanf("%d",&size);

    int arr[size];

    printf("Enter array : ");
    for(int i = 0; i < size; i++) {
        printf("Enter element[%d]",i+1);
        scanf("%d",&arr[i]);
    }

    
    return 0;
}