#include <string>
#include <iostream>

using namespace std;

typedef struct 
{
    string company_id;
    string company_name;
}company_detail;

typedef struct 
{
    string emp_name;
    string emp_id;
    double salary;
    company_detail cmp_detail;
}Emp;

Emp get_data();
void print_data(Emp a[]);
double get_average( Emp a[], string y);
double get_salary( Emp y[],string x);

int main()
{
    Emp employee[5];    
    string x;
    string y;
    int i;
    for (i = 0; i < 5; i++)
    {
        employee[i] = get_data();
    }
    print_data(employee);
    cout << "\nEnter a name: ";
    cin >> x;
    cout << "\n";
    get_salary(employee, x);
    cout << "Enter the company name to get average salary: ";
    cin >> y;
    cout << "The average salary for this company is " << get_average(employee,y);
}

Emp get_data()
{
    Emp x;
    company_detail y;
    cout << "\nEnter Employee Details.." << endl;
    cout << "Enter Employee ID.." << endl;
    cin >> x.emp_id;
    cout << "Enter Employee Name.." << endl;
    cin >> x.emp_name;
    cout << "Enter Company Details.." << endl;
    cout << "Enter Company ID:.." << endl;
    cin >> x.cmp_detail.company_id;
    cout << "Enter Company Name:.." << endl;
    cin >> x.cmp_detail.company_name;
    cout << "Enter Employee Salary:.." << endl;
    cin >> x.salary;
    return x;
}
void print_data(Emp a[])
{
    int i;
    for (i = 4; i >= 0; i--)
    {   
        cout <<" \n *****Employee details*****" << endl;
        cout <<"Employee ID: " << a[i].emp_id << endl;
        cout <<"Employee Name: " << a[i].emp_name << endl;
        cout <<"Employee Salary: " << a[i].salary<< endl;
        cout <<"Company ID: " << a[i].cmp_detail.company_id << endl;
        cout <<"Company Name: " << a[i].cmp_detail.company_name << endl;
    }
}
double get_average( Emp a[], string y)
{
    double sum = 0;
    int i;
    double temp = 0;
    for (i = 0; i < 5; i++)
    {
        if (a[i].cmp_detail.company_name == y)
        {
            sum += a[i].salary;
            temp++;
        }
    }
    temp = sum / temp;
    return temp;
}

double get_salary( Emp a[],string x)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (a[i].emp_name == x)
        {
            cout << "The Salary of this employee is: $" <<  a[i].salary << endl;
            return a[i].salary;
        }
    }
}
