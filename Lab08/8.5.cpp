#include <iostream>

using namespace std;

//Function Prototype
void reorder(int *a , int *b, int *c);

int main()
{
    int a;
    int b;
    int c;
    
    //Ask user to enter data
    cout << "Enter the value for A \n";
    cin >> a;
    cout << "Enter the value for B \n";
    cin >> b;
    cout << "Enter the value for C \n";  
    cin >> c;

    // pass the address to function so it changes original values too.
    reorder(&a,&b,&c);
    //displaying results
    cout << "A: " << a << "\n";
    cout << "B: " << b << "\n";
    cout << "C: " << c << "\n";

    return 0;

}

//Function with pointers
void reorder(int *a , int *b, int *c)
{
    //if statements to order the integers
    int temp = 0;
    if(*a>*c)
    {
        temp=*c;
        *c=*a;
        *a=temp;
    }
    if(*a>*b)
        {
            temp=*b;
            *b=*a;
            *a=temp;
        }
    if(*b>*c)
    {
        temp=*c;
        *c=*b;
        *b=temp;
    }
    }