#include <iostream>

using namespace std;

template <typename T> 
T Min(T x, T y)
{ 
    if(x>y){
        return y;
    }else if(x<y){
        return x;
    }else{
        return -1;
    }
} 

int main()
{
    int a= 0;
    float b =0;
    cout << "Integer Values: \n";
    a = Min<int>(10, 5);
    if(a==-1){
        cout << "Both values are equal\n";
    }else{
        cout << a << " is smaller\n";
    }
    cout << "Float Values: \n";
    b = Min<float>(3.50, 3.70);
    if(b==-1){
        cout << "Both values are equal\n";
    }else{
        cout << b << " is smaller\n";
    }
    return 0;
}


