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

    hptr = NULL; //intialized to null

    hptr = cptr = nptr;
    nptr = new STUDENTName;
    nptr->letter = 'A';
    cout << "Linked List\n";
    //cout << nptr-> letter << "--> "; //printing nptr
    nptr->next = NULL; //nptr to next =null
    hptr = nptr;
    cptr = nptr;

    nptr = new STUDENTName;
    nptr->letter = 'G';
    //cout << nptr-> letter << "--> "; //printing nptr
    nptr->next = NULL; //nptr to next =null
    hptr->next = nptr;
    cptr = hptr->next;

    nptr = new STUDENTName;
    nptr->letter = 'L';
    //cout << nptr-> letter << "--> "; //printing nptr
    nptr->next = NULL; //nptr to next =null
    hptr->next = nptr;
    cptr = hptr->next;

    nptr = new STUDENTName;
    nptr->letter = 'O';
    //cout << nptr -> letter << "--> "; //printing nptr
    nptr->next = NULL; //nptr to next =null
    hptr->next = nptr;
    cptr = hptr->next;

    nptr = new STUDENTName;
    nptr->letter = 'Y';
    //cout << nptr-> letter << "\n"; //printing nptr
    nptr->next = NULL; //nptr to next =null
    cptr->next = nptr;
    cptr = hptr;

    cout << "Linked List:\n";
    while (cptr != NULL) //runs only when currentptr is not null
    {

        cout << cptr->letter << "\n"; // prints all the letters and number while the loop is running
        cptr = cptr->next;
    }
    return 0;
}