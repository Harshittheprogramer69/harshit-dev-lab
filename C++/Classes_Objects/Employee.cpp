#include <iostream>
using namespace std;

// Class is like structure rather having more functions and features

class AbstractEmployee {
    public:
        virtual void AskForPromotion()=0;
};

class Employee : public AbstractEmployee {
    protected:
        string name;
        string company;
        int age;    

    public: 
        Employee(string name, string company, int age) {
            setDetails(name,company,age);    
        }
        
        bool setDetails(string name, string company, int age) {
            if (age < 18) return false;

            this->name = name;
            this->company = company;
            this->age = age;

            return true;
        }

        // Employe Introduction
        virtual void Introduce() const {
            cout << name << "|" << company << "|" << age << endl;
        }

        // Asking For Promotion as name suggests man.
        void AskForPromotion() {
            cout << name << " asked promotion!" << endl;
            if(company=="Khanna Ltd" && age > 20){
                cout << name << " Is Promoted!!" << endl;
            } else if(company == "Khanna Ltd" && age < 20) {
                cout << name << " should work more" << endl;
            } else {
                cout << name << ", you dont even work here bruh!" << endl;
            } 
        }

};

class Owner : public Employee {
    private:
        string FavProgramingLanguage;
    public:
        Owner(string name, string company, int age, string FavProgramingLanguage) : Employee(name, company,age) 
        {
            this->FavProgramingLanguage = FavProgramingLanguage;
        }
        void Introduce() const override {
            cout << name << "|" << company << "|" << age << "|" << FavProgramingLanguage << endl;
        }
};

int main() {
    // Created Employee 1
    cout << "Before Changes " << endl;

    Employee employee1("Salinda", "Salinda LTD.",21);

    // Employee 1 Details
    // employee1.Name = "Salinda";
    // employee1.Company = "Salinda LTD.";
    // employee1.Age = 21;
    employee1.Introduce();
    
    // Created Employee 2
    Employee employee2("Jason", "Khanna Ltd",24);

    // employee2.Name = "Jason";
    // employee2.Company = "Khanna LTD.";
    // employee2.Age = 24;
    employee2.Introduce();
    
    cout << "After Changes" << endl;
    employee1.setDetails("Pratham","Khanna Ltd",18);
    employee2.setDetails("Nishant","Pratham Ltd",28);
    
    employee1.Introduce();
    employee2.Introduce();

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    Owner Khanna("Harshit Khanna","Khanna Ltd", 24, "C#");
    Khanna.Introduce();

    return 0;
}