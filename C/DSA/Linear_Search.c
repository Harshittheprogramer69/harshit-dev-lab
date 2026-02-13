#include <stdio.h>

int main() {
    int array[100],size,i,key,position = -1;
    
    printf("Enter Size of array: ");
    scanf("%d",&size);
    
    // array input 
    for(i = 0; i<size; i++) {
        printf("Enter Element %d: ", i+1);
        scanf("%d",&array[i]);
    }

    // array printing my way
    printf("\n\n{");
    for(i = 0; i < size; i++) {
        printf("%d",array[i]);
        if(i<size-1) {
            printf(",");
        }
    }
    printf("}\n\n");

    printf("Enter Key for linear Search: ");
    scanf("%d",&key);

    for(i = 0; i<size; i++) {
        if(array[i] == key) {
            position = i;
            break;
        }
    }

    if(position == -1) {
        printf("Key Not found in array\n");
    } else {
        printf("Key fount at index %d in array\n",position);
    }
    return 0;
}