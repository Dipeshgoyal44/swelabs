#include <iostream>
#include <ctime> 


using namespace std;

//Prototypes
int number_generator();
double price_generator(char type);
double tv_price(int number, double price);
double refrigirator_price(int number, double price);
double laptop_price(int number, double price);
double mobile_price(int number, double price);
int menu(char type);

int main()
{
    char type;
    cout<< "Enter Type: \n";
    cin >> type;
    srand(time(NULL));
    
    //cout << "\nTV TOTAL: " << tv_price(number_generator(), price) << "\n"; 
    // cout << "\nREFRIGRATOR TOTAL: " << refrigirator_price(number_generator(), price) << "\n"; 
//cout << "\n LAPTOP TOTAL: " << laptop_price(number_generator(), price) << "\n"; 
    // cout << "\n MOBILE TOTAL: " << mobile_price(number_generator(), price) << "\n"; 
    menu(type);
    

}

int menu(char type)
{
    double price = price_generator(type);
    int number = number_generator();
    while(type != 'E'){
    switch (type)
    {
    case 'T':
        cout << "Rate for TV is: " << price << "\n";
        cout << "Number of TVs in this purchase is : " << number << "\n";
        cout << "Total Price of the TV is " << tv_price(number,price) << "\n";
        cout << "Bill amount for TVs after payback (if any) is " << tv_price(number,price) << "\n";
        menu(type);
        break;

    case 'R':
        cout << "Rate for refrigerator is: " << price << "\n";
        cout << "Number of Refrigerators in this purchase is " << number << "\n";
        cout << "Bill amount for Refrigerator is " << refrigirator_price(number,price) << "\n";
        break;

    case 'L':
        cout << "Number of Laptops in this purchase is : " << number << "\n";
        cout << "Bill amount for Laptop is " << laptop_price(number,price) << "\n";
        break; 

    case 'M':
        cout << "Number of Mobiles in this purchase is : " << number << "\n";
        cout << "Bill amount for Mobile is " << mobile_price(number,price) << "\n";
        break;

    case 'E':
        cout << "FINAL RECEIPT \n";
        
        return 0;
        break;
    default:
        cout << "Error! Invalid Selection";
        break;
    }}
    

}

int number_generator()
{
	return rand() % 15+ 1  ; // random number between 1 and 15
}


double price_generator(char type)
{
    if(type =='T'){
    double min=300.0;
    double max =1000.0;
    return ((double)rand() / RAND_MAX) * (max - min) + min;
    }else if(type =='R'){
    double min=100.0;
    double max =500.0;
    return ((double)rand() / RAND_MAX) * (max - min) + min;
    }else if(type =='L'){
    double price = 1000.0; //fixed price
    return price;
    }else if(type =='M'){
    double price = 500.0; //fixed price
    return price;
    }
}

double tv_price(int number, double price)
{
    // cout << "\n PRICE:" << price;
    // cout << "\n number:" << number;
    double total = 0;
    if(price > 500){
    total = number * price;
    total = total - number * 50;    
    return total;
    }else{
    return total = number * price;
    }
}

double refrigirator_price(int number, double price)
{
    // cout << "\n PRICE:" << price;
    // cout << "\n number:" << number;
    double total = 0;
    total = number * price;
    double tax = total * 5.5 /100;
    total = total + tax;
    return total;
}

double laptop_price(int number, double price)
{
    // cout << "\n PRICE:" << price;
    // cout << "\n number:" << number;
    double total = 0;
    total = number * price;
    return total;
}

double mobile_price(int number, double price)
{
    // cout << "\n PRICE:" << price;
    // cout << "\n number:" << number;
    double total = 0;
    if(number <= 10){
        total = number * price;
        return total;
    }else{
        int numberdiscount = number - 10; // number = 14
        total = price * 10;
        numberdiscount = numberdiscount * price / 2;
        total = total + numberdiscount;
        return total;
    }
}