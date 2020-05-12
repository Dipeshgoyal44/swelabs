#include <iostream>
#include <string>

using namespace std;

struct studentname {
    char letter;
    struct studentname *next; 
    };  
typedef struct studentname STUDENTName;
typedef STUDENTName *STUDENTNamePtr;
//self referential structure

int main() {
    
STUDENTName *hptr;  
STUDENTName *cptr; 
STUDENTName *nptr;  

hptr = NULL; //intialized to null

nptr = (STUDENTNamePtr)malloc(sizeof(STUDENTNamePtr)); //assigning memory to nptr
hptr = cptr = nptr; 
nptr = new STUDENTName;
nptr -> letter = 'A';
cout << "Linked List\n";
cout << nptr-> letter << "--> "; //printing nptr
nptr->next = NULL; //nptr to next =null

nptr = (struct studentname*)malloc(sizeof(struct studentname)); //assigning memory to nptr
nptr = new STUDENTName;
nptr -> letter = 'G';
cout << nptr-> letter << "--> "; //printing nptr
nptr->next = NULL; //nptr to next =null

nptr = (struct studentname*)malloc(sizeof(struct studentname)); //assigning memory to nptr
nptr = new STUDENTName;
nptr -> letter = 'L';
cout << nptr-> letter << "--> "; //printing nptr
nptr->next = NULL; //nptr to next =null

nptr = (struct studentname*)malloc(sizeof(struct studentname)); //assigning memory to nptr
nptr = new STUDENTName;
nptr -> letter = 'O';
cout << nptr -> letter << "--> "; //printing nptr
nptr->next = NULL; //nptr to next =null

nptr = (struct studentname*)malloc(sizeof(struct studentname)); //assigning memory to nptr
nptr = new STUDENTName;
nptr -> letter = 'Y';
cout << nptr-> letter << "\n"; //printing nptr
nptr->next = NULL; //nptr to next =null
cptr = hptr; 
return 0;
}