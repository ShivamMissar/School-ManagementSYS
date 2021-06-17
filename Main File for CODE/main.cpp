
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Student.h" // header file for students
#include "Teacher.h" // header file for teachers


using namespace std;



int MainMenuFunction()
{
    int userINput = 0;
    cout << "Choose from the following options that apply to you: " << endl;
    cout << "1. Student " << endl;
    cout << "2. Teacher " << endl;
    cout << "3. Exit software" << endl;
    cin >> userINput;
    return userINput;
}

int StudentSubMenu1() // this menu will appear first ,it will allow the user to check if they're already registered and if they're already registered then they will go to StudentSubMenu2()
{
    int userINput = 0;
    cout << "Welcome User, choose from the options below " << endl;
    cout << "1. Register your details" << endl;
    cout << "2. Find a student " << endl; // this will allow the user to find themseleves to see if they're registered
    cout << "3. Back to Main Menu" << endl;
    cin >> userINput;
    return userINput;
}
int StudentSubMenu2()
{
    int userINput = 0;
    cout << "Welcome Back, choose from the options below " << endl;
    cout << "1. Display Details " << endl;
    cout << "2. Register Medical Detials" << endl;
    cout << "3. Display Medical Records" << endl; // this will display anything that the user has entered from option 'Register Medical Detials'
    cout << "4. Back to Main Menu" << endl;
    cin >> userINput;
    return userINput;
}
    
int TeacherSUBmenu1()
{
    int userINput = 0;
    cout << "Choose from the options below " << endl;
    cout << "1. Register your details" << endl;
    cout << "2. Find Teacher" << endl;
    cout << "3. Back to Main Menu" << endl;
    cin >> userINput;
    return userINput;
   
}
int TeacherSubMenu2()
{
    int userINput = 0;
    cout << "Welcome Teacher, choose from the options below: " << endl;
    cout << "1.Display" << endl;
    cout << "2.Student Find" << endl; // A teacher can look up Student Details
    cout << "3.Back to main menu" << endl;
    cin >> userINput;
    return userINput;
}
    
int main()
{
    Student CurrentStudent; // Student Object
    Teacher PresentTeachers; // Teacher Object
    vector<Student>StuVector; // student vector for storing elements
    vector<Teacher>TeachVector; // Teacher vector
    vector<Student>MedicalVector; // medical vector
    bool exit = false; // used as a way of exiting the program
    bool back = false; // used as a way of navigating out of teacher and student sections
    do
    {
        cout << "--Main MENU--" << endl;
        cout << "-----------------" << endl;
        int UserINPUT1 = MainMenuFunction();
        switch (UserINPUT1)
        {
            case 1:
               back = false;
                do {
                    if(CurrentStudent.firstName == "")
                    {
                       back = false;
                        do {
                            cout << "--STUDENT MENU FOR NEW STUDENTS--" << endl;
                            int UserINPUT2 = StudentSubMenu1(); // Menu for New students
                            switch (UserINPUT2) // this will load StudentSubMenu1() and this will allow user to pick an option from this menu
                            {
                                case 1:
                                    CurrentStudent.RegisterStudent(); // This function will allow user to register
                                    StuVector.push_back(CurrentStudent); // vector will store those details in a element
                                    break;
                                case 2:
                                    CurrentStudent.FindStudent(); // This function will allow the user to find and see if they're registered
                                    break;
                                case 3:
                                   back = true; // this will allow user to go back to main menu
                                    break;
                                default:
                                    cout << "Invaild Input try again" << endl;
                                    break;
                            }
                        } while (CurrentStudent.firstName == "" && !back); // This will keep looping back until user is registered or wants to go back to main menu
                    }//if
                    else
                    {
                       back = false;
                        do {
                            cout << "--STUDENT MENU FOR CURRENT STUDENTS--" << endl;
                            int UserINPUT4 = StudentSubMenu2(); // Menu for Returning students if they are already registered
                            switch (UserINPUT4) //  this will load StudentSubMenu2(), user can then choose what option they'd like to pick from the menu
                            {
                                case 1:
                                    CurrentStudent.DisplayStudent(); // allow the user to see thier detials
                                    break;
                                case 2:
                                    CurrentStudent.RegisterMedical(); // Registered students will be allowed to register for Medicial
                                    MedicalVector.push_back(CurrentStudent); // vector will store Medical details in some element
                                    break;
                                case 3:
                                    CurrentStudent.DisplayMedical(); // Display whatever the user has put in for in case 2
                                    break;
                                case 4:
                                    back = true;
                                    break;
                                default:
                                    cout << "Sorry this input is invaild" << endl; // if user enters a invaild input it will come up with error message
                                    break;
                                } // student
                        }while (!back);
                    } // else
               } while (!back);
                break;
            case 2:
                if (PresentTeachers.TeachersLogin()) // This is a login for teachers and only teachers will know the passcode
                {
                    cout << "--TeacherMENU--" << endl;
                    cout << "-----------------" << endl;
                    back = false;
                    do {
                        if (PresentTeachers.fname == "") // if "" it will take user to SubMenu1 where they would need to register/ if they have already registered they can choose case 2 where it will see if they exist
                        {
                            do
                            {
                                int UserINPUT3 = TeacherSUBmenu1();
                                switch (UserINPUT3) // it will load TeacherSubMenu1(), it will allow the user to pick from the menu options
                                {
                                    case 1:
                                        PresentTeachers.TeacherRegistration();
                                        TeachVector.push_back(PresentTeachers); // vector will store those details in some element
                                        break;
                                    case 2:
                                        PresentTeachers.FindTeacher();
                                        break;
                                    case 3:
                                        back = true;
                                        break;
                                    default:
                                        cout << "Sorry this input is invaild" << endl;
                                        break;
                                } // switch
                            } while (PresentTeachers.fname == "" && !back); // teacher
                        }
                        else{
                            back = false;
                            do {
                                int UserINPUT5 = TeacherSubMenu2(); // for registered teachers
                                switch (UserINPUT5) // it will load TeacherSubMenu2(), it will allow the user to pick from the menu options
                                {
                                    case 1:
                                        PresentTeachers.DisplayTeacher(); // allow the teacher to see their details of what they put in
                                        break;
                                    case 2:
                                        PresentTeachers.Teacher_FindStudent(); // allow the teacher to look for a student
                                        break;
                                    case 3:
                                        back = true;
                                        break;
                                    default:
                                        cout << "Sorry this input is invaild" << endl;
                                        break;
                                }
                            } while (!back);
                        }
                    } while (!back);
                    break;
                }
                
            case 3:
                exit = true;
                break;
            default:
                if (cin.fail()) // this will check to see if the user entered any string characters instead of interger, and will display this error message
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout  <<"You have entered a string ,please enter a vaild number " << endl;
                    /* this was taken from <https://www.hackerearth.com/practice/notes/validating-user-input-in-c/>  */
                }
                else
                {
                    cout << "You have entered an invaild number"  << endl;
                }
                break;
                }
    }while(!exit);
}


   
 
       
             
