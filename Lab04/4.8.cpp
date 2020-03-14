# include <iostream>
using namespace std;


int add(int a, int b)
{
    int add;
    add = a + b;

    // Return statement
    return add;
}

int subtract(int a, int b)
{
    int subtract;
    subtract = a - b;

    // Return statement
    return subtract;
}

int divide(int a, int b)
{
    int divide;
    divide = a / b;

    // Return statement
    return divide;
}



int main()
{
    int op;
    double num1, num2;
    
    cout << "Enter The First Number:\n";
    cin >> num1;
    cout << "Enter The Second Number:\n";
    cin >> num2;

    cout << "Choose your Operator 1(Add), 2(Subtract), 3(Divide), 4(Exit)";
    cin >> op;

    switch(op)
    {
        case '1':
            add(num1,num2);
            break;

        case '2':
            subtract(num1,num2);
            break;

        case '3':
            divide(num1,num2);
            break;

        case '4':
            cout << "The Program will now Exit \n";
            return 0;
            break;

        default:
            cout << "Error! Invalid Selection";
            break;
    }

    return 0;
}