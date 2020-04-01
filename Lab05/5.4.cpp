#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Random();

int main()
{
    int dice1 = Random();
    int dice2 = Random();
    int bankBalance = 100;
    int wager = 0;
    int sum2 = 0;
    cout << "You have $100 in the bank.\n";
    do{
    cout << "Place your wager: ";
    cin >> wager;
    if(wager > bankBalance){
        cout << "The wager amount cannot exceed your bank balance. Please try again!\n";
    }
    }while(wager > bankBalance);
    cout << "\nRolling the dice....\n";
    cin.ignore();
    int sum = dice1 + dice2;
    cout << "Player rolled " << dice1 << " + " << dice2 << " = " << sum << "\n";
    if(sum == 7 || sum == 11){
        cout << "Player Wins!!\n";
        cout << "You're up big. Now's the time to cash in your chips!\n";
        bankBalance += wager;
        cout << "Your new bank balance is: " << bankBalance << "\n";
    }else if(sum == 2 || sum == 3 || sum == 12){
        cout << "Player Lost.\n";
        cout << "Sorry. You busted!\n"; 
        bankBalance = bankBalance - wager;
        cout << "Your new bank balance is: " << bankBalance << "\n";
    }else{ 
        cout << "Player made a point!\n";
        cout << "Point is: " << sum << "\n";
        cout << "Aw cmon, take a chance!\n";
        }
        do{
            dice1 = Random();
            dice2 = Random();
            cout << "Press any key to reroll.\n";
            cin.ignore();
            int sum2 = dice1 + dice2;
            cout << "Player rolled " << dice1 << " + " << dice2 << " = " << sum2 << "\n";
            if(sum==sum2){
                cout << "Player Wins!!\n";
                cout << "Nice Win. Better cash those chips now!!\n";
                bankBalance += wager;
                cout << "Your new bank balance is: " << bankBalance << "\n";
                return 0;
            }else if(sum2==7){
                cout << "Player Lost.\n";
                cout <<  "Oh, you're going for broke, huh?\n";
                bankBalance = bankBalance - wager;
                cout << "Your new bank balance is: " << bankBalance << "\n";
                return 0;
            }
        }while(sum !=sum2 || sum2 == 7);

    return 0;
}

int Random()
{
    int number;
    static int flag = 1; // initial value - holds value when changed

    // Seed the random number generator - ONCE
    if (flag == 1)
    {
        srand(time(0)); // use clock to get a seed
        flag = 0;       // clear flag: never enter here again
    }

    // get the actual random number here
    number = rand() % 6 + 1;
    return number;
}

// int bankBalanceWin()
// {


// }

// int bankBalanceLose()
// {


// }