#include <string>
#include <iostream>

using namespace std;

typedef struct company_detail 
{
    string company_id;
    string company_name;
};

typedef struct Emp
{
    string emp_name;
    string emp_id;
    double salary;
    company_detail cmp_detail;
};

Emp get_data();
void print_data(Emp a[]);
double get_average( Emp a[], int temp);
double get_salary( Emp y[],string x);

int main()
{
    Emp employee[5];    
    string x;
    int i;
    for (i = 0; i < 2; i++)
    {
        employee[i] = get_data();
    }
    print_data(employee);
    get_average(employee, 5);
    printf("\n The Average Salary is: %.2f\n", get_average(employee, 5));
    cout << "Enter a name: ";
    cin >> x;
    cout << "\n";
    get_salary(employee, x);
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
double get_average( Emp a[], int temp)
{
    double sum = 0;
    int i;
    for (i = 0; i < temp; i++)
    {
        sum += a[i].salary;
    }
    temp = sum / temp;
    return temp;
}

double get_salary( Emp a[],string x)
{
    int i, temp = 0;
    for (i = 0; i < 5; i++)
    {
        if (a[i].emp_name == x)
        {
            temp = 1;
            cout << "The Salary of this employee is: " <<  a[i].salary << endl;
            return a[i].salary;
        }
    }
}
