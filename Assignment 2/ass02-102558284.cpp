#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int total1(int array[],int arraySize);
int total2(int array[],int arraySize);
void reverse_array(int array[], int length);

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
        scanf("%d", &temp);
        if (temp != -1) // stores till -1 is entered
        {
            array[i] = temp;
            count++;
        }
        else
            break;
    }
    printf("The Credit Card number is: ");
    int c;
    for (c = 0; c < count; c++)
    {
        cout <<array[c];
    }
    printf("\n");


// SUM 1
    int sum1 = total1(array,count);
    printf("Sum 1 is %d \n", sum1);

    // SUM 2 
    int sum2 = total2(array,count);
    printf("Sum 2 is %d \n", sum2);

    // CheckSum
    sumTotal = sum1 + sum2;
    sumTotal = sumTotal * 9;
    checksum = sumTotal % 10;

    printf("Check sum is %d \n", checksum);
    printf("The last digit of the credit card is %d \n", array[count - 1]);

    if (array[count - 1] == checksum)
    {
        printf("Check sum digit %d and the last digit %d are the same: Valid credit card number. \n", checksum, array[count - 1]);
    }
    else
    {
        printf("Check sum digit %d and the last digit %d are not the same: Invalid credit card number. \n", checksum, array[count - 1]);
    }
    return 0;
}

int total1(int array[],int arraySize)
{
    int total1=0;
    int i = 0;
    int x= 0;
    int sum= 0;
    cout<< "Numbers for sum1 are ";
    for (i = arraySize - 2; i >= 0; i = i - 2)
    {
        cout<<  array[i] << " ";   
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
    cout <<  "\n";   
    return total1;

}

int total2(int array[],int arraySize)
{
    int total2= 0;
    int i = 0;
    cout<< "Numbers for sum2 are ";
    for(i = arraySize - 3; i >= 0; i = i - 2)
    {
        total2 = total2 + array[i];
        cout<<  array[i] << " ";   
        }
        cout <<  "\n";   
    return total2;
    
}



