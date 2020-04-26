#include <iostream>

using namespace std;

int calcVolts(int current[], int resistance[], int voltage[]);
void dispVolts(int voltage[]);


int main()
{
    int current[10] = {2,5,10,9,3,6,2,2,6,8};
    int resistance[10] = {8,1,5,9,5,6,8,2,3,7};
    int voltage[10];

    calcVolts(current,resistance,voltage);
    dispVolts(voltage);
    return 0;
}

int calcVolts(int current[], int resistance[], int voltage[])
{
    for (int i = 0; i < 10; i++) {
    voltage[i] = current[i] * resistance[i];
    }
}

void dispVolts(int voltage[])
{
    for (int i = 0; i < 10; i++) {
    cout << voltage[i] << "\n";
    }
}