#include <iostream>
#include <ctime>

using namespace std;

typedef struct Node
{
    int data;
    Node *next;
}Node;

Node *hptr = NULL;

//function protypes
void insert(int new_data);
void display();
void BubbleSort(int array[]);

int main()
{
    int array[10];
    srand(time(NULL)); 

    for (int i = 0; i < 10; i++)
    {
    array[i] = rand() % 50 + 1;
    }

    BubbleSort(array);
    for (int i = 0; i < 10; i++)
    {
    insert(array[i]);
    }

    cout << "The linked list is: ";
    display();
    return 0;
}

void insert(int data)
{
    Node *nptr = (Node *)malloc(sizeof(Node));
    nptr->data = data;
    nptr->next = hptr;
    hptr = nptr;
}
void display()
{
    Node *ptr;
    ptr = hptr;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void BubbleSort(int array[]) //bubble sort
{
    int i, j, temp;
    for (i = 0; i < (10 - 1); ++i) //outter loop
    {
        for (j = 0; j < 10 - 1 - i; ++j) //inner loop
        {
            if (array[j] < array[j + 1]) {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}



