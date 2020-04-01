#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int num);
void comment(int attempts);

int main()
{
    bool playAgain = true;
    char choice;
    while(!playAgain);
    {
    int num = random(num);
	int guess, attempts = 0;
	cout << "I have a number between 1 and 1000.\n";
    cout << "Can you guess my number?\n";
	do
	{
		cout << "Enter a guess between 1 and 1000 : ";
		cin >> guess;
		attempts++;

		if (guess > num)
			cout << "Too high. Try again\n";
		else if (guess < num)
			cout << "Too low. Try again\n";
		else
			cout << "\nExcellent! You guessed the number!\n";
            comment(attempts);
            cout << "Would you like to play again?\n";
            cout << "Please type y or n?\n";
            cin >> choice;
            choice = toupper(choice);
            if (choice== 'Y'){
                playAgain = true;
            }
            // << tries << " guesses!\n";
	} while (guess != num);
    }

	return 0;
}

int random(int num)
{
    srand(time(0)); //seed random number generator
	num = rand() % 1000 + 1; // random number between 1 and 100
    return num;
}

void comment(int attempts)
{
    if(attempts <= 10){
        cout << "Either you know the secret or you got lucky!\n"; 
    }
    if(attempts == 10){
        cout << "Ahah! You knowthe secret!\n"; 
    }
    if(attempts >= 10){
        cout << "You should be able to do better!\n";
    }
}
