#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct person_tag{
    string name;
    int age;
};

struct official_tag{
    int dept_id;
    string cmp_name;
    double salary;
};

struct employee_tag{
    person_tag personal_info;
    official_tag official_info;
};

//function prototype
int read_file(employee_tag a[],int * array_size);
void display_students(employee_tag a[], int array_size);
int find_max_salary(employee_tag a[], int array_size);
double find_average_salary(employee_tag *a, string y,int array_size);
void menu();

int main()
{   
    int error;
    int choice;
    int max = 0;
    string cname;
    employee_tag employee[100];
    int array_size =0;
    double average_salary= 0;
    do
    { // MENU function displays option and returns user input
        menu();
        cin >> choice;
        switch (choice) //c is storing the user input for choice
        {
        case 1:
        read_file(employee, &array_size);
        display_students(employee, array_size);
            break;
        case 2:
        read_file(employee, &array_size);
        cout << "Details of employee who gets highest pay: \n";
        find_max_salary(employee,array_size);
            break;
        case 3:
        error = 1;
        read_file(employee, &array_size);
        cout << "Enter Company Name: \n"; 
        cin >> cname;
        for (int i = 0; i < array_size; i++)
        {
            if(employee[i].official_info.cmp_name == cname){
                error=0;
            average_salary = find_average_salary(employee,cname,array_size);
            cout << "Average salary of " << cname << " is $" << average_salary << "\n";
        }
        }
            if(error !=0){
                cout << "No such company in the database\n";
            }
            break;
        case -1:
            printf("SEE YOU LATER! \n");
            return 0;
            break;
        default:
            cout << "Please try again! Your input is invalid!\n";
            break;
        }
        cin.clear();
        cin.ignore(1000,'\n');
    } while (choice != -1); //while loop keeps running till 4 is chosen as an option.
}

void menu()
{
    cout << "\nEnter your choice\n" <<
        "Enter 1 to display the employee details\n" <<
        "Enter 2 to find the employee who gets the highest salary \n" <<
        "Enter 3 to  find the average salary of all employees in a company\n" <<
        "Enter -1 to exit the program\n";
}

int read_file(employee_tag a[],int * array_size) //readfile function
{
    string titlename;
    string titleage;
    string titleid;
    string company;
    string salary;
    int count;
    double total = 0;
    string filename = "employee.txt"; // filename
    ifstream inFile(filename);

    if (inFile.fail()) // if file doesnt open successfully
    {
        cout << "The File was not opened successfully\n";
        cout << "Please check that the file currently exists\n";
        return 0;
    }
    inFile >> titlename >> titleage >> titleid >> company >> salary;
    int i = 0;
    while (inFile.peek() != EOF) // until the end of the file
    {
        inFile >> a[i].personal_info.name >> a[i].personal_info.age >> a[i].official_info.dept_id
        >> a[i].official_info.cmp_name >> a[i].official_info.salary; 
        i++;
    }
    *array_size = i; // temp has the same value of i to check how many records of data is in the file
    inFile.close();  //close file
}
void display_students(employee_tag a[], int array_size) //display function
{
    int i;
    cout << "Name" << "\t\t" << "Age" << "\t\t" << "Dept id" << "\t\t" << "Company" <<  "\t\t" << "Salary\n";
    for (i = 0; i < array_size; i++)
    { //loop runs till the count is same as the value of temp, which is the end of the file.
        double total = 0;
        cout << a[i].personal_info.name << "\t\t" << a[i].personal_info.age << "\t\t" <<
        a[i].official_info.dept_id << "\t\t" << a[i].official_info.cmp_name << "\t\t" << 
        a[i].official_info.salary;
        cout  << "\n";  
    }
}


double find_average_salary(employee_tag *a, string y,int array_size)
{
    double sum = 0;
    int i;
    double temp = 0;

    for (i = 0; i < array_size - 1; i++)
    {
        if (a[i].official_info.cmp_name == y) 
        {
            sum += a[i].official_info.salary;
            temp++;
        }
    }
    temp = sum / temp;
    return temp;
}

int find_max_salary(employee_tag a[], int array_size)
{
    int i;
    int max = 0;
    for (i = 0; i < array_size; i++)
    {
        if (a[i].official_info.salary > max)
        {
            max = a[i].official_info.salary;
        }
    }
    for (i = 0; i < array_size; i++)
    {
        if (a[i].official_info.salary == max)
        {
        cout << "Name: " <<  a[i].personal_info.name << "\n";
        cout << "Age: " <<  a[i].personal_info.age << "\n";
        cout << "Dept_ID: " <<  a[i].official_info.dept_id << "\n";
        cout << "Company Name: " <<  a[i].official_info.cmp_name << "\n";
        cout << "Salary: $" <<  a[i].official_info.salary << "\n";
        }
    }
}