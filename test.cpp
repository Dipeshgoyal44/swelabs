#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Structures
typedef struct
{
    int noofmarks;
    string id;
    int marks[10];
} student_details;


int read_file(student_details *s, int *size);
void display_students(student_details *s, int size);
int calculateMedian(student_details *s, int size);

int main ()
{
    int size = 0;
    student_details array[100];
    read_file(array, &size);
    display_students(array,size);
    cout << "mean is " << calculateMean(array,size); "\n";
    cout << "Median is " << calculateMedian(array,size); "\n";
}


int read_file(student_details *s, int *size) //readfile function
{
    string student_id;
    int marks;
    string filename = "marks.txt"; // filename
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
        inFile >> s[i].noofmarks;
        inFile>>s[i].id;
        for (int j = 0; j < s[i].noofmarks; j++)
        {
            inFile >> s[i].marks[j];
        }
        i++;
    }
    *size = i;
    inFile.close();  //close file
    
}


void display_students(student_details *s, int size) 
{
    int i;
    cout << "-----STUDENTS' LIST-----\n\n";
    for (i = 0; i < size; i++)
    { 
        cout << "ID: " << s[i].id << "\n";
        for (int j = 0; j < s[i].noofmarks; j++)
        {
            cout << "Marks: " << s[i].marks[j] << "\n";
        }
    }
}

int calculateMean(student_details *s, int size)
{
    int sum = 0;
    double mean = 0;
    double j = 0;

    for(int i =0; i < size; i++)
    {
        for (int j = 0; j < s[i].noofmarks; j++)
        {
            sum = sum + s[i].marks[j];
        }
    }
	mean = sum/size;
    return mean;
}

int calculateMedian(student_details *s, int size)
{
    int sum = 0;
    double mean = 0;
    double j = 0;

    for(int i =0; i < size; i++)
    {
        for (int j = 0; j < s[i].noofmarks; j++)
        {
            sum = sum + s[i].marks[j];
        }
    }
	mean = sum/size;
    return mean;
}

