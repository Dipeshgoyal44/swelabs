#include <iostream>

using namespace std;


void reorder(int *a , int *b, int *c);

int main()
{
    int a = 9;
    int b = 6;
    int c = 7;
    
    reorder(&a,&b,&c);
    cout << "A: " << a << "B: " << b << "C: " << c << "\n";

    return 0;

}

void reorder(int *a , int *b, int *c)
{
    int temp = 0;
    if(*a>*b && *a>*c)
    {
        temp=*c;
        *c=*a;
        *a=temp;
        if(*a>*b)
        {
            temp=*b;
            *b=*a;
            *a=temp;
        }
    }
    if(*b>*a && *b>*c)
    {
        temp=*c;
        *c=*b;
        *b=temp;
    }
}