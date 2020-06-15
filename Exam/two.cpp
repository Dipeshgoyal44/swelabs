#include <iostream>

using namespace std;

struct personalDetails{
    string name;
    int age;
};

struct companyDetails
{
	string cmpName;
	double salary;
};		

struct employeeDetails
{
    personalDetails personalInfo;
    companyDetails companyInfo;
    struct employeeDetails *nextptr;
};	

typedef struct employeeDetails EMPLOYEEdetails;
typedef EMPLOYEEdetails *employeeDetailsPtr;

void displayList(employeeDetails * head);

int main()
{ 
	employeeDetailsPtr startptr = NULL;   
	employeeDetailsPtr newptr;           
	employeeDetailsPtr crntptr; 	 
	
	newptr =  new employeeDetails;
	newptr->personalInfo.name = "Alex";
	newptr -> personalInfo.age = 35;
    newptr -> companyInfo.cmpName = "Apple";
    newptr -> companyInfo.salary = 10000;
	newptr -> nextptr = NULL;
	startptr = newptr;
	
	newptr = new employeeDetails;
	newptr->personalInfo.name = "Mary";
	newptr -> personalInfo.age = 44;
    newptr -> companyInfo.cmpName = "Coles";
    newptr -> companyInfo.salary = 5000;
	newptr -> nextptr = NULL;
	startptr->nextptr = newptr;
	crntptr = startptr;
    displayList(crntptr);
}

void displayList(employeeDetails * head)
{
    while (head !=NULL)
	{
		cout<<"\nEmployee Name:\t"<<head -> personalInfo.name <<"\nEmployee Age: \t"<< head -> personalInfo.age << "\nCompany Name: " << head -> companyInfo.cmpName << "\nCompany Salary: " << head -> companyInfo.salary <<endl;
		head = head -> nextptr;
	}
}

