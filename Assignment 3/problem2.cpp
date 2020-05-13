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
void search_student(student_tag *s, int temp, string name, int count);
void sort_details(student_tag *s, int temp, int *count);
int binarySearch(student_tag *s, string x, int temp);
void find_maximum(student_tag *s, int temp);
void update_file();

int main()
{
    student_tag student_array[100]; //array of size 100 of datatype student
    int temp = 0;
    int var = 0;
    string name;
    int count = 0;
    int c; //switch statement to display menu
    do
    {
        c = menu();

        switch (c) //c is storing the user input for choice
        {
        case 1:
            // read_file(student_array, &temp);       // reads the file
            // display_students(student_array, temp); // displays the file contents
            break;
        case 2:
            // read_file(student_array, &temp);
            // sort_details(student_array, temp, &count);
            // display_students(student_array, temp);
            break;
        case 3:
            cout << "------SEARCHING----------\n";
            cout << "Input name: ";
            cin >> name;
            read_file(student_array, &temp);
            var = count;
            search_student(student_array, temp, name, var);
            break;
        case 4:
            // cout << "\n-------DETAILS OF STUDENT WHO GOT MAXIMUM AVERAGE MARK--------\n";
            // read_file(student_array, &temp);
            // find_maximum(student_array, temp);
            break;
        case 5:
            // read_file(student_array, &temp);
            // update_file();
            // read_file(student_array, &temp);
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
    cout << "4.Find the details of student who received maximum average\n";
    cout << "5.Add new student to the record\n";
    cout << "6.Quit program\n";
    cout << "Your choice: ";
    cin >> c;
    return c;
}

int read_file(student_tag *s, int *temp) //readfile function
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
    *temp = i;      // temp has the same value of i to check how many records of data is in the file
    inFile.close(); //close file
}



void search_student(student_tag *s, int temp, string name, int count)
{
    student_tag student_array[100];
    char choice;
    int i = 0;
    int check;
    int total;
    int invalid = 0;

    do
    {
        invalid = 0;
        cout << "1.Linear Search\n";
        cout << "2.Binary Search\n";
        cout << "Input choice: ";
        cin >> choice;
        if (choice == '1')
        {
            for (i = 0; i < temp; i++)
                if (s[i].student_info.name == name)
                {
                    double total = 0;
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
                }
                else
                {
                    //cout << "Student with name " << name << " is not in the list\n\n";
                }
        }
        else if (choice == '2' && count != 1)
        {

            cout << "Can't perform binary search on unsorted array!!!\n\n";
            cout << "-----> SEARCHING FINISHED!!!!\n\n";
        }
        else if (choice == '2' && count == 1)
        {
            int result = binarySearch(student_array, name, temp);
            cout << "Binary search\n";
            cout << "result :" << result << "\n";
            cout << "-----> SEARCHING FINISHED!!!!\n\n";
        }
        else
        {
            cout << "Please try again! Your input is invalid!\n\n";
            invalid = 1;
        }
    } while (invalid == 1);
}

void sort_details(student_tag *s, int temp, int *count)
{

    int invalid = 0;
    student_tag sort;
    student_tag sort1;
    char choice;
    int i = 0;
    int m = 0;
    string L;

    cout << "------SORTING--------\n";
    do
    {
        invalid = 0;
        cout << "1.Sort by name\n";
        cout << "2.Sort by average mark\n";
        cout << "Input choice: ";
        cin >> choice;
        if (choice == '1')
        {
            *count = 1;
            cout << "sort by name\n";
            for (i = 0; i < temp - 1; i++)
            {
                for (m = i + 1; m < temp - 1; m++)
                {
                    if ((s[i].student_info.name) > (s[m].student_info.name))
                    {
                        sort1 = s[i];
                        s[i] = s[m];
                        s[m] = sort1;
                    }
                }
            }
            cout << "\n------SORTING FINISHED----------\n\n";
            cout << "Array after sorting by name :\n\n";
        }
        else if (choice == '2')
        {
            *count = 1;
            int j;
            for (i = 0; i < (temp - 1); ++i)
            {
                for (j = 0; j < temp - 1 - i; ++j)
                {
                    if (s[j].course_info.avg > s[j + 1].course_info.avg)
                    {
                        sort = s[j + 1];
                        s[j + 1] = s[j];
                        s[j] = sort;
                    }
                }
            }
            cout << "\n------SORTING FINISHED----------\n\n";
            cout << "Array after sorting by average marks :\n\n";
        }
        else
        {
            cout << "Please try again! Your input is invalid!\n\n";
            invalid = 1;
        }
    } while (invalid == 1);
}

int binarySearch(student_tag *s, string x, int temp)
{
    int low = 0;
    int high = temp - 1;
    int middle; //variable for storing middle value
    //while loop continue until low subscript is greater then higher
    while (low <= high)
    {
        middle = (low + high) / 2; //determines middle element

        //if search query is same as middle element, return middle
        if (x == s[middle].student_info.name)
            return middle;

        //if search is less than middle, set new high
        else if (x < s[middle].student_info.name)
            high = middle - 1; //search lowest end of the array

        //if search query is greater than middle, set new low
        else
            low = middle + 1;
    }

    return -1; //search value not found
}
