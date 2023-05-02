#ifndef Roster_Header
#define Roster_Header
#include "student.h"
#include "degree.h"

class Roster : public Student {

public:
    static const int roster_size = 5; // determine size of the student roster array here so we can update it in one place if code is modified
    int lastIndex = 0; // index of the last student added to the roster
    Student* classRosterArray[roster_size]; // roster array of pointers to student objects

    // constructor
    Roster();

    void Parse(std::string studentData);

    // add and remove student methods
    void AddStudent(std::string student_id, std::string first_name, std::string last_name, std::string email, int age, int days_in_course1, int days_in_course2, int days_in_course3, DegreeProgram degree_program);
    void RemoveStudent(std::string student_id);

    // print methods
    void PrintAll();
    void PrintAverageDaysInCourse(std::string student_id);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degree_program);
    
    ~Roster();//destructor
};

#endif 
