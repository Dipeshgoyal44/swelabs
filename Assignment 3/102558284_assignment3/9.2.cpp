#include <string>
#include <iostream>

using namespace std;

//structures
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

//function prototypes
Emp get_data();
void print_data(Emp a[]);
double get_average( Emp a[], string y);
double get_salary( Emp y[],string x);

int main()
{
    char menu;
    Emp employee[5];    
    string name; // employee name
    string cname; //company name
    int i;
    do { //switch menu 
        cout << "\n(1)Enter 1 to store employee data\n" <<
        "(2)Enter 2 to print the employee details.\n" <<
        "(3)Enter 3 to search for employee salary by name\n" <<
        "(4)Enter 4 to calculate average salary of particular company\n" <<
        "(5)Enter 5 to Exit.\n";
    cin >> menu;
    switch (menu)
    {
    case '1':
    for (i = 0; i < 5; i++) // loop to store 5 records of employee
    {
        employee[i] = get_data();
    }
        break;
    case '2':
    print_data(employee); // prints all the data 
        break;
    case '3':
    cout << "\nEnter the employee name to search for salary: ";
    cin >> name;
    get_salary(employee,name); //gets salary for employee name entered
        break;
    case '4':
    cout << "Enter the company name to get average salary: ";
    cin >> cname;
    cout << "The average salary for this company is " << get_average(employee,cname); 
    case '5':
    return 0;
        break;
    default:
        cout << "Error! Invalid Selection";
        break;
    }}while(menu != 5);
}    
Emp get_data()
{
    // gets employee data
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
    return x; //returns x which has a datatype of emp
}
void print_data(Emp a[])
{
    // prints all data
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
    //gets averages
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
    cout << "Employee not found\n";
}
