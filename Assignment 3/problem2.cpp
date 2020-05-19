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
//self referential structure
typedef struct student_tag Student_Tag;
typedef Student_Tag *Student_TagPtr;

Student_TagPtr hptr; //headptr
Student_TagPtr cptr; // currentptr
Student_TagPtr nptr;  //nextptr

//function protypes
void menu();
void read_file();
void display_students();
void linear_search(string name);
void find_maximum();

int main()
{
    string name;
    char c; //switch statement to display menu
    do
    {
        menu();
        cout << "Your choice: ";
        cin >> c;
        switch (c) //c is storing the user input for choice
        {
        case '1':
        //display
            read_file();      // reads the file
            display_students(); // displays the file contents
            break;
        case '2':
        //search
            cout << "Input name: ";
            cin >> name;
            cout << "----------SEARCHING----------\n";
            linear_search(name);
            break;
        case '3':
        //max average
            find_maximum();
            break;
        case '4':
            printf("SEE YOU LATER! \n");
            exit(1);
            break;
        default:
            cout << "Please try again! Your input is invalid!\n";
            break;
        }
    } while (c != 4); //while loop keeps running till 4 is chosen as an option.
}

void menu()
{
    char c;
    cout << "\n----MENU----\n";
    cout << "1.Display student's details\n";
    cout << "2.Search for a student's mark\n";
    cout << "3.Find the details of student with largest average\n";
    cout << "4.Quit program\n\n";
}

void read_file() //readfile function
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
        // Read the data into the node
        inFile >> cptr->student_info.name;
        inFile >> cptr->student_info.id;
        inFile >> cptr->course_info.course_name;
        inFile >> cptr->course_info.no_of_units;
        for (int j = 0; j < cptr->course_info.no_of_units; j++)
        {
            inFile >> cptr->course_info.marks[j];
            total = total + cptr->course_info.marks[j];
        }
        double average = total / cptr->course_info.no_of_units;
        cptr->course_info.avg = average; //storing average
        if (hptr == NULL)
        {
            // First item in the list. hptr pointing to first item
            hptr = cptr;
        }
        else
        {
            // if tot the first item, appending it to the tail.
            nptr->next = cptr;
        }
        nptr = cptr; // Move the tail pointer
    }
    cptr->next = NULL; //  last items next pointer set to NULL
    inFile.close();    //close file
}

void display_students()
{
    Student_TagPtr ptr;
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

void linear_search(string name) // linear search
{
    Student_TagPtr ptr;
    ptr = hptr;
    Student_TagPtr temp; // if name not found
    temp = hptr;
    int check = 0;
    //CHECKING IF NAME IS IN THE LIST
    while (temp != NULL)
    {
        if (temp->student_info.name != name){
            check=1;    
        }
        temp = temp->next;
    }
    if(check==1){
        cout << "Student with name " << name << " is not in the list\n\n";
    }

    while (ptr != NULL)
    {
        if (ptr->student_info.name == name)
        {
            check = 0;
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
            cout << "-----> SEARCHING FINISHED!!!!\n\n";
        }
        ptr = ptr->next;
    }
}

void find_maximum() //display function
{
    cout << "\n-------DETAILS OF STUDENT WHO GOT MAXIMUM AVERAGE MARK--------\n";
    Student_TagPtr ptr;
    Student_TagPtr temp;
    ptr = hptr; // to get max
    temp =hptr; // to display largest average
    double max;
    
    while (ptr != NULL)
    {
        if (ptr->course_info.avg > max){ 
            max = ptr->course_info.avg; // getting max
        }
        ptr = ptr->next;
    }
        while (temp != NULL){
        if (temp->course_info.avg == max) // Checking for max
        {
            cout << "The Student Name: " << temp->student_info.name << "  \n";
            cout << "The Student ID: " << temp->student_info.id << "  \n";
            cout << "The course name: " << temp->course_info.course_name << "  \n";
            cout << "Number of units " << temp->course_info.no_of_units << "  \n";
            cout << "Marks recieved: \n";
            for (int j = 0; j < temp->course_info.no_of_units; j++)
            {
                cout << temp->course_info.marks[j] << "  \n";
            }
            cout << "Average : " << setprecision(2) << fixed << temp->course_info.avg << " \n";
            cout << "------------------------\n\n";
        }
        temp = temp->next;
        }
}