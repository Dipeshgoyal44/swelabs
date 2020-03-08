#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x,y,voltage=0; // Variable Decalaration
    int stage = 0;
    cout<<"Enter the frequency: \n"; // User Prompts
    cin>> x;
    cout<<"Enter the stage of the amplifier: \n";
    cin>> stage;
    voltage = pow((275 / sqrt(pow(23,2) + 0.5 * pow(x,2))),stage); //Calculation
    cout<< "At a frequency of " << x <<" hertz, the voltage gain is " <<voltage; //Output
    return 0;
}
