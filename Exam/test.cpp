#include <iostream>
#include <fstream>

using namespace std;

void readData(ifstream &inFile, double * array, int *array_size);
double findAverage(double * array, int size);

int main()
{
    double array[10];
    int count = 0;
    string filename = "data.txt";

    ifstream inFile;

    inFile.open(filename.c_str());

    if (inFile.fail())
    {
        cout << "The File was not opened successfully\n";
        return 0;
    }
    readData(inFile,array,&count);
    cout << "The average is : " << findAverage(array,count);
    return 0;
}

void readData(ifstream &inFile, double * array, int *array_size)
{
    int i = 0;
    while (inFile.peek() != EOF)
    {
        inFile >> array[i];
        i++;
    }
    *array_size = i;
}

double findAverage(double * array, int size)
{
    double sum = 0;
    double average = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return  average = sum / size;
}
