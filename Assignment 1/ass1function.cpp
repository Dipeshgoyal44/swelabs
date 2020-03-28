#include <iostream>
using namespace std;

// Function Prototypes
void reverse_array(int array[], int arraylength);
int encode(int array1[], int array2[], int arraylength,int result);
void decode(int array[], int arraylength,int result); 

int main()
{
    //Variables
    int number = 0;
    int length = 0;
    int calc = 0;
    int j;

    //Do while loop for validation of input
    do
    {
        cout << "Enter The Number: \n"; //Prompt to enter input
        cin >> number;
        if (number < 10 || number > 99999999) // condition if input out of range
        {
            cout << "Not a valid input, re enter the number\n"; // display if out of range
        }
    } while (number < 10 || number > 99999999); //while condition

    length = to_string(number).length();                 //convering the input into string to check no. of digits and storing in length
    int num[length];                                     // using the length for array size.
    cout << "Number contains " << length << " digits\n"; //Display how many digits in the input

    for (int i = length - 1; i >= 0; i--) // Loop to store the input entered into the array backwards
    {
        num[i] = number % 10;
        number /= 10;
    }
    int array[length]; // Second array initiliazation

    switch (length) // Switch statement based on the length of the input
    {
    case 2:
        cout << "The encoded number is ";     //Encoded Number
        for (int i = length - 1; i >= 0; i--) // Backwards loop to  to encode the input
        {
            cout << num[i];
        }
        reverse_array(num, length);           // reversing the encoded array to decode
        cout << "\nThe decoded number is ";   //Decoded Number
        for (int i = length - 1; i >= 0; i--) // Loop to display the decoded output
        {
            cout << num[i];
        }
        break;
    case 3:
        cout << "The encoded number is ";     //Encoded Number
        for (int i = length - 1; i >= 0; i--) // Backwards loop to  to encode the input
        {
            cout << num[i];
        }
        reverse_array(num, length);           // reversing the encoded array to decode
        cout << "\nThe decoded number is ";   //Decoded Number
        for (int i = length - 1; i >= 0; i--) // Loop to display the decoded output
        {
            cout << num[i];
        }
        break;
    case 4:
        reverse_array(num, length); // reversing the array
        cout << "The encoded number is "; //Encoded Number
        encode(num,array,length,calc);
        cout << "\nThe decoded number is "; //Decoded Number
        //reverse_array(array, length); // reversing the array
        decode(array, length,calc); //decode function passing the array that stored calc values
        reverse_array(array, length); // reversing the array
        for (int i = 0; i < length; i++) // loop to display decoded value
        {
            cout << array[i];
        }
        break;
        // the same process is used for rest of the cases till 7
    // case 5:
    //     reverse_array(num, length);
    //     cout << "The encoded number is ";
    //     for (int i = length; i >= 1; i--)
    //     {
    //         calc = (num[i - 1] + i) % 10;
    //         array[j] = calc;
    //         j++;
    //         cout << calc;
    //     }
    //     cout << "\nThe decoded number is ";
    //     reverse_array(array, length);
    //     decode(array, length);
    //     reverse_array(array, length);
    //     for (int i = 0; i < length; i++)
    //     {
    //         cout << array[i];
    //     }
    //     break;
    // case 6:
    //     reverse_array(num, length);
    //     cout << "The encoded number is ";
    //     for (int i = length; i >= 1; i--)
    //     {
    //         calc = (num[i - 1] + i) % 10;
    //         array[j] = calc;
    //         j++;
    //         cout << calc;
    //     }
    //     cout << "\nThe decoded number is ";
    //     reverse_array(array, length);
    //     decode(array, length);
    //     reverse_array(array, length);
    //     for (int i = 0; i < length; i++)
    //     {
    //         cout << array[i];
    //     }
    //     break;
    // case 7:
    //     reverse_array(num, length);
    //     cout << "The encoded number is ";
    //     for (int i = length; i >= 1; i--)
    //     {
    //         calc = (num[i - 1] + i) % 10;
    //         array[j] = calc;
    //         j++;
    //         cout << calc;
    //     }
    //     cout << "\nThe decoded number is ";
    //     reverse_array(array, length);
    //     decode(array, length);
    //     reverse_array(array, length);
    //     for (int i = 0; i < length; i++)
    //     {
    //         cout << array[i];
    //     }
    //     break;
    // case 8:
    //     string choice;  // variable for extra protection
    //     cout << "Do you want to do a second level of encryption, enter yes or no? "; // prompt
    //     cin >> choice;
    //     if (choice == "yes")
    //     { //condition if yes to prompt
    //         reverse_array(num, length);
    //         cout << "The encoded number is ";
    //         for (int i = length; i >= 1; i--)
    //         {
    //             num[i - 1] = (num[i - 1] + i) % 10; //extra protection encoding
    //         }
    //         for (int i = 0; i < length; i++)
    //         {
    //             cout << num[i]; // prints encoded number
    //         }
    //         cout << "\nThe decoded number is ";
    //         decode(num, length); // decode the number
    //         reverse_array(num, length); // reverses the number
    //         for (int i = 0; i < length; i++)
    //         {
    //             cout << num[i]; // prints the decoded number
    //         }
    //         //WORKING!
    //     }
    //     else
    //     { // condition if no to the prompt
    //         reverse_array(num, length);
    //         cout << "The encoded number is ";
    //         for (int i = length; i >= 1; i--) // the normal 8 digit encoding if choice is no
    //         {
    //             calc = (num[i - 1] + i) % 10;
    //             array[j] = calc;
    //             j++;
    //             cout << calc;
    //         }
    //         cout << "\nThe decoded number is ";
    //         reverse_array(array, length);
    //         decode(array, length);
    //         reverse_array(array, length);
    //         for (int i = 0; i < length; i++)
    //         {
    //             cout << array[i];
    //         }
    //         break;
    //     }
    }
    return 0;
}

int encode(int array1[], int array2[], int arraylength,int result)
{
    for (int i = arraylength; i >= 1; i--)// Backwards loop to  to encode the input
        {
            result = (array1[i - 1] + i) % 10; // the encoded logic from vid and stored in var calc
            cout << result; //prints encoded number 
        }
        return result;
        
}

void decode(int array2[], int arraylength,int result) // function to decode logic taken from video
{
    for (int i = 0; i < arraylength; i++)
    {
        int j = 0;
        array2[j] = result; // initializing array to calc and storing the values in array to be used later
        j++; //increments everytime the loop runs
    }
   for (int i = arraylength; i >= 1; i--)
    {
        array2[i] += 9 - i;
        array2[i] = array2[i] % 10;   
    }
}
void reverse_array(int array[], int arraylength) // Function to reverse arrays that are passed
{
    for (int i = 0; i < (arraylength / 2); i++)
    {
        int temporary = array[i];
        array[i] = array[(arraylength - 1) - i];
        array[(arraylength - 1) - i] = temporary;
    }
}
