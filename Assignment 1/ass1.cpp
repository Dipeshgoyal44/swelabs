#include <iostream>
using namespace std;

void reverse_array(int array[], int arraylength);

int main()
{
    int number = 0;
    int length = 0;
    int temp = 0;

    cout << "Enter The Number: \n";
    cin >> number;
    length = to_string(number).length();
    int num[length];
    for (int i = length - 1; i >= 0; i--)
    {
        num[i] = number % 10;
        number /= 10;
    }

    switch (length)
    {
    case 2:
        cout << "\nCase 1:\n";
        for (int i = length - 1; i >= 0; i--)
        {
            cout << num[i];
        }
        break;
    case 3:
        cout << "Case 2\n";
        reverse_array(num, length);
        temp = num[0];
        num[0] = num[2];
        num[2] = temp;
        for (int i = length - 1; i >= 0; i--)
        {
            cout << num[i];
        }
        break;
    case 4:
        cout << "Case 3\n";
        break;
    case 5:
        cout << "Case 3\n";
        break;
    case 6:
        cout << "Case 3\n";
        break;
    case 7:
        cout << "Case 3\n";
        break;
    case 8:
        cout << "Case 3\n";
        break;
    }
    return 0;
}

void reverse_array(int array[], int arraylength)
{
    for (int i = 0; i < (arraylength / 2); i++)
    {
        int temporary = array[i]; // temporary wasn't declared
        array[i] = array[(arraylength - 1) - i];
        array[(arraylength - 1) - i] = temporary;
    }
}