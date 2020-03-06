#include<iostream>	
#include<string>	
using namespace std; 

// Calculates the sum of three integers

int main() {	
	int x,y,z,result = 0; // Variable Declaration

	cout << "Enter the First Integer:"<< endl;	 // Instructs the user to enter first integer
	cin >> x;                                   // stores user input in variable x
	cout << "Enter the Second Integer:"<< endl;	 // Instructs the user to enter second integer
	cin >> y;                                    // stores user input in variable y
	cout << "Enter the Third Integer:"<< endl;	// Instructs the user to enter third integer
	cin >> z;                                    // stores user input in variable z
	result=x+y+z;                               // Stores the total of the three integers in variable result
	cout << "Sum of the Three Integers is:"<< result << endl;	 // outputs variable result
	return 0;	
}