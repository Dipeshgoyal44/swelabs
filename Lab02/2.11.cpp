#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x,y,result=0;
    cout<<"Enter the frequency: \n";
    cin>> x;
    
    result = (275 / sqrt(pow(23,2) + 0.5 * pow(x,2))) *  4;
    cout<<result;
    return 0;
}
