#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int random();

int main()
{
    int dice1 = random();
    int dice2 = random();

    cout << "Press any key to roll the two dice\n";
    cin.ignore();
    cout << "The first dice rolled: " << dice1 << "\n";
    cout << "The second dice rolled: " << dice2 << "\n";
    int sum = dice1 + dice2;
    cout<< "The sum of these two rolls is:" << sum << "\n";

    return 0;
}

int random()
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
