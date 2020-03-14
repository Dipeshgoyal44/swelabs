# include <iostream>
using namespace std;

void add(double a, double b);
void subtract(double a, double b);
void divide(double a, double b);

int main()
{
    int op;
    double num1, num2;
    do{  
    cout << "\nEnter The First Number:\n";
    cin >> num1;
    cout << "Enter The Second Number:\n";
    cin >> num2;

    cout << "Choose your Operator 1(Add), 2(Subtract), 3(Divide), 4(Exit) \n";
    cin >> op;

    switch(op)
    {
        case 1:
            add(num1,num2);
            break;

        case 2:
            subtract(num1,num2);
            break;

        case 3:
            divide(num1,num2);
            break;

        case 4:
            cout << "The Program will now exit \n";
            return 0;
            break;

        default:
            cout << "Error! Invalid Selection";
            break;
    }}while(op != 4);
}


void add(double a, double b)
{
    double add;
    add = a + b;
    cout << "The result is: " << add << "\n" ;
}

void subtract(double a, double b)
{
    double subtract;
    subtract = a - b;
    cout << "The result is: " << subtract << "\n" ;
}

void divide(double a, double b)
{
    double divide;
    divide = a / b;
    cout << "The result is: " << divide << "\n" ;
}