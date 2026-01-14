#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string str = "HARSHIT";
    unordered_map<char, int> charCount;

    // Count occurrences of each character
    for (char c : str) {
        charCount[c]++;
    }

    // Find and print the first non-repeating character
    for (char c : str) {
        if (charCount[c] == 1) {
            cout << "First non-repeating character: " << c << endl;
            break;
        }
    }

    return 0;
}