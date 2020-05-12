#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

typedef struct
{
    string name;
    string id;
} person_tag;

typedef struct
{
    string course_name;
    int no_of_units;
    int marks[4];
    double avg;
} course_tag;

typedef struct
{
    person_tag student_info;
    course_tag course_info;
} student_tag;

//function protypes
int menu();
int read_file(student_tag *s, int *temp);
void display_students(student_tag *s, int temp);
void search_student(student_tag *s, int temp, string name);
void sort_details();
//void find_maximum(student_tag *s, int temp);
void update_file();

int main()
{
    student_tag student_array[100]; //array of size 100 of datatype student
    int temp = 0;
    string name;
    int c; //switch statement to display menu
    do
    {
        c = menu();
        cout << "\nYour choice: " << c << "\n\n";
        // if(c==(int)c && c <= 6 && c >= 1){

        switch (c) //c is storing the user input for choice
        {
        case 1:
            read_file(student_array, &temp);       // reads the file
            display_students(student_array, temp); // displays the file contents
            break;
        case 2:
            read_file(student_array, &temp);
            sort_details();
            break;
        case 3:
            cout << "Input name: ";
            cin >> name;
            read_file(student_array, &temp);
            search_student(student_array, temp, name);
            break;
        case 4:
            read_file(student_array, &temp);
            sort_details();
            //find_maximum(student_array, temp);
            break;
        case 5:
            read_file(student_array, &temp);
            update_file();
            read_file(student_array, &temp);
            break;
        case 6:
            printf("SEE YOU LATER! \n");
            exit(1);
            break;
        default:
            cout << "Please try again! Your input is invalid!\n";
            break;
        }
    } while (c != 6); //while loop keeps running till 4 is chosen as an option.
}


int menu()
{
    int c;
        cout << "----MENU----\n";
        cout << "1.Display student's details\n";
        cout << "2.Sort the student's details\n";
        cout << "3.Search for a particular student's mark\n";
        cout << "4.Display student's details\n";
        cout << "5.Add new student to the record\n";
        cout << "6.Quit program\n";
        cin >> c;
        return c;
}

int read_file(student_tag *s, int *temp) //readfile function
{
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
        //name, id,course_name,no of units, marks, average
        inFile >> s[i].student_info.name;
        inFile >> s[i].student_info.id;
        inFile >> s[i].course_info.course_name;
        inFile >> s[i].course_info.no_of_units;
        for (int j = 0; j < s[i].course_info.no_of_units; j++)
        {
            inFile >> s[i].course_info.marks[j];
        }
        i++;
    }
    *temp = i;      // temp has the same value of i to check how many records of data is in the file
    inFile.close(); //close file
}

void update_file() //update function
{
    ofstream outFile;
    student_tag s;
    outFile.open("students.txt", ios::app);
    cout << "-----UPDATE DATA-----\n\n";
    cout << "Enter name: ";
    cin >> s.student_info.name;
    outFile << s.student_info.name << "\n";
    cout << "Enter ID: ";
    cin >> s.student_info.id;
    outFile << s.student_info.id << "\n";
    cout << "Enter course name: ";
    cin >> s.course_info.course_name;
    outFile << s.course_info.course_name << "\n";
    cout << "Enter number of units: ";
    cin >> s.course_info.no_of_units;
    outFile << s.course_info.no_of_units << "\n";
    cout << "Enter " << s.course_info.no_of_units << " marks: \n";
    for (int j = 0; j < s.course_info.no_of_units; j++)
    {
        cin >> s.course_info.marks[j];
        outFile << s.course_info.marks[j] << "\n";
    }
    cout << "\n\n-----> UPDATE FINISHED!!!!\n\n";
    outFile.close(); //close file
}

void display_students(student_tag *s, int temp) //display function
{
    int i;
    cout << "-----STUDENTS' LIST-----\n\n";
    for (i = 0; i < temp - 1; i++)
    { //loop runs till the count is same as the value of temp, which is the end of the file.
        double total = 0;
        cout << "------------------------\n";
        cout << "Name: " << s[i].student_info.name << "\n";
        cout << "ID: " << s[i].student_info.id << "\n";
        cout << "Course Name: " << s[i].course_info.course_name << "\n";
        cout << "Number of units: " << s[i].course_info.no_of_units << "\n";
        for (int j = 0; j < s[i].course_info.no_of_units; j++)
        {
            cout << s[i].course_info.marks[j] << "\n";
            total = total + s[i].course_info.marks[j];
        }
        double average = total / s[i].course_info.no_of_units;
        cout << "Average : " << setprecision(2) << fixed << average << "\n";
        cout << "------------------------\n\n";
    }
}

void search_student(student_tag *s, int temp, string name)
{
    int choice;
    int i = 0;
    int check;
    int total;
    cout << "1.Linear Search\n";
    cout << "2.Binary Search\n";
    cin >> choice;
    cout << "Input choice: " << choice << "\n";
    switch (choice) //c is storing the user input for choice
    {
    case 1:
    for (i = 0; i < temp; i++){
            if (name != s[i].student_info.name){
            check = 1;
            }}
        if(check == 1){
            cout << "Student with name " << name << " is not in the list\n\n";
        }
        for (i = 0; i < temp; i++)
            if (s[i].student_info.name == name)
            {
                double total = 0;
                cout << "Name: " << s[i].student_info.name << "\n";
                cout << "ID: " << s[i].student_info.id << "\n";
                cout << "Course Name: " << s[i].course_info.course_name << "\n";
                cout << "Number of units: " << s[i].course_info.no_of_units << "\n";
                for (int j = 0; j < s[i].course_info.no_of_units; j++)
                {
                    cout << s[i].course_info.marks[j] << "\n";
                    total = total + s[i].course_info.marks[j];
                }
                double average = total / s[i].course_info.no_of_units;
                cout << "Average : " << setprecision(2) << fixed << average << "\n";
                cout << "------------------------\n\n";
                cout << "-----> SEARCHING FINISHED!!!!\n\n";
            }else if(check != 1) {
                cout << "Student with name " << name << " is not in the list\n\n"; 
            }
        break;
    case 2:
        cout << "Can't perform binary search on unsorted array\n\n";
        break;
    default:
        cout << "Please try again! Your input is invalid!\n";
        break;
    }
}


void sort_details()
{
    int choice;
    int i = 0;
    do {
    cout << "------SORTING------\n";
    cout << "1.Sort by name\n";
    cout << "2.Sort by average mark\n";
    cin >> choice;
    cout << "Input choice: " << choice << "\n";
     switch (choice) //c is storing the user input for choice
    {
    case 1:
        break;
    case 2:
        cout << "Can't perform binary search on unsorted array\n\n";
        break;
    default:
        cout << "Please try again! Your input is invalid!\n";
        break;
    }} while (choice < 1 || choice > 2);
}








// void find_maximum(student_tag *s, int temp) //display function
// {
//     int i;
//     double max;
//     for (i = 0; i < temp - 1 ; i++)
//     { //loop runs till the count is same as the value of temp, which is the end of the file.
//         double total = 0;
//         double average = 0;
//         for (int j = 0; j < s[i].course_info.no_of_units; j++) {
//         cout << s[i].course_info.marks[j] << "\n";
//         total = total + s[i].course_info.marks[j];
//         }
//         average  =  total/s[i].course_info.no_of_units;
//         double average2 = average;
//         if (average > average2) // condition for max
//             max = average;
//             cout << max << "\n";
//     }
// }