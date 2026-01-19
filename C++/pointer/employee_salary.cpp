#include <iostream>
using namespace std;

class Employee {
    int id;
    float salary;

public:
    Employee(int id, float salary) {
        this->id = id;
        this->salary = salary;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee* e = new Employee(1, 50000);
    e->display();
    delete e;
    return 0;
}
