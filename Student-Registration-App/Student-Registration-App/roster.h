#pragma once

#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include "student.h"

class Roster {

public:
	//Roster constructor for default values
	Roster();
	//Roster destructor
	~Roster();

	//dynamically access each element in Student
	Student** classRosterArray;
	
	//parse each set of data 
	void parse(string data);

	//add each student object to classRosterArray
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	//removes student by studentID
	void remove(string StudentID);

	//print complete tab-separated list of student data
	void printAll();

	//verifies student email addresses and displays all invalid email addresses
	void printInvalidEmails() const;

	//prints average number of days in the three courses by studentID for each student
	void printAverageDaysInCourse(string studentID);

	//prints student information for degree program by enum type
	void printByDegreeProgram(DegreeProgram degreeProgram);

private:
	//index for adding each student object to classRosterArray
	int index;
};

#endif