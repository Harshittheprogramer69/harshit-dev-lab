#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int a, b;
    char op,ans;
    string YON;
    cin >> a;
    cin >> op;
    cin >> b; 
    do {
        switch (op) {
            case '+': 
            cout << (a + b) << endl;
            break;
            case '-':
            cout << (a - b) << endl;
            break;
            case '*':
            cout << (a * b) << endl;
            break;
            case '/':
            if (b != 0)
            cout << (a / b) << endl;
            else
            cout << "Division by zero error" << endl;
            break;
            default:
            cout << "invalid response" << endl;
        }
        cout << "WRITE N";
        cin >> YON;
    } while (YON == "n" || YON == "N");
    return 0;
}
