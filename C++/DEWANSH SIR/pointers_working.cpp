#include <iostream>
using namespace std;

int main () {
    int first = 10;
    int *third = &first;
    cout << first << endl;
    cout << third << endl;
    cout << *third << endl;
    return 0;
}