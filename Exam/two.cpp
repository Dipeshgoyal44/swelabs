#include <iostream>

using namespace std;

struct model_details{
    string brand;
    string type;
    int id;
};

struct vehicle{
        int year;
        double price;
        struct model_details model;
        struct vehicle *next;
};		

typedef struct vehicle Vehicle;
typedef Vehicle *VehiclePtr;

void print_list(Vehicle * head);

int main()
{ 
	VehiclePtr startptr = NULL;   
	VehiclePtr newptr;           
	VehiclePtr crntptr; 	 
	
	newptr =  new Vehicle;
	newptr->model.brand = "Kia";
	newptr -> model.id = 1;
    newptr -> year = 2010;
    newptr -> price = 20000;
	newptr -> next = NULL;
	startptr = newptr;
	
	newptr = new Vehicle;
	newptr->model.brand = "Mazda";
	newptr -> model.id = 2;
    newptr -> year = 2020;
    newptr -> price = 40000;
	newptr -> next = NULL;
	startptr->next = newptr;
	crntptr = startptr;
    print_list(crntptr);
}

void print_list(Vehicle * head)
{
    while (head !=NULL)
	{
		cout<<"\nBrand Name:\t"<<head -> model.brand <<"\nModel ID: \t"<< head -> model.id << "\nModel Year: " << head -> year << "\nPrice: " << head -> price <<endl;
		head = head -> next;
	}
}

