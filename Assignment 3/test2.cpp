#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//---------- Function Prototypes -----------
struct stud_grade
{
    string last_name;
    string first_name;
    int grade;
    stud_grade *next;
};

stud_grade *list;
stud_grade *p, *q; // pointers
//--------------  Main ---------------------

int main()
{
    ifstream inputFile;
    list = NULL;
    p = new stud_grade;

    inputFile.open("test.txt");

    while (!inputFile.eof())
    {
        p = new stud_grade;
        inputFile >> p->last_name;
        cout << p->last_name << endl; //testing purposes
        inputFile >> p->first_name;
        cout << p->first_name << endl; //testing purposes
        inputFile >> p->grade;
        cout << p->grade << endl; //testing purposes
    }
    if (list == NULL)
    {
        list = p;
    }
    else
    {
        q = list;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }

    inputFile.close();

    q = list;
    while (q != NULL)
    {
        cout << p->last_name << " " << p->first_name << " " << p->grade << " ";
        q = q->next;
    }

    return 0;
}
