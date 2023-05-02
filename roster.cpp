#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>

void Roster::Parse()
    std::cout << "Parsing data and adding students to roster..." << std::endl;
    for (int i = 0; i < roster_size; i++) //loops through studentData array
    {
        std::string studentData = studentData[i]; //assigns each element of studentData array to studentData string
        int rhs = studentData.find(","); //finds the first comma in the studentData string
        std::string student_id = studentData.substr(0, rhs); //assigns the substring from the beginning of the studentData string to the first comma to student_id
        int lhs = rhs + 1; //assigns the index of the character after the first comma to lhs
        rhs = studentData.find(",", lhs); //finds the second comma in the studentData string
        std::string first_name = studentData.substr(lhs, rhs - lhs); //assigns the substring from the character after the first comma to the second comma to first_name
        lhs = rhs + 1; //assigns the index of the character after the second comma to lhs
        rhs = studentData.find(",", lhs); //finds the third comma in the studentData string
        std::string last_name = studentData.substr(lhs, rhs - lhs); //assigns the substring from the character after the second comma to the third comma to last_name
        lhs = rhs + 1; //assigns the index of the character after the third comma to lhs
        rhs = studentData.find(",", lhs); //finds the fourth comma in the studentData string
        std::string email = studentData.substr(lhs, rhs - lhs); //assigns the substring from the character after the third comma to the fourth comma to email
        lhs = rhs + 1; //assigns the index of the character after the fourth comma to lhs
        rhs = studentData.find(",", lhs); //finds the fifth comma in the studentData string
        int age = stoi(studentData.substr(lhs, rhs - lhs)); //assigns the substring from the character after the fourth comma to the fifth comma to age
        lhs = rhs + 1; //assigns the index of the character after the fifth comma to lhs
        rhs = studentData.find(",", lhs); //finds the sixth comma in the studentData string
};

// add student methods
void Roster::AddStudent(std::string student_id,
    std::string first_name,
    std::string last_name,
    std::string email,
    int age,
    int days_in_course1,
    int days_in_course2,
    int days_in_course3,
    DegreeProgram degree_program)
{
    int days_in_course[Student::numDays] = { days_in_course1, days_in_course2, days_in_course3 }; //adds 3 days_in_course values to an array
    classRosterArray[lastIndex] = new Student(student_id, first_name, last_name, email, age, days_in_course, degree_program); //creates a new student object and adds it to the roster array
    lastIndex++; //increments the index of the last student added to the roster
};

void RemoveStudent(std::string student_id) //removes student from roster by studentID
{
    bool studentFound = false;
    for (int i = 0; i < lastIndex; i++) //loop through the roster array to search for studentID
    {
        if (classRosterArray[i]->getStudentID() == student_id) //passes studentID to getStudentID method to compare to studentID in roster array
        {
            studentFound = true;
            delete classRosterArray[i]; //deletes student object from roster array if found
            classRosterArray[i] = classRosterArray[lastIndex - 1]; //replaces deleted student object with the last student object in the roster array
            lastIndex--;
        }
    }
    if (studentFound)
    {
        std::cout << student_id << " removed from roster." << std::endl; //prints message if student is found and removed
    }
    else
    {
        std::cout << student_id << " not found." << std::endl; //prints message if student is not found
    }
}

// print methods
void PrintAll()
{
    for (int i = 0; i < lastIndex; i++) //loops through roster array and calls print method for each student object
    {
        (classRosterArray[i])->print();
    }
};
void PrintAverageDaysInCourse(std::string student_id) //prints average number of days in course for a given studentID
{
    bool studentFound = false;
    for (int i = 0; i < lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == student_id)
        {
            studentFound = true;
            int* days = classRosterArray[i]->getDaysToComplete();
            std::cout << "Average number of days to complete courses for student " << student_id << " is " << (days[0] + days[1] + days[2]) / 3 << std::endl;
        }
    }
    if (!studentFound)
    {
        std::cout << "Student " << student_id << " not found." << std::endl;
    }
};
void PrintInvalidEmails()//takes no arguments because it loops through all students in the roster array
{
    std::cout << "Invalid email addresses:" << std::endl;
    for (int i = 0; i < lastIndex; i++)
    {
        std::string email = classRosterArray[i]->getEmailAddress(); //strings return npos if not found
        if ((email.find("@") == std::string::npos) || (email.find(".") == std::string::npos) || (email.find(" ") != std::string::npos))
        {
            std::cout << email << std::endl;
        }
    }
};
void PrintByDegreeProgram(DegreeProgram degree_program)
{
    std::cout << "Students in the " << degreeProgramStrings[degree_program] << " program:" << std::endl; //uses degreeProgramStrings array from degree.h to print degree program name
    for (int i = 0; i < lastIndex; i++)
    {
        if (classRosterArray[i]->getDegreeProgram() == degree_program)
        {
            classRosterArray[i]->print();
        }
    }
};