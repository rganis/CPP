#ifndef Student_Header
#define Student_Header
#include "degree.h"

class Student
{
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
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToCompleteCourses[], DegreeProgram degreeProgram); //full constructor

    void setStudentID(std::string studentID); //setters
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int daysToCompleteCourses[numDays]);
    void setDegreeProgram(std::string degreeProgram);

    std::string getStudentID(); //getters
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int getDaysToComplete();
    std::string getDegreeProgram();

    virtual void PrintAll() = 0; // virtual print function to be overridden by derived classes

    ~Student(){};
};

#endif