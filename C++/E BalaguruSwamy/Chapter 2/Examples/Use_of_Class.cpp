// Example 2.3
#include <iostream>
using namespace std;
class person {
    char name[30];
    int age;
    public: 
        void getdata() {
            cout << "Enter Name : ";
            cin >> name;
            cout << "Enter Age : ";
            cin >> age;
        }
        void display() {
            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl;
        }

};

int main() {
    person p;
    p.getdata();
    p.display();
    return 0;
}