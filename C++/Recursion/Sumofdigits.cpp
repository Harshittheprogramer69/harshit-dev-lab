#include <iostream>
using namespace std;

int sumOfDigits(int number) {
    if (number == 0)
        return 0;

    return (number % 10) + sumOfDigits(number / 10);
}

int main() {
    int inputNumber;
    cout << "Enter number: ";
    cin >> inputNumber;

    cout << "Sum of digits: " << sumOfDigits(inputNumber) << endl;
    return 0;
}
