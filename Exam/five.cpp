#include <iostream>

using namespace std;

class Rectangle{
    private:
        double length;
        double width;
        double area;
    public:
        Rectangle()
        {
            length = 5;
            width = 2;
        }
        Rectangle(double l, double w, double a)
        {
            length = l;
            width = w;
            area = a;
        }
        int calculateArea(){
            area = length * width;
        }
        void printRectangle(){
            cout << "\nLength: " << length;
            cout << "\nWidth: " << width;
            cout << "\nArea: " << area;
        }
};

int main()
{
    Rectangle rectangle1,rectangle2(10,5,0);
    cout << "Rectangle 1:\n";
    rectangle1.calculateArea();
    rectangle1.printRectangle();
    
    cout << "\n\nRectangle 2:\n";
    rectangle2.calculateArea();
    rectangle2.printRectangle();
    return 0;
}


