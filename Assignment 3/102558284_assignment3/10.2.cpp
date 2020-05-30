#include <iostream>
#include <string>

using namespace std;

struct studentname
{
    char letter;
    struct studentname *next;
};

typedef struct studentname STUDENTName;
typedef STUDENTName *STUDENTNamePtr;
//self referential structure

int main()
{
    STUDENTName *hptr;
    STUDENTName *cptr;
    STUDENTName *nptr;
    STUDENTName *pptr;

    nptr =  new STUDENTName;
	nptr->letter = 'G';
    nptr -> next = NULL;
	hptr = nptr;

	nptr = new STUDENTName;
	nptr->letter = 'O';
	nptr -> next = NULL;
	hptr->next = nptr;

	nptr = new STUDENTName;
	nptr->letter = 'A';
	pptr = NULL;
	cptr = hptr;
	nptr ->next = cptr;
	hptr = nptr;
	pptr = (hptr ->next)->next;
	cptr = NULL;	

	nptr = new STUDENTName;
	nptr->letter = 'Y';
    nptr -> next = cptr;
	pptr -> next = nptr;
	cptr = pptr;
	
	nptr = new STUDENTName;
	nptr->letter = 'L';
	pptr=hptr->next;
	cptr=pptr->next;
	pptr->next=nptr;
	nptr ->next=cptr;

	cptr = hptr;
	while (cptr !=NULL)
	{
		cout<<cptr -> letter <<"->"; //AGLOY
		cptr = cptr -> next;
	}
}