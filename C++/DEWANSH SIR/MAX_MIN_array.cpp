#include <iostream>
using namespace std;

int main() {
    int arr[6] = {10,23,432,4533,342,22};
    int max,min,size,i;

    max = arr[0];
    min = arr[0];

    size = 6;

    for(i = 0; i<size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        } else if(arr[i] > max) {
            max = arr[i];
        }
    }

    cout << max << endl;
    cout << min << endl;
    
    return 0;
}