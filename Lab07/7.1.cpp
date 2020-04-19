#include <iostream>
#include <fstream> // file open header file

using namespace std;

int main()
{
    int count, stor[100];
    char filename[10]={"price.dat"};
    readFile(filename,stor, count);
    show(count,, stor);
    system("pause");
    return 0 ;
}

void readFile(char Price[], int storage [], int &noP)
{
    ifstream take(Price);
    take >> noP;
    for (int i = 0; i < noP; i++)
    {
        take >> storage[i];
    }




}