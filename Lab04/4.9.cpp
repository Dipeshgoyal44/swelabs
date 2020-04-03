#include <iostream>

using namespace std;

int main()
{
    // Variable Declarations
    int week;
    int weather;
    do
    {
        cout << "\nEnter week number (1-7):"; // User input for weekday.
        cin >> week;
        switch (week)
        {
        case 1:                     //Switch statement to display weekday output
            cout << "Sunday";
            break;
        case 2:
            cout << "Monday";
            break;
        case 3:
            cout << "Tuesday";
            break;
        case 4:
            cout << "Wednesday";
            break;
        case 5:
            cout << "Thursday";
            break;
        case 6:
            cout << "Friday";
            break;
        case 7:
            cout << "Saturday";
            break;
        default:
            cout << "\nInvalid Input! Please enter week in between 1-7."; 
        }
    } while (week <= 0 | week > 7);         // Do while loop for invalid input
    do
    {
        cout << "\nHow's the weather today? (1)Sunny,(2)Cold or (3)Raining\n";
        cin >> weather;
        switch (weather)
        {
        case 1:
            cout << "Sunny";                            //Switch statement to display weather output
            break;
        case 2:
            cout << "Cold";
            break;
        case 3:
            cout << "Raining";
            break;
        default:
            cout << "\nInvalid Input! Please enter the weather between 1-3.";
        }
    } while (weather <= 0 | weather > 3);          // Do while loop for invalid input
    // OUTPUT STATEMENTS
    // If statements to display output
    if (week == 1 & weather == 1) //STARTING FROM SUNDAY.
    {
        cout << "\nEat Ice cream and go to the beach";
    }
    if (week == 1 & weather == 2)
    {
        cout << "\nStay home and watch a movie";
    }
    if (week == 1 & weather == 3)
    {
        cout << "\nCook soup and play a video game";
    }
    if (week == 2 & weather == 1)
    {
        cout << "\nYou walk.";
    }

    if (week == 2 & weather == 2)
    {
        cout << "\nYou take your jacket with you";
    }
    if (week == 2 & weather == 3)
    {
        cout << "\nYou take your Car.";
    }
    if (week == 3 & weather == 1)
    {
        cout << "\nYou walk.";
    }
    if (week == 3 & weather == 2)
    {
        cout << "\nYou take your jacket with you";
    }
    if (week == 3 & weather == 3)
    {
        cout << "\nYou take your Car.";
    }
    if (week == 4 & weather == 1)
    {
        cout << "\nYou walk.";
    }
    if (week == 4 & weather == 2)
    {
        cout << "\nYou take your jacket with you";
    }
    if (week == 4 & weather == 3)
    {
        cout << "\nYou take your Car.";
    }

    if (week == 5 & weather == 1)
    {
        cout << "\nYou walk.";
    }

    if (week == 5 & weather == 2)
    {
        cout << "\nYou take your jacket with you";
    }
    if (week == 5 & weather == 3)
    {
        cout << "\nYou take your Car.";
    }

    if (week == 6 & weather == 1)
    {
        cout << "\nYou walk..";
    }

    if (week == 6 & weather == 2)
    {
    cout << "\nYou take your jacket with you";
    }
    if (week == 6 & weather == 3)
    {
    cout << "\nYou take your Car.";
    }

    if (week == 7 & weather == 1)
    {
    cout << "\nEat Ice cream and go to the beach";
    }
    if (week == 7 & weather == 2)
    {
    cout << "\nStay home and watch a movie";
    }
    if (week == 7 & weather == 3)
    {
    cout << "\nCook soup and play a video game";
    }
}