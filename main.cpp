#include <iostream>

class Student
{
private: //members
    std::string m_studentID;
    std::string m_firstName;
    std::string m_lastName;
    std::string m_emailAddress;
    int m_age;
    int m_daysToCompleteCourses[3];
    std::string m_degreeProgram;
   
public: //constructor
    Student(std::string m_studentID,
        std::string m_firstName,
        std::string m_lastName,
        std::string m_emailAddress,
        int m_age,
        int m_daysToCompleteCourses[3],
        std::string m_degreeProgram)
        {}

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
    int getDaysToComplete() {return m_daysToCompleteCourses[3];}                                        //get daysToComplete array;
    void setDaysToComplete(int daysToComplete[3]) {m_daysToCompleteCourses[3] = daysToComplete[3];}     //set daysToComplete array
};

void print()
{
    std::cout << Student.m_firstName;
}
int main()
{
    Student student1("A1","John","Smith","John1989@gmail.com",[20,30,35,40],"SECURITY");
    print();
    return 0;
}