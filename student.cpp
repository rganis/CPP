#include "student.h"
#include <iostream>

//empty constructor
Student::Student();//set all members to default values to avoid undefined behavior
    this->m_studentID = "";
    this->m_firstName = "";
    this->m_lastName = "";
    this->m_emailAddress = "";
    this->m_age = 0;
    for (int i = 0; i < numDays; i++) this->m_daysToCompleteCourses[i] = 0;
    this->m_degreeProgram = DegreeProgram::UNDECIDED;

//full constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToCompleteCourses[], DegreeProgram degreeProgram)
{
    this->m_studentID = studentID;
    this->m_firstName = firstName;
    this->m_lastName = lastName;
    this->m_emailAddress = emailAddress;
    this->m_age = age;
    for (int i = 0; i < numDays; i++) this->m_daysToCompleteCourses[i] = daysToCompleteCourses[i];
    this->m_degreeProgram = degreeProgram;
}

//print functions for each member

void Student::printStudentID(){std::cout << getStudentID() << std::endl;}
void Student::printFirstName(){std::cout << getFirstName() << std::endl;}
void Student::printLastName(){std::cout << getLastName() << std::endl;}
void Student::printEmailAddress(){std::cout << getEmailAddress() << std::endl;}
void Student::printAge(){std::cout << getAge() << std::endl;}
void Student::printDaysToComplete(){std::cout << getDaysToComplete() << std::endl;}
void Student::printDegreeProgram(){std::cout << getDegreeProgram() << std::endl;}

//setters/getters

std::string getStudentID() {return m_studentID;}                                                    //get StudentID
void setStudentID(std::string studentID) {m_studentID = studentID;}                                 //set studentID

std::string getFirstName() {return m_firstName;}                                                    //get firstName
void setFirstName(std::string firstName) {m_firstName = firstName;}                                 //set firstName

std::string getLastName() {return m_lastName;}                                                      //get lastName
void setLastName(std::string lastName) {m_lastName = lastName;}                                     //set lastName

std::string getEmailAddress() {return m_emailAddress;}                                              //get EmailAddress
void setEmailAddress(std::string emailAddress) {m_emailAddress = emailAddress;}                     //set emailAddress

int getAge() {return m_age;}                                                                        //get age
void setAge(int age) {m_age = age;}                                                                 //set age

int getDaysToComplete() {return m_daysToCompleteCourses[3];}                                        //get daysToComplete array
void setDaysToComplete(int daysToComplete[3]) {m_daysToCompleteCourses[3] = daysToComplete[3];}     //set daysToComplete array
    
std::string getDegreeProgram() {return m_degreeProgram;}                                            //get degreeProgram
void setDegreeProgram(std::string degreeProgram) {m_degreeProgram = degreeProgram;}                 //set degreeProgram;

//destructor
~Student() {}
