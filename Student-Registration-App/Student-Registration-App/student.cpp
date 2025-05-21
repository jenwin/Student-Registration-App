#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//Student constructor with default values
Student::Student() : studentID(""), firstName(""), lastName(""), emailAddress(""), age(0), numDaysCompleteCourse{0, 0, 0}, degreeProgram(DegreeProgram::NONE) {}

//Student constructor with parameters
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourseArray[3], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++) {
        this->numDaysCompleteCourse[i] = daysInCourseArray[i];
    }
    this->degreeProgram = degreeProgram;
}

//Student destructor
Student::~Student() {}

//accessors (getters)
string Student::getStudentID() {
    return this->studentID;
}
string Student::getFirstName() {
    return this->firstName;
}
string Student::getLastName() {
    return this->lastName;
}
string Student::getEmailAddress() {
    return this->emailAddress;
}
int Student::getStudentAge() const {
    return this->age;
}
const int* Student::getNumDaysCompleteCourse() {
    return this->numDaysCompleteCourse;
}
DegreeProgram Student::getDegreeProgram() const {
    return this->degreeProgram;
}

//mutators (setters)
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::setStudentAge(int age) {
    this->age = age;
}
void Student::setNumDaysCompleteCourse(int numDaysCompleteCourse[3]) {
    for (int i = 0; i < 3; i++) {
        this->numDaysCompleteCourse[i] = numDaysCompleteCourse[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degree) {
    this->degreeProgram = degree;
}

//print student data
void Student::print() {
    const string tab = "\t";

    cout << getStudentID() << tab  
    << getFirstName() << tab 
    << getLastName() << tab
    << getStudentAge() << tab 
    << "{" << getNumDaysCompleteCourse()[0] << ","
    << getNumDaysCompleteCourse()[1] << ","
    << getNumDaysCompleteCourse()[2] << "}" << tab
    << degreeProgramStrings[getDegreeProgram()] << endl;
}