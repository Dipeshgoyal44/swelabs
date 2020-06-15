#include <iostream>

using namespace std;

struct Date
{
    int yy,mm,dd;
};

struct Emp
{

    char EmpName[25];
    float Salary;
    struct Date hired;
};

int storedata(Emp * s, int size);
void display_students(Emp * s, int size) ;

int main()
{
    struct Emp student[100];
    storedata(student,1);
    display_students(student,1);
    return 0;
}

int storedata(Emp * s, int size)
{
    struct Emp temp[10];
    temp->EmpName = "Dipesh";
    int salary = 50;
    for (int i = 0; i < size - 1; i++){
    s[i].Salary = salary;
}

void display_students(Emp * s, int size) //display function
{
    for (int i = 0; i < size - 1; i++){
        cout << "Name: " << s[i].EmpName << "\n";
        cout << "ID: " << s[i].Salary << "\n";
    }
}