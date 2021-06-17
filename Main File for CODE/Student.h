//
//  StudentPage.h
//  C++ProjectHandIn
//
//  Created by Shivam Missar on 26/03/2021.
//




#define StudentPage_h
#include <fstream>
#include <string>
using namespace std;
class Student
{
public:
    // functions
    void RegisterStudent();
    void FindStudent();
    void DisplayStudent();
    void RegisterMedical();
    void DisplayMedical();
    // contstructors & deconstrcutors
    Student(); // default
    Student(string,string,string,string,string,string,string,double,double,double,string,string,string,string); // check for registered students
    ~Student(); // default de-contstructor
    // variables
    string firstName;
    string middleName; // this optional
    string lastName;
    string ID_number; // Student Number
    string age;
    string course; // their current course
    string course_Type; // if the user does full-time/ Sandwich Year
    string special_Conditions;
    string disabilities;
    string contact_Number; //  Emergency Contact Number
    string contact_Name; // Emergency Contact Name
    string locator; // this will allow the programme to search for the user
    double height;
    double weight;
    double BMI; // this will calculate the BMI of the user
};



