#include <iostream>
#include <fstream> // file open header file
#include <cstdio> // c file 

using namespace std;


int main()

{
    FILE *fp;
    int count, i;
    int a, total = 0, max = 0, min = 1000000, average = 0;
    double b;

    fp = fopen("price.dat", "r");
    if (fp == NULL)
    {
        cout << " Error in opening the file....\n";
        return 0;
    }
    fscanf(fp, "%d", &count);
    
    for (i = 0; i < 10; i++)
    {
        fscanf(fp, "%d%f", &a, &b);
        printf("%d           %.2f \n", a, b);
        total = total + b;
        if (max < b)
            max = b;
        if (min > b)
            min = b;
    }
   
    // printf("The total is = %d \n", total);
    // printf("The average is = %d \n", total / count);
    // printf("The max is =%d \n", max);
    // printf("The min is =%d \n", min);
//  fp = fopen("output.txt", "a");
    // fprintf(fp, "The total is = %d \n", total);
    // fprintf(fp, "The average is = %d \n", total / count);
    // fprintf(fp, "The max is =%d \n", max);
    // fprintf(fp, "The min is =%d \n", min);

    return 0;
}
