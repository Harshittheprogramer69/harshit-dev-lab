#include <stdio.h>

int main() {
    int first,second,third,Largest;

    printf("Enter First: ");
    scanf("%d",&first);
    printf("Enter Second: ");
    scanf("%d",&second);
    printf("Enter Third: ");
    scanf("%d",&third);

    if(first>second) {
        if(first>third) {
            Largest = first;
        } else {
            Largest = third;
        }
    } else {
        if(second>third) {
            Largest = second;
        } else {
            Largest = third;
        }
    }

    printf("%d is Largest",Largest);

    return 0;
}