#include <iostream>
#include<string>
#include "course.h"
using namespace std;
int main(){
    int capacity=5; //capacity
    int size=0; //size
    Roster rs; //variable for Roster class
    Course cs; //variable for Course class
    Course* courseArr= new Course[capacity]; //creates a dynamically allocated array to store the courses in
    int option; //user input option
    string nameStudent;
    string nameCourse;
    string nameremove;
    string coderemove;
    string code;
    string roster;
    string idStudent;
    int removestudent;
    char classification;
    //prints out menu of program options to the user
    cout<<"1. Create a course"<<endl;
    cout<<"2. Remove a course"<<endl;
    cout<<"3. List all courses"<<endl;
    cout<<"4. Enroll a student in a course"<<endl;
    cout<<"5. Remove a student from a course"<<endl;
    cout<<"6. Quit program"<<endl;
    cout<<"Please select an option from the list"<<endl;
    cin>>option; //user input
    if(option>6 || option<1) //input validation
    {
        cout<<"Invalid input select a number 1-6"<<endl;
        cin>>option;
    }
    //while option does not =6/stop program
    while(option!=6)
    {
        if(option==1) //if user enters 1 Create a course
        {
            cout<<"Enter the name of the course you would like to create."<<endl;
            cin>>nameCourse; //user enters name of course
            cout<<"Enter the code of the course you would like to create."<<endl;
            cin>>code; //user enters course code
            courseArr[size].setName(nameCourse); //outs the entered name of course into the array
            courseArr[size].setCode(code); //puts code user inputed into course array

            size++; //for each course entered size increments by 1

            
        }
        if(option==2) //option 2 remove course
        {
            cout<<"Enter the number of the course you would like to remove."<<endl;
            cin>>removestudent; //number of student user wants to remove
            for(int i=removestudent-1; i<size-1;i++) //normalizes number into user terms
            {
                courseArr[i]=courseArr[i+1]; //removes student and keeps the rest of the array
            }
            size--; //decrement the size by 1
        }
        if(option==3) //3 list
        {
            cout<<cs; //calls insertion operator in course class
            for(int i=0; i<size; i++)
            {
                cout<<courseArr[i]<<" "; //prints out course array with spaces
            }
            cout<<endl;
        }
        int coursenum;
        if(option==4) //option 4 add student
        {
            cout<<"Enter the of student you would like to enroll in course"<<endl;
            cin>>nameStudent; //students name from user
            cout<<"Enter the id of the student you would like to enroll in course"<<endl;
            cin>>idStudent; //student id from user
            cout<<"Enter the classification of the student you would like to enroll in course"<<endl;
            cin>>classification; //classification user inputs
            cout<<"Enter the number of the course you would like to enroll in"<<endl;
            cin>>coursenum; //course the student wants to be added to
            //calls add course function in student class that calls function in student class      
            courseArr[coursenum-1].AddSt(nameStudent,idStudent,classification);
            
        }
        int remcourse;
        if(option==5) // removes course
        {
            cout<<"Enter the course number you would like to be removed from."<<endl;
            cin>>remcourse;
            cout<<"Enter the number of the student you would like to remove."<<endl;
            cin>>removestudent;
            
            courseArr[remcourse-1].RmStudent(removestudent); //calls remove student function in course class that calls roster
        }
//goes through menu again
    cout<<"1. Create a course"<<endl;
    cout<<"2. Remove a course"<<endl;
    cout<<"3. List all courses"<<endl;
    cout<<"4. Enroll a student in a course"<<endl;
    cout<<"5. Remove a student from a course"<<endl;
    cout<<"6. Quit program"<<endl;
    cout<<"Please select an option from the list"<<endl;
    cin>>option;
    if(option>6 || option<1)
    {
        cout<<"Invalid input select a number 1-6"<<endl;
        cin>>option;
    }
    }


    return 0;
}
