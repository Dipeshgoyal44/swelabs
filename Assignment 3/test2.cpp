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
student_tag read();
student_tag *read_file();
void display_students();

student_tag read() //readfile function
{
    hptr = NULL; //intialized to null
    string name;
    string id;
    string coursename;
    int units;
    int marks[4];
    string filename = "students.txt";
    ifstream inFile(filename);

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
        inFile >> name ;
        inFile >> id;
        inFile >> coursename;
        inFile >> units;
        for (int j = 0; j < units; j++) {
        inFile >> marks[j];
        total = total + marks[j];
        }
        i++;
    hptr = cptr = nptr; 
    nptr = new Student_Tag;
    nptr -> student_info.name = name;
    //cout << nptr-> student_info.name << "\n"; //printing nptr
    nptr->next = NULL; //nptr to next =null

    hptr = cptr = nptr; 
    nptr = new Student_Tag;
    nptr -> student_info.id = id;
    //cout << nptr-> student_info.id << "\n"; //printing nptr
    nptr->next = NULL; //nptr to next =null
    
    hptr = cptr = nptr; 
    nptr = new Student_Tag;
    nptr -> course_info.course_name = coursename;
    //cout << nptr-> course_info.course_name << "\n"; //printing nptr
    nptr->next = NULL; //nptr to next =null

    hptr = cptr = nptr; 
    nptr = new Student_Tag;
    nptr -> course_info.no_of_units = units;
    //cout << nptr-> course_info.no_of_units << "\n"; //printing nptr
    nptr->next = NULL; //nptr to next =null
for (int j = 0; j < units; j++) {
    hptr = cptr = nptr; 
    nptr = new Student_Tag;
    nptr -> course_info.marks[j] = marks[j];
    //cout << nptr-> course_info.marks[j] << "\n"; //printing nptr
    nptr->next = NULL; //nptr to next =null
    }
    hptr = cptr = nptr; 
    nptr = new Student_Tag;
    nptr -> course_info.avg = total / units;
    //cout << nptr-> course_info.avg << "\n"; //printing nptr
    nptr->next = NULL; //nptr to next =null
    }
    
    inFile.close();  //close file
}



void display()
{
    while (hptr != NULL)
    {
        cout << "The Student Name: " << hptr->student_info.name << "  \n";
        cout << "The Student ID: " << hptr->student_info.id << "  \n";
        // cout << "The course name: " << ptr->course_info.course_name << "  \n";
        // cout << "Number of units " << ptr->course_info.no_of_units << "  \n";
        // cout << "Marks recieved: \n";
        // for (int j = 0; j < ptr->course_info.no_of_units; j++)
        // {
        //     cout << ptr->course_info.marks[j] << "  \n";
        // }
        // cout << "The marks average is : " << ptr->course_info.avg << "  \n";
        // ptr = ptr->next;
    }
}

int main()
{
    int array_size = 0;
    read();
    cout << "The linked list is: ";
   display();
    return 0;
}


// student_tag *read_file() //readfile function
// {
//     int count = 0;
//     double total = 0;
//     string filename = "test.txt";
//     ifstream inFile;

//     inFile.open(filename.c_str());

//     if (inFile.fail()) // if file doesnt open successfully
//     {
//         cout << "The File was not opened successfully\n";
//         cout << "Please check that the file currently exists\n";
//         return nullptr;
//     }
//     int i = 0;
//     student_tag *tail = nullptr;
//     student_tag *nptr = new student_tag;
    
//     while (inFile.peek() != EOF) // until the end of the file
//     {
//         if (tail)
//         {
//             tail->next = nptr;
//         }
//         else
//         {
//             hptr = nptr;
//         }
//         tail = nptr;
//         nptr = new student_tag; // create space for the next one
//     }
//     // You created space for the one that failed to read. Delete it
//     delete nptr;
//     inFile.close(); //close file
//     return hptr;
// }