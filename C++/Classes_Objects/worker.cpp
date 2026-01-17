#include <iostream>

using namespace std;

class Worker{
    protected:
        int age;
        string name;
        string company;
    public: 
        int work_hours = 0;
        Worker(string name, string company, int age) {
            setDetails(name, company, age);
            cout << "Worker Has been added." << endl;
        }

        bool setDetails(string name, string company, int age) {
            if (age < 18) return false;

            this->name = name;
            this->company = company;
            this->age = age;

            return true;
        }

        void doWork() {
            work_hours++;
            cout << name << " is Working" << endl;
        }

        bool working() const {
            if(work_hours < 0) {
                return false;
            } else {
                return true;
            }
        }

        void promotion() const {
            if(working()) {
                cout << name << " is getting promotion." << endl;
            } else {
                cout << name << ", Do more WORK YOU ARE NOT EVEN WORKING YOU." << endl;
            }
        }
        
        void gethours() const {
            cout << work_hours << endl;
        }
};

int main() {

    Worker worker1("Pratham","Khanna ltd",18);
    Worker worker2("Harshit Khanna","Khanna ltd",23);
    Worker worker3("nishant","Khanna ltd",32);

    worker1.doWork();
    worker1.doWork();

    worker2.doWork();
    worker2.doWork();
    worker2.doWork();
    worker2.doWork();
    worker2.doWork();

    worker1.gethours();
    worker2.gethours();
    worker3.gethours();

    worker1.promotion();
    worker2.promotion();
    worker3.promotion();

    return 0;
}