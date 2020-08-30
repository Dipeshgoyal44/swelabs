#include <iostream>

using namespace std;


int main()
{
    int input = 0;
    double voltage;
    double current;
    int power;
    double resistance;
    
    do {
    cout << "Menu\n" 
         << "-----" <<
        "\n1. Calculate power\n" <<
        "2. Calculate resistance\n" <<
        "3. Quit program\n" <<
        "___________________________\n" <<
        "Enter your choice (1,2, or 3): 5\n";
        
    cin >> input;
    
    switch (input)
    {
    case 1:
    cout << "\nEnter voltage: ";
    cin >>voltage;
    cout << "\nEnter current: ";
    cin >>current;
    power = voltage * current;
    cout << "Power  = " << power << " Watts\n";
        break;  

    case 2:
    cout << "\nEnter voltage: ";
    cin >>voltage;
    cout << "\nEnter current: ";
    cin >>current;
    resistance = voltage / current;
    cout << "resistance  = " << resistance << " Ohms\n";
        break;
        
    case 3:
    cout << "Ending program!...\n";
        return 0;
        break; 

    default:
        cout << "Invalid input!(Enter a number between 1 and 3\n";
        break;
    }}while(input != 3);
}




