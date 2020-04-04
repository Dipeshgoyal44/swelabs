#include <iostream>

using namespace std;

int main()
{
    // Variable Declarations
    int week;
    int rain;
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
    } while (week <= 0 || week > 7);         // Do while loop for invalid input
    do
    {
        cout << "\nIs it raining today? (1)-Yes OR (0)-No.\n"; //taking 1 for yes and 0 for no
        cin >> rain;
    } while (rain < 0 || rain > 1); // Do while loop for invalid input


    // OUTPUT STATEMENTS
    // If statements to display output

    // IF IT IS RAINING
    if (week == 1 && rain == 1)
    {
        cout << "\nRead in bed";
    }
    if (week == 2 && rain == 1)
    {
        cout << "\nIt is raining today. Take an umbrella with you.";
    }
    if (week == 3 && rain == 1)
    {
        cout << "\nIt is raining today. Take an umbrella with you.";
    }
    if (week == 4 && rain == 1)
    {
        cout << "\nIt is raining today. Take an umbrella with you.";
    }
    if (week == 5 && rain == 1)
    {
        cout << "\nIt is raining today. Take an umbrella with you.";
    }
    if (week == 6 && rain == 1)
    {
        cout << "\nIt is raining today. Take an umbrella with you.";
    }
    if (week == 7 && rain == 1)
    {
        cout << "\nRead in bed";
    }

    // IF IT IS NOT RAINING
    if (week == 1 && rain == 0) //STARTING FROM SUNDAY.
    {
        cout << "\nYou go out and have fun";
    }
    if (week == 2 && rain == 0)
    {
        cout << "\nIts not raining. You won't need a umbrella today";
    }
    if (week == 3 && rain == 0)
    {
        cout << "\nIts not raining. You won't need a umbrella today";
    }
    if (week == 4 && rain == 0)
    {
        cout << "\nIts not raining. You won't need a umbrella today";
    }
    if (week == 5 && rain == 0)
    {
        cout << "\nIts not raining. You won't need a umbrella today";
    }
    if (week == 6 && rain == 0)
    {
        cout << "\nIts not raining. You won't need a umbrella today";
    }
    if (week == 7 && rain == 0)
    {
        cout << "\nYou go out and have fun";
    }

}