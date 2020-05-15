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
void menu();
int read_file(student_tag *s, int *array_size);
void display_students(student_tag *s, int array_size);
void sort_mark(student_tag *s, int array_size);
void sort_name(student_tag *s, int array_size);
void sort_details(student_tag *s, int array_size, int *count);
int binary_search(student_tag *s, string name, int array_size);
int linear_search(student_tag *s, string name, int array_size);
void search_student(student_tag *s, int array_size, string name, int count);
void find_maximum(student_tag *s, int array_size);
void update_file();

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
            read_file(student_array, &array_size);
            sort_details(student_array, array_size, &count);
            display_students(student_array, array_size);
            break;
        case '3':
            cout << "------SEARCHING----------\n";
            cout << "Input name: ";
            cin >> name;
            read_file(student_array, &array_size);
            var = count;
            search_student(student_array, array_size, name, var);
            break;
        case '4':
            cout << "\n-------DETAILS OF STUDENT WHO GOT MAXIMUM AVERAGE MARK--------\n";
            read_file(student_array, &array_size);
            find_maximum(student_array, array_size);
            break;
        case '5':
            read_file(student_array, &array_size);
            update_file();
            read_file(student_array, &array_size);
            break;
        case '6':
            printf("SEE YOU LATER! \n");
            exit(1);
            break;
        default:
            cout << "Please try again! Your input is invalid!\n";
            break;
        }
    } while (c != 6); //while loop keeps running till 4 is chosen as an option.
}

void menu()
{
    char c;
    cout << "\n----MENU----\n";
    cout << "1.Display student's details\n";
    cout << "2.Sort the student's details\n";
    cout << "3.Search for a particular student's mark\n";
    cout << "4.Find the details of student who received maximum average\n";
    cout << "5.Add new student to the record\n";
    cout << "6.Quit program\n";
    
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

void sort_mark(student_tag *s, int array_size)
{
    for (int key = 0; key < array_size - 1; key++)
    {
        for (int i = 0; i < array_size - 1; i++)
        {
            if (s[i].course_info.avg > s[key].course_info.avg)
            {
                std::swap(s[key], s[i]);
            }
        }
    }
}

void sort_name(student_tag *s, int array_size)
{
    for (int i = 0; i < array_size - 1; i++)
    {
        for (int m = i + 1; m < array_size - 1; m++)
        {
            if ((s[i].student_info.name) > (s[m].student_info.name))
            {
                std::swap(s[i], s[m]);
            }
        }
    }
}

void sort_details(student_tag *s, int array_size, int *count)
{
    int invalid = 0;
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
            sort_name(s, array_size);
            cout << "\n------SORTING FINISHED----------\n\n";
            cout << "Array after sorting by name :\n\n";
        }
        else if (choice == '2')
        {
            *count = 1;
            sort_mark(s, array_size);
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

int linear_search(student_tag *s, string name, int array_size)
{
    int i;
    int temp1;
    for (i = 0; i < array_size; i++){
        if (s[i].student_info.name == name)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(student_tag *s, string name, int array_size)
{
    int low = 0;
    int high = array_size - 1;
    int middle; //variable for storing middle value
    //while loop continue until low subscript is greater then higher
    while (low <= high)
    {
        middle = (low + high) / 2; //determines middle element
        //if search query is same as middle element, return middle
        if (name == s[middle].student_info.name)
        {
            return middle;
            //if search is less than middle, set new high
        }
        else if (name < s[middle].student_info.name)
            high = middle - 1; //search lowest end of the array
        //if search query is greater than middle, set new low
        else
            low = middle + 1;
    }
    return -1;
}

void search_student(student_tag *s, int array_size, string name, int count)
{
    // student_tag student_array[100];
    char choice;
    int i = 0;
    int index1 = 0;
    int index = 0;
    int invalid = 0;
    char temp;
    do
    {
        invalid = 0;
        cout << "1.Linear Search\n";
        cout << "2.Binary Search\n";
        cout << "Input choice: ";
        cin >> choice;
        if (choice == '1')
        {
        index1 = linear_search(s, name, array_size);
        ///cout << "LINEAR SEARCH KEY: " << s[index1].student_info.name << "\n";
        if(index1 != -1 ){
            cout << "\n\nName: " << s[index1].student_info.name << "\n";
            cout << "ID: " << s[index1].student_info.id << "\n";
            cout << "Course Name: " << s[index1].course_info.course_name << "\n";
            cout << "Number of units: " << s[index1].course_info.no_of_units << "\n";
            for (int j = 0; j < s[index1].course_info.no_of_units; j++)
            {
                cout << s[index1].course_info.marks[j] << "\n";
            }
            cout << "Average : " << setprecision(2) << fixed << s[index1].course_info.avg << "\n";
            cout << "------------------------\n\n";
            cout << "-----> SEARCHING FINISHED!!!!\n\n";
            }else{
            cout << "Student with name " << name << " is not in the list\n\n";
            cout << "-----> SEARCHING FINISHED!!!!\n\n";
            }
        }
        else if (choice == '2' && count != 1)
        {
            cout << "Can't perform binary search on unsorted array!!!\n\n";
            cout << "-----> SEARCHING FINISHED!!!!\n\n";
        }
        else if (choice == '2' && count == 1)
        {
            sort_mark(s, array_size);
            index = binary_search(s, name, array_size);
            if(index == -1){
            cout << "Student with name " << name << " is not in the list\n\n";
            cout << "-----> SEARCHING FINISHED!!!!\n\n";
            }else{
            cout << "\n\nName: " << s[index].student_info.name << "\n";
            cout << "ID: " << s[index].student_info.id << "\n";
            cout << "Course Name: " << s[index].course_info.course_name << "\n";
            cout << "Number of units: " << s[index].course_info.no_of_units << "\n";
            for (int j = 0; j < s[index].course_info.no_of_units; j++)
            {
                cout << s[index].course_info.marks[j] << "\n";
            }
            cout << "Average : " << setprecision(2) << fixed << s[index].course_info.avg << "\n";
            cout << "------------------------\n\n";
            cout << "-----> SEARCHING FINISHED!!!!\n\n"; 
            }
        }
        else
        {
            cout << "Please try again! Your input is invalid!\n\n";
            invalid = 1;
        }
    } while (invalid == 1);
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

// THINGS NOT WORKING
//1.  need to change original array after sorting.