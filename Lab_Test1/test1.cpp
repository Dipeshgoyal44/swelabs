#include <iostream>
#include <iomanip>
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
    int total;
    do {
    srand(time(NULL));
    int number = number_generator();
    double price = price_generator(type);
    cout<< "Enter Type: \n";
    cin >> type;
    switch (type)
    {
    case 'T':
        total = tv_price(number,price_generator(type));
        //cout << "\nRate for TV is: " << price << "\n";
        cout << "Number of TVs in this purchase is : " << number << "\n";
        cout << "Total Price of the TV is " << total << "\n";
        cout << "Bill amount for TVs after payback (if any) is " << total << "\n";
        break;

    case 'R':
        total = refrigirator_price(number,price_generator(type) );
        cout << "Rate for refrigerator is: " << price_generator(type)  << "\n";
        cout << "Number of Refrigerators in this purchase is " << number << "\n";
        cout << "Bill amount for Refrigerator is " << total << "\n";
        break;

    case 'L':
        total = laptop_price(number,price_generator(type) );
        cout << "Number of Laptops in this purchase is : " << number << "\n";
        cout << "Bill amount for Laptop is " << total << "\n";
        break; 

    case 'M':
        total = mobile_price(number,price_generator(type) );
        cout << "Number of Mobiles in this purchase is : " << number << "\n";
        cout << "Bill amount for Mobile is " << total << "\n";
        break;

    case 'E':
        cout << "FINAL RECEIPT \n\n";
        cout << setw(20) << "********************\n";
         cout << setw(20) << "*   Final Receipt  *\n";

        return 0;
        break;
    default:
        cout << "Error! Invalid Selection";
        break;
    }}while(type != 'E');
    
    

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
    cout << "\n PRICE:" << price;
    cout << "\n number:" << number << "\n";
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
    double total = 0;
    total = number * price;
    double tax = total * 5.5 /100;
    total = total + tax;
    return total;
}

double laptop_price(int number, double price)
{
    double total = 0;
    total = number * price;
    return total;
}

double mobile_price(int number, double price)
{
    double total = 0;
    if(number <= 10){
        total = number * price;
        return total;
    }else{
        int numberdiscount = number - 10; 
        total = price * 10;
        numberdiscount = numberdiscount * price / 2;
        total = total + numberdiscount;
        return total;
    }
}