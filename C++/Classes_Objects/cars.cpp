#include <iostream>
using namespace std;

class CARS{
    protected:
        int total_cars;
        string company;
        static int company_count;
    public:
        virtual void vehicleType() = 0;
        CARS(int total_cars, string company) { // constructor
            this->total_cars = total_cars;
            this->company = company;
            company_count++;
        }
        CARS(string company) {
            total_cars = 0;
            this->company = company;
            company_count++;
        }
        void setTotalCars(int total) {
            if(total >= 0) {
                total_cars = total;
            }
        }
        int getTotalCars() const {
            return total_cars;
        }
        string getCompany() const {
            return company;
        }
        static int getCompanyCount() {
            return company_count;   
        }
        virtual void display() const {
            cout << "Company: " << company << ", Total cars: " << total_cars << endl;        
        }
        virtual ~CARS() {
            cout << "Company fell apart" << endl;
        }
};

int CARS::company_count = 0;

class TRUCK : public CARS {
    protected:
        string truck_name;
    public:
        TRUCK(int total_cars, string company, string truck_name) : CARS(total_cars,company) {
            this->truck_name = truck_name;
        }
        void vehicleType() override {
            cout << "This is a truck" << endl;
        }
        void display() const override {
            CARS::display();
            cout << "Truck Name: " << truck_name << endl;
        }

        ~TRUCK() {
            cout << "Trucks Crashed" << endl;
        }
};

int main() {
    CARS* garage[100];
    int count = 0;
    int choice;
    do {
        /*USER INTERFACE*/
        cout << "\n====== VEHICLE MANAGEMENT SYSTEM ======\n";
        cout << "1. Add Truck\n";
        cout << "2. Show All Vehicles\n";
        cout << "3. Show Company Count\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        /*options*/
        if(choice == 1) {
            if (count >= 100) {
                cout << "Garage is full!\n";
                continue;
            }
            int totalVehciles;
            string company, truckName;

            cout << "Enter Company Name: ";
            cin >> company;

            cout << "Enter Truck Name: ";
            cin >> truckName;

            cout << "Enter Total Vehciles: ";
            cin >> totalVehciles;

            garage[count] = new TRUCK(totalVehciles,company,truckName);     
            count++;

            cout << "TRUCK HAS BEEN CREATED" << endl;
        } else if (choice == 2) {
            if(count == 0) {
                cout << "No Vechiles added yet." << endl;
            } else {
                cout << "------------------------\n";
                for(int i = 0; i < count; i++) {
                    garage[i]->vehicleType();
                    garage[i]->display();
                    cout << "------------------------\n";
                }   
            }
        } else if (choice == 3) {
            cout << "Total Companies created: " << CARS::getCompanyCount() << endl;
        } else if (choice == 4) {
            cout << "Shutting down system..\n";

            for(int i = 0; i < count; i++) {
                delete garage[i];
            }
        } else {
            cout << "Invalid Choice";
        }
    } while(choice != 4);
    return 0;
}