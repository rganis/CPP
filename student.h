#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"

class Student{
public:
const static int numDays = 3; //set number of days to complete courses here so we don't have to udpate it in multiple places

private: //members--private so they can't be accessed by derived classes--prefix m_ to indicate member variable
    std::string m_studentID;
    std::string m_firstName;
    std::string m_lastName;
    std::string m_emailAddress;
    int m_age;
    int m_daysToCompleteCourses[numDays];
    DegreeProgram m_degreeProgram;
   
public:

//constructors
    Student();//default constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram); //full constructor
    ~Student();//destructor
    
    void setStudentID(std::string studentID); //setters
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysToComplete1(int daysInCourse1);
    void setDaysToComplete2(int daysInCourse2);
    void setDaysToComplete3(int daysInCourse3);
    void setDegreeProgram(std::string degreeProgram);

    std::string getStudentID(); //getters
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int getDaysToComplete1();
    int getDaysToComplete2();
    int getDaysToComplete3();
    DegreeProgram getDegreeProgram();
    
    void printStudentID(); //print functions for each member
    void printFirstName();
    void printLastName();
    void printEmailAddress();
    void printAge();
    void printDaysToComplete();
    void printDegreeProgram();
    void print();
};
#endif