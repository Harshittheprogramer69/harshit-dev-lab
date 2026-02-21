#include <stdio.h>

struct Complex_Number {
    float real;
    float imaginary;
};

struct Complex_Number add_complex(struct Complex_Number number_1, struct Complex_Number number_2) {
    struct Complex_Number result;
    result.real = number_1.real + number_2.real;
    result.imaginary = number_1.imaginary + number_2.imaginary;
    return result;
}

struct Complex_Number subtract_complex(struct Complex_Number number_1, struct Complex_Number number_2) {
    struct Complex_Number result;
    result.real = number_1.real - number_2.real;
    result.imaginary = number_1.imaginary - number_2.imaginary;
    return result;
}

int main() {
    struct Complex_Number number_1, number_2, addition_result, subtraction_result;

    printf("Enter real and imaginary part of first complex number: ");
    scanf("%f %f", &number_1.real, &number_1.imaginary);

    printf("Enter real and imaginary part of second complex number: ");
    scanf("%f %f", &number_2.real, &number_2.imaginary);

    addition_result = add_complex(number_1, number_2);
    subtraction_result = subtract_complex(number_1, number_2);

    printf("\nAddition Result: %.2f + %.2fi\n", addition_result.real, addition_result.imaginary);
    printf("Subtraction Result: %.2f + %.2fi\n", subtraction_result.real, subtraction_result.imaginary);

    return 0;
}