#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string str = "foggy";
    unordered_map<char,int> m;
    
    for(char c : str) m[c]++;

    for(char c : str) {
        if(m[c] > 1) {
            cout << c << "ofy" << c;
            break;
        }
    }
    return 0;
}