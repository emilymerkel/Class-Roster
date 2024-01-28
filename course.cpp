#include<iostream>
#include "course.h"
#include<string>
using namespace std;
//Student Class
Student::Student(){
    //default constructor setting the varibles to their default values
   name="nothing";
   id="nothing";
   classification= 0; 
}
//parameterized constructor definition setting parameters equal to private members
Student::Student(string nm, string ID, char cls) {
    name=nm;
    id=ID;
    classification=cls;
}
//insertion operator that calls the Student Class
ostream& operator<<(ostream& out, const Student& stu) {
    out<<stu.name<<" "<<stu.id<<" "<<stu.classification<<" ";

    return out;
}
//getters
string Student::getName() const{
    return name;
}
string Student::getId() const {
    return id;
}
char Student::getClassification() const {
    return classification;
}
//setters
void Student::setName(string nm){
    name=nm;
}
void Student::setId(string i) {
    id=i;
}
void Student::setClassification(char cl) {
    classification=cl;
}

//Roster Class
Roster::Roster(){
    //default constructor sets capacity to 5, size to 0, and makes contents dynamically allocated
    capacity=5;
    size=0;
    contents = new Student[capacity]; 
}
//insertion operator definition prints out contents
ostream& operator<<(ostream& out, const Roster& r3) {
    for(int i=0; i<r3.size; i++)
    {
        out<<r3.contents[i]<<" ";
    }
    return out;
}
//destructor deletes contents dynamically allocated array: rule of 3
Roster::~Roster(){
    delete [] contents;
}
//shallow copy constructor: rule of 3
Roster::Roster(const Roster& r3) {
    capacity = r3.capacity;
    size=r3.size;

    contents = new Student[capacity];
    for(int j=0; j< size; j++) {
        contents[j] = r3.contents[j];
    }
}
//deep copy assignment overload: rule of 3
Roster& Roster::operator=(const Roster& r3) {
    capacity = r3.capacity;
    size = r3.size;

    delete [] contents;
    contents = new Student[capacity];   
    for(int j = 0; j<size; j++)
    {
        contents[j] = r3.contents[j];
    }
    return *this;
}

Student* Roster::getContents() const{
    return contents;
}
//Add Student adds more space to roster if above 5, adds 5 more places in roster for students
void Roster:: AddStudent(const Student& st){
    if(size>=capacity) //if capacity is reached
    {
        capacity+=5;    //adds 5 to capacity
        Student* temp1 = new Student[capacity]; //creates temp arrayt
        for(int i=0; i<size; i++)
        {
                temp1[i]=contents[i]; //puts temp array equal to old array
        }
        delete []contents; //deletes olf array
        contents=temp1; //old array equals new array
    }
    contents[size]=st; 
    size++; //incrementing the size variable after student is added
}
//Remove Function definition
void Roster::RemoveStudent(int index){
    for(int i=index-1; i<size-1; i++) //index is number user enters to be removed, -1 to normalize it
    {
        contents[i]=contents[i+1]; //moves everything after the removes number forward one in the array
    }
    size--; //decrements size after removal
}
//getters
int Roster::getSize() const {
    return size;
}
int Roster::getCapacity() const {
    return capacity;
}
//setters
void Roster::setContents(Student* con) {
    contents=con;
}
void Roster::setSize(int s) {
    size=s;;
}
void Roster::setCapacity(int cap) {
    capacity=cap;
}


//Course Class
//empty default constructor
Course::Course(){

}

Course::Course(string nm, string cd, Roster rst)
{

}
//insertion operator that calls roster which calls student 
ostream& operator<<(ostream& out, const Course& crs) {
    out<<crs.name<<" "<<crs.code<<endl;
    out << crs.roster;
    return out;
}
//takes the variables from class by calling it and then sends them to other Add Student function this confused me so much took me forever to figure out please be right
void Course:: AddSt(string nm,string ID,char cls){
    Student s(nm, ID, cls);
    roster.AddStudent(s);
}
//calls other remove fuction but this time with rister variable
void Course::RmStudent(int index){
    roster.RemoveStudent(index);
}
//getters
string Course::getName() const{
    return name;
}
string Course::getCode() const{
    return code;
}
Roster Course::getRoster() const{
    return roster;
}
//setters
void Course::setName(string n){
    name=n;
}
void Course::setCode(string c){
    code=c;
}
void Course::setRoster(Roster r){
    roster=r;
}

