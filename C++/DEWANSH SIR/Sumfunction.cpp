#include <iostream>
using namespace std;

int addition(int a, int b) {
    return a+b;
}

int main() {
    int first,second;
    cin >> first;
    cin >> second;
    int ans = addition(first,second);
    cout << "SUM = " << ans << endl;
    return 0;
}