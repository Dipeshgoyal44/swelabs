#include <iostream>
using namespace std;

int main()
{
    int index;
    int i;

    cout << "\nEnter The Pollution Index: (1-Less than 35, 2- Between 35-60, 3-Above 60)\n";
    cin >> index;

    switch (index)
    {
    case 1:
        while (i < 5)
        {
            cout << "Pleasant \n";
            i++;
        }
        break;

    case 2:
        while (i < 5)
        {
            cout << "Unpleasant \n";
            i++;
        }
        break;

    case 3:
        while (i < 5)
        {
            cout << "Health Hazard \n";
            i++;
        }
        break;

    default:
        cout << "Error! Invalid Selection";
        break;
    }
}