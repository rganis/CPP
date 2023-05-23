#ifndef Roster_Header
#define Roster_Header
#include <string>
#include "student.h"
#include "degree.h"

class Roster : public Student {

public:
    static const int roster_size = 5; // determine size of the student roster array here so we can update it in one place if code is modified
    int lastIndex; // index of the last student added to the roster
    Student* classRosterArray[roster_size]; // roster array of pointers to student objects

    // constructor
    Roster();

    void parse(std::string studentData);

    // add and remove student methods
    void addStudent(std::string student_id, std::string first_name, std::string last_name, std::string email, int age, int days_in_course1, int days_in_course2, int days_in_course3, DegreeProgram degree_program);
    void removeStudent(std::string student_id);

    // print methods
    void printAll();
    void printAverageDaysInCourse(std::string student_id);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degree);
    
    ~Roster();//destructor
};

#endif 
