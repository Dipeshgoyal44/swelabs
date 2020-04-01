#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Random();

int main()
{
    int dice1 = Random();
    int dice2 = Random();
    int sum2 = 0;

    cout << "Press any key to roll the two dice\n";
    cin.ignore();
    cout << "The first dice rolled: " << dice1 << "\n";
    cout << "The second dice rolled: " << dice2 << "\n";
    int sum = dice1 + dice2;
    cout<< "The sum of these two rolls is: " << sum << "\n";
    if(sum == 7 || sum == 11){
        cout << "Player Wins!!\n";
    }else if(sum == 2 || sum == 3 || sum == 12){
        cout << "Player Lost.\n";
    }else{ 
        cout << "Player made a point!\n";
        cout << "Point is: " << sum << "\n";
        do{
            dice1 = Random();
            dice2 = Random();
            cout << "Press any key to reroll.\n";
            cin.ignore();
            int sum2 = dice1 + dice2;
            cout << "Player rolled " << dice1 << " + " << dice2 << " = " << sum2 << "\n";
            if(sum==sum2){
                cout << "Player Wins!!\n";
                return 0;
            }else if(sum2==7){
                cout << "Player Lost.\n";
                return 0;
            }
        }while(sum !=sum2 || sum2 == 7);
    }

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
