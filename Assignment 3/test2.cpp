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

//function protypes
void menu();
student_tag read(int *array_size);
int read_file(student_tag *s, int *array_size);
void display_students(student_tag *s, int array_size);
void linear_search(student_tag *s, string name, int array_size);
void find_maximum(student_tag *s, int array_size);


Student_TagPtr hptr;

student_tag read(int *array_size) //readfile function
{
    int count;
    double total = 0;
    string filename = "students.txt";
    ifstream inFile;

    inFile.open(filename.c_str());

    if (inFile.fail()) // if file doesnt open successfully
    {
        cout << "The File was not opened successfully\n";
        cout << "Please check that the file currently exists\n";
        exit(1);
    }
    int i = 0;
    while (inFile.peek() != EOF) // until the end of the file
    {
        double total = 0;
        inFile >> hptr-> student_info.name ;
        inFile >> hptr->student_info.id;
        // inFile >> s[i].course_info.course_name; for testing
        // inFile >> s[i].course_info.no_of_units;
        // for (int j = 0; j < s[i].course_info.no_of_units; j++)
        // {
        //     inFile >> s[i].course_info.marks[j];
        //     total = total + s[i].course_info.marks[j];
        // }
        // s[i].course_info.avg = total / s[i].course_info.no_of_units;
        i++;
    }
    *array_size = i; // temp has the same value of i to check how many records of data is in the file
    inFile.close();  //close file
}

student_tag *read_file() //readfile function
{
    int count = 0;
    double total = 0;
    string filename = "test.txt";
    ifstream inFile;

    inFile.open(filename.c_str());

    if (inFile.fail()) // if file doesnt open successfully
    {
        cout << "The File was not opened successfully\n";
        cout << "Please check that the file currently exists\n";
        return nullptr;
    }
    int i = 0;
    student_tag *tail = nullptr;
    student_tag *nptr = new student_tag;
    read(&count);
    while (inFile.peek() != EOF) // until the end of the file
    {
        if (tail)
        {
            tail->next = nptr;
        }
        else
        {
            hptr = nptr;
        }
        tail = nptr;
        nptr = new student_tag; // create space for the next one
    }
    // You created space for the one that failed to read. Delete it
    delete nptr;
    inFile.close(); //close file
    return hptr;
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

int main()
{
    int array_size = 0;
    read_file();
    cout << "The linked list is: ";
    display();
    return 0;
}
