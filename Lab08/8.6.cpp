#include <iostream>

using namespace std;


void reorder(int *a , int *b, int *c);

int main()
{
    int a = 7;
    int b = 3;
    int c = 1;
    
    reorder(&a,&b,&c);
    cout << "A: " << a << "B: " << b << "C: " << c << "\n";

    return 0;

}

void reorder(int *a , int *b, int *c)
{
    int temp = 0;
    if( *a >  *b){ // a bigger than b
    temp = *b; // a stored in temp bigger than b
    *b = *a;
    *a = temp;
    }
    if( *b > *c){
    temp = *c; // a stored in temp bigger than b
    *c = *b;
    *b = temp;
    }
     if( *a > *c){
    temp = *a; // a stored in temp bigger than b
    *a = *c;
    *c = temp;
    }
}