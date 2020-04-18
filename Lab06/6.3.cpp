#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
void scan(char input[], int size);
void alphabetSort(char input[], int size);
void frequent(char input[], int size);

int main()
{
	char input[10];
	scan(input, 10);
	alphabetSort(input, 10);
	frequent(input, 10);
}

void scan(char input[], int size)
{
	int i, c;
	char m;

	for (i = 0; i < size; i++)
	{
		cout << "Enter character \n";
		fflush(stdin);
		cin >> m;
		if (tolower(m) < 'a' || tolower(m) > 'z')
		{
			cout << "Not an alphabet \n";
			i--;
		}
		else
			input[i] = m;
		for (c = 0; c < i; c++)
		{

			if (input[c] == input[i])
			{
				cout << "repeat \n";
				c = i;
			}
		}
	}
	cout << "\n";
	cout << "The original array is:\n";
	for (i = 0; i < size; i++)
	{
		cout << input[i];
	}
	
}

void alphabetSort(char input[], int size)
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
	cout << "\nThe sorted array is:\n";
	for (i = 0; i < size; i++)
	{
		cout << input[i];
	}
}

void frequent(char input[], int size) // Frequent Letter function
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
		if(Max == fre[i])
		{
			cout << "\nThe mode is " << mode[i] << "and it is occuring  " << fre[i] << "times\n";
		}else if(Max == 20){
			cout << "\n All characters are the same\n";
		}else if(Max == 1){
			cout << "\n All characters are entered only one time\n";
	}
}