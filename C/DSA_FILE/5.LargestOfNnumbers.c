#include <stdio.h>

int main() {
    int n,i,Number,Maximum;
    printf("Enter how many Numbers you want to add: ");
    scanf("%d",&n);

    printf("Enter Number 1: ");
    scanf("%d",&Maximum);

    for(i = 2;i<=n;i++) {
        printf("Enter Number %d: ",i);
        scanf("%d",&Number);

        if(Number > Maximum) {
            Maximum = Number;
        }
    }

    printf("Largest is %d", Maximum);
    
    return 0;
}