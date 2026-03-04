#include <iostream>
using namespace std;

class base {
    public: 
        base() {
            cout << "It is base class" << endl;
        }
};

class derived : public base {
    public: 
        derived() {
            cout << "It is derived class" << endl;
        }
};

int main() {
    derived D;
    return 0;
}