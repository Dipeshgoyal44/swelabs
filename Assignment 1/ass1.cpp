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
        cout << "Number contains "<< length << " digits\n";
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
                cout <<  num[i];
            }
            break;
        case 4:
        reverse_array(num, length);
        cout << "The encoded number is ";
            for (int i = length; i >= 1; i--)
            {
                cout << (num[i-1]+i) % 10;
            }
            break;
        case 5:
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
            {
                cout << (num[i-1]+i) % 10;
            }
            break;
        case 6:
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
            {
                cout << (num[i-1]+i) % 10;
            }
            break;
        case 7:
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
            {
                cout << (num[i-1]+i) % 10;
            }
            break;
        case 8:
        reverse_array(num, length);
        cout << "The encoded number is ";
        for (int i = length; i >= 1; i--)
            {
                cout << (num[i-1]+i) % 10;
            }
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