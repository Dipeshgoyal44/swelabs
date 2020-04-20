#include <iostream>
#include <fstream> // file open header file
#include <cstdio> // c file 

using namespace std;


int main()

{
    FILE *fp;
    int count, i,a;
    float total, max , average, b;
    float min=10000000; // for the condition to work

    fp = fopen("price.dat", "r");
    if (fp == NULL)
    {
        cout << " Error in opening the file....\n";
        return 0;
    }
    fscanf(fp, "%d", &count);

    for (i = 0; i < count; i++)
    {
        fscanf(fp, "%d %f", &a, &b);
        //printf("%d           %.2f \n", a, b);
        total = total + b;
        if (max < b)
            max = b;
        if (min > b)
            min = b;
    }
    printf("Number of price readings: %d \n", count);
    printf("Maximum price: %.2f \n", max);
    printf("Minimum price: %.2f \n", min);
    printf("Average price: %.2f \n", total / count);
    fp = fopen("output.dat", "a");
    fprintf(fp, "The total is = %d \n", total);
    fprintf(fp, "The average is = %d \n", total / count);
    fprintf(fp, "The max is =%d \n", max);
    fprintf(fp, "The min is =%d \n", min);

    return 0;
}
