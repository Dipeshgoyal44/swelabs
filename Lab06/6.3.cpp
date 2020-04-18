#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Function Protypes
void readArray(char input[], int size);
void alphabetSort(char input[], int size);
void frequency(char input[], int size);


int main() //MAIN Function
{
	char input[20]; // Array of 20 characters
	readArray(input, 20); 
	alphabetSort(input, 20);
	frequency(input, 20);
}


void readArray(char input[], int size) //Function to store characters in array and check for duplicate and letters
{
	int i, c;
	char m;

	for (i = 0; i < size; i++)
	{
		cout << "Enter character \n";
		fflush(stdin);
		cin >> m;
		if (tolower(m) < 'a' || tolower(m) > 'z') // Check if alphabet or not
		{
			cout << m << " is not an alphabet\n";
			i--;
		}
		else
			input[i] = m;
		for (c = 0; c < i; c++)
		{

			if (input[c] == input[i]) // if matches it is a duplicate
			{
				cout << input[c] << " is a duplicate letter.\n";
				c = i;
			}
		}
	}
	cout << "\n";
	cout << "The original array is:\n"; // Prints the original array
	for (i = 0; i < size; i++)
	{
		cout << input[i];
	}
	
}

void alphabetSort(char input[], int size) // Function to sort the array in alphabatical order
{
	int i = 0, m = 0;
	char L;
	for (i = 0; i < size; i++)
	{
		for (m = i + 1; m < size; m++)
		{
			if (tolower(input[i]) > tolower(input[m]))
			{
				L = input[i];
				input[i] = input[m];
				input[m] = L;
			}
		}
	}
	cout << "\nThe sorted array is:\n"; // Prints the sorted array
	for (i = 0; i < size; i++)
	{
		cout << input[i];
	}
}

void frequency(char input[], int size) // Frequent Letter function
{
	char mode[20];
	int count=0, Max=0, a=0, fre[20], i, j;
	
	for(i=0; i<size; i++)
	{
		count =1;
		for(j=i+1; j<size; j++)
		{ 
			if(input[i] == input[j])
				count++;
			else
				break;									
		}
		mode[a]= input[i];
		fre[a]= count;
		if(Max<count)	
			Max = count;
		a++;
		i = j-1;
	}
	for(i=0; i<size; i++)	
	{
		if(Max == 1){ // If the max is 1 means the all occurences only happened once.
			cout << "\nAll characters are entered only one time.\n";
			break;
		}else if(Max == size){ // if max is equal to size means all characters are different
			cout << "\nAll characters are the same.\n";
			break;
		}else if(Max == fre[i]){  // to print occurences more than 1
			cout << "\nThe mode is '" << mode[i] << "' and it is occuring  " << fre[i] << " times.\n";
			break;
	}
}
}