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
double find_average_salary(employee_tag a[], string y);


int main()
{   
    int max = 0;
    employee_tag employee[100];
    int array_size =0;

    read_file(employee, &array_size);
    display_students(employee, array_size);
    cout << "MAX SALARY \n";
    max =  find_max_salary(employee,array_size);
    cout << "Max Salary is: " << max << "\n";
    return 0;
}

void menu()
{
    cout << "\nEnter your choice\n" <<
        "(2)Enter 1 to display the grade details.\n" <<
        "(3)Enter 2 to print the employee's detail with \n" <<
        "(4)Enter 4 to calculate average salary of particular company\n" <<
        "(5)Enter 5 to Exit.\n";

}

void display_students(employee_tag a[], int array_size) //display function
{
    int i;
    for (i = 0; i < array_size - 1; i++)
    { //loop runs till the count is same as the value of temp, which is the end of the file.
        double total = 0;
        cout << "Name :" <<  a[i].personal_info.name << "\n";
        cout << "Age :" <<a[i].personal_info.age<< "\n";
        cout << "Department ID :" <<a[i].official_info.dept_id << "\n";
        cout << "Employee Name: " <<a[i].official_info.cmp_name << "\n";
        cout << "Salary :" <<a[i].official_info.salary << "\n";
        cout  << "\n";  
    }
}


int read_file(employee_tag a[],int * array_size) //readfile function
{
    int count;
    double total = 0;
    string filename = "data.txt"; // filename
    ifstream inFile;

    inFile.open(filename.c_str());

    if (inFile.fail()) // if file doesnt open successfully
    {
        cout << "The File was not opened successfully\n";
        cout << "Please check that the file currently exists\n";
        return 0;
    }
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


double find_average_salary(employee_tag a[], string y)
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
    return max;
}

