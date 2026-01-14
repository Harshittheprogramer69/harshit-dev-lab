#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string str = "Harshit";
    unordered_map<char, int> charCount;

    // Convert string to uppercase to ensure case insensitivity
    string New = str;
    for(char &c : New) {
        c = toupper(c);
    }

    // Count occurrences of each character
    for (char c : New) {
        charCount[c]++;
    }

    // Find and print the first repeating character
    for (char c : New) {
        if (charCount[c] > 1) {
            cout << "First repeating character: " << c << endl;
            break;
        }
    }
    return 0;
}
