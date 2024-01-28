#include<string>
using namespace std;

class Student
{
    //insertion operator declaration
    friend ostream& operator<<(ostream& out, const Student& stu);
    private:
        string name;
        string id;
        char classification;
    public:
        Student(); //default constructor declaration
        Student(string nm, string ID, char cls); //parameterized constructor declaration
        //getters
        string getName() const;
        string getId() const;
        char getClassification() const;
        //setter
        void setName(string nm);
        void setId(string i);
        void setClassification(char cl);
};

class Roster
{
    //insertion operator declaration
    friend ostream& operator<<(ostream& out, const Roster& r3);
    private:
        Student* contents;
        int size;
        int capacity;
    public:
        ~Roster();   //rule of 3: destructor
        Roster(); //default constructor declaraction
        Roster(const Roster& r3); //rule of 3: copy constructor
        Roster& operator=(const Roster& r3); //rule of 3: Deep Copy Assignment Overload
        //getters
        Student* getContents() const; 
        //Add and Remove Student 
        void AddStudent(const Student& st);
        void RemoveStudent(int index);
        Student GetAt(int index) const; 
        int getSize() const;
        int getCapacity() const;
        //setters
        void setContents(Student* con);
        void setSize(int s);
        void setCapacity(int cap);
};

class Course 
{
    //insertion operator for course delcaration
    friend ostream& operator<<(ostream& out, const Course& crs);
    private:
        string name;
        string code;
        Roster roster;
    public:
        Course(); //default constructor
        Course(string nm, string cd, Roster rst); //parameterized constructor
        void AddSt(string nm, string ID, char cls); //Add Student
        void RmStudent(int index); //Remove Student
        //getters
        string getName() const;
        string getCode() const;
        Roster getRoster() const;
        //setters
        void setName(string n);
        void setCode(string c);
        void setRoster(Roster r);
};
