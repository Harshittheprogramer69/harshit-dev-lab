#include <stdio.h>
#include <string.h>

int main() {
    char name[] = "Harshit ";
    char surname[] = "Khanna";
    strcat(name,surname);
    printf("%s",name);
    return 0;
}