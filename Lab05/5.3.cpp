#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int num);


int main()
{
    string choice;
    do
    {
    int num = random(num);
	int guess, tries = 0;
	cout << "I have a number between 1 and 1000.\n";
    cout << "Can you guess my number?\n";
	do
	{
		cout << "Enter a guess between 1 and 1000 : ";
		cin >> guess;
		tries++;

		if (guess > num)
			cout << "Too high. Try again\n";
		else if (guess < num)
			cout << "Too low. Try again\n";
		else
			cout << "\nExcellent! You guessed the number!\n";
            cout << "Would you like to play again?\n";
            cout << "Please type yes or no?\n";
            cin >> choice;
            // << tries << " guesses!\n";
	} while (guess != num);
    }while (choice !="no");

	return 0;
}

int random(int num)
{
    srand(time(0)); //seed random number generator
	num = rand() % 1000 + 1; // random number between 1 and 100
    return num;
}
