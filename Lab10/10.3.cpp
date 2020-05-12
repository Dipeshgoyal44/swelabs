#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

//function protypes
void insert(int new_data);
void display();
void BubbleSort(int array[]);

int main()
{
    int array[10];
    
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


void insert(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}
void display()
{
    struct Node *ptr;
    ptr = head;
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



