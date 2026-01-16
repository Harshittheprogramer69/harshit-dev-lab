#include <stdio.h>
#include <math.h>

int main() {
    int n;

    printf("Enter limit: ");
    scanf("%d", &n);

    for (int num = 1; num <= n; num++) {
        int original = num;
        int temp = num;
        int digits = 0;
        int sum = 0;
        int digit;

        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        temp = num;

        while (temp != 0) {
            digit = temp % 10;
            sum += (int)(pow(digit, digits) + 0.5);
            temp /= 10;
        }

        if (sum == original) {
            printf("%d ", original);
        }
    }

    return 0;
}
