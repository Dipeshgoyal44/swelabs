#include <iostream>

using namespace std;

class Student{
    private:
        string name;
        double mark1;
        double mark2;
        double Average;
    public:
        Student(string name1, double m1, double m2, double avg)
        {
            name = name1;
            mark1 = m1;
            mark2 = m2;
            Average = avg;
        }
        Student();
        int calculateAverage(){
            int sum = mark1 + mark2;
            Average = sum / 2;
            return Average;
        }
        void printStudents(){
            cout << "\nName: " << name;
            cout << "\nMark 1: " << mark1;
            cout << "\nMark 2: " << mark2;
            cout << "\nAverage: " << Average;
        }
};

int main()
{
    Student Student1("Dipesh",70,90,0);
    Student1.calculateAverage();
    Student1.printStudents();
    return 0;
}


