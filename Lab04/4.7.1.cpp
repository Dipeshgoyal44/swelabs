#include <iostream>
using namespace std;

int main()
{
    int index;

    cout << "\nEnter The Pollution Index: (1-Less than 35, 2- Between 35-60, 3-Above 60)\n";
    cin >> index;

    switch (index)
    {
    case 1:
        for (int i = 0; i < 5; i++)
        {
            cout <<"Pleasant \n";
        }
        break;

    case 2:
        for (int i = 0; i < 5; i++)
        {
            cout <<"Unpleasant \n";
        }
        break;

    case 3:
        for (int i = 0; i < 5; i++)
        {
            cout <<"Health Hazard \n";
        }
        break;

    default:
        cout << "Error! Invalid Selection";
        break;
    }
}