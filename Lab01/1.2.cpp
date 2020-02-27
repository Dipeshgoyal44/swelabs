#include<iostream>	
#include<string>	
using namespace std; 	

int main() {	
	string name;
	int count;

	cout << "Enter Your Name:"<< endl;	
	cin >> name;	
	cout << "Welcome to my World " << name << "!" << endl;
	cout << "How many greetings?"<< endl;	
	cin >> count;
	for (int i = 0; i < count; i++) {
         cout << "Have a Good Day!" << "\n";
    }
	
	return 0;	
}