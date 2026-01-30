#include <iostream>
using namespace std;

class CARS{
    protected:
        int total_cars;
        string company;
    public:
        CARS(int total_cars, string company) { // constructor
            this->total_cars = total_cars;
            this->company = company;
        }
        CARS(string company) {
            total_cars = 0;
            this->company = company;
        }
        void display() {
            cout << "Total number of cars are " << total_cars << "in Company = " << company << endl;
        }
        ~CARS() {
            cout << "Company fell apart" << endl;
        }
};

class TRUCK : public CARS {
    protected:
        string truck_name;
    public:
        TRUCK(int total_cars, string company, string truck_name) : CARS(total_cars,company) {
            this->truck_name = truck_name;
        }
        void showTruck() {
            display();
            cout << "Truck Name: " << truck_name << endl;
        }

        ~TRUCK() {
            cout << "Trucks Crashed" << endl;
        }
};

