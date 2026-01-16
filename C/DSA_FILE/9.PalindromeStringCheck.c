#include <stdio.h>
#include <string.h>

void main() {
    char str1[100],str2[100],temp;
    int i,j;

    printf("Enter the palindrome : ");
    gets(str1);
    
    strcpy(str2,str1);
    j=strlen(str2)-1;

    
    for(i=0;i<j;i++,j--) {
        temp = str2[i];
        str2[i] = str2[j];
        str2[j] = temp;
    }

    if (strcmp(str1, str2) == 0) {
        printf("String is palindrome.");
    } else {
        printf("String is not a palindrome");
    }
}