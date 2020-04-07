#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
int random(int num);
void comment(int attempts);


int main()
{
    int num = random(num);
	int guess, attempts = 0;
    char answer = 'y';
	cout << "I have a number between 1 and 1000.\n";
    cout << "Can you guess my number?\n";
	do
	{
		cout << "Enter a guess between 1 and 1000 : ";
		cin >> guess;
		attempts++;
		if (guess > num)
        {
			cout << "Too high. Try again\n";
        }
		else if (guess < num)
        {
			cout << "Too low. Try again\n";
        }
		else
            {
                cout << "\nExcellent! You guessed the number!\n";
                comment(attempts);
                cout << "Would you like to play again?\n";
                cout << "Please type y or n?\n";
                cin >> answer;
                if(answer == 'y')
                {
                    num = random(num);
                    guess = 0; 
                    attempts = 0;    
                }
            }
	} while (answer == 'y');
	return 0;
}

//Function 1
int random(int num) // Function to generate random number
{
    srand(time(NULL)); //seed random number generator
	num = rand() % 1000 + 1; // random number between 1 and 100
    return num;
}

//Function 2
void comment(int attempts) // function to display comment based on number of attempts
{
    if(attempts <= 10){
        cout << "Either you know the secret or you got lucky!\n"; 
    }
    else if(attempts == 10){
        cout << "Ahah! You know the secret!\n"; 
    }
    else if(attempts >= 10){
        cout << "You should be able to do better!\n";
    }
}