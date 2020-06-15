#include <iostream>

using namespace std;

struct Date
{
    int yy,mm,dd;
};

struct Emp
{
    string EmpName;
    float Salary;
    struct Date hired;
};

void PrintData(Emp * data);
int main()
{
    struct Emp  data;
    struct Emp *dataptr;
    data.EmpName = "Dipesh";
    data.Salary = 10000;
    data.hired.yy = 2001;
    data.hired.mm = 04;
    data.hired.dd = 24;
    dataptr = &data;
    PrintData(dataptr);
    return 0;
}

void PrintData(Emp * data)
{
    cout << "\nEmployee Name: " << data->EmpName << "\nEmployee Salary: " << data->Salary
    << "\nEmployee Hired : " << data->hired.dd << "/" <<  data->hired.mm << "/" << data->hired.yy << "\n";
}

