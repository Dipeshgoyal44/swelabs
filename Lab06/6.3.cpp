#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
void scan(char input[], int size);

int main()
{
 char input[10];
	scan(input, 10);
}


void scan(char input[], int size)
{
	int i,c;
	char m;
	
	for(i=0;i<size;i++)
	{												                                                         
		cout<< "Enter character \n";
		fflush(stdin);
		cin>> m;
														/* this is were the letter is going to be scanned and looked at*/ 
		if(tolower(m) < 'a' || tolower(m) > 'z')			/*this is going to let me see the a to z                                                           */
	/* if these are not entered it should print this                                                          */
			{
				cout << "Not an alphabet \n";
				i--;
			}

		else
			input[i]=m;

		

	for(c=0;c<i;c++)
		{

		if(input[c] == input[i])								
			{
				cout << "repeat \n";
				c=i;
			}
		}		

	}

}
