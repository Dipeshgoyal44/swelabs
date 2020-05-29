#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

struct bankEmployee
{
	string name;
	struct bankEmployee *next;
};			

typedef struct bankEmployee BANKEmployee;
typedef BANKEmployee *BANKEmployeePtr;

int main()
{ 
	BANKEmployeePtr startptr = NULL;/*This is question 1 part A*/	   
	BANKEmployeePtr newptr;  /*pointer to a new node*/         
	BANKEmployeePtr prevptr;	/*pointer to the previous node*/   
	BANKEmployeePtr crntptr; 	/*pointer to the current node*/	  	 
	BANKEmployeePtr temp;
	
	newptr =  new BANKEmployee;
	newptr->name = "G";
    startptr=newptr ->next;

	newptr = new BANKEmployee;
	newptr->name = "O";

	newptr = new BANKEmployee;
	newptr->name = "Y";

	newptr = new BANKEmployee;
	newptr->name = "A";
    newptr->next = NULL;
    startptr = newptr;
	
	newptr = new BANKEmployee;
	newptr->name = "L";

	crntptr = startptr;
	while (crntptr !=NULL)
	{
		cout<<crntptr -> name <<"->" <<endl; //AGLOY
		crntptr = crntptr -> next;
	}

}
	
	

