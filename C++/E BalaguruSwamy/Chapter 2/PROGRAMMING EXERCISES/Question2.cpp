/*
2.2 Question: Write a program to read two numbers from the keyboard and display the larger value on screen.
*/

#include <iostream>
using namespace std;

int main() {
    double number1,number2;
    cout << "ENTER 2 NUMBERS : ";
    cin >> number1;
    cin >> number2;
    cout << ((number1>number2) ? number1 : number2) << endl;
}