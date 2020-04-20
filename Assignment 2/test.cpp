#include <stdio.h>
int main()
{
int array[20],i = 0, temp=0, count=0, sum=0, total=0,x=0, total2=0, checksum=0;
printf("Enter The Credit Card Number Below: \n");
for (i=0;i<20;i++)
{

scanf("%d", &temp);
if (temp!=-1)
{
array[i]=temp;
count++;
}
else
break;
}

printf("The Credit Card number is: ");
int c;
for (c = 0; c < count; c++)
{

    printf("%d", array[c]);


}
printf("\n");

for(i=count-2; i>=0; i=i-2)
{
    x=array[i]*2;
    if (x>9)
    {
    
            x = x % 10;
            sum = 1 + x;
            total=total+sum;
    }
    else
    {
        total += array[i] * 2;
    }

    
}
printf("Sum 1 is  %d \n", total);

for(i=count - 3; i>=0;i=i-2)
{
    total2 = total2 + array[i];
}
printf("Sum 2 is %d \n", total2);
total = total + total2;

total = total * 9;

checksum = total % 10;

printf("Check sum is %d \n", checksum);
printf("The last digit of the credit card is %d \n", array[count-1]);

if (array[count-1] == checksum) {
    printf("Check sum digit %d and the last digit %d are the same: Valid credit card number. \n", checksum, array[count-1]);
}
else {
    printf("Check sum digit %d and the last digit %d are not the same: Invalid credit card number. \n", checksum, array[count-1]);
}
return 0;
}