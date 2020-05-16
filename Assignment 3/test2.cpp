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

student_tag *hptr = NULL;
// typedef struct student_tag Student_Tag;
// typedef Student_Tag *Student_TagPtr;


//function protypes
int read_file(student_tag *s, int *array_size); 
void display();


int main()
{
    student_tag student_array[100]; //array of size 100 of datatype student
    int array_size = 0;
    read_file(student_array, &array_size); 
    cout << "The linked list is: ";
    display();
    return 0;
}

int read_file(student_tag *s, int *array_size) //readfile function
{
    int count;
    double total = 0;
    string filename = "test.txt";
    ifstream inFile;

    inFile.open(filename.c_str());

    if (inFile.fail()) // if file doesnt open successfully
    {
        cout << "The File was not opened successfully\n";
        cout << "Please check that the file currently exists\n";
        return 0;
    }
    int i = 0;
    student_tag *nptr = (student_tag *)malloc(sizeof(student_tag));
    while (inFile.peek() != EOF) // until the end of the file
    {
        double total = 0;
        inFile >> s[i].student_info.name;
        nptr->student_info.name = s[i].student_info.name;
        inFile >> s[i].student_info.id;
        nptr->student_info.id = s[i].student_info.id;
        inFile >> s[i].course_info.course_name;
        nptr->course_info.course_name = s[i].course_info.course_name;;
        inFile >> s[i].course_info.no_of_units;
        nptr->course_info.no_of_units = s[i].course_info.no_of_units;;
        for (int j = 0; j < s[i].course_info.no_of_units; j++)
        {
            inFile >> s[i].course_info.marks[j];
            nptr->course_info.marks[j] = s[i].course_info.marks[j];;
            total = total + s[i].course_info.marks[j];
        }
        s[i].course_info.avg = total / s[i].course_info.no_of_units;
        nptr->course_info.avg = s[i].course_info.avg;
        nptr->next = hptr;
        hptr = nptr;
        i++;
    }
    
    *array_size = i; // temp has the same value of i to check how many records of data is in the file
    inFile.close();  //close file
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
        cout << "The marks average is : " << ptr->course_info.avg << "  \n";
        ptr = ptr->next;
    }
}

