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

int main()
{
    char type;
    double total1 = 0,total2 = 0,total3 = 0,total4 = 0;
    int finaltotal= 0;
    do {
    srand(time(NULL));
    int number = number_generator();
    double price = price_generator(type);
    cout << "\n(T)Enter T for TV\n" <<
        "(R)Enter R for Refrigerator\n" <<
        "(L)Enter L for Laptop\n" <<
        "(M)Enter M for Mobile\n" <<
        "(E)Enter E to exit\n";
    cin >> type;
    switch (type)
    {
        
    case 'T':
        total1 = tv_price(number,price_generator(type));
        //cout << "\nRate for TV is: " << price << "\n";
        cout << "Number of TVs in this purchase is : " << number << "\n";
        cout << "Total Price of the TV is " << total1 << "\n";
        cout << "Bill amount for TVs after payback (if any) is " << total1 << "\n";
        break;

    case 'R':
        total2 = refrigirator_price(number,price_generator(type) );
        cout << "Rate for refrigerator is: " << price_generator(type)  << "\n";
        cout << "Number of Refrigerators in this purchase is " << number << "\n";
        cout << "Bill amount for Refrigerator is " << total2 << "\n";
        break;

    case 'L':
        total3 = laptop_price(number,price_generator(type) );
        cout << "Number of Laptops in this purchase is : " << number << "\n";
        cout << "Bill amount for Laptop is " << total3 << "\n";
        break; 

    case 'M':
        total4 = mobile_price(number,price_generator(type) );
        cout << "Number of Mobiles in this purchase is : " << number << "\n";
        cout << "Bill amount for Mobile is " << total4 << "\n";
        break;

    case 'E':
        cout << "\n";
        cout << setw(30) << "******************************\n";
        cout << setw(30) << "*       FINAL  RECIEPT       *\n";
        cout << setw(30) << "******************************\n";
        cout << " * TV" << "\t" << ":" << "\t" << total1 << "\t" <<" *\n ";
        cout << "* Refrigerator" << "\t" << ":" << "\t" << total2 << "\t" <<" *\n ";
        cout << "* Laptop" << "\t" << ":" << "\t"  << total3 << "\t" <<" * \n";
        cout << " * Mobile" << setw(15) << ":" << setw(5)  << total4 << setw(12) <<" * \n";
        cout << setw(30) << "------------------------------\n";
        finaltotal = total1 + total2 + total3 + total4;
        cout << " * Total" << setw(15) << ":" << setw(5)  << finaltotal << setw(12) <<" *\n";
        cout << setw(30) << "******************************\n";
        cout << "Rounded bill amount is: " << finaltotal;
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
    // cout << "\n PRICE:" << price;
    // cout << "\n number:" << number << "\n";
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