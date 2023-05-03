#include "student.h"
#include <iostream>
#include <string>

//empty constructor
Student::Student()//set all members to default values to avoid undefined behavior
{
    this->m_studentID = "";
    this->m_firstName = "";
    this->m_lastName = "";
    this->m_emailAddress = "";
    this->m_age = 0;
    for (int i = 0; i < numDays; i++) this->m_daysToCompleteCourses[i] = 0;
    this->m_degreeProgram = DegreeProgram::SECURITY;

}
//full constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    this->m_studentID = studentID;
    this->m_firstName = firstName;
    this->m_lastName = lastName;
    this->m_emailAddress = emailAddress;
    this->m_age = age;
    this->m_daysToCompleteCourses[0] = daysInCourse1;
    this->m_daysToCompleteCourses[1] = daysInCourse2;
    this->m_daysToCompleteCourses[2] = daysInCourse3;
    this->m_degreeProgram = degreeProgram;
}

//print functions for each member

void Student::printStudentID(){std::cout << Student::getStudentID() << std::endl;}
void Student::printFirstName(){std::cout << Student::getFirstName() << std::endl;}
void Student::printLastName(){std::cout << Student::getLastName() << std::endl;}
void Student::printEmailAddress(){std::cout << Student::getEmailAddress() << std::endl;}
void Student::printAge(){std::cout << getAge() << std::endl;}
void Student::printDaysToComplete(){std::cout << Student::getDaysToComplete() << std::endl;}
void Student::printDegreeProgram(){std::cout << Student::getDegreeProgram() << std::endl;}

//setters/getters

std::string Student::getStudentID() {return m_studentID;}                                                    //get StudentID
void Student::setStudentID(std::string studentID) {m_studentID = studentID;}                                 //set studentID

std::string Student::getFirstName() {return m_firstName;}                                                    //get firstName
void Student::setFirstName(std::string firstName) {m_firstName = firstName;}                                 //set firstName

std::string Student::getLastName() {return m_lastName;}                                                      //get lastName
void Student::setLastName(std::string lastName) {m_lastName = lastName;}                                     //set lastName

std::string Student::getEmailAddress() {return m_emailAddress;}                                              //get EmailAddress
void Student::setEmailAddress(std::string emailAddress) {m_emailAddress = emailAddress;}                     //set emailAddress

int Student::getAge() {return m_age;}                                                                        //get age
void Student::setAge(int age) {m_age = age;}                                                                 //set age

int Student::getDaysToComplete() {return m_daysToCompleteCourses[3];}                                        //get daysToComplete array
void Student::setDaysToComplete(int daysToComplete[3]) {m_daysToCompleteCourses[3] = daysToComplete[3];}     //set daysToComplete array
    
std::string Student::getDegreeProgram() //get degreeProgram
{   
    if (m_degreeProgram = DegreeProgram::SECURITY){
        return "SECURITY";
    } else if (m_degreeProgram = DegreeProgram::NETWORK){
        return "NETWORK";
    } else if (m_degreeProgram = DegreeProgram::SOFTWARE){
        return "SOFTWARE";
    } else {
        std::cerr << "Invalid degree program specified: " << std::endl;
    }
}                                            

void Student::setDegreeProgram(std::string degreeProgram)  //set degreeProgram;
 {    
    if (degreeProgram == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;} 
    else if (degreeProgram == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;}
    else if (degreeProgram == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;} 
    else {
        std::cerr << "Invalid degree program specified: " << std::endl;
    }
}                                       

//destructor
Student::~Student() {}