#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct person_tag
{
    string name;
    string id;
};

struct course_tag
{
    string course_name;
    int no_of_units;
    int marks[4];
    double avg;
};

struct student_tag
{
    person_tag student_info;
    course_tag course_info;
    student_tag *next;
};

typedef struct student_tag Student_Tag;
typedef Student_Tag *Student_TagPtr;

Student_Tag *hptr;
Student_Tag *cptr;
Student_Tag *nptr;

//function protypes
void menu();
void read();
void display_students();

void read() //readfile function
{
    double total;
    hptr = nptr = NULL; //intialized to null
    string filename = "students.txt";
    ifstream inFile(filename);

    if (inFile.fail()) // if file doesnt open successfully
    {
        cout << "The File was not opened successfully\n";
        cout << "Please check that the file currently exists\n";
        exit(1);
    }
    while (inFile.peek() != EOF) // until the end of the file
    {
        total = 0;
        cptr = new Student_Tag;
        // Read the data into the new item
        inFile >> cptr->student_info.name;
        inFile >> cptr->student_info.id;
        inFile >> cptr->course_info.course_name;
        inFile >> cptr->course_info.no_of_units;
        for (int j = 0; j < cptr->course_info.no_of_units; j++)
        {
            inFile >> cptr->course_info.marks[j];
            total = total + cptr->course_info.marks[j];
        }
        double average =    total/ cptr->course_info.no_of_units;
        cptr -> course_info.avg = average;
        if (hptr == NULL)
        {
            // First item in the list. hptr pointing to first item
            hptr = cptr;
        }
        else
        {
            // Not the first item, append it to the tail.
            nptr->next = cptr;
        }
        nptr = cptr; // Move the tail pointer
    }
    cptr->next = NULL; //  last items next pointer set to NULL
    inFile.close();    //close file
}

void display()
{
    student_tag *ptr;
    ptr = hptr;
    while (ptr != NULL)
    {
        cout << "The Student Name: " << ptr->student_info.name << "  \n";
        cout << "The Student ID: " << ptr->student_info.id << "  \n";
        cout << "The course name: " << ptr->course_info.course_name << "  \n";
        cout << "Number of units " << ptr->course_info.no_of_units << "  \n";
        cout << "Marks recieved: \n";
        for (int j = 0; j < ptr->course_info.no_of_units; j++)
        {
            cout << ptr->course_info.marks[j] << "  \n";
        }
        cout << "Average : " << setprecision(2) << fixed << ptr->course_info.avg << " \n";
        cout << "------------------------\n\n";
        ptr = ptr->next;
    }
    
}

int main()
{
    read();
    display();
    return 0;
}
