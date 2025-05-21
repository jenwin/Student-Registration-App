#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "degree.h"
using namespace std;

class Student {

public:
    //Student constructor for default values
    Student();
    //Student parametized constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysCompleteCourse[3], DegreeProgram degreeProgram);
    //Student destructor
    ~Student();

    //accessors (getters)
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getStudentAge() const;
    const int* getNumDaysCompleteCourse();
    DegreeProgram getDegreeProgram() const;

    //mutators (setters)
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setStudentAge(int age);
    void setNumDaysCompleteCourse(int numDaysCompleteCourse[3]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    //print method to print student data
    void print();

//private variables for Student class
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numDaysCompleteCourse[3];
    DegreeProgram degreeProgram;
};

#endif