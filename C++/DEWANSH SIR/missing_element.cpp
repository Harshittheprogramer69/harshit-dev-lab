#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5};
    int n = 5;              
    int size = 4;           

    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    int missing = expectedSum - actualSum;

    cout << "Missing : " << missing << endl;

    return 0;
}
