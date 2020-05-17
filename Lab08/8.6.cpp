#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

//Function Protypes
int calcVolts(int *current, int *resistance, int *voltage);
void dispVolts(int *current, int *resistance, int *voltage);

int main()
{
    int current[10];
    int resistance[10];
    int voltage[10];
    srand(time(NULL));

    //gettings random numbers for current and resistance
    for(int i = 0; i < 10; ++i) {
    current[i] = rand() % 10 + 1;
    resistance[i] = rand() % 10 + 1;
    }

    calcVolts(current, resistance, voltage); // calculating voltage 
    dispVolts(current, resistance, voltage); // displaying voltage

    return 0;
}

int calcVolts(int *current, int *resistance, int *voltage)
{
    for (int i = 0; i < 10; i++)
    {
        voltage[i] = current[i] * resistance[i]; //mutiplying current with resistance to get voltage
    }
}

void dispVolts(int *current, int *resistance, int *voltage)
{
    //displays results
    cout << "Current";
    cout << setw(15) << "Resistance";
    cout << setw(16) << "Voltage\n";
    for (int i = 0; i < 10; i++)
    {
        cout << current[i] << setw(15) << resistance[i] << setw(19) << voltage[i] << "\n";
    }
}
