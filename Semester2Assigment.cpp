#include <iostream>
#include <fstream>
#include <cstdlib> // needed for exit()
#include <string>
using namespace std;
int displayMarks(int[], int);
int calculateMean(int[], int);
int calculateMedian(int[], int);
int main()
{	

int count;
		int num;
    	string studentid;
    	int marksarray[100];
    	float sum = 0;
        int size = 0;
        float Mean;
        float Median;
int choice;
do{
string filename = "marks.txt";
ifstream inFile;
inFile.open(filename.c_str()); //I open the file
if (inFile.fail()) // check for successful open
{
cout << "\nThe file named " << filename
<<  "was not successfully opened"
<< "\n Please check that the file currently exists."
<< endl;
exit(1);
}		
    	
        
cout<< "\n\tMenu\n \t----"<<endl;
cout<< "1. Display Data\n";
cout<< "2. Calculate Mean\n";
cout<< "3. Calculate Median\n";
cout<< "4. Find minimum\n";
cout<< "5. Find maximum\n";
cout<< "6. Find average for student\n";
cout<< "7. Add new student Data\n";
cout<< "8. Quit program\n";
cout<<"\n---------------------\n";
cout<<"Enter your choice(1-8): ";
cin>> choice;


switch (choice)
    {
    case 1:
            cout << "\nDisplaying marks from the array"<<endl;
			displayMarks(marksarray,  count);
			cout << "Done!";
		inFile.close();
        break;  
    case 2:
            cout <<"\nCalculating the Mean score"<<endl;
			calculateMean(marksarray, count);
   			cout << "Done!";
       	inFile.close();
        break;
    case 3:
    	/*when the user selects 3, it quits the program by saying this message*/
            cout << "\nCalculating the Median score"<<endl;
    		calculateMedian(marksarray, count);
            cout << "Done!";
        inFile.close();
        break;
         case 4:
    cout << "\nresistance "<<endl;
        break;
         case 5:
    cout << "\nresistance "<<endl;
        break;
         case 6:
    cout << "\nresistance "<<endl;
        break;
         case 7:
    cout << "\nresistance "<<endl;
        break;
         case 8:
     cout << "Ending program!...\n";
        return 0;
    
        break;
    default:
    	/*If the number selected is not from the menu then give the condition stating it is not valid*/
        cout << "Invalid input!(Enter a number between 1 and 3\n"<<endl;
        break;
    }
        cin.clear(); /*resets any error flags which is not suitable for the cin input*/
        cin.ignore(1000,'\n');/*to ignore one or more characters or spaces for the input buffer*/	
    
}while(choice !=8);
}






int displayMarks(int marksarray[100], int count){
string filename = "marks.txt";
ifstream inFile;
inFile.open(filename.c_str()); //I open the file
if (inFile.fail()) // check for successful open
{
cout << "\nThe file named " << filename
<<  "was not successfully opened"
<< "\n Please check that the file currently exists."
<< endl;
exit(1);
}
while(inFile.good()){
		int num;
    	string studentid;
    		do{
		if(num = 0){	
		return 0;
}
    inFile>>num;
	inFile>>studentid;
	
	for(count=0; count < num; count++){			
	    inFile>>marksarray[num];
		cout<<marksarray[num]<<" ";
	sizeof(marksarray[num]);
}
}while(marksarray[num]);
}
}



int calculateMean(int marksarray[100], int count){
	string filename = "marks.txt";
ifstream inFile;
inFile.open(filename.c_str()); //I open the file
if (inFile.fail()) // check for successful open
{
cout << "\nThe file named " << filename
<<  "was not successfully opened"
<< "\n Please check that the file currently exists."
<< endl;
exit(1);
}
while(inFile.good()){	
int num;
    	string studentid;
	    float sum = 0;
        int size = 0;
        float Mean;  
        do{

	if(num = 0){	
		return 0;
}  
    inFile>>num;
	inFile>>studentid;
    
	for(count=0; count < num; count++){	
	    inFile>>marksarray[num];
		sum = sum  + marksarray[num];
		size = size+ 1;
}
	Mean = sum/size;
	}while(marksarray[num]);
	cout<<"Mean Score is "<<Mean<<endl;	
}
}



int calculateMedian(int marksarray[], int count){
	string filename = "marks.txt";
ifstream inFile;
inFile.open(filename.c_str()); //I open the file
if (inFile.fail()) // check for successful open
{
cout << "\nThe file named " << filename
<<  "was not successfully opened"
<< "\n Please check that the file currently exists."
<< endl;
exit(1);
}
while(inFile.good()){	
        int num;
    	string studentid;
        int size = 0;
		double Median; 
		
        	do{
			
	if(num = 0){	
		return 0;
}  
    inFile>>num;
	inFile>>studentid;
    
	for(count=0; count < num; count++){	
	    inFile>>marksarray[num];
		size = size+ 1;	
		}	
		
		<here>
Median = (size+1)/2;	
}while(marksarray[num]);
	cout<<"Median Score is "<<Median<<endl;
}	
}


