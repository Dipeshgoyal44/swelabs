#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;


int Random();

int main() 
{			
    int i;
    int x;
    int j;
	int dice1;	
	int dice2;
	int total = 0;
	const int columnSize = 6;
	const int rowSize = 6;
	int diagonal[6];
	int faces[columnSize][rowSize];
	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 6; column++)
		faces[row][column] = 0;
	}
	for (int i = 0; i < 50000; i++) 
	{ 
		dice1 = Random();
		dice2 = Random();
	
	faces[dice1][dice2]++;
	faces[6][6] = faces[dice1][dice2];
	}
    cout<< "\n-----\t-----\t-----\t-----\t-----\t-----";
	for(int row = 0; row < 6; row++)
	{
		
        cout<<endl;
        cout<< ":";
		for(int column = 0; column < 6; column++)
		{
			cout<< faces[column][row] << " :" << "\t";
            
		}
        cout<< "\n-----\t-----\t-----\t-----\t-----\t-----";
	}
	cout << "\n";
	cout << "\nThe sum of the diagonal element is \n";
	for (i=0;i < rowSize;++i)
        {
            for (j=0;j < columnSize;++j)
            {
                if (i==j)
                cout << "\n" << faces[i][j] ;
                }
                }
            cout << " +\n";
            cout << "-------\n";
	return 0;

}


int Random()
{
    int number;
    static int flag = 1; //static so only meets the condition once.

    if (flag == 1) // this ensures the function gives different random numbers everytime.
    {
        srand(time(0)); 
        flag = 0;       
    }
    number = rand() % 6;
    return number;
}
