#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
int Random();
int bankBalanceWin(int balance, int wager);
int bankBalanceLose(int balance, int wager);

int main()
{
    //variable declaration
    int dice1 = Random();
    int dice2 = Random();
    int bankBalance = 100; // bank balance
    int wager = 0;
    int sum2 = 0;
    int sum = 0;
    char answer = 'y';
    do // loop to keep running until users chose not to play.
	{
    cout << "You have $ " << bankBalance << "   in the bank.\n";
    do{ // loop to keep running if wager is higher than bank balance
    cout << "Place your wager: ";
    cin >> wager;
    if(wager > bankBalance){
        cout << "The wager amount cannot exceed your bank balance. Please try again!\n";
    }
    }while(wager > bankBalance);
    cout << "\nRolling the dice....\n";
    cin.ignore();
    sum = dice1 + dice2;
    //Displays the dice1 and 2 with the sum
    cout << "Player rolled " << dice1 << " + " << dice2 << " = " << sum << "\n";
    if(sum == 7 || sum == 11){
        // when plater wins
        cout << "Player Wins!!\n";
        cout << "You're up big. Now's the time to cash in your chips!\n";
        cout << "Your new bank balance is: " << bankBalanceWin(bankBalance,wager) << "\n";
        cout << "Please type y or n?\n"; // Prompt if they want to play again or not
        cin >> answer;
        if(answer == 'y')
        {
            int bankBalance = bankBalanceWin(bankBalance,wager);
            int dice1 = Random();
            int dice2 = Random();
            int wager = 0;
            int sum=0;
            int sum2 = 0;   
        }else{
                return 0;
                }
        // when player losses
    }else if(sum == 2 || sum == 3 || sum == 12){
        cout << "Player Lost.\n";
        cout << "Sorry. You busted!\n"; 
        cout << "Your new bank balance is: " << bankBalanceLose(bankBalance,wager) << "\n";
        cout << "Please type y or n?\n"; // Prompt if they want to play again or not
        cin >> answer;
        if(answer == 'y')
            {
        int bankBalance = bankBalanceLose(bankBalance,wager);
        int dice1 = Random();
        int dice2 = Random();
        int wager = 0;
        int sum = 0;
        int sum2 = 0;   
            }else{
                    return 0;
                }
    }else{ 
        // when a point is made
        cout << "Player made a point!\n";
        cout << "Point is: " << sum << "\n";
        cout << "Aw cmon, take a chance!\n";
        }
        do{
            // reset values of dice 1 and  dice 2.
            dice1 = Random();
            dice2 = Random();
            cout << "Press any key to reroll.\n";
            cin.ignore();
            // new sum if player makes a point
            int sum2 = dice1 + dice2;
            cout << "Player rolled " << dice1 << " + " << dice2 << " = " << sum2 << "\n";
            if(sum==sum2){
                cout << "Player Wins!!\n";
                cout << "Nice Win. Better cash those chips now!!\n";
                cout << "Your new bank balance is: " << bankBalanceWin(bankBalance,wager) << "\n"; // function to display
                cout << "Please type y or n?\n"; // Prompt if they want to play again or not
                cin >> answer;
                if(answer == 'y')
                {
                int bankBalance = bankBalanceWin(bankBalance,wager);
                int dice1 = Random();
                int dice2 = Random();
                int wager = 0;
                int sum2 = 0;   
                int sum = 0 ;
                }else{
                    return 0;
                }
            }else if(sum2==7){
                //Player loses if summ is equal to 7
                cout << "Player Lost.\n";
                cout <<  "Oh, you're going for broke, huh?\n";
                cout << "Your new bank balance is: " << bankBalanceLose(bankBalance,wager) << "\n"; // function to display
                cout << "Would you like to play again?\n";
                cout << "Please type y or n?\n"; // Prompt if they want to play again or not
                cin >> answer;
                if(answer == 'y')
                {
                int bankBalance = bankBalanceLose(bankBalance,wager);
                int dice1 = Random();
                int dice2 = Random();
                int wager = 0;
                int sum = 0 ;
                int sum2 = 0;   
                }else{
                    return 0;
                }
            }
        }while(sum !=sum2 || sum2 != 7); // loop to keep running until player loses or wins
        } while (answer == 'y');

    return 0;
}

//Function to generate random number
int Random()
{
    int number;
    static int flag = 1; //static so only meets the condition once.

    if (flag == 1) // this ensures the function gives different random numbers everytime.
    {
        srand(time(0)); 
        flag = 0;       
    }
    number = rand() % 6 + 1;
    return number;
}

// Function to add balance and wager when player wins.
int bankBalanceWin(int balance, int wager)
{
    return wager + balance;
}
// Function to minus the wager from balance when player loses.
int bankBalanceLose(int balance, int wager)
{
    return balance - wager; 
}