#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double PI = 3.14159; // PI VALUE
    float resistance, frequency, capacitance, inductance, EMF, current ,calc1,calc2 = 0; // Variable Declarations
    // Asks for input and stores user input
    cout<<"Enter the Resistance: \n";
    cin>> resistance;
    cout<<"Enter the frequency: \n";
    cin>> frequency;
    cout<<"Enter the capacitance: \n";
    cin>> capacitance;
    cout<<"Enter the inductance: \n";
    cin>> inductance;
    cout<<"Enter the EMF: \n";
    cin>> EMF;
    
    calc1 = 2 * PI * frequency * inductance ;  // Calculation divided in 2 parts
    calc2 = 2 * PI * frequency * capacitance ; // Calculation divided in 2 parts
    current = EMF / sqrt(pow(resistance,2)+ pow(calc1 - 1 / calc2,2)); //Both calculations combined
    cout<< "The current is " << current << " Amps\n"; //Result Displayed
    return 0;
}
