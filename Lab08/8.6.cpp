#include <iostream>
#include <iomanip>

using namespace std;
int calcVolts(int *current, int *resistance, int *voltage);
void dispVolts(int *current, int *resistance, int *voltage);
int main()
{
    int current[10] = {2, 5, 10, 9, 3, 6, 2, 2, 6, 8};
    int resistance[10] = {8, 1, 5, 9, 5, 6, 8, 2, 3, 7};
    int voltage[10];
    calcVolts(current, resistance, voltage);
    dispVolts(current, resistance, voltage);

    return 0;
}
int calcVolts(int *current, int *resistance, int *voltage)
{
    for (int i = 0; i < 10; i++)
    {
        voltage[i] = current[i] * resistance[i];
    }
}
void dispVolts(int *current, int *resistance, int *voltage)
{
    cout << "Current";
    cout << setw(15) << "Resistance";
    cout << setw(16) << "Voltage\n";
    for (int i = 0; i < 10; i++)
    {
        cout << current[i] << setw(15) << resistance[i] << setw(19) << voltage[i] << "\n";
    }
}