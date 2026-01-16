#include <stdio.h>
#include <math.h>

int main() {

    // ax2 + bx + c = 0
    float a, b, c;
    float discriminant;
    float root1, root2;

    printf("Quadratic Equation Solver: \n");
    printf("Equation: aX2 + bX + c = 0\n");

    printf("Enter value of a: ");
    scanf("%f", &a);

    printf("Enter value of b: ");
    scanf("%f", &b);

    printf("Enter value of c: ");
    scanf("%f", &c);

    discriminant = (b * b) - (4 * a * c);

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are %.2f and %.2f", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Root is %.2f", root1);
    } else {
        printf("Roots are imaginary");
    }

    return 0;
}
