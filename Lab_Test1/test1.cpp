#include <iostream>
#include <ctime> 


using namespace std;

//Prototypes
int number_generator();
double price_generator(char type);
double tv_price(int number, double price);
double refrigirator_price();
double laptop_price();
double mobile_price();

int main()
{
    char type;
    cout<< "Enter Type: \n";
    cin >> type;
    srand(time(NULL));
    double price = price_generator(type);
    cout << "Price is: " << price  << "\n";
    cout << "\nTV TOTAL: " << tv_price(number_generator(), price) << "\n"; 


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
    cout << "\n number:" << number;
    double total;
    if(price > 500){
    total = number * price;
    total = total - number * 50;    
    return total;
    }else{
    total = number * price;
    }
}

double refrigirator_price(int number, double price)
{

}


// double laptop_price(int number, double price)
// {


// }
// double mobile_price(int number, double price)
// {

// }