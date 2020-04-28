#include <iostream>
#include <fstream> // file open header file
#include <string>
#include <iomanip>
#include <cmath> 

using namespace std;

int main()

{
    string filename = "price.dat";
    int descrip;
    double price = 0;
    int count = 0;
    double total = 0;
    float max = 0;
    double min = 10000000; // for condition to satisfy
    int i;

    ifstream inFile;

    inFile.open(filename.c_str());

    if (inFile.fail())
    {
        cout << "The File was not opened successfully\n";
        cout << "Please check that the file currently exists\n";
        return 0;
    }
    inFile >> count;

    for (i = 0; i < count; i++)
    {
        inFile >> descrip >> price;
        //cout << descrip << ' ' << price << endl;
        total = total + price;
        if (max < price)
            max = price;
        if (min > price)
            min = price;
    }

    inFile.close();

    

    cout << "Number of price readings: " << count << "\n";
    cout <<  "Maximum price: " << setprecision(2) << fixed  << max << "\n";
    cout << "Minimum price: " << min << "\n";
    cout << "Average price: " << total / count << "\n";

    ofstream outFile;
    outFile.open("output.dat");
    outFile << "Number of price readings: " << count << "\n";
    outFile << "Maximum price: " << setprecision(2) << fixed  << max << "\n";
    outFile << "Minimum price: " << min << "\n";
    outFile << "Average price: " << total / count << "\n";
    outFile.close();

    return 0;
}
