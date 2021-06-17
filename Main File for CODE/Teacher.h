//
//  TeacherPage.h
//  C++ProjectHandIn
//
//  Created by Shivam Missar on 26/03/2021.
//

#ifndef TeacherPage_h
#define TeacherPage_h

#include <fstream>

using namespace std;

class Teacher
{
protected:
    string password = "TeacherAdmin" ; // teacher passcode
public:
    // functions
    bool TeachersLogin(); // this will first prompt the user to enter the teacher password
    void TeacherRegistration(); // This will allow the user to enter thier data
    void FindTeacher(); // this will see if teacher already exists 
    void DisplayTeacher(); // this will display the data that the user has entered
    void Teacher_FindStudent();
    
    // constructors & deconstructors
    Teacher(); //  default constructor
    Teacher(string,string,string,string,double,double,string,string); // if user is registered constructor
    ~Teacher(); //  default destructor
//Variables
    string fname;
    string lname;
    string salary; // yearly salaray
    string experience; // years of experience
    string degree; // type of degree
    double hours_expected; // hours that meant to be done per week
    double hours_done;
    string teaching_subject;
    string passwordAttempt;
    string locator;
};




#endif /* TeacherPage_h */
