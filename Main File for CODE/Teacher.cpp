//
//  Teacher.cpp
//  C++ProjectHandIn
//
//  Created by Shivam Missar on 08/04/2021.
//


#include <iostream>
#include <fstream>
#include <string>
#include "Teacher.h"
#include "Student.h"
using namespace std;
Student TeacherAccess;


Teacher::Teacher() // default constructor checking to see if user has registered
{
    fname = "";
    lname = "";
    salary = "";
    experience = "";
    degree = "";
    hours_expected = 0;
    hours_done = 0;
    teaching_subject = "";
}

Teacher::Teacher(string pfname,string plname,string psalary,string pexperience, double phours_expected,double phours_done,string pteaching_subject,string pdegree) // 
{
    fname = pfname;
    lname = plname;
    psalary = psalary;
    experience = pexperience;
    degree = pdegree;
    hours_expected = phours_expected;
    hours_done = phours_done;
    teaching_subject = pteaching_subject;
    
};

Teacher::~Teacher(){/*no additonal content required*/};


void Teacher::Teacher_FindStudent() // this will allow the teacher to read student data
{
    {
        ifstream studentdata2("StudentRegistration.txt"); // teacher will be able to read from student file
        cout << "Enter a of the student...: " << endl;
        cin >> locator;
        cout << "-----------------" << endl;
        bool searcher = false;
        for (int s = 0; !studentdata2.eof(); s++) // the !studentdata.eof will not allow previous data to be overwritten with new data and will allow new data to be saved side by side with old data.
        {
            getline(studentdata2, TeacherAccess.firstName);
            if (TeacherAccess.firstName == locator) // this will check to see if the name matches with the locator
            {
                searcher = true;
                getline(studentdata2, TeacherAccess.middleName); // getline function will get the line that matches with the users first name
                cout << "MiddleName: " << TeacherAccess.middleName << endl;
                getline(studentdata2, TeacherAccess.lastName);
                cout << "LastName: " << TeacherAccess.lastName << endl;
                getline(studentdata2, TeacherAccess.ID_number);
                cout << "ID Number: " << TeacherAccess.ID_number << endl;
                getline(studentdata2, TeacherAccess.age);
                cout << "Age: " << TeacherAccess.age << endl;
                getline(studentdata2, TeacherAccess.course);
                cout << "Course: " << TeacherAccess.course << endl;
                getline(studentdata2, TeacherAccess.course_Type);
                cout << "Course Type: " << TeacherAccess.course_Type << endl;
                break; // stop from progressing
            }
        }
        if (searcher == false)
        {
            cout << "This student could not be found, try entering a different name" << endl;
        }
        studentdata2.close(); // closes the student file after being used.
        
    }
}


bool Teacher::TeachersLogin() // used for teacher to login
{
    int attempts = 0;
    do {
        cout << "Please enter your password" << endl;
        cin >> passwordAttempt;
        if (passwordAttempt != password) // this will check to see if the user got the password wrong
        {
           cout <<  "Invaild password" << endl;
            cout <<"Attempt Num: " << attempts <<  endl;
            attempts++;
        }
        else if (attempts <= 3) // if teacher gets the password correct within 3 attempts
        {
            cout << "Welcome User" << endl;
            return true;
        }
        if (attempts > 3) // if password is incorrect more than 3 times
        {
            cout << "You've had max attempts...try again later" << endl;
            return false;
        }
    }while (passwordAttempt != password);
    return false;
}



void Teacher:: TeacherRegistration()
{
    ofstream teacherRecords;
    teacherRecords.open("Teacherfiles.txt",ios::app); // the data entered by the user will continusly be saved onto the file with the append function
    char UserAnswer = 'n';
    do
    {
        cout << "FirstName: " << endl;
        cin >> fname;
        cout << "LastName: "<< endl;
        cin >> lname;
        cout << "Annual salary: " << endl;
        cin >> salary;
        cout << "Years of experience: "<< endl;
        cin >> experience;
        cout << "Degree: " << endl;
        cin >> degree;
        cout << "Hours expected: " << endl;
        cin >> hours_expected;
        cout << "Hours/day : " << endl;
        cin >> hours_done;
        hours_done = hours_done * 5;
        if (hours_done > hours_expected)
        {
            cout << "your totals hours are: " << hours_done << endl;
            cout << "You've worked over time" << endl;
        }
        else if(hours_done < hours_expected)
        {
            cout << "your totals hours are: " << hours_done << endl;
            cout << "You've worked under, please make sure you've meet your min hours" << endl;
        }
        cout << "Your teaching subject: " << endl;
        cin >> teaching_subject;
        cout <<"Your creation was succesful" << endl;
        cout << "Would you like to enter more data?: y/n" << endl;
        teacherRecords << fname << endl << lname << endl << salary << endl << experience << endl << degree << endl << hours_expected << endl << hours_done << endl << teaching_subject << endl; // structure of how data will be saved to file.
        cin >> UserAnswer;
    } while (UserAnswer != 'n');
    teacherRecords.close();
}

void Teacher::FindTeacher() // this will check to see if the user is registerd or not
{
    ifstream teacherdata1;
    teacherdata1.open("Teacherfiles.txt"); // it will read from this file
    if (teacherdata1) // this will check to see if the file exists or not
    {
        cout << "File is exists" << endl; // if file exists then it will carry on with reading from file
    }
    else
    {
        cout << "File does not exist" << endl;
    } // if file does not exist then it will not be able to read from file
    
    cout << "Enter a name to be found: " << endl;
    cin >> locator;
    cout << "-----------------" << endl;
    bool searcher = false;
    string hours_done1;
    string hours_expected1;
    for (int s = 0; !teacherdata1.eof(); s++) // the !teacherdata2.eof means that it will not generate an error when going past end-of-file, it will allow more data to be entered past end of file
    {
        getline(teacherdata1, fname);
        if (fname == locator) // will look for the users firstname
        {
            searcher = true; // if found it will getlines of the data entered by that specifc user
            getline(teacherdata1, lname);
            getline(teacherdata1, salary);
            getline(teacherdata1, experience);
            getline(teacherdata1, degree);
            getline(teacherdata1, hours_expected1);
            getline(teacherdata1, hours_done1);
            getline(teacherdata1, teaching_subject);
            hours_expected = stod(hours_expected1); // stod used for conversion
            hours_done = stod(hours_done1);
            cout << "You've been found" << endl;
            break; // stop from progressing
        }
    }
    if (searcher == false) // if not found then it will display an error message
    {
        cout << "Your name is not registered,please go and register!!! " << endl;
    }
    teacherdata1.close();
    
}

void Teacher:: DisplayTeacher() // it will then display all the data of what the user had orginally inputted in
{
    cout << "First Name: " << fname << endl;
    cout << "Last Name: " << lname << endl;
    cout << "Annual salary: " << salary << endl;
    cout << "Years of experience: "<< experience << endl;
    cout << "Degree: " << degree << endl;
    cout << "Hours expected from you: " << hours_expected << endl;
    cout << "Hours per day : " << hours_done << endl;
    cout << "Your teaching subject: " << teaching_subject << endl;
}




