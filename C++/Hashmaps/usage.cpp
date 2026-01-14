#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string str = "harshit";
    unordered_map<char , int> charCount;
    
    // Count Occurence of Each Character
    for (char c : str) {
        charCount[c]++;
    }

    // Print Occurence with String Characters
    for (char c : str) {
        cout << c << " -> " << charCount[c] << endl;
    } 
    
    return 0;
}