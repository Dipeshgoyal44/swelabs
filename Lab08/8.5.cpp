#include <iostream>

using namespace std;

//Function Prototype
void reorder(int *a , int *b, int *c);

int main()
{
    int a = 9;
    int b = 6;
    int c = 7;
    
    cout << "Enter the value for A \n";
    cin >> a;
    cout << "Enter the value for B \n";
    cin >> b;
    cout << "Enter the value for C \n";  
    cin >> c;

    reorder(&a,&b,&c);
    cout << "A: " << a << "\n";
    cout << "B: " << b << "\n";
    cout << "C: " << c << "\n";

    return 0;

}

//Function with pointers
void reorder(int *a , int *b, int *c)
{
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