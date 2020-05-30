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
    newptr -> next = NULL;
	startptr = newptr;

	newptr = new BANKEmployee;
	newptr->name = "O";
	newptr -> next = NULL;
	startptr->next = newptr;

	newptr = new BANKEmployee;
	newptr->name = "Y";
	prevptr = NULL;
	crntptr = startptr;
	newptr ->next = crntptr;
	startptr = newptr;
	prevptr = (startptr ->next)->next;
	crntptr = NULL;	

	newptr = new BANKEmployee;
	newptr->name = "A";
    newptr -> next = crntptr;
	prevptr -> next = newptr;
	crntptr = prevptr;
	
	newptr = new BANKEmployee;
	newptr->name = "L";
	prevptr=startptr->next;
	crntptr=prevptr->next;
	prevptr->next=newptr;
	newptr ->next=crntptr;

	crntptr = startptr;
	while (crntptr !=NULL)
	{
		cout<<crntptr -> name <<"->" <<endl; //AGLOY
		crntptr = crntptr -> next;
	}
}
	
	

