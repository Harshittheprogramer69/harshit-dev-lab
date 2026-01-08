#include <stdio.h>
int main() {
    int array[] = {1,2,2,3};
    printf("%d",(sizeof(array)/sizeof(array[0])));
}
