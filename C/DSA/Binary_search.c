#include <stdio.h>

int main() {
    int array[100], size, i, key, low, high, mid, position = -1;

    printf("Enter size of array: ");
    scanf("%d",&size);

    printf("Enter %d sorted elements:\n",size);
    for(i = 0; i<size; i++){
        scanf("%d",&array[i]);
    }

    printf("Enter Key to Binary search in arrray: ");
    scanf("%d",&key);

    low = 0, high = size-1;
    while(low<=high) {
        mid = (low+high)/2;
        if(array[mid] == key) {
            position = mid;
            break;
        } else if(key < array[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if(position == -1) {
        printf("Key not found in array\n");
    } else {
        printf("Key found in array at index %d\n", position);
    }
    return 0;
}