#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Variable Declarations
    string username, empname,pctype,mac;
    float cpuspeed;
    float IP=0;
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
    cout <<iP_part_1 << "\n";
    cout <<iP_part_2 << "\n";
    cout <<iP_part_3 << "\n";
    cout <<iP_part_4 << "\n";
    
    IP = iP_part_1 * pow(256., 3)+iP_part_2 * pow(256., 2) +iP_part_3 * 256 +iP_part_4;
    cout<< int(IP);

    return 0;
}
