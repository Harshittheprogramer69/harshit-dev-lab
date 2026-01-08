#include <iostream>
using namespace std;

void swap(int *ptr,int *ptr2) {
    int temp = *ptr;
    *ptr = *ptr2;
    *ptr2 = temp;
}

int main() {
    int a = 10;
    int b = 20;
    swap(&a,&b);
    cout << a << " " << b << endl;
}