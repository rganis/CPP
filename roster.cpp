#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>

Roster::Roster() {
    lastIndex = -1;
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr;
    }
}

void Roster::parse(std::string studentData){ //parses data and adds students to roster. there are 8 commas per student
    std::cout << "Parsing data and adding students to roster..." << std::endl;
    for (int i = 0; i < roster_size; i++){  //loops through studentData array
        int rhs = studentData.find(","); //find first comma
        std::string student_id = studentData.substr(0, rhs); 

        int lhs = rhs + 1; 
        rhs = studentData.find(",", lhs); //find second comma
        std::string first_name = studentData.substr(lhs, rhs - lhs); 

        lhs = rhs + 1; 
        rhs = studentData.find(",", lhs); //find third comma
        std::string last_name = studentData.substr(lhs, rhs - lhs); 

        lhs = rhs + 1; 
        rhs = studentData.find(",", lhs); //find fourth comma
        std::string email = studentData.substr(lhs, rhs - lhs);

        lhs = rhs + 1; 
        rhs = studentData.find(",", lhs); //find fifth comma
        int age = stoi(studentData.substr(lhs, rhs - lhs)); 

        lhs = rhs + 1; 
        rhs = studentData.find(",", lhs); //find sixth comma
        int days_in_course1 = stoi(studentData.substr(lhs, rhs - lhs)); 

        lhs = rhs + 1; 
        rhs = studentData.find(",", lhs); //find seventh comma
        int days_in_course2 = stoi(studentData.substr(lhs, rhs - lhs)); 
        
        lhs = rhs + 1; 
        rhs = studentData.find(",", lhs); //find eighth comma
        int days_in_course3 = stoi(studentData.substr(lhs, rhs - lhs)); 
        }
};

// add student methods
void Roster::addStudent(std::string student_id,
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
	Student* newStudent = new Student(student_id, first_name, last_name, email, age, days_in_course1, days_in_course2, days_in_course3, degree_program); //creates a new student object and adds its pointer the roster array
    classRosterArray[lastIndex++] = newStudent; //increments the index of the last student added to the roster
};

void Roster::removeStudent(std::string student_id) //removes student from roster by studentID
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
void Roster::printAll()
{
    for (int i = 0; i < lastIndex; i++) //loops through roster array and calls print method for each student object
    {
        (classRosterArray[i])->print();
    }
};
void Roster::printAverageDaysInCourse(std::string student_id) //prints average number of days in course for a given studentID
{
    bool studentFound = false;
    for (int i = 0; i < lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == student_id)
        {
            studentFound = true;
            int* days = classRosterArray[i]->getDaysToComplete();
            int sum = days[0] + days[1] + days[2];
            double avg = static_cast<double>(sum) / Student::numDays; //cast average as double to get decimal value
            std::cout << "Average number of days to complete courses for student " << student_id << " is " << avg << std::endl;
        }
    }
    if (!studentFound)
    {
        std::cout << "Student " << student_id << " not found." << std::endl;
    }
};
void Roster::printInvalidEmails()//takes no arguments because it loops through all students in the roster array
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
void Roster::printByDegreeProgram(DegreeProgram degree_Program)
{
    std::cout << "Students in the " << degreeProgramStrings[degree_Program] << " program:" << std::endl; //uses degreeProgramStrings array from degree.h to print degree program name
    for (int i = 0; i < lastIndex; i++)
    {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgramStrings[degree_Program])
        {
            classRosterArray[i]->print();
        }
    }
};

Roster::~Roster() //destructor
{
    for (int i = 0; i < lastIndex; i++)
    {
        delete classRosterArray[i]; //deletes each student object in the roster array
    }
    delete this; //deletes roster object
};