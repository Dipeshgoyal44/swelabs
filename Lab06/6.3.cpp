#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
void scan(char input[], int size);
void alphabetSort(char input[], int size);

int main()
{
	char input[10];
	scan(input, 10);
	alphabetSort(input, 10);
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
	cout << "Sorted\n");
	for (i = 0; i < size; i++)
	{
		cout << input[i];
	}
}
