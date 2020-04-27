#include <iostream>
#include <cstdio>


using namespace std;

int total1(int array[],int arraySize);
int total2(int array[],int arraySize);

int main()
{
    int array[20];
    int i;
    int temp = 0;
    int count= 0;
    int sumTotal = 0;
    int checksum= 0;
    printf("Enter The Credit Card Number Below: \n");
    for (i = 0; i < 20; i++)
    {
       cin >> temp; // can i use scanf in c++ with cstdlib
        if (temp != -1) // stores till -1 is entered
        {
            array[i] = temp;
            count++;
        }
        else
            break;
    }
    cout << "The Credit Card number is: ";
    int c;
    for (c = 0; c < count; c++)
    {
        cout <<array[c];
    }
    cout << "\n";
// SUM 1
    int sum1 = total1(array,count);
    cout << "Sum 1 is " << sum1 << "\n";
    // SUM 2 
    int sum2 = total2(array,count);
    cout << "Sum 2 is " <<  sum2 << "\n";
    // CheckSum
    sumTotal = sum1 + sum2;
    sumTotal = sumTotal * 9;
    checksum = sumTotal % 10;
    cout << "Check sum is " << checksum << "\n";
    cout << "The last digit of the credit card is " << array[count - 1] << "\n";
    if (array[count - 1] == checksum)
    {
        cout << "Check sum digit "<< checksum << " and the last digit " << array[count - 1] << " are the same: Valid credit card number. \n";
    }
    else
    {
        cout << "Check sum digit "<< checksum << "and the lastdigit " << array[count - 1] << " are not the same: Invalid credit card number. \n";
    }
    return 0;
}


int total1(int array[],int arraySize)
{
    int total1=0;
    int i = 0;
    int x= 0;
    int sum= 0;
    int temp[10];
    int count = 0;
    cout<< "Numbers for sum1 are ";
    for (i = arraySize - 2; i >= 0; i = i - 2)
    {
        temp[count + 1] = array[i];
        count++;
        x = array[i] * 2;
        if (x > 9)
        {
            x = x % 10;
            sum = 1 + x;
            total1 = total1 + sum;
        }
        else
        {
            total1 += array[i] * 2;
        }
    }
    for (i = count; i > 0; i--)
    {
        cout << temp[i] << " ";


    }
    cout <<  "\n";   
    return total1;
}


int total2(int array[],int arraySize)
{
    int total2= 0;
    int i = 0;
    int temp[10];
    int count = 0;
    cout<< "Numbers for sum2 are ";
    for(i = arraySize - 3; i >= 0; i = i - 2)
    {
        temp[count + 1] = array[i];
        count++;
        total2 = total2 + array[i]; 
        }
    for (i = count; i > 0; i--)
    {
        cout << temp[i] << " ";
    }
    cout <<  "\n";   
    return total2;
}