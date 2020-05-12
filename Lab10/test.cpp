#include <iostream>

using namespace std;

/* self-referential structure*/

struct listNode
{
    int data;                /* each listNode contains a character*/
    struct listNode *nextPtr; /*pointer to next node*/
};                            /* end structure listNode*/
typedef listNode *ListNodePtr;


/* prototypes*/
void insert(ListNodePtr *sPtr, char value);
char remove(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);
int main(void)
{
    ListNodePtr startPtr = NULL; /* initially there are no nodes*/
    unsigned int choice;         /*	 user's choice*/
    char item;                   /* char entered by user*/
    instructions();              /* display the menu*/
    cout << "?";
    cin >> choice;
    /* loop while user does not choose 3*/
    while (choice != 3)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter a character:";
            cin >> item;
            insert(&startPtr, item); /* insert item in list*/
            printList(startPtr);
            break;
        case 2: /* delete an element*/
            /* if list is not empty*/
            if (!isEmpty(startPtr))
            {
                cout << "Enter character to be deleted: ";
                cin >> item;
                /* if character is found, remove it*/
                if (remove(&startPtr, item)) /* remove item*/
                {
                    cout << item << "deleted.\n";
                    printList(startPtr);
                } /* end if*/
                else
                {
                    cout << item << " not found.\n\n";
                } /* end else*/
            }     /* end if*/
            else
            {
                cout << "List is empty.\n";
            } /* end else*/
            break;
        default:
            cout << "Invalid choice.\n";
            instructions();
            break;
        } /* end switch*/
        cout << "? ";
        cin >> choice;
    } /* end while*/
    cout << "End of run.";
} /* end main*/
/* display program instructions to user*/
void instructions(void)
{
    cout << "Enter your choice:\n"
            " 1 to insert an element into the list.\n"
            " 2 to delete an element from the list.\n"
            " 3 to end.";
} /* end function instructions*/
/* insert a new value into the list in sorted order*/
void insert(ListNodePtr *sPtr, char value)
{
    ListNodePtr newPtr;      /* pointer to new node*/
    ListNodePtr previousPtr; /* pointer to previous node in list*/
    ListNodePtr currentPtr;  /*	pointer to current node in list*/
    newPtr = new listNode;   /* create node*/
    if (newPtr != NULL)      /* is space available*/
    {
        newPtr->data = value;   /* place value in node*/
        newPtr->nextPtr = NULL; /*	node does not link to another node*/
        previousPtr = NULL;
        currentPtr = *sPtr;
        /* loop to find the correct location in the list*/
        while (currentPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr;         /* walk to ...*/
            currentPtr = currentPtr->nextPtr; /* ... next node*/
        }                                     /* end while*/
        /* insert new node at beginning of list*/
        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }    /* end if*/
        else /* insert new node between previousPtr and currentPtr*/
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } /* end else*/
    }     /* end if*/
    else
    {
        cout << value << " not inserted. No memory available.\n";
    } /* end else*/
} /* end function insert*/
/* delete a list element*/
char remove(ListNodePtr *sPtr, char value)
{
    ListNodePtr previousPtr; /* pointer to previous node in list*/
    ListNodePtr currentPtr;  /* pointer to current node in list*/
    ListNodePtr tempPtr;     /* temporary node pointer*/
    /* delete first node*/
    if (value == (*sPtr)->data)
    {
        tempPtr = *sPtr;          /* hold onto node being removed*/
        *sPtr = (*sPtr)->nextPtr; /* de-thread the node*/
        delete (tempPtr);         /* free the de-threaded node*/
        return value;
    } /* end if*/
    else
    {
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;
        /* loop to find the correct location in the list*/
        while (currentPtr != NULL && currentPtr->data != value)
        {
            previousPtr = currentPtr;         /* walk to ...*/
            currentPtr = currentPtr->nextPtr; /*... next node*/
        }                                     /*	end while*/
        /* delete node at currentPtr*/
        if (currentPtr != NULL)
        {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            delete (tempPtr);
            return value;
        } /* end if*/
    }     /* end else*/
    return '\0';
} /* end function delete*/
/* return 1 if the list is empty, 0 otherwise*/
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
} /* end function isEmpty*/
/* print the list*/
void printList(ListNodePtr currentPtr)
{
    /* if list is empty*/
    if (isEmpty(currentPtr))
    {
        cout << "List is empty.\n";
    } /* end if*/
    else
    {
        cout << "The list is: ";
        /* while not the end of the list*/
        while (currentPtr != NULL)
        {
            cout << currentPtr->data << "--> ";
            currentPtr = currentPtr->nextPtr;
        } /* end while*/
        cout << "NULL\n";
    } /* end else*/
} /* end function printList */