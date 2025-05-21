#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
using namespace std;

int main() {

    //studentData including personal information 
    const string studentData[] = { 
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Caden,Longe,Longe@gmail.com,20,30,40,50,SOFTWARE"
    };

    //prints project title
    cout << "Student Enrollment List" << "\n" 
    << endl;

    //classRoster instance to add each student to classRoster
    Roster* classRoster = new Roster();

    //parse string from studentData before adding Student object to classRosterArray
    const static int studentDataSize = 5;
        for (int i = 0; i < studentDataSize; i++) {
            classRoster->parse(studentData[i]);
    }

    //printAll loops through classRosterArray and calls print function for each student
    cout << "Displaying all Students:" << endl;
    classRoster->printAll();
    cout << endl;

    //prints emails that are invalid 
    cout << "Displaying invalid emails:" << endl;
    classRoster->printInvalidEmails();
    cout << endl;

    //prints student ID and average of days in course
    int i = 0;
    while (i < studentDataSize) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
        ++i;
    }
    cout << endl;

    //prints degree program
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;

    //removes studentID A3
    cout << "Removing A3:" << endl;
    classRoster->remove("A3");

    //prints data after removing studentID A3
    classRoster->printAll();
    cout << endl;

    //remove studentID A3 again causes an error
    cout << "Removing A3 Again" << endl;
    classRoster->remove("A3");

    //delete classRoster object
    delete classRoster;
};