#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

int main()
{
    //Variable Declarations
    string username, empname,pctype,mac;
    float cpuspeed;
    long long int IP=0;
    int nocores =0;
    char serialno[10];
    int iP_part_1, iP_part_2, iP_part_3, iP_part_4 = 0;
    
    // User Prompts
    cout<<" Please Enter The Username: ";
    cin>> username;
    cout<<"\n Please Enter The Employee Name: ";
    cin>> empname;
    cout<<"\n Please Enter The PC serial number(max 10): ";
    cin>> serialno;
    cout<<"\n Please Enter The PC type (S=Server, D= Dekstop, L=Laptop, T=Tablet, P= Phone) : ";
    cin>> pctype;
    cout<<"\n Please Enter The Number Of Cores: ";
    cin>> nocores;
    cout<<"\n Please Enter The CPU Speed (GHz) : ";
    cin>> cpuspeed;
    cout<<"\n Please Enter The MAC Address : ";
    cin>> mac;
    cout<<"\n Please Enter The IPV4 Address Without The Dots (e.g. 111 222 333 444) : ";
    cin>> iP_part_1;    
    cin>> iP_part_2;
    cin>> iP_part_3;
    cin>> iP_part_4;
    
    IP = iP_part_1 * pow(256., 3)+iP_part_2 * pow(256., 2) +iP_part_3 * 256 +iP_part_4;
    cout<< IP;

    //DISPLAY

    // First Line 
	cout<< " __________" << setw(67)
	<< "+ \n";
    cout << "| User: "
	<<"   gswinburne |" <<  setw(10) 
	<< "Employee:" <<  setw(20) 
	<< "George Swinburne |" << setw(8) 
	<< "Serial:" << setw(12) 
	<< "130201nxx5"<< setw(5)
	<< "| \n";
	
	// Second Line 
	cout<< " __________" << setw(67)
	<< "+ \n";

	cout << "| Type: "
	<<" D |" <<  setw(7) 
	<< "Cores:" <<  setw(5) 
	<< "2 |" << setw(5) 
	<< "MAC:" << setw(15) 
	<< "005056C00001 |"<< setw(5)
	<< "IP:" << setw(13) 
	<< "136.186.1.10"<< setw(16)
	<< "| \n";
	
	// Second Line 
	cout<< " __________" << setw(67)
	<< "+ \n";
	
	cout << "|" <<  setw(40)
	<< "IP Address as integer:" << setw(11)
	<< "2293891338" << setw(26)
	<< "| \n";
	
	cout << setw(78) << "+ \n";

    return 0;
}
