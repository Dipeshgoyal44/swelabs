#include <iostream>
#include <fstream> 
#include <iomanip>

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

    if (inFile.fail()) // if file doesnt open successfully
    {
        cout << "The File was not opened successfully\n";
        cout << "Please check that the file currently exists\n";
        return 0;
    }
    inFile >> count; // storing number of records in count

    for (i = 0; i < count; i++) // for loop to get the total, min and max
    {
        inFile >> descrip >> price;
        total = total + price; // total for average
        if (max < price) // condition for max
            max = price;
        if (min > price) // condition for min
            min = price;
    }
    inFile.close(); // file close

    // display output in terminal
    cout << "Number of price readings: " << count << "\n";
    cout <<  "Maximum price: " << setprecision(2) << fixed  << max << "\n";
    cout << "Minimum price: " << min << "\n";
    cout << "Average price: " << total / count << "\n";

    ofstream outFile;
    //write output to file.
    outFile.open("output.dat");
    outFile << "Number of price readings: " << count << "\n";
    outFile << "Maximum price: " << setprecision(2) << fixed  << max << "\n";
    outFile << "Minimum price: " << min << "\n";
    outFile << "Average price: " << total / count << "\n";

    outFile.close(); // close output file.

    return 0;
}
