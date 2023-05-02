#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

const string studentData[] =
{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
 "A5,Richard,Ganis,rganis@wgu.edu,31,21,28,25,SOFTWARE"
};

int main() {
    cout << "C867 Scripting and Programming - Applications" << endl;
    cout << "C++" << endl;
    cout << "Student ID: 001177106" << endl;
    cout << "Richard Ganis" << endl << endl;

    Roster classRoster;

    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }

    cout << "Displaying all students:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Displaying students with invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "Displaying average days in course for each student:" << endl;
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;

    cout << "Displaying students in the Software degree program:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing student A3:" << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "Removing student A3 again:" << endl;
    classRoster.remove("A3");
    cout << endl;

    classRoster.~Roster();

    return 0;
}
