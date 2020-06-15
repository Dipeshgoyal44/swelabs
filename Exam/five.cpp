#include <iostream>

using namespace std;

class Employee{
    private:
        string Name;
        double Basic;
        double Bonus;
        double Salary;
    public:
        Employee(string name1, double b1, double b2, double sal)
        {
            Name = name1;
            Basic = b1;
            Bonus = b2;
            Salary = sal;
        }
        Employee();
        int calculateSalary(){
            Salary = Basic + Bonus;
        }
        void printEmployee(){
            cout << "\nName: " << Name;
            cout << "\nBasic: " << Basic;
            cout << "\nBonus: " << Bonus;
            cout << "\nSalary: " << Salary;
        }
};

int main()
{
    Employee Employee1("Dipesh",10000,2000,0);
    Employee1.calculateSalary();
    Employee1.printEmployee();
    return 0;
}


