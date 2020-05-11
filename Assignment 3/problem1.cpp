#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip>

using namespace std;

typedef struct{
    string name;
    string id;
}person_tag;

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
}student_tag;

int readFile(student_tag *s, int *temp) //readfile function
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
    while(inFile.peek()!=EOF) // until the end of the file
    {
        //name, id,course_name,no of units, marks, average
        inFile >> s[i].student_info.name;
        inFile >> s[i].student_info.id;
        inFile >> s[i].course_info.course_name;
        inFile >> s[i].course_info.no_of_units;
        for (int j = 0; j < s[i].course_info.no_of_units; j++) {
        inFile >> s[i].course_info.marks[j];
        }
        i++;
    }
    *temp = i; // temp has the same value of i to check how many records of data is in the file

    inFile.close(); //close file
}

// void updateFile(FILE *fp) //update function
// {
//     student_tag a;
//     fp = fopen("grades.txt", "a"); //opening in append mode
//     printf("\n Enter the details \n");
//     printf("\n Enter the name:  \n");
//     fflush(stdin);
//     gets(a.name);
//     printf("\n Enter the ID:  \n");
//     fflush(stdin);
//     scanf("%d", &a.id);
//     printf("\n Enter the Marks:  \n");
//     fflush(stdin);
//     scanf("%f", &a.mark);
//     fprintf(fp, "%s %d %.2f \n", a.name, a.id, a.mark); //printing in file
//     printf("\nData Stored Successfully ..\n");
//     fclose(fp); //closing
// }

void displayStudents(student_tag *s, int temp) //display function
{
    
    int i;
    cout << "-----STUDENTS' LIST-----\n\n";
    for (i = 0; i < temp - 1 ; i++)
    { //loop runs till the count is same as the value of temp, which is the end of the file.
        double total = 0;
        cout << "------------------------\n";
        cout << "Name: " <<  s[i].student_info.name << "\n" ;
        cout << "ID: " << s[i].student_info.id << "\n" ;
        cout << "Course Name: " << s[i].course_info.course_name << "\n" ;
        cout <<  "Number of units: " << s[i].course_info.no_of_units << "\n" ;
        for (int j = 0; j < s[i].course_info.no_of_units; j++) {
        cout << s[i].course_info.marks[j] << "\n";
        total = total + s[i].course_info.marks[j];
        }
        double average =  total/s[i].course_info.no_of_units;
        cout << "Average : " << setprecision(2) << fixed << average << "\n";
        cout << "------------------------\n\n";

    }
}

int main()
{
    FILE *fp;
    student_tag student_array[100]; //array of size 100 of datatype student
    int temp = 0;

    int c; //switch statement to display menu
    do
    {
        cout << "----MENU----\n";
        cout << "1.Display student's details\n";
        cout << "2.Sort the student's details\n";
        cout << "3.Search for a particular student's mark\n";
        cout << "4.Display student's details\n";
        cout << "5.Add new student to the record\n";
        cout << "6.Quit program\n";
        cin >> c;
        cout << "Your choice: " << c << "\n";

        switch (c) //c is storing the user input for choice
        {
        case 1:
            readFile(student_array, &temp); // reads the file
            displayStudents(student_array, temp); // displays the file contents
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            printf("SEE YOU LATER! \n");
            exit(1);
            break;
        default:
            cout << "Please try again! Your input is invalid!\n";
            break;
        }
    } while (c != 4); //while loop keeps running till 4 is chosen as an option.
}