#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef Node *NodePtr;

//function protypes
void insert(NodePtr *sPtr, char data);
void printList(NodePtr cptr);
double averageList(NodePtr cptr);

int main()
{
    double average;
    NodePtr hptr = NULL;
    srand(time(NULL));
    int data;

    for (int i = 0; i < 10; i++) // generating random numbers
    {
        data = rand() % 50 + 1; // storing random number in data
        insert(&hptr,data);
    }
    cout << "The linked list is: ";
    printList(hptr); // displaying linked list
    average = averageList(hptr);
    cout << "The average of the list is " << average  <<endl;
    return 0;
}

void insert(NodePtr *sPtr, char data )
{
	NodePtr newPtr; 
	NodePtr previousPtr; // pointer to previous node in list
	NodePtr cptr;       //pointer to current node in list
	newPtr = new Node ;	
	if ( newPtr != NULL )  
	{
		newPtr->data = data; 
		newPtr->next = NULL; 
		previousPtr = NULL;
		cptr = *sPtr;

		while ( cptr != NULL && data > cptr ->data)
		{
			previousPtr = cptr; 
			cptr = cptr->next; 
		} 
		//inserts  new node at the start of list
		if ( previousPtr == NULL )
		{
			newPtr->next = *sPtr;
			*sPtr = newPtr;
		} 
		else   // inserts new node between previousPtr and cptr
		{
			previousPtr->next = newPtr;
			newPtr->next = cptr;
		} 
	} 
	else
	{
		cout<<data<<" not inserted. No memory available.\n";
	} 
} 

int isEmpty( NodePtr sPtr )
{
	return sPtr == NULL;
} 

void printList(NodePtr cptr )
{
	//if list is empty
	if ( isEmpty( cptr ))
	{
		cout<<"List is empty.\n" ;
	} 
	else
	{
		cout<<"The list is: " ;
		// while not the end of the list
		while ( cptr != NULL )
		{
			cout<<cptr->data<<"--> ";
			cptr = cptr ->next;
		} 
		cout<<"NULL\n" ;
	} 
} 

double averageList(NodePtr cptr )
{
    double sum = 0;
    int count= 0;
    double average;
    while(cptr != NULL) // till list is NULL
    {
        sum+=cptr->data; //storing the sum of all values
        cptr = cptr->next;
        count++;
    }
    average = sum/count;
    return average;
}