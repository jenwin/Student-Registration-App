#include <iostream>
#include <string>
#include "roster.h"
#include <algorithm>
using namespace std;

//Roster constructor
Roster::Roster() {
	//classRosterArray array of pointers to student objects 
	classRosterArray = new Student * [5];

	//student object created to add each student and populates in classRosterArray
	for (int i = 0; i < 5; ++i) {
		classRosterArray[i] = new Student();
	}

	//set index to 0 for add function
	Roster::index = 0;
}

//Roster destructor
Roster::~Roster() {
	//delete every object that was populated in classRosterArray
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}

	//delete the entire classRosterArray
	delete[] classRosterArray;
}

//parses student data
void Roster::parse(string data) {

	size_t comma = data.find(',');

	//checks if the comma position exists
	if (comma != string::npos) {
		
		//extract studentID
		string studentIdData = data.substr(0, comma);
		string studentID = studentIdData;

		//extract firstName
		size_t secondComma = data.find(',', comma + 1);
		string firstName = data.substr(comma + 1, secondComma - comma - 1);

		//extract lastName
		size_t thirdComma = data.find(',', secondComma + 1);
		string lastName = data.substr(secondComma + 1, thirdComma - secondComma - 1);

		//extract emailAddress
		size_t fourthComma = data.find(',', thirdComma + 1);
		string emailAddress = data.substr(thirdComma + 1, fourthComma - thirdComma - 1);

		//extract age and convert from string to integer
		size_t fifthComma = data.find(',', fourthComma + 1);
		string stringAge = data.substr(fourthComma + 1, fifthComma - fourthComma - 1);
		int age = std::stoi(stringAge);

		//extract daysInCourse1, daysInCourse2, daysInCourse3 and convert from string to integer
		size_t sixthComma = data.find(',', fifthComma + 1);
		string daysInCourse1String = data.substr(fifthComma + 1, sixthComma - fifthComma - 1);
		int daysInCourse1 = std::stoi(daysInCourse1String);

		size_t seventhComma = data.find(',', sixthComma + 1);
		string daysInCourse2String = data.substr(sixthComma + 1, seventhComma - sixthComma - 1);
		int daysInCourse2 = std::stoi(daysInCourse2String);

		size_t eighthComma = data.find(',', seventhComma + 1);
		string daysInCourse3String = data.substr(seventhComma + 1, eighthComma - seventhComma - 1);
		int daysInCourse3 = std::stoi(daysInCourse3String);

		//set default value for DegreeProgram, extract the substring after the last comma for enum type
		DegreeProgram degreeProgram = NONE;

		//check enum type values
		if (data.substr(0,2) == "A1" || data.substr(0, 2) == "A4") {
			degreeProgram = SECURITY;
		} else if (data.substr(0, 2) == "A2") {
			degreeProgram = NETWORK;
		} else if (data.substr(0, 2) == "A3" || data.substr(0, 2) == "A5") {
			degreeProgram = SOFTWARE;
		} else {
			degreeProgram = NONE;
		}

		//add each student to the classRosterArray
		if (!data.empty()) {
			add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
		} else {
			cout << "No student Added." << endl;
		}	
	} else {
		cout << "A student was not parsed. A student was not added." << endl;
	}
}

//add each student object to classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourseArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	if (Roster::index < 5) {
		classRosterArray[Roster::index] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram);
		++Roster::index;
	} else {
		cout << "A student was not added." << endl;
	}
}

//removes student by studentID
void Roster::remove(string studentID) {
	int indexToRemove = -1;
	int numArray = 5;
	int lastIndexArray = numArray - 1;

	for (int i = 0; i < Roster::index; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			indexToRemove = i;
			//switches i and the last indexed element
			if (i < lastIndexArray) {
				swap(classRosterArray[i], classRosterArray[numArray - 1]);
				//checks if there is at least 4 elements in numArray
				//switches the last 2 indexes when A3 is removed
				if (2 < numArray && 3 < numArray) {
					swap(classRosterArray[numArray - 3], classRosterArray[numArray - 2]);
				}
				Roster::index--;
			}
		}
	}
	//error message when studentID A3 cannot be found
	if (indexToRemove == -1) {
		cout << "The student with the ID: " << studentID << " was not found." << "\n" << "DONE." << endl;
	}
}

//prints complete tab-separated list of student data
void Roster::printAll() {
	for (int i = 0; i < Roster::index; ++i) {
		classRosterArray[i]->print();
	}
}

//prints a student's average number of days in the three courses by studentID
void Roster::printAverageDaysInCourse(string studentID) {

	for (int i = 0; i < Roster::index; ++i) {
		string fetchStudentID = classRosterArray[i]->getStudentID();
		if (fetchStudentID == studentID) {
			string studentID = classRosterArray[i]->getStudentID();
			int dayOne = classRosterArray[i]->getNumDaysCompleteCourse()[0];
			int dayTwo = classRosterArray[i]->getNumDaysCompleteCourse()[1];
			int dayThree = classRosterArray[i]->getNumDaysCompleteCourse()[2];

			int average = ((dayOne + dayTwo + dayThree) / 3);

			cout << "Student ID: " << studentID << ", average days in course is: " << average << endl;
		}
	}
}

//verifies student email addresses and displays all invalid email addresses
void Roster::printInvalidEmails() const {
	for (int i = 0; i < Roster::index; ++i) {
		string emails = classRosterArray[i]->getEmailAddress();
		//if emails contain underscore or spaces then print out invalid emails
		if (emails.find('_') != string::npos || emails.find(' ') != string::npos) {
			cout << emails << " - is invalid." << endl;
		}
	}
}

//prints student information for degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	bool degreePrint = false;

	for (int i = 0; i < Roster::index; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			if (!degreePrint) {
				cout << "Showing students in degree program: " << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << endl;
				degreePrint = true;
			}
			classRosterArray[i]->print();
		}
	}
}