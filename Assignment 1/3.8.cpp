#include <iostream>
#include <cmath>   //calculations
#include <iomanip> // for setwidth function
#include <string>  // For getline

/* This program produces a text-based form displaying data about a particular computer. */

using namespace std;

int main()
{
    //Variable Declarations
    string username, empname , mac, serialno;
    char pctype;
    double cpuspeed;
    unsigned long long int IP = 0; // The integer data type wasn't big enough to store the ip so used long long.
    int cores = 0;
    unsigned int iP_part_1, iP_part_2, iP_part_3, iP_part_4 = 0;

    // User Prompts
    cout << " Please Enter The Username: ";
    getline(cin, username);
    cout << "\n Please Enter The Employee Name: ";
    getline(cin, empname);
    cout << "\n Please Enter The PC serial number(max 10): ";
    cin >> serialno;
    cout << "\n Please Enter The PC type (S=Server, D= Dekstop, L=Laptop, T=Tablet, P= Phone) : ";
    cin >> pctype;
    cout << "\n Please Enter The Number Of Cores: ";
    cin >> cores;
    cout << "\n Please Enter The CPU Speed (GHz) : ";
    cin >> cpuspeed;
    cout << "\n Please Enter The MAC Address : ";
    cin >> mac;
    cout << "\n Please Enter The IPV4 Address Without The Dots (e.g. 111 222 333 444) : "; // Stores ip in different variables
    cin >> iP_part_1;
    cin >> iP_part_2;
    cin >> iP_part_3;
    cin >> iP_part_4;

    //Calculates IP
    IP = iP_part_1 * pow(256., 3) + iP_part_2 * pow(256., 2) + iP_part_3 * 256 + iP_part_4;

    //DISPLAY
    // First Line
    cout << "\n __________" << setw(67)
    << "+ \n";
    cout << "| User: "
    << username << "|" << setw(10)
    << "Employee:" << setw(20)
    << empname << "|" << setw(8)
    << "Serial:" << setw(12)
    << serialno << setw(8)
    << "| \n";

    // Second Line
    cout << " __________" << setw(67)
    << "+ \n";

    cout << "| Type: "
    << pctype << "|" << setw(7)
    << "Cores:" << setw(3)
    << cores << " |" << setw(5)
    << "Speed:" << setw(5)
    << cpuspeed << "Ghz "
    << "|" << setw(5)
    << "MAC:" << setw(10)
    << mac << " |" << setw(3)
    << " IP:" << setw(4)
    << iP_part_1 << "." << iP_part_2 << "." << iP_part_3 << "." << iP_part_4 << setw(4)
    << "| \n";

    // Second Line
    cout << " __________" << setw(67)
    << "+ \n";

    // Third Line
    cout << "|" << setw(40)
    << "IP Address as integer:" << setw(11)
    << IP << setw(26)
    << "| \n";

    cout << setw(78) << "+ \n";

    return 0;
}
