#include <iostream>
using namespace std;

void reverse_array(int array[], int arraylength);
int decode(int array[]);

int main()
{
    int number = 0;
    int length = 0;
    int temp = 0;

    cout << "Enter The Number: \n";
    cin >> number;
    length = to_string(number).length();
    int num[length];
    cout << "Number contains " << length << " digits\n";
    for (int i = length - 1; i >= 0; i--)
    {
        num[i] = number % 10;
        number /= 10;
    }

    switch (length)
    {
    case 2:
        for (int i = length - 1; i >= 0; i--)
        {
            cout << "The encoded number is " << num[i];
        }
        break;
    case 3:
        reverse_array(num, length);
        temp = num[0];
        num[0] = num[2];
        num[2] = temp;
        cout << "The encoded number is ";
        for (int i = length - 1; i >= 0; i--)
        {
            cout << num[i];
        }
        break;
    case 4:
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
        {
            int calc = (num[i - 1] + i) % 10;
            cout << calc;
        }
        if (num[0] > 0)
        {
            num[0] = num[0] - 1;
        }
        else
        {
            num[0] = 9;
        }
        if (num[1] > 1)
        {
            num[1] = num[1] - 2;
        }
        else
        {
            num[1] = num[1] + 8;
        }
        if (num[2] > 2)
        {
            num[2] = num[2] - 3;
        }
        else
        {
            num[2] = num[2] + 7;
        }
        if (num[3] > 3)
        {
            num[3] = num[3] - 4;
        }
        else
        {
            num[3] = num[3] + 6;
        }
        if (num[4] > 4)
        {
            num[4] = num[4] - 5;
        }
        else
        {
            num[4] = num[4] + 5;
        }
        for (int i = length - 1; i >= 0; i--)
        {
            cout << "\n"
                 << num[i];
        }
        break;
    case 5:
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
        {
            int calc = (num[i - 1] + i) % 10;
            cout << calc;
        }
        if (num[0] > 0)
        {
            num[0] = num[0] - 1;
        }
        else
        {
            num[0] = 9;
        }
        if (num[1] > 1)
        {
            num[1] = num[1] - 2;
        }
        else
        {
            num[1] = num[1] + 8;
        }
        if (num[2] > 2)
        {
            num[2] = num[2] - 3;
        }
        else
        {
            num[2] = num[2] + 7;
        }
        if (num[3] > 3)
        {
            num[3] = num[3] - 4;
        }
        else
        {
            num[3] = num[3] + 6;
        }
        if (num[4] > 4)
        {
            num[4] = num[4] - 5;
        }
        else
        {
            num[4] = num[4] + 5;
        }
        for (int i = length - 1; i >= 0; i--)
        {
            cout << "\n"
                 << num[i];
        }
        break;
    case 6:
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
        {
            cout << (num[i - 1] + i) % 10;
        }
        break;
    case 7:
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
        {
            cout << (num[i - 1] + i) % 10;
        }
        break;
    case 8:
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
        {
            cout << (num[i - 1] + i) % 10;
        }
        break;
    }
    return 0;
}

int decode(int array[])
{
    if (array[0] > 0)
    {
        array[0] = array[0] - 1;
    }
    else
    {
        array[0] = 9;
    }
    if (array[1] > 1)
    {
        array[1] = array[1] - 2;
    }
    else
    {
        array[1] = array[1] + 8;
    }
    if (array[2] > 2)
    {
        array[2] = array[2] - 3;
    }
    else
    {
        array[2] = array[2] + 7;
    }
    if (array[3] > 3)
    {
        array[3] = array[3] - 4;
    }
    else
    {
        array[3] = array[3] + 6;
    }
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