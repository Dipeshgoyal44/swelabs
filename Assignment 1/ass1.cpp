#include <iostream>
using namespace std;
void reverse_array(int array[], int arraylength);
void Decode(int array[], int arraylength);
int main()
{
    int number = 0;
    int length = 0;
    int calc = 0;
    int temp1 = 0;
    int temp2 = 0;
    int j;
    string choice;
    do
    {
        cout << "Enter The Number: \n";
        cin >> number;
        if (number < 10 || number > 99999999)
        {
            cout << "Not a valid input, re enter the number\n";
        }
    } while (number < 10 || number > 99999999);
    length = to_string(number).length();
    int num[length];
    cout << "Number contains " << length << " digits\n";
    for (int i = length - 1; i >= 0; i--)
    {
        num[i] = number % 10;
        number /= 10;
    }
    int array[length];
    switch (length)
    {
    case 2:
        cout << "The encoded number is ";
        for (int i = length - 1; i >= 0; i--)
        {
            cout << num[i];
        }
        reverse_array(num, length);
        cout << "\nThe decoded number is ";
        for (int i = length - 1; i >= 0; i--)
        {
            cout << num[i];
        }
        break;
    case 3:
        // temp = num[0];
        // num[0] = num[2];
        // num[2] = temp;
        cout << "The encoded number is ";
        for (int i = length - 1; i >= 0; i--)
        {
            cout << num[i];
        }
        reverse_array(num, length);
        cout << "\nThe decoded number is ";
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
            calc = (num[i - 1] + i) % 10;
            array[j] = calc;
            j++;
            cout << calc;
        }
        cout << "\nThe decoded number is ";
        reverse_array(array, length);
        Decode(array, length);
        reverse_array(array, length);
        for (int i = 0; i < length; i++)
        {
            cout << array[i];
        }
        break;
    case 5:
       reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
        {
            calc = (num[i - 1] + i) % 10;
            array[j] = calc;
            j++;
            cout << calc;
        }
        cout << "\nThe decoded number is ";
        reverse_array(array, length);
        Decode(array, length);
        reverse_array(array, length);
        for (int i = 0; i < length; i++)
        {
            cout << array[i];
        }
        break;
    case 6:
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
        {
            calc = (num[i - 1] + i) % 10;
            array[j] = calc;
            j++;
            cout << calc;
        }
        cout << "\nThe decoded number is ";
        reverse_array(array, length);
        Decode(array, length);
        reverse_array(array, length);
        for (int i = 0; i < length; i++)
        {
            cout << array[i];
        }
        break;
    case 7:
       reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
        {
            calc = (num[i - 1] + i) % 10;
            array[j] = calc;
            j++;
            cout << calc;
        }
        cout << "\nThe decoded number is ";
        reverse_array(array, length);
        Decode(array, length);
        reverse_array(array, length);
        for (int i = 0; i < length; i++)
        {
            cout << array[i];
        }
        break;

// extra protection not working. need to store encoded extra protection array to pass into decode

    case 8:
        cout << "Do you want to do a second level of encryption, enter yes or no? ";
        cin >> choice;
        if (choice=="yes"){
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
        {
            num[i-1] = (num[i - 1] + i) % 10;
            calc = num[i];
            array[j] = calc;
            j++;
            cout << calc;
        }
        cout << "\nThe decoded number is ";
        reverse_array(array, length);
        Decode(array, length);
        reverse_array(array, length);
        for (int i = 0; i < length; i++)
        {
            cout << num[i];
        }
        } else {
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
        {
            calc = (num[i - 1] + i) % 10;
            array[j] = calc;
            j++;
            cout << calc;
        }
        cout << "\nThe decoded number is ";
        reverse_array(array, length);
        Decode(array, length);
        reverse_array(array, length);
        for (int i = 0; i < length; i++)
        {
            cout << array[i];
        }
        break;
    }}
    return 0;
}
void Decode(int array[], int arraylength)
{
    for (int i = 0; i < arraylength; i++)
    {
        array[i] += 9 - i; 
        array[i] = array[i] % 10;
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