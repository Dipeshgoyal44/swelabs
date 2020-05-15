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

struct  student_tag
{
    person_tag student_info;
    course_tag course_info;
    student_tag *next;
};

//function protypes
void menu();
int read_file(student_tag *s, int *array_size);
void display_students(student_tag *s, int array_size);
void linear_search(student_tag *s, string name, int array_size);
void find_maximum(student_tag *s, int array_size);

int main()
{
    student_tag student_array[100]; //array of size 100 of datatype student
    int array_size = 0;
    int var = 0;
    string name;
    int count = 0;
    char c; //switch statement to display menu
    do
    {
        menu();
    cout << "Your choice: ";
    cin >> c;
        switch (c) //c is storing the user input for choice
        {
        case '1':
            read_file(student_array, &array_size);       // reads the file
            display_students(student_array, array_size); // displays the file contents
            break;
        case '2':
            cout << "------SEARCHING----------\n";
            cout << "Input name: ";
            cin >> name;
            read_file(student_array, &array_size);
            var = count;
            break;
        case '3':
            cout << "\n-------DETAILS OF STUDENT WHO GOT MAXIMUM AVERAGE MARK--------\n";
            read_file(student_array, &array_size);
            find_maximum(student_array, array_size);
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
    cout << "4.Quit program\n";
    
}

int read_file(student_tag *s, int *array_size) //readfile function
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
        return 0;
    }
    int i = 0;
    while (inFile.peek() != EOF) // until the end of the file
    {
        double total = 0;
        //name, id,course_name,no of units, marks, average
        inFile >> s[i].student_info.name;
        inFile >> s[i].student_info.id;
        inFile >> s[i].course_info.course_name;
        inFile >> s[i].course_info.no_of_units;
        for (int j = 0; j < s[i].course_info.no_of_units; j++)
        {
            inFile >> s[i].course_info.marks[j];
            total = total + s[i].course_info.marks[j];
        }
        s[i].course_info.avg = total / s[i].course_info.no_of_units;
        i++;
    }
    *array_size = i; // temp has the same value of i to check how many records of data is in the file
    inFile.close();  //close file
}

void display_students(student_tag *s, int array_size) //display function
{
    int i;
    cout << "-----STUDENTS' LIST-----\n\n";
    for (i = 0; i < array_size - 1; i++)
    { //loop runs till the count is same as the value of temp, which is the end of the file.
        double total = 0;
        cout << "---------------------------\n";
        cout << "Name: " << s[i].student_info.name << "\n";
        cout << "ID: " << s[i].student_info.id << "\n";
        cout << "Course Name: " << s[i].course_info.course_name << "\n";
        cout << "Number of units: " << s[i].course_info.no_of_units << "\n";
        for (int j = 0; j < s[i].course_info.no_of_units; j++)
        {
            cout << s[i].course_info.marks[j] << "\n";
        }
        cout << "Average : " << setprecision(2) << fixed << s[i].course_info.avg << "\n";
        cout << "------------------------\n\n";
    }
}

void linear_search(student_tag *s, string name, int array_size)
{
    int i;
    int temp1;
    for (i = 0; i < array_size; i++){
        if (s[i].student_info.name == name)
        {
            cout << "\n\nName: " << s[i].student_info.name << "\n";
            cout << "ID: " << s[i].student_info.id << "\n";
            cout << "Course Name: " << s[i].course_info.course_name << "\n";
            cout << "Number of units: " << s[i].course_info.no_of_units << "\n";
            for (int j = 0; j < s[i].course_info.no_of_units; j++)
            {
                cout << s[i].course_info.marks[j] << "\n";
            }
            cout << "Average : " << setprecision(2) << fixed << s[i].course_info.avg << "\n";
            cout << "------------------------\n\n";
            cout << "-----> SEARCHING FINISHED!!!!\n\n"; 
            //return i;
        }
    }
    cout << "Student with name " << name << " is not in the list\n\n";
    cout << "-----> SEARCHING FINISHED!!!!\n\n";
}


void find_maximum(student_tag *s, int array_size) //display function
{
    double max = 0;
    int i = 0;
    for (i = 0; i < array_size - 1; i++)
    {
        if (s[i].course_info.avg > max) // condition for max
            max = s[i].course_info.avg;
    }
    for (i = 0; i < array_size; i++)
        if (s[i].course_info.avg == max)
        {
            cout << "\nName: " << s[i].student_info.name << "\n";
            cout << "ID: " << s[i].student_info.id << "\n";
            cout << "Course Name: " << s[i].course_info.course_name << "\n";
            cout << "Number of units: " << s[i].course_info.no_of_units << "\n";
            for (int j = 0; j < s[i].course_info.no_of_units; j++)
            {
                cout << s[i].course_info.marks[j] << "\n";
            }
            cout << "Average : " << setprecision(2) << fixed << s[i].course_info.avg << "\n";
            cout << "------------------------\n\n";
        }
}