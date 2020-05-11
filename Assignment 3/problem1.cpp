#include <iostream>
#include <string>
#define SIZE 100;

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
    float avg;
} course_tag;

typedef struct
{
    person_tag student_info;
    course_tag course_info;
}student_tag;

void readFile(FILE *fp, student_tag *s, int *temp) //readfile function
{

    fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening input file \n "); //error message if the fp pointer is null-means no file is found
        return;
    }

    int i = 0;
    while (!feof(fp)) // until the end of the file
    {
        fscanf(fp, "%s %d %f\n", &s[i].name, &s[i].id, &s[i].mark); //scans the input from file
        i++;
    }
    *temp = i; // temp has the same value of i to check how many records of data is in the file

    fclose(fp); //close file
}

void updateFile(FILE *fp) //update function
{
    student_tag a;
    fp = fopen("grades.txt", "a"); //opening in append mode
    printf("\n Enter the details \n");
    printf("\n Enter the name:  \n");
    fflush(stdin);
    gets(a.name);
    printf("\n Enter the ID:  \n");
    fflush(stdin);
    scanf("%d", &a.id);
    printf("\n Enter the Marks:  \n");
    fflush(stdin);
    scanf("%f", &a.mark);
    fprintf(fp, "%s %d %.2f \n", a.name, a.id, a.mark); //printing in file
    printf("\nData Stored Successfully ..\n");
    fclose(fp); //closing
}

void displayStudents(student_tag *s, int temp) //display function
{

    int i;

    for (i = 0; i < temp; i++)
    { //loop runs till the count is same as the value of temp, which is the end of the file.
        printf("\n Student Name: \t Student ID: \t Student Marks:\n");
        printf("%s \t \t %d \t \t %.2f\n", s[i].name, s[i].id, s[i].mark); //prints out all the records in tabular form
    }
}

void calculateAverage(FILE *fp, student_tag *s, int temp) //average function
{

    float sum = 0, average = 0;
    for (int i = 0; i < temp; i++) //loop runs till the count is same as the value of temp, which is the end of the file.
        sum += s[i].mark;          //adds all the marks in the record
    average = sum / temp;          //classic average calculations
    printf("Total Number of Students:%d\n", temp);
    printf("The average is %.2f\n", average);
}

int main()
{
    FILE *fp;
    student_tag stud[100]; //array of size 100 of datatype student
    int temp = 0;

    int c; //switch statement to display menu
    do
    {
        printf("\n --Chose on of the options below to get started--  \n");
        printf("\n (1)Display all student details \n");
        printf("\n (2)Calculate average of all student marks \n");
        printf("\n (3)Add new student to the record \n");
        printf("\n (4)EXIT \n");
        printf("\n\n------------------------------------------\n");
        printf("\nEnter your choice between 1-4:\n");
        scanf("%d", &c);
        printf("\n");

        switch (c) //c is storing the user input for choice
        {
        case 1:
            readFile(fp, stud, &temp);
            displayStudents(stud, temp);
            break;
        case 2:
            calculateAverage(fp, stud, temp);
            break;
        case 3:
            updateFile(fp);
            break;
        case 4:
            printf("Program is now closing \n");
            exit(1);
            break;
        default: //only allows 1-4 options to be selected, else prints the error message below.
            printf("\n Your choice is wrong\nPlease try again...\n");
            break;
        }
    } while (c != 4); //while loop keeps running till 4 is chosen as an option.
}