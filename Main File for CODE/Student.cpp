
#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// default constructor
Student::Student() //  this will check to see user is registered or not
{
    firstName = "";
    middleName = "";
    lastName = "";
    ID_number = "";
    age = "";
    course = "";
    course_Type = "";
    height = 0 ;
    weight = 0 ;
    BMI = 0 ;
    special_Conditions = "";
    disabilities = "";
    contact_Number = "";
    contact_Name = "" ;
}

//to make code modular - used to fill info in
Student::Student(string pfirstName, string pmiddleName, string plastName, string pID_number, string page, string pcourse, string pcourse_Type,double pheight, double pweight,double pBMI,string pspecial_Conditions, string pdisabilities, string pcontact_Number, string pcontact_Name)
{
    firstName = pfirstName;
    middleName = pmiddleName;
    lastName = plastName;
    ID_number = pID_number;
    age = page;
    course = pcourse;
    course_Type = pcourse_Type;
    height = pheight;
    weight = pweight;
    BMI = pBMI;
    special_Conditions = pspecial_Conditions;
    disabilities = pdisabilities;
    contact_Number = pcontact_Number;
    contact_Name = pcontact_Name;
};

Student::~Student()
{ /* default de-constructor - no additonal code needed */ };



void Student:: RegisterStudent() // this function will allow the user to register themselevs.
{
    
    ofstream studentrecord1;
    studentrecord1.open("StudentRegistration.txt",ios::app);
   
    char UserReply = 'n';
    do {
        cout << "FirstName: " << endl;
        cin >>firstName;
        cout <<"MiddleName(If this applies to you),if not type in: none" << endl;
        cin >> middleName;
        cout << "LastName: "<< endl;
        cin >> lastName;
        cout <<"ID Number:" << endl;
        cin >> ID_number;
        cout << "Age:" << endl;
        cin >> age;
        cout << "Course Name: " << endl;
        cin >> course;
        cout << "Course Type(Full-Time/Sandwitch):" << endl;
        cin >> course_Type;
        studentrecord1 << firstName << endl <<  middleName << endl << lastName << endl << ID_number << endl << age << endl << course << endl << course_Type << endl; // data will then get saved to a file
        cout << "You have succesfully registered!!" << endl;
        cout <<"Would you like to enter more data: y/n?" << endl;
        cin >> UserReply;
    } while (UserReply != 'n'); // if user enters 'y' it will rewind the loop and the user can enter more data.If 'n' then it will go back to StudentSubMenu1()
    studentrecord1.close();
}

void Student::FindStudent() // this will check to see if the user is registerd or not
{
    ifstream studentdata2;
    studentdata2.open("StudentRegistration.txt"); // it will read from this file
    if (studentdata2) // this will check to see if the file exists or not
    {
        cout << "File is exists" << endl;
    }
    else
    {
        cout << "File does not exist" << endl;
    }
    
    cout << "Enter a name to be found: " << endl;
    cin >> locator;
    cout << "-----------------" << endl;
    bool searcher = false;
    for (int s = 0; !studentdata2.eof(); s++) // the !studentdata2.eof means that it will not generate an error when going past end-of-file, it will allow more data to be entered past end of file
    {
        getline(studentdata2, firstName);
        if (firstName == locator) // will look for the users firstname
        {
            searcher = true; // if found it will display all the users data
            getline(studentdata2, middleName);
            getline(studentdata2, lastName);
            getline(studentdata2, ID_number);
            getline(studentdata2, age);
            getline(studentdata2, course);
            getline(studentdata2, course_Type);
            cout << "You've been found" << endl;
            break; // stop from progressing
        }
    }
    if (searcher == false) // if not found then it will display an error message
    {
        cout << "Your name is not registered,please go and register!!! " << endl;
    }
    studentdata2.close();
    
}

void Student::DisplayStudent() // if student has been found it will display all the details they had inputted before
{
    cout << "FirstName: " << firstName <<endl;
    cout << "MiddleName: " << middleName <<endl;
    cout << "LastName: " << lastName <<endl;
    cout << "ID: " << ID_number <<endl;
    cout << "Age: " << age << endl;
    cout << "Course: " << course << endl;
    cout << "Course Type:(Full-Time/Sandwitch): " << course_Type <<endl;
}

void Student::RegisterMedical() // this will allow user to register thier Medical Details
    {
        ofstream MedicalData1;
        MedicalData1.open("MedicalRecords.txt",ios::app); // will allow user to keep adding to the file
        char UserMed = 'n';
        do
        {
            cout << "FirstName: " << endl;
            cin >> firstName;
            cout << "Height(CM): " << endl;
            cin >> height;
            cout << "Weight(KG): " << endl;
            cin >> weight;
            cout << "Do you suffer from any conditions? y/n" << endl;
            cin >> special_Conditions;
            cout << "Disabilities: " << endl;
            cin >> disabilities;
            cout << "Emergency Contact: " << endl;
            cin >>contact_Name;
            cout << "Emergency ContactNumber:" << endl;
            cin >> contact_Number;
            BMI = weight / height * height;
            if (BMI < 18.9)
            {
                cout << "Your underweight" << endl;
            }
            else if (BMI < 25.9){
                cout << "your average" << endl;
            }
            else if(BMI > 25.9)
            {
                cout << "Your overweight" << endl;
            }
            cout << "Your BMI is: " << BMI <<  endl;
            MedicalData1 << firstName << endl <<  height << endl << weight << endl << special_Conditions << endl << disabilities << endl << contact_Name << endl << contact_Number << endl << BMI << endl << endl; // everything will be saved to this file
            cout << "Would you like to enter more data?: y/n" << endl;
            cin >> UserMed;
            
        } while (UserMed != 'n');
        MedicalData1.close();
}

void Student::DisplayMedical()
{
    ifstream Medicaldata2("MedicalRecords.txt");
    if (Medicaldata2) // this will check to see if the file exists or not
    {
        cout << "File is exists" << endl;
    }
    else
    {
        cout << "File does not exist" << endl;
    }
    cout << "Enter a name to be displayed: " << endl;
    cin >> locator;
    cout << "-----------------" << endl;
    bool searcher = false;
    string BMIV2; // for converision
    string Height1; // for converision
    string Weight1; // for converision
    for (int s = 0; !Medicaldata2.eof(); s++)
    {
        getline(Medicaldata2, firstName);
        if (firstName == locator) // will look for user
        {
            searcher = true;
            getline(Medicaldata2, Height1); // getline for that specfic data the user had enetered
            cout << "Height:  " << Height1 << endl;
            getline(Medicaldata2, Weight1); // getline for that specfic data the user had enetered
            cout << "Weight: " << Weight1 << endl;
            getline(Medicaldata2, special_Conditions); // getline for that specfic data the user had enetered
            cout << "Conditions:  " << special_Conditions <<  endl;
            getline(Medicaldata2, disabilities); // getline for that specfic data the user had enetered
            cout << "disabilities:  "<< disabilities <<endl;
            getline(Medicaldata2, contact_Name); // getline for that specfic data the user had enetered
            cout << "Emergency Contact Name: " << contact_Name << endl;
            getline(Medicaldata2, contact_Number); // getline for that specfic data the user had enetered
            cout << "Emergency Contact Number: " << contact_Number << endl;
            getline(Medicaldata2, BMIV2); // getline for that specfic data the user had enetered
            cout << "BMI: " << BMIV2 << endl;
            cout << "FirstName: " << firstName << endl;
            height = stod(Height1); // this will convert double into a string
            weight = stod(Weight1); // this will convert double into a string
            BMI = stod(BMIV2); // this will convert double into a string
        }
    }
    if (searcher == false)
    {
        cout << "Your name is not register, please go and register" << endl;
    }
    Medicaldata2.close();
}
