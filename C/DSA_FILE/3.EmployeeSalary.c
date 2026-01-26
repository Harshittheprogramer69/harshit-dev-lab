#include <stdio.h>

int main() {
    float basic, hra, ta, it, grossSalary;

    printf("Enter the basic pay of the employee: ");
    scanf("%f", &basic);

    hra = 0.10 * basic;  // 10% of basic
    ta  = 0.05 * basic;  // 5% of basic
    it  = 0.025 * basic; // 2.5% of basic

    grossSalary = basic + hra + ta - it;

    printf("\nBasic Pay: %.2f\n", basic);
    printf("HRA (10%%): %.2f\n", hra);
    printf("TA (5%%): %.2f\n", ta);
    printf("IT Deduction (2.5%%): %.2f\n", it);
    printf("Gross Salary: %.2f\n", grossSalary);

    return 0;
}
