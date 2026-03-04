#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a+b;
}
float sum(float a, float b) {
    return a+b;
}
int sum(int a, int b, int c) {
    return a+b+c;
}
double sum(double a, double b, double c) {
    return a+b+c;
}

int main() {
    cout << sum(1,2) << endl;
    cout << sum(1.2f,2.1f) << endl;
    cout << sum(1,2,3) << endl;
    cout << sum(1.2,2.3,3.1) << endl;
    return 0;
}