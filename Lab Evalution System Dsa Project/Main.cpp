#include<iostream>
#include<fstream>
#include<iomanip>
#include<Conio.h>
#include<string.h>
#include<windows.h>
#include<string>
#include"List.h"
#include"Tree.h"

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//Edited
Tree tree;

class Teacher
{
private:
    string teacherName, id, password, course;
public:
    Teacher();
    void setData(string teacherName, string id, string pass, string course);
};
Teacher::Teacher()
{
    teacherName = " ";
    id = " ";
    password = " ";
    course = " ";
}
void Teacher::setData(string teacherName, string id, string pass, string course)
{
    this->teacherName = teacherName;
    this->id = id;
    password = pass;
    this->course = course;
}

class Student
{
protected:
    string studentName, fatherName, email, phoneNumber, gender, course, enrollment;
    int age;

public:
    Student();
    void setStudentName(string student);
    void setEnrollment(string enrol);
    void setFatherName(string father);
    void setGender(string gender);
    void setPhoneNo(string number);
    void setCourse(string course);
    void setEmail(string email);
    void setAge(int age);
    string getStudentName();
    string getEnrollment();
};
Student::Student()
{
    studentName = "";
    fatherName = "";
    email = "";
    phoneNumber = "";
    gender = "";
    course = "";
    age = 0;
    enrollment = "";
}
void Student::setStudentName(string student)
{
    studentName = student;
}
void Student::setFatherName(string father)
{
    fatherName = father;
}
void Student::setEnrollment(string enrol)
{
    enrollment = enrol;
}
void Student::setCourse(string sn)
{
    course = sn;
}
void Student::setPhoneNo(string sn)
{
    phoneNumber = sn;
}
void Student::setGender(string gender)
{
    this->gender = gender;
}
void Student::setAge(int age)
{
    this->age = age;
}
void Student::setEmail(string email)
{
    this->email = email;
}
string Student::getStudentName()
{
    return studentName;
}
string Student::getEnrollment()
{
    return enrollment;
}
class Lab :public Student
{
private:
    string labNo, labName, labType, date, remarks;
    float rubric1, rubric2, rubric3, rubric4, total, result, finalResult;
public:
    void setLab(string lNumber, string lName, string lType, string remarks, string date, float rub1, float rub2, float rub3, float rub4, float lTotal);
    void setLabNo(string lNumber);
    void setLabName(string lName);
    void setLabType(string lType);
    void setDate(string date);
    void setRemarks(string remarks);
    void setRubOne(float rub1);
    void setRubSec(float rub2);
    void setRubThrd(float rub1);
    void setRubForth(float rub4);
    void setTotal(float lTotal);
    string getLabNo();
    string getLabName();
    string getLabType();
    string getDate();
    string getRemarks();
    float getRubOne();
    float getRubSec();
    float getRubThrd();
    float getRubForth();
    float getTotal();
    void setResult(float lb);
    void setFinalResult(float lb);
    float getResult();
    float getFinalResult();
    friend ostream& operator<<(ostream& os, const Lab& lab);
    bool operator==(const Lab& obj);
    bool operator!=(const Lab& obj);
};
bool Lab::operator!=(const Lab& obj)
{
    return(this->studentName != obj.studentName && this->enrollment != obj.enrollment);
}
bool Lab::operator==(const Lab& obj)
{
    return(this->studentName == obj.studentName || this->enrollment == obj.enrollment);
}
ostream& operator<<(ostream& os, const Lab& lab)
{
    os << lab.labNo << "|" << lab.labName << "|" << lab.labType << "|" << lab.enrollment << "|" << lab.studentName << "|" << lab.rubric1 << "|" << lab.rubric2 << "|" << lab.rubric3 << "|" << lab.rubric4 << "|" << lab.total;
    return os;
}
void Lab::setLabNo(string lNumber)
{
    labNo = lNumber;
}
void Lab::setLabName(string lName)
{
    labName = lName;
}
void Lab::setLabType(string lType)
{
    labType = lType;
}
void Lab::setDate(string date)
{
    date = date;
}
void Lab::setRemarks(string remarks)
{
    remarks = remarks;
}
void Lab::setRubOne(float rub1)
{
    rubric1 = rub1;
}
void Lab::setRubSec(float rub2)
{
    rubric2 = rub2;
}
void Lab::setRubThrd(float rub3)
{
    rubric3 = rub3;
}
void Lab::setRubForth(float rub4)
{
    rubric4 = rub4;
}
void Lab::setTotal(float lTotal)
{
    total = lTotal;
}
float Lab::getRubOne()
{
    return rubric1;
}
float Lab::getRubSec()
{
    return rubric2;
}
float Lab::getRubThrd()
{
    return rubric3;
}
float Lab::getRubForth()
{
    return rubric4;
}
float Lab::getTotal()
{
    return total;
}
string Lab::getLabNo()
{
    return labNo;
}
string Lab::getLabName()
{
    return labName;
}
string Lab::getLabType()
{
    return labType;
}
string Lab::getDate()
{
    return date;
}
string Lab::getRemarks()
{
    return remarks;
}
void Lab::setResult(float lb)
{
    result = lb;
}
void Lab::setFinalResult(float lb)
{
    finalResult = lb;
}
float Lab::getResult()
{
    return result;
}
float Lab::getFinalResult()
{
    return finalResult;
}
void teacherLogin();
void teacherCourse(string course);
void teacherLab(string str, string course);
void createLab(string course, string str);
void editlab(string s1, string course, int numberOfStudent);
void searchStudentByName(Node<Lab>* start, List<Lab>& labList);
void searchStudentByEnrollment(Node<Lab>* start, List<Lab>& labList);
Lab updation(Lab& obj);
void viewLab(string s1, string course, int numberOfStudent);
void calculateResult(string s1, string course, int numberOfStudent);
void viewLab(string course, int numberOfStudent);
void adminLogin(List<Lab>& studentList, List<Teacher>& teacherList);
void Admin(List<Lab>& studentList, List<Teacher>& teacherList);
void getRegister(List<Lab>& studentList, List<Teacher>& teacherList);
void viewDetail(List<Lab>& studentList, List<Teacher>& teacherList);
string decrypted(string str);
string encrypted(string str);

int main()
{
    system("cls");
    Lab obj;
    List<Lab> studentList;
    List<Teacher> teacherList;
    int choice;
    SetConsoleTextAttribute(hConsole,3);
    cout << "\n\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t                          Welcome to Lab Evaluation System                                \n\n";
    cout << "\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t    *******************    \n";
    cout << "\t\t\t\t\t\t      << Main Menu >>    \n";
    cout << "\t\t\t\t\t\t    *******************    \n";
    SetConsoleTextAttribute(hConsole, 6);
    cout << "\n\t\t\t[1] Administrative"; 
    cout << "\n\n\t\t\t[2] Teacher ";
    cout << "\n\n\t\t\t[0] Exit \n";
    cout << "\n\n\t\t\tEnter choice : ";
    cin >> choice;
   
    switch (choice)
    {
    case 1:
        adminLogin(studentList, teacherList);
        break;
    case 2:
        teacherLogin();
        break;
    case 0:
        exit(0);
        break;
    default:
        cout << "Invalid input. Try again." << endl;
        break;
    }
    return 0;
}

void adminLogin(List<Lab>& studentList, List<Teacher>& teacherList)
{
    SetConsoleTextAttribute(hConsole, 3);

    char choice = 'y';
    while (choice == 'y' || choice == 'Y')
    {
        system("cls");
        cout << "\n\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t                           Lab Evaluation System                                \n\n";
        cout << "\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t\t\t\t    *********************   \n";
        cout << "\t\t\t\t\t\t      << Admin Login >>    \n";
        cout << "\t\t\t\t\t\t    *********************    \n";
        SetConsoleTextAttribute(hConsole, 3);

        string number = "usman123";
        string id = "usman@123";
        string iD;
        string pass;
        cin.ignore();
        cout << "\n\n\t\t\t\tEnter ID : ";
        getline(cin, iD);
        cout << "\n\n\t\t\t\tEnter Password : ";
        char cha;
        for (int i = 0; i >= 0;)
        {
            cha = _getch();
            if (cha != 13 && cha != 8)
            {
                pass.push_back(cha);
                cout << '*';
                i++;
            }
            else if (cha == 8) // if backspace is presssed
            {
                if (i != 0)
                {
                    cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
                    i--;
                }
            }
            else if (cha == 13)
            {
                break;         // for end of string
            }
        }
        if (pass == number && iD == id)
        {
            cout << "\n\n\n\t\t\t\t\t\t  << login successfully >>\n\n";
            cout << "\t\t\t\t";
            system("pause");
            Admin(studentList, teacherList);

        }
        else
        {
            while (true)
            {
                SetConsoleTextAttribute(hConsole, 4);
                
                cout << "\n\n\n\t\t\t\t\t\t\t\t  ERROR!!!!!";
                cout << "\n\n\n\t\t\t\t\t\t  <<< UNAUTHORIZED ACCESS !! >>>\n";
                cout << "\t\t\t\tDo You Want To Try Again[Y/N]: ";
                choice = _getche();

                if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
                    break;
            }
            if (choice == 'n' || choice == 'N')
                main();
            SetConsoleTextAttribute(hConsole, 6);
        }
    }
    
}

void Admin(List<Lab>& studentList, List<Teacher>& teacherList)
{
    SetConsoleTextAttribute(hConsole, 3);
    char choice;
    while (true)
    {
        
        system("cls");
        cout << "\n\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t                           Lab Evaluation System                                \n\n";
        cout << "\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t\t\t\t    *********************   \n";
        cout << "\t\t\t\t\t\t      << Admin Panel >>    \n";
        cout << "\t\t\t\t\t\t    *********************    \n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "\n\t\t\t[1] Registeration";
        cout << "\n\n\t\t\t[2] View Detail";
        cout << "\n\n\t\t\t[0] exit \n";
        cout << "\n\n\t\t\tEnter choice : ";
        cin >> choice;
        if (choice == '1' || choice == '2' || choice == '0')
            break;

    }
    switch (choice)
    {
    case '1':
        system("cls");
        getRegister(studentList, teacherList);
        break;
    case '2':
        system("cls");
        viewDetail(studentList, teacherList);
        break;
    case '0':
        system("cls");
        main();
        break;
    default:
        SetConsoleTextAttribute(hConsole, 4);
        cout << "\n\t\t\tInvalid input. Try again." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        break;
    }
    
}

void getRegister(List<Lab>& studentList, List<Teacher>& teacherList)
{
    SetConsoleTextAttribute(hConsole, 3);
    system("cls");
    cout << "\n\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t                           Lab Evaluation System                                \n\n";
    cout << "\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t    *********************   \n";
    cout << "\t\t\t\t\t\t      << Admin Panel >>    \n";
    cout << "\t\t\t\t\t\t    *********************    \n";
    SetConsoleTextAttribute(hConsole, 6);
    fstream file;
    int choice;
    Teacher obj1;
    Lab obj;
    string data, studentName = "", fatherName = "", email = "", phoneNumber = "", gender = "", enrollment = "01-131212-000", teacherName = "", id = "", password = "", courseT1 = "", course1 = "";
    int age = 0;
    string course, courseT;
    cout << "\n\t\t\t[1] Student Registeration"; 
    cout << "\n\n\t\t\t[2] Teacher Registeration";
    cout << "\n\n\t\t\t[0] Exit\n";
    cout << "\n\n\t\t\tEnter choice : ";
    cin >> choice;
    char ch;
    switch (choice)
    {
    case 1:
        do
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 3);
            cout << "\n\t\t\t******************************************************************************\n\n";
            cout << "\t\t\t                           Lab Evaluation System                                \n\n";
            cout << "\t\t\t******************************************************************************\n\n";
            cout << "\t\t\t\t\t\t    **********************  \n";
            cout << "\t\t\t\t\t\t      << Registration >>    \n";
            cout << "\t\t\t\t\t\t    **********************   \n";
            SetConsoleTextAttribute(hConsole, 6);
            course = "";
            file.open("Student.txt");
            if (file.is_open())
            {
                getline(file, data);
                while (!file.eof())
                {
                    getline(file, enrollment, '|');
                    getline(file, data);
                }
            }
            else
            {
                enrollment = "01-131222-000";
            }
            file.close();
            if (enrollment[12] == '9')
            {
                if (enrollment[11] == '9')
                {
                    enrollment[10]++;
                    enrollment[11] = '0';
                    enrollment[12] = '0';
                }
                else
                {
                    enrollment[11]++;
                    enrollment[12] = '0';
                }
            }
            else
            {
                enrollment[12]++;
            }
            cin.ignore();
            cout << "\n\n\t\t\t\t\tEnter detail of Student w" << endl << endl;
            while (true)
            {
                cout << "\n\n\t\t\t\tEnter Name: ";
                getline(cin, studentName);

                if (studentName.length() < 4)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\n\t\t\t\tPlease Enter Correct Name. There are Some Rules For Entering Name."<<endl;
                    cout << "\t\t\t\t[1] Your name Should be atleast 4 character..." << endl;
                    cout << "\t\t\t\t[2] You should Enter Full Name..." << endl;
                    system("pause");
                    SetConsoleTextAttribute(hConsole, 6);
                    continue;
                }
                else
                {
                    break;
                }
            }
            while (true)
            {
                cout << "\n\n\t\t\t\tEnter Father Name: ";
                getline(cin, fatherName);

                if (fatherName.length() < 4)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\n\t\t\t\tPlease Enter Correct Name. There are Some Rules For Entering Name." << endl;
                    cout << "\t\t\t\t[1] Your name Should be atleast 4 character..." << endl;
                    cout << "\t\t\t\t[2] You should Enter Full Name..." << endl;
                    SetConsoleTextAttribute(hConsole, 6);
                    system("pause");
                    continue;
                }
                else
                {
                    break;
                }
            }
            while (true)
            {
                cout << "\n\n\t\t\t\tEnter Email: ";
                getline(cin, email);

                if (email.length() < 13 || email.substr(email.length() - 10) != "@gmail.com")
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\n\t\t\t\tPlease Enter Email. There are Some Rules For Entering Name." << endl;
                    cout << "\t\t\t\t[1] Your Email Should be atleast 13 character..." << endl;
                    cout << "\t\t\t\t[2] You should Enter Authentic Email..." << endl;
                    cout << "\t\t\t\t[3] Your Email should Contain @gmail.com..." << endl;
                    cout << "\t\t\t\t[4] Example example@gmail.com" << endl;
                    SetConsoleTextAttribute(hConsole, 6);
                    system("pause");
                    continue;
                }
                else
                {
                    break;
                }
            }
            while (true)
            {
                cout << "\n\n\t\t\t\tEnter Phone Number: ";
                getline(cin, phoneNumber);

                if (phoneNumber.length() < 11)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\n\t\t\t\tPlease Enter Correct Phone. There are Some Rules For Entering Name." << endl;
                    cout << "\t\t\t\t[1] Your Phone Number Should be atleast 11 Digits..." << endl;
                    cout << "\t\t\t\t[2] You should Enter +92 OR 0 at the Start of Number..." << endl;
                    SetConsoleTextAttribute(hConsole, 6);
                    system("pause");
                    continue;
                }
                else
                {
                    break;
                }
            }
            while (true)
            {
                cout << "\n\n\t\t\t\tEnter Gender [M/F]: ";
                getline(cin, gender);

                if (gender!="M"&& gender != "m"&& gender != "f"&& gender != "F")
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\n\t\t\t\tPlease Enter Correct Gender" << endl;
                    cout << "\t\t\t\t[1] Your Gender Should be Male [M/m] Or Female [F/f]" << endl;
                    SetConsoleTextAttribute(hConsole, 6);
                    system("pause");
                    continue;
                }
                else
                {
                    if (gender == "M" || gender == "m")
                    {
                        gender = "Male";
                    }
                    else if (gender == "F" || gender == "F")
                    {
                        gender = "Female";
                    }
                    break;
                }
                
            }
            while (true)
            {
                cout << "\n\n\t\t\t\tEnter age: ";
                cin >> age;

                if (age<16)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\n\t\t\t\tPlease Enter Correct Age" << endl;
                    cout << "\t\t\t\t[1] Your age Should be atleast 16 years" << endl;
                    SetConsoleTextAttribute(hConsole, 6);
                    system("pause");
                    continue;
                }
                else
                {
                    break;
                }
            }
            
            cout << "\n\n\t\t\t\t\tSelect the courses you want to register";
            do
            {
                system("cls");
                int choice2;
                cout << "\n\t\t\t [01] Computing Fundamentals (CF)";
                cout << "\n\t\t\t [02] Computer Programming (CP)";
                cout << "\n\t\t\t [03] Applied Physics (AP)";
                cout << "\n\t\t\t [04] Object-Oriented Programming (OOP)";
                cout << "\n\t\t\t [05] Data Structures & Algorithms (DSA)";
                cout << "\n\t\t\t [06] Computer Architecture and Logic Design (CALD)";
                cout << "\n\t\t\t [07] Operating Systems (OS)";
                cout << "\n\t\t\t [08] Database Management System (DMS)";
                cout << "\n\t\t\t [09] Software Design & Architecture (SDA)";
                cout << "\n\t\t\t [10] Computer Communication & Networks (CCN)";
                cout << "\n\t\t\t [11] Software Construction (SC)";
                cout << "\n\t\t\t [12] Cloud Computing (CC)";
                cout << "\n\t\t\t [13] Numerical Analysis (NA)";
                cout << "\n\n\t\t\tEnter choice : ";
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                    course1 = "CF";
                    file.open("CF.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 2:
                    course1 = "CP";
                    file.open("CP.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 3:
                    course1 = "AP";
                    file.open("AP.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 4:
                    course1 = "OOP";
                    file.open("OOP.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 5:
                    course1 = "DSA";
                    file.open("DSA.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 6:
                    course1 = "CALD";
                    file.open("CALD.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 7:
                    course1 = "OS";
                    file.open("OS.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 8:
                    course1 = "DMS";
                    file.open("DMS.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 9:
                    course1 = "SDA";
                    file.open("SDA.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 10:
                    course1 = "CCN";
                    file.open("CCN.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 11:
                    course1 = "SC";
                    file.open("SC.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 12:
                    course1 = "CC";
                    file.open("CC.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                case 13:
                    course1 = "NA";
                    file.open("NA.txt", ios::app);
                    file << "\n" << enrollment << "|" << studentName;
                    file.close();
                    break;
                }
                cout << "\n\n\t\t\tDo you want to register for another course";
                cout << "\n\t\t\t [y/Y] Yes";
                cout << "\n\t\t\t [n/N] No\n";
                cout << "\n\n\t\t\tEnter choice : ";
                cin >> ch;
                course = course + "|" + course1;
            } while (ch == 'y' || ch == 'Y');
            obj.setStudentName(studentName);
            obj.setFatherName(fatherName);
            obj.setEnrollment(enrollment);
            obj.setCourse(course);
            obj.setEmail(email);
            obj.setGender(gender);
            obj.setPhoneNo(phoneNumber);
            obj.setAge(age);
            studentList.insertAtStart(obj);
            file.open("Student.txt", ios::app);
            file << "\n" << enrollment << "|" << studentName << "|" << fatherName << "|" << gender << "|" << age << "|" << phoneNumber << "|" << email << course;
            file.close();
            cout << "\n\n\t\t\tDo you want to register another student"; 
            cout << "\n\t\t\t [y/Y] Yes";
            cout<< "\n\t\t\t [n/N] No\n";
            cout << "\n\n\t\t\tEnter choice : ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        break;
    case 2:
        do
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 3);
            cout << "\n\t\t\t******************************************************************************\n\n";
            cout << "\t\t\t                           Lab Evaluation System                                \n\n";
            cout << "\t\t\t******************************************************************************\n\n";
            cout << "\t\t\t\t\t\t    **********************   \n";
            cout << "\t\t\t\t\t\t      << Registration >>    \n";
            cout << "\t\t\t\t\t\t    **********************   \n";
            SetConsoleTextAttribute(hConsole, 6);
            courseT = "";
            cin.ignore();
            cout << "\n\n\t\t\t\t\tEnter detail of teacher " << endl << endl;
            while (true)
            {
                cout << "\n\n\t\t\t\tEnter Teacher Name: ";
                getline(cin, teacherName);

                if (teacherName.length() < 4)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\n\t\t\t\tPlease Enter Correct Name. There are Some Rules For Entering Name." << endl;
                    cout << "\t\t\t\t[1] Your name Should be atleast 4 character..." << endl;
                    cout << "\t\t\t\t[2] You should Enter Full Name..." << endl;
                    SetConsoleTextAttribute(hConsole, 6);
                    system("pause");
                    continue;
                }
                else
                {
                    break;
                }
            }
            bool flag=false;
            while (true)
            {
                cout << "\n\n\t\t\t\tEnter Teacher ID: ";
                getline(cin, id);

                if (id.length() < 6)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\n\t\t\t\tPlease Enter Correct ID. There are Some Rules For Entering Name." << endl;
                    cout << "\t\t\t\t[1] Your ID Should be atleast 5 Digits..." << endl;
                    cout << "\t\t\t\t[2] Your ID may Contain Digits, Letter..." << endl;
                    SetConsoleTextAttribute(hConsole, 6);
                    system("pause");
                    continue;
                }
                else
                {
                    for (int i = 0; i < id.length(); i++)
                    {
                        if (id[i] == '&' || id[i] == '*' || id[i] == '$' || id[i] == '%' || id[i] == '#' || id[i] == '@' || id[i] == '!' || id[i] == '(' || id[i] == ')' || id[i] == ':' || id[i] == '|' || id[i] == '/' || id[i] == ';' || id[i] == ',' || id[i] == '"' || id[i] == '+' || id[i] == '.')
                        {
                            SetConsoleTextAttribute(hConsole, 4);
                            cout << "\n\n\t\t\t\tPlease Enter Correct ID. There are Some Rules For Entering Name." << endl;
                            cout << "\t\t\t\t[1] Your ID Should be atleast 5 Digits..." << endl;
                            cout << "\t\t\t\t[2] Your ID may Contain Digits, Letter..." << endl;
                            cout << "\t\t\t\t[3] Your ID Should Not Contain Spacial Symbole..." << endl;
                            SetConsoleTextAttribute(hConsole, 6);
                            flag = true;
                        }
                    }
                    if (flag)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                    
                }
            }
            
            
            //password = encrypted(password);
            while (true)
            {
                cout << "\n\n\t\t\t\tEnter Teacher Password: ";
                char cha;
                for (int i = 0; i >= 0;)
                {
                    cha = _getch();
                    if (cha != 13 && cha != 8)
                    {
                        password.push_back(cha);
                        cout << '*';
                        i++;
                    }
                    else if (cha == 8) // if backspace is presssed
                    {
                        if (i != 0)
                        {
                            cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
                            i--;
                        }
                    }
                    else if (cha == 13)
                    {
                        break;         // for end of string
                    }
                }

                if (id.length() < 6)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\n\t\t\t\tPlease Enter Correct ID. There are Some Rules For Entering Name." << endl;
                    cout << "\t\t\t\t[1] Your ID Should be atleast 5 Digits..." << endl;
                    cout << "\t\t\t\t[2] Your ID may Contain Digits, Letter..." << endl;
                    SetConsoleTextAttribute(hConsole, 6);
                    system("pause");
                    continue;
                }
                else
                {
                    
                    break;
                }
            }
            cout << "\n\n\t\t\t\t\t\t\tSelect the courses you want to register";
            do
            {
                system("cls");
                int choice3;
                cout << "\n\t\t\t [01] Computing Fundamentals (CF)";
                cout << "\n\t\t\t [02] Computer Programming (CP)";
                cout << "\n\t\t\t [03] Applied Physics (AP)";
                cout << "\n\t\t\t [04] Object-Oriented Programming (OOP)";
                cout << "\n\t\t\t [05] Data Structures & Algorithms (DSA)";
                cout << "\n\t\t\t [06] Computer Architecture and Logic Design (CALD)";
                cout << "\n\t\t\t [07] Operating Systems (OS)";
                cout << "\n\t\t\t [08] Database Management System (DMS)";
                cout << "\n\t\t\t [09] Software Design & Architecture (SDA)";
                cout << "\n\t\t\t [10] Computer Communication & Networks (CCN)";
                cout << "\n\t\t\t [11] Software Construction (SC)";
                cout << "\n\t\t\t [12] Cloud Computing (CC)";
                cout << "\n\t\t\t [13] Numerical Analysis (NA)";

                cout << "\n\n\t\t\tEnter choice : ";
                cin >> choice3;
                switch (choice3)
                {
                case 1:
                    courseT1 = "CF";
                    break;
                case 2:
                    courseT1 = "CP";
                    break;
                case 3:
                    courseT1 = "AP";
                    break;
                case 4:
                    courseT1 = "OOP";
                    break;
                case 5:
                    courseT1 = "DSA";
                    break;
                case 6:
                    courseT1 = "CALD";
                    break;
                case 7:
                    courseT1 = "OS";
                    break;
                case 8:
                    courseT1 = "DMS";
                    break;
                case 9:
                    courseT1 = "SDA";
                    break;
                case 10:
                    courseT1 = "CCN";
                    break;
                case 11:
                    courseT1 = "SC";
                    break;
                case 12:
                    courseT1 = "CC";
                    break;
                case 13:
                    courseT1 = "NA";
                    break;
                }
                cout << "\n\n\t\t\tDo you want to register for another course";
                cout << "\n\t\t\t [y/Y] Yes";
                cout<< "\n\t\t\t [n/N] No\n";
                cout << "\n\n\t\t\tEnter choice : ";
                cin >> ch;
                courseT = courseT + "|" + courseT1;
            } while (ch == 'y' || ch == 'Y');
            obj1.setData(teacherName, id, password, courseT);
            teacherList.insertAtStart(obj1);
            file.open("Teacher.txt", ios::app);
            file << "\n" << teacherName << "|" << id << "|" << password << courseT;
            file.close();
            cout << "\n\n\t\t\tDo you want to register another Teacher"; 
            cout << "\n\t\t\t [y/Y] Yes";
            cout<< "\n\t\t\t [n/N] No\n";
            cout << "\n\n\t\t\tEnter choice : ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        break;
    case 0:
        system("cls");
        Admin(studentList, teacherList);
        break;
    default:
        SetConsoleTextAttribute(hConsole, 4);
        cout << "\n\t\tInvalid input. Try again." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        break;
    }
    system("cls");
    getRegister(studentList, teacherList);
}

void viewDetail(List<Lab>& studentList, List<Teacher>& teacherList)
{
    system("cls");
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t                           Lab Evaluation System                                \n\n";
    cout << "\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t    *********************   \n";
    cout << "\t\t\t\t\t\t      << Admin Panel >>    \n";
    cout << "\t\t\t\t\t\t    *********************    \n";
    SetConsoleTextAttribute(hConsole, 6);
    ifstream file;
    int choice;
    string studentName = "", fatherName = "", email = "", phoneNumber = "", gender = "", course = "", enrollment = "", data = "";
    int age = 0;
    string teacherName = "", id = "", password = "", courseT = "", data2 = "";
    cout << "\n\t\t\t [1] Student Detail";
    cout << "\n\t\t\t [2] Teacher Detail";
    cout<< "\n\t\t\t [0] Exit";
    cout << "\n\n\t\t\tEnter choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t                           Lab Evaluation System                                \n\n";
        cout << "\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t\t\t\t    *********************   \n";
        cout << "\t\t\t\t\t\t     << Student List >>    \n";
        cout << "\t\t\t\t\t\t    *********************    \n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "Enrollment" << setw(30) << "Student Name" << setw(30) << "Father Name" << setw(15) << "Gender" << setw(15) << "Age" << setw(20) << "Phone Number" << setw(22) << "Email" << setw(40) << "Course" << endl;
        file.open("Student.txt");
        getline(file, data);
        while (!file.eof())
        {
            getline(file, enrollment, '|');
            getline(file, studentName, '|');
            getline(file, fatherName, '|');
            getline(file, gender, '|');
            getline(file, data, '|');
            age = stoi(data);
            getline(file, phoneNumber, '|');
            getline(file, email, '|');
            getline(file, course);
            cout << enrollment << setw(30) << studentName << setw(30) << fatherName << setw(15) << gender << setw(15) << age << setw(20) << phoneNumber << setw(22) << email << setw(40) << course;
            cout << endl;
        }
        file.close();
        system("pause");
        break;
    case 2:
        system("cls");
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t                           Lab Evaluation System                                \n\n";
        cout << "\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t\t    *********************   \n";
        cout << "\t\t\t\t     << Teacher List >>    \n";
        cout << "\t\t\t\t    *********************    \n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "\t\t\t" << "Name" << setw(30) << "ID" << setw(25) << "Password" << setw(30) << "Course" << endl;
        file.open("Teacher.txt");
        getline(file, data2);
        while (!file.eof())
        {
            getline(file, teacherName, '|');
            getline(file, id, '|');
            getline(file, password, '|');
            getline(file, courseT);
            cout << "\t\t\t" << teacherName << setw(30) << id << setw(25) << password << setw(30) << courseT;
            cout << endl;
        }
        file.close();
        system("pause");
        break;
    case 0:
        system("cls");
        Admin(studentList, teacherList);
        break;
    default:
        cout << "\n\n\n\t\t\t\t\t\t  Invalid input. Try again." << endl;
        break;
    }
    system("cls");
    viewDetail(studentList, teacherList);
}

void teacherLogin()
{
    char choice = 'y';
    while (choice == 'y' || choice == 'Y')
    {
        system("cls");
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t                           Lab Evaluation System                                \n\n";
        cout << "\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t\t\t\t    ***********************    \n";
        cout << "\t\t\t\t\t\t      << Teacher Login >>    \n";
        cout << "\t\t\t\t\t\t    ***********************    \n";
        SetConsoleTextAttribute(hConsole, 6);
        ifstream file;
        bool check = true;
        string data, iD = "", id = "", pass = "", password = "", course;
        cin.ignore();
        cout << "\n\t\t\t Enter ID: ";
        getline(cin, iD);
        cout << "\n\t\t\t Enter password: ";
        char cha;
        for (int i = 0; i >= 0;)
        {
            cha = _getch();
            if (cha != 13 && cha != 8)
            {
                pass.push_back(cha);
                cout << '*';
                i++;
            }
            else if (cha == 8) // if backspace is presssed
            {
                if (i != 0)
                {
                    cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
                    i--;
                }
            }
            else if (cha == 13)
            {
                break;         // for end of string
            }
        }

        file.open("Teacher.txt", ios::app);
        int i = 0;
        while (!file.eof())
        {
            getline(file, data, '|');
            getline(file, id, '|');
            getline(file, password, '|');
            getline(file, course);
            //password = decrypted(password);
            if (pass == password && iD == id)
            {
                check = true;
                break;
            }
            else
            {
                check = false;
            }
        }
        file.close();
        if (check == true)
        {
            cout << "\n\n\n\t\t\t\t\t\t  << login successfully >>\n";
            cout << "\n\t\t\t";
            system("pause");

            teacherCourse(course);
        }
        else
        {
            while (true)
            {
                SetConsoleTextAttribute(hConsole, 4);
                cout << "\n\n\n\t\t\t\t\t\t  ERROR!!!!!";
                cout << "\n\n\n\t\t\t\t\t\t  <<< UNAUTHORIZED ACCESS !! >>>\n";
                SetConsoleTextAttribute(hConsole, 6);
                cout << "\t\t\tDo You Want To Try Again[Y/N]: ";
                choice = _getche();


                if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
                    break;
            }
            if (choice == 'n' || choice == 'N')
                main();
           
        }
    }
    
}

void teacherCourse(string str)
{
    system("cls");
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t                           Lab Evaluation System                                \n\n";
    cout << "\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t    ***********************    \n";
    cout << "\t\t\t\t\t\t       << Teacher Panel >>    \n";
    cout << "\t\t\t\t\t\t    ***********************    \n";
    SetConsoleTextAttribute(hConsole, 6);
    string hr = str;
    int size;
    int choice;
    string course[8];
    string deli = "|";
    int i = 0;
    int start = 0;
    int end = str.find(deli);
    while (end != -1)
    {
        course[i] = str.substr(start, end - start);
        start = end + deli.size();
        end = str.find(deli, start);
        i++;
    }
   
    course[i] = str.substr(start, end - start);
    course[i] = course[i];
    for (int j = 0; j <= i; j++)
    {
        if (course[j] == "CF")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Computer Fundamental";
        else if (course[j] == "CP")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Computer Programing";
        else if (course[j] == "AP")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Applied Physics";
        else if (course[j] == "OOP")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Object-Oriented Programming";
        else if (course[j] == "DSA")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Data Structures & Algorithms";
        else if (course[j] == "CALD")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Computer Architecture and Logic Design";
        else if (course[j] == "OS")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Operating Systems";
        else if (course[j] == "DMS")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Database Management System";
        else if (course[j] == "SDA")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Software Design & Architecture";
        else if (course[j] == "CCN")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Computer Communication & Networks";
        else if (course[j] == "SC")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Software Construction";
        else if (course[j] == "CC")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Cloud Computing";
        else if (course[j] == "NA")
            cout << "\n\t\t\t [" << j + 1 << "] " << " Numerical Analysis";
        course[j] = course[j];
    }
    //cout << str.substr(start, end - start);
    cout << "\n\t\t\t [0]  Exit";
    cout << "\n\n\t\t\t\t Enter your choice: ";
    cin >> choice;
    size = i + 1;
    if (size == 1)
    {
        switch (choice)
        {
        case 1:
            teacherLab(str, course[0]);
            break;
        case 0:

            main();
            break;
        default:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\n\n\t\t\t\t\t\t\t\t  Invalid input. Try again." << endl;
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }
    }
    else if (size == 2)
    {
        switch (choice)
        {
        case 1:
            teacherLab(str, course[0]);
            break;
        case 2:
            teacherLab(str, course[1]);
            break;
        case 0:

            main();
            break;
        default:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\n\n\t\t\t\t\t\t\t\t  Invalid input. Try again." << endl;
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }
    }
    else if (size == 3)
    {
        switch (choice)
        {
        case 1:
            teacherLab(str, course[0]);
            break;
        case 2:
            teacherLab(str, course[1]);
            break;
        case 3:
            teacherLab(str, course[2]);
            break;
        case 0:

            main();
            break;
        default:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\n\n\t\t\t\t\t\t\t\t  Invalid input. Try again." << endl;
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }
    }
    else if (size == 4)
    {
        switch (choice)
        {
        case 1:
            teacherLab(str, course[0]);
            break;
        case 2:
            teacherLab(str, course[1]);
            break;
        case 3:
            teacherLab(str, course[2]);
            break;
        case 4:
            teacherLab(str, course[3]);
            break;
        case 0:

            main();
            break;
        default:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\n\n\t\t\t\t\t\t\t\t  Invalid input. Try again." << endl;
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }
    }
    else if (size == 5)
    {
        switch (choice)
        {
        case 1:
            teacherLab(str, course[0]);
            break;
        case 2:
            teacherLab(str, course[1]);
            break;
        case 3:
            teacherLab(str, course[2]);
            break;
        case 4:
            teacherLab(str, course[3]);
            break;
        case 5:
            teacherLab(str, course[4]);
            break;
        case 0:

            main();
            break;
        default:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\n\n\t\t\t\t\t\t\t\t  Invalid input. Try again." << endl;
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }
    }
    else if (size == 6)
    {
        switch (choice)
        {
        case 1:
            teacherLab(str, course[0]);
            break;
        case 2:
            teacherLab(str, course[1]);
            break;
        case 3:
            teacherLab(str, course[2]);
            break;
        case 4:
            teacherLab(str, course[3]);
            break;
        case 5:
            teacherLab(str, course[4]);
            break;
        case 6:
            teacherLab(str, course[5]);
            break;
        case 0:

            main();
            break;
        default:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\n\n\t\t\t\t\t\t\t\t  Invalid input. Try again." << endl;
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }
    }
    else if (size == 7)
    {
        switch (choice)
        {
        case 1:
            teacherLab(str, course[0]);
            break;
        case 2:
            teacherLab(str, course[1]);
            break;
        case 3:
            teacherLab(str, course[2]);
            break;
        case 4:
            teacherLab(str, course[3]);
            break;
        case 5:
            teacherLab(str, course[4]);
            break;
        case 6:
            teacherLab(str, course[5]);
            break;
        case 7:
            teacherLab(str, course[6]);
            break;
        case 0:

            main();
            break;
        default:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\n\n\t\t\t\t\t\t\t\t  Invalid input. Try again." << endl;
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }
    }
    else if (size == 8)
    {
        switch (choice)
        {
        case 1:
            teacherLab(str, course[0]);
            break;
        case 2:
            teacherLab(str, course[1]);
            break;
        case 3:
            teacherLab(str, course[2]);
            break;
        case 4:
            teacherLab(str, course[3]);
            break;
        case 5:
            teacherLab(str, course[4]);
            break;
        case 6:
            teacherLab(str, course[5]);
            break;
        case 7:
            teacherLab(str, course[6]);
            break;
        case 8:
            teacherLab(str, course[7]);
            break;
        case 0:

            main();
            break;
        default:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\n\n\t\t\t\t\t\t\t\t  Invalid input. Try again." << endl;
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "\n\n\n\t\t\t\t\t\t\t\t  Error!!!!!!!!!";
        SetConsoleTextAttribute(hConsole, 6);
        system("pause");
    }
    teacherCourse(hr);

}

void teacherLab(string str, string course)
{
    system("cls");
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t                           Lab Evaluation System                                \n\n";
    cout << "\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t    ***********************    \n";
    cout << "\t\t\t\t\t\t       << Teacher Panel >>    \n";
    cout << "\t\t\t\t\t\t    ***********************    \n";
    SetConsoleTextAttribute(hConsole, 6);
    int choice;
    cout << "\n\t\t\t [1] Create Lab";
    cout << "\n\t\t\t [2] View Lab";
    cout << "\n\t\t\t [3] Edit Lab";
    cout << "\n\t\t\t [4] View Result";
    cout<< "\n\t\t\t [0] Exit\n";
    cout << "\n\n\t\t\t\t Enter your choice: ";
    cin >> choice;
    string data, Course;
    ifstream file;
    int numberOfStudent = 0;
    Course = course + ".txt";
    file.open(Course);
    getline(file, data);
    while (!file.eof())
    {
        getline(file, data, '|');
        getline(file, data);
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] <= 90 && data[i] >= 65)
            {
                data[i] = data[i] + 32;
            }
            else if (data[i] == ' ')
            {
                data[i] = '{';
            }
        }
        tree.insert(data);
        numberOfStudent++;
    }
    switch (choice)
    {
    case 1:
        createLab(course, str);
        break;
    case 2:
        viewLab(str, course, numberOfStudent);
        break;
    case 3:
        editlab(str, course, numberOfStudent);
        break;
    case 4:
        calculateResult(str, course, numberOfStudent);
        break;
    case 0:
        teacherCourse(str);
        break;
    default:
        SetConsoleTextAttribute(hConsole, 4);
        cout << "\n\n\n\t\t\t\t\t\t  Invalid input. Try again." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        break;
    }
    teacherLab(str, course);
}

void viewLab(string s1, string course, int numberOfStudent)
{
    system("cls");
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t                           Lab Evaluation System                                \n\n";
    cout << "\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t    ********************    \n";
    cout << "\t\t\t\t\t\t       << Lab Detail >>    \n";
    cout << "\t\t\t\t\t\t    ********************    \n";
    SetConsoleTextAttribute(hConsole, 6);
    string labNo, labTopic, labType, date, remarks, data;
    fstream file;
    string courseLab;
    courseLab = course + " Lab.txt";
    cout << "\n\n\t\t\tDisplaying detial of " << course << " lab\n\n";
    cout << "\n\t\t"<<setw(10) << "Lab No" << setw(30) << "Lab Topic" << setw(30) << "Lab Type" << setw(30) << "Date" << setw(30) << "Remark\n";
    int i;
    file.open(courseLab);
    getline(file, data);
    bool isEmpty = false;
    while (!file.eof())
    {
        getline(file, labNo);
        if (labNo == "")
        {
            isEmpty = true;
            break;
        }
           
        getline(file, labTopic);
        getline(file, labType);
        getline(file, date);
        getline(file, remarks);
        for (i = 0; i < numberOfStudent; i++)
        {
            getline(file, data);
        }
        cout << "\n\t\t"<< setw(10) << labNo << setw(30) << labTopic << setw(30) << labType << setw(30) << date << setw(30) << remarks << endl;
    }
    if (isEmpty)
        cout << "\n\t\tThere is No Lab Created....\n\t\t";
    system("pause");
    teacherLab(s1, course);
}

void createLab(string course, string str)
{
    system("cls");
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t                           Lab Evaluation System                                \n\n";
    cout << "\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t    ********************    \n";
    cout << "\t\t\t\t\t\t      << Create Lab >>    \n";
    cout << "\t\t\t\t\t\t    ********************    \n";
    SetConsoleTextAttribute(hConsole, 6);
    int i, choice;
    List<Lab> labList[100];
    string enrollment, studentName, data;
    float rubric1 = 0, rubric2 = 0, rubric3 = 0, rubric4 = 0, total = 0;
    fstream outFile;
    fstream inFile;
    string labNo, labTopic, labType, date, remarks;
    Lab obj;
    cin.ignore();
    while (true)
    {
        cout << "\n\t\t\t Enter Lab Number: ";
        getline(cin, labNo);

        if (!(isdigit(labNo[0])))
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\t\t\tPlease Enter Correct Data..." << endl;
            cout << "\n\t\t\tYour lab No shoud be number..." << endl;
            cout << "\n\t\t\t";
            SetConsoleTextAttribute(hConsole, 6);
            system("pause");
            continue;
        }
        break;
    }
   
   
    while (true)
    {
        cout << "\n\t\t\t Enter Lab Topic: ";
        getline(cin, labTopic);

        if (labTopic.length()<4)
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\t\t\tPlease Enter Correct Data..." << endl;
            cout << "\n\t\t\tYour lab Topic shoud be at least 4 character..." << endl;
            cout << "\n\t\t\tif You Dont have Lab Topic Then Enter \"NILL\"..." << endl;
            cout << "\n\t\t\t";
            SetConsoleTextAttribute(hConsole, 6);
            system("pause");
            continue;
        }
        break;
    }
    while (true)
    {
        cout << "\n\n\t\t\t Select Lab Type\n\t\t\t [1] Simple\n\t\t\t [2] OpenEnded\n\t\t\t [3] Mid\n\t\t\t [4] Project\n";
        cout << "\n\t\t\t Enter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
        {
            break;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Invalid Type" << endl;
            SetConsoleTextAttribute(hConsole, 6);
            cout << "\n\t\t\t";
            system("pause");
            continue;
        }
    }
    
    switch (choice)
    {
    case 1:
        labType = "Normal";
        break;
    case 2:
        labType = "OpenEnded";
        break;
    case 3:
        labType = "Mid";
        break;
    case 4:
        labType = "Project";
        break;
    default:
        cout << "\n\n\n\t\t\t\t\t  Invalid Type";
    }
    cin.ignore();
   
    while (true)
    {
        cout << "\n\t\t\t Enter Date: ";
        getline(cin, date);

        if (date.length() < 6)
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\t\t\tPlease Enter Correct Data..." << endl;
            cout << "\n\t\t\tYour Date shoud be at least 6 character..." << endl;
            cout << "\n\t\t\tYour Date should be \"day-monthe-year\"   (02-08-2023)..." << endl;
            cout << "\n\t\t\t";
            SetConsoleTextAttribute(hConsole, 6);
            system("pause");
            continue;
        }
        break;
    }
  
    while (true)
    {
        cout << "\n\t\t\t Enter Remarks: ";
        getline(cin, remarks);

        if (labTopic.length() < 4)
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\t\t\tPlease Enter Correct Data..." << endl;
            cout << "\n\t\t\tYour Remarks shoud be at least 4 character..." << endl;
            cout << "\n\t\t\tif You Dont have Remarks Then Enter \"NILL\"..." << endl;
            cout << "\n\t\t\t";
            SetConsoleTextAttribute(hConsole, 6);
            system("pause");
            continue;
        }
        break;
    }
    string courseLab, fileName;
    courseLab = course + " Lab.txt";
    fileName = course + ".txt";
    inFile.open(courseLab, ios::app);
    inFile << "\n" << labNo << "\n" << labTopic << "\n" << labType << "\n" << date << "\n" << remarks;
    inFile.close();
    outFile.open(fileName);
    getline(outFile, data);
    while (!outFile.eof())
    {
        getline(outFile, enrollment, '|');
        getline(outFile, studentName);
        for (int i = 0; i < studentName.length(); i++)
        {
            if (studentName[i] <= 90 && studentName[i] >= 65)
            {
                studentName[i] = studentName[i] + 32;
            }
        }
        obj.setLabNo(labNo);
        obj.setLabName(labTopic);
        obj.setLabType(labType);
        obj.setDate(date);
        obj.setRemarks(remarks);
        obj.setEnrollment(enrollment);
        obj.setStudentName(studentName);
        obj.setRubOne(rubric1);
        obj.setRubSec(rubric2);
        obj.setRubThrd(rubric3);
        obj.setRubForth(rubric4);
        obj.setTotal(total);
        i = stoi(labNo) - 1;
        labList[i].insertAtEnd(obj);
    }
    outFile.close();
    int choice1;
    char ch;
    Lab obj1[100];
    for (int j = 0; j < 15; j++)
    {
        if (stoi(labNo) == j + 1)
        {
            Node<Lab>* start = labList[j].getStart();
            do
            {
                cout << "\n\t\t\t [1] Search By Name\n\t\t\t [2] Search By Enrollment\n";
                cout << "\n\t\t\t Enter choice: ";
                cin >> choice1;
                switch (choice1)
                {
                case 1:
                    searchStudentByName(start, labList[j]);
                    break;
                case 2:
                    searchStudentByEnrollment(start, labList[j]);
                    break;
                default:
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\n\n\t\t\t\t\t  Invalid Choice";
                    SetConsoleTextAttribute(hConsole, 6);
                }
                cout << "\n\t\t\t Do you want to mark another student\n\t\t\t [y/Y] Yes\n\t\t\t [n/N] No\n";
                cout << "\n\t\t\t Enter choice: ";
                cin >> ch;
            } while (ch == 'y' || ch == 'Y');

            inFile.open(courseLab, ios::app);
            start = labList[j].getStart();
            for (Node<Lab>* ptr = start; ptr != NULL; ptr = ptr->next)
            {
                obj = ptr->info;
                inFile << "\n" << obj.getEnrollment() << "|" << obj.getStudentName() << "|" << obj.getRubOne() << "|" << obj.getRubSec() << "|" << obj.getRubThrd() << "|" << obj.getRubForth() << "|" << obj.getTotal();
            }
            inFile.close();
        }
    }
    system("pause");
    teacherLab(str, course);
}

void editlab(string s1, string course, int numberOfStudent)
{
    system("cls");
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\t\t\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t                           Lab Evaluation System                                \n\n";
    cout << "\t\t\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t\t\t    ******************   \n";
    cout << "\t\t\t\t\t\t\t\t       << Edit Lab >>    \n";
    cout << "\t\t\t\t\t\t\t\t    ******************   \n";
    SetConsoleTextAttribute(hConsole, 6);
    List<Lab> labList[100];
    string studentName, enrollment, labNo, labName, labType, data, date, remarks;
    float rubric1, rubric2, rubric3, rubric4, total;
    int i, j = 0;
    Lab obj;
    fstream file;
    string fileName;
    fileName = course + " Lab.txt";
    file.open(fileName);
    getline(file, data);
    bool isEmpty = false;
    while (!file.eof())
    {
        i = 0;
        getline(file, labNo);
        if (labNo == "")
        {
            isEmpty = true;
            break;
        }
        getline(file, labName);
        getline(file, labType);
        getline(file, date);
        getline(file, remarks);
        while (i < numberOfStudent)
        {
            getline(file, enrollment, '|');
            getline(file, studentName, '|');
            for (int i = 0; i < studentName.length(); i++)
            {
                if (studentName[i] <= 90 && studentName[i] >= 65)
                {
                    studentName[i] = studentName[i] + 32;
                }
            }
            getline(file, data, '|');
            rubric1 = stoi(data);
            getline(file, data, '|');
            rubric2 = stoi(data);
            getline(file, data, '|');
            rubric3 = stoi(data);
            getline(file, data, '|');
            rubric4 = stoi(data);
            getline(file, data);
            total = stoi(data);
            obj.setLabNo(labNo);
            obj.setLabName(labName);
            obj.setLabType(labType);
            obj.setDate(date);
            obj.setRemarks(remarks);
            obj.setEnrollment(enrollment);
            obj.setStudentName(studentName);
            obj.setRubOne(rubric1);
            obj.setRubSec(rubric2);
            obj.setRubThrd(rubric3);
            obj.setRubForth(rubric4);
            obj.setTotal(total);
            j = stoi(labNo) - 1;
            labList[j].insertAtEnd(obj);
            i++;
        }
    }
    if (isEmpty)
    {
        cout << "\n\t\t\t\tThere is No Lab Created....\n\t\t\t\t";
        system("pause");
        teacherLab(s1, course);
    }
    file.clear();
    file.close();
    char ch;
    Lab obj1[100];
    cout << "\n\t\t\t\t\t Enter Lab Number You Want to Edit:";
    int w = j;
    cin >> w;
    int t;
    t = w - 1;
    int choice1;
    ofstream file2;
    file2.open(fileName);
    Node<Lab>* start = NULL;
    for (int k = 0; k <= 15; k++)
    {
        start = labList[k].getStart();
        if (start != NULL)
        {
            if (k == t)
            {
                do
                {
                    cout << "\n\t\t\t\t\t [1] Search By Name\n\t\t\t\t\t [2] Search By Enrollment\n";
                    cout << "\n\t\t\t\t\t Enter choice: ";
                    cin >> choice1;
                    switch (choice1)
                    {
                    case 1:
                        searchStudentByName(start, labList[k]);
                        break;
                    case 2:
                        searchStudentByEnrollment(start, labList[k]);
                        break;
                    default:
                        cout << "Invalid Choice";
                    }
                    cout << "\n\t\t\t\t\t Do you want to mark another student\n\t\t\t\t\t [y/Y] Yes\n\t\t\t\t\t [n/N] No\n";
                    cout << "\n\t\t\t\t\t Enter choice: ";
                    cin >> ch;
                } while (ch == 'y' || ch == 'Y');
            }
            start = labList[k].getStart();
            obj = start->info;
            file2 << "\n" << obj.getLabNo() << "\n" << obj.getLabName() << "\n" << obj.getLabType() << "\n" << obj.getDate() << "\n" << obj.getRemarks();
            for (Node<Lab>* ptr = start; ptr != NULL; ptr = ptr->next)
            {
                obj = ptr->info;
                file2 << "\n" << obj.getEnrollment() << "|" << obj.getStudentName() << "|" << obj.getRubOne() << "|" << obj.getRubSec() << "|" << obj.getRubThrd() << "|" << obj.getRubForth() << "|" << obj.getTotal();
            }
        }
    }
    file2.close();
    system("pause");
    teacherLab(s1, course);
}

void searchStudentByName(Node<Lab>* start, List<Lab>& labList)
{
    system("cls");
    string str = {};
    string str2 = {};
    char ch;
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t                           Lab Evaluation System                                \n\n";
    cout << "\t\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t    *********************   \n";
    cout << "\t\t\t\t\t\t      << Searching >>    \n";
    cout << "\t\t\t\t\t\t    *********************    \n";
    SetConsoleTextAttribute(hConsole, 6);
    labList.traverse();
    cout << "\n\n\t\t\tEnter Student to search: ";
    ch = _getch();
    if (ch <= 90 && ch >= 65)
    {
        ch = ch + 32;
    }
    //This Loop will input ch from user and will keep on suggesting names until ENTER is pressed
    while (ch != 13) //13 is ASCII code of ENTER key so while loop will continue until Enter is pressed
    {

        system("cls");
        if (ch == 8) //8 is ASCII code of Backspace key so when backspace is pressed it will pop character
        {
            if (str.length() > 0)
            {
                str = str.erase(str.size() - 1);
                str2 = str2.erase(str2.size() - 1);
            }
        }
        else if (ch == ' ')
        {
            str.push_back('{');
            str2.push_back(' ');
        }
        else
        {
            if (ch >= 97 && ch <= 122)
            {
                str.push_back(ch);
                str2.push_back(ch);
            }
        }
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t                           Lab Evaluation System                                \n\n";
        cout << "\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t\t\t\t    *********************   \n";
        cout << "\t\t\t\t\t\t       << Searching >>    \n";
        cout << "\t\t\t\t\t\t    *********************    \n";
        SetConsoleTextAttribute(hConsole, 6);
        labList.traverse();
        cout << "\n\n\t\t\tEnter Student to search: ";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '{')
                cout << str[i];
            else
                cout << " ";

        }
        cout << endl;
        SetConsoleTextAttribute(hConsole, 9);
        cout << "\n\t\t\t\t\t----   Suggestions -----" << endl;
        SetConsoleTextAttribute(hConsole, 6);
        tree.printAutoSuggestions(str);
        ch = _getch();
        if (ch <= 90 && ch >= 65)
        {
            ch = ch + 32;
        }
    }
    Lab obj1[100];
    int i = 0;
    for (Node<Lab>* ptr = start; ptr != NULL; ptr = ptr->next)
    {
        obj1[i] = ptr->info;
        if (str2 == obj1[i].getStudentName()) // found
        {
            if (i == 0)
            {
                obj1[i] = labList.deleteAtMiddle(obj1[i]);
                obj1[i] = updation(obj1[i]);
                labList.insertAtStart(obj1[i]);
                break;
            }
            else if (i > 0)
            {
                obj1[i] = labList.deleteAtMiddle(obj1[i]);
                obj1[i] = updation(obj1[i]);
                labList.insertAtMiddle(obj1[i - 1], obj1[i]);
                break;
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 4);
                cout << "\n\n\t\t\t\t\t Error!!!";
                SetConsoleTextAttribute(hConsole, 6);

            }
        }
        i++;
    }
}

void searchStudentByEnrollment(Node<Lab>* start, List<Lab>& labList)
{
    string key;
    
    system("cls");
    string str = {};
    string str2 = {};
    char ch;
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t                           Lab Evaluation System                                \n\n";
    cout << "\t\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t    *********************   \n";
    cout << "\t\t\t\t\t\t      << Searching >>    \n";
    cout << "\t\t\t\t\t\t    *********************    \n";
    SetConsoleTextAttribute(hConsole, 6);
    labList.traverse();
    cout << "\n\n\t\t\tEnter Student to search: ";
    ch = _getch();
 /*   if (ch <= 90 && ch >= 65)
    {
        ch = ch + 32;
    }*/
    //This Loop will input ch from user and will keep on suggesting names until ENTER is pressed
    while (ch != 13) //13 is ASCII code of ENTER key so while loop will continue until Enter is pressed
    {

        system("cls");
        if (ch == 8) //8 is ASCII code of Backspace key so when backspace is pressed it will pop character
        {
            if (str.length() > 0)
            {
                str = str.erase(str.size() - 1);
                str2 = str2.erase(str2.size() - 1);
            }
        }
        else if (ch == ' ')
        {
            str.push_back('{');
            str2.push_back(' ');
        }
        else
        {
            if (ch >= 97 && ch <= 122)
            {
                str.push_back(ch);
                str2.push_back(ch);
            }
        }
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t                           Lab Evaluation System                                \n\n";
        cout << "\t\t\t******************************************************************************\n\n";
        cout << "\t\t\t\t\t\t    *********************   \n";
        cout << "\t\t\t\t\t\t       << Searching >>    \n";
        cout << "\t\t\t\t\t\t    *********************    \n";
        SetConsoleTextAttribute(hConsole, 6);

        labList.traverse();
        cout << "\n\n\t\t\tEnter Student to search: ";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '{')
                cout << str[i];
            else
                cout << " ";

        }
        cout << endl;
        SetConsoleTextAttribute(hConsole, 9);
        cout << "\n\t\t\t\t\t----   Suggestions -----" << endl;
        SetConsoleTextAttribute(hConsole, 6);
        tree.printAutoSuggestions(str);
        ch = _getch();
        if (ch <= 90 && ch >= 65)
        {
            ch = ch + 32;
        }
    }
    Lab obj1[100];
    int i = 0;
    for (Node<Lab>* ptr = start; ptr != NULL; ptr = ptr->next)
    {

        obj1[i] = ptr->info;
        if (key == obj1[i].getEnrollment()) // found
        {

            if (i == 0)
            {

                obj1[i] = labList.deleteAtMiddle(obj1[i]);
                obj1[i] = updation(obj1[i]);
                labList.insertAtStart(obj1[i]);
            }
            else if (i > 0)
            {

                obj1[i] = labList.deleteAtMiddle(obj1[i]);
                obj1[i] = updation(obj1[i]);
                labList.insertAtMiddle(obj1[i - 1], obj1[i]);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 4);
                cout << "\n\t\t\t\t\t\t\t Error!!!";
                SetConsoleTextAttribute(hConsole, 6);
            }
        }
        i++;
    }
}

Lab updation(Lab& obj)
{
    char rubric1, rubric2, rubric3, rubric4;
    int new_rubric1, new_rubric2, new_rubric3, new_rubric4;
    while (true)
    {
        SetConsoleTextAttribute(hConsole, 9);
        cout << "\n\n\t\t\trubrics1\t\trubrics2\t\trubrics3\t\trubrics4 \n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "\t\t\t";
        rubric1 = _getche();
        cout << "\t\t\t ";
        rubric2 = _getche();
        cout << "\t\t\t ";
        rubric3 = _getche();
        cout << "\t\t\t ";
        rubric4 = _getche();

        new_rubric1 = rubric1 - '0';
        new_rubric2 = rubric2 - '0';
        new_rubric3 = rubric3 - '0';
        new_rubric4 = rubric4 - '0';

        if (new_rubric1 <= 5 || new_rubric2 <= 5 || new_rubric3 <= 5 || new_rubric4 <= 5)
            break;
        else
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\n\t\t\tYour Marks Should be 5 or Less then 5\n";
            cout << "\t\t\t";
            SetConsoleTextAttribute(hConsole, 6);
            system("pause");
            continue;
        }
    }
    
    float new_total = new_rubric1 + new_rubric2 + new_rubric3 + new_rubric4;
    obj.setRubOne(new_rubric1);
    obj.setRubSec(new_rubric2);
    obj.setRubThrd(new_rubric3);
    obj.setRubForth(new_rubric4);
    obj.setTotal(new_total);
    return obj;
}

void calculateResult(string s1, string course, int numberOfStudent)
{
    system("cls");
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\t\t\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t                           Lab Evaluation System                                \n\n";
    cout << "\t\t\t\t\t******************************************************************************\n\n";
    cout << "\t\t\t\t\t\t\t\t    *********************   \n";
    cout << "\t\t\t\t\t\t\t\t      << Result list >>    \n";
    cout << "\t\t\t\t\t\t\t\t    *********************    \n";
    SetConsoleTextAttribute(hConsole,6);
    List<Lab> labResultList, list;
    string studentName, enrollment, labNo, labName, labType, data;
    float result;
    Lab obj, obj1;
    ifstream file, file1;
    string fileName, filename;
    filename = course + ".txt";
    fileName = course + " Lab.txt";
    file1.open(filename);
    getline(file1, data);
    while (!file1.eof())
    {
        getline(file1, enrollment, '|');
        getline(file1, studentName);
        obj.setEnrollment(enrollment);
        obj.setStudentName(studentName);
        list.insertAtEnd(obj);
    }
    file1.close();
    file.open(fileName);
    getline(file, data);
    while (!file.eof())
    {
        getline(file, labNo);
        getline(file, labName);
        getline(file, labType);
        getline(file, data);
        getline(file, data);
        int i = 0;
        while (i < numberOfStudent)
        {
            getline(file, enrollment, '|');
            getline(file, studentName, '|');
            getline(file, data, '|');
            getline(file, data, '|');
            getline(file, data, '|');
            getline(file, data, '|');
            getline(file, data);
            result = stoi(data);
            if (labType == "Normal")
            {
                result = (result / 20) * 4;
            }
            else if (labType == "OpenEnded")
            {
                result = (result / 20) * 6;
            }
            else if (labType == "Mid")
            {
                result = (result / 20) * 12;
            }
            else if (labType == "Project")
            {
                result = (result / 20) * 30;
            }
            obj.setLabName(labName);
            obj.setLabType(labType);
            obj.setEnrollment(enrollment);
            obj.setStudentName(studentName);
            obj.setResult(result);
            labResultList.insertAtEnd(obj);
            i++;
        }
    }
    float total;
    file.close();
    Node<Lab>* start1 = list.getStart();
    Node<Lab>* start2 = labResultList.getStart();
    int size=0;
    bool midFlag = false;
    bool projectFalg = false;
    for (Node<Lab>* ptr1 = start1; ptr1 != NULL; ptr1 = ptr1->next)
    {
        for (Node<Lab>* ptr2 = start2; ptr2 != NULL; ptr2 = ptr2->next)
        {
            obj1 = ptr2->info;
            if (obj.getEnrollment() == obj1.getEnrollment())
            {
                obj1 = ptr2->info;
                if (obj.getEnrollment() == obj1.getEnrollment())
                {
                    if (obj1.getResult() > 4 && obj1.getResult() <= 12)
                    {
                        midFlag = true;
                    }
                    else if (obj1.getResult() > 12 && obj1.getResult() <= 30)
                        projectFalg = true;
                    
                }
                size++;
            }
        }
        break;
        
    }
    cout << "\n\t\t\t" << "Enrollment\tName\t";
    for (int i = 0; i < size; ++i)
    {
        if (midFlag)
            cout << "Mid\t";
        else if (projectFalg)
            cout << "Project\t";
        else
            cout << "Lab# " << i + 1 << "\t";
    }
    cout << "Result";
    for (Node<Lab>* ptr1 = start1; ptr1 != NULL; ptr1 = ptr1->next)
    {
        obj = ptr1->info;
        cout << "\n\t\t\t" << obj.getEnrollment() << "\t" << obj.getStudentName();
        total = 0;
        for (Node<Lab>* ptr2 = start2; ptr2 != NULL; ptr2 = ptr2->next)
        {
            obj1 = ptr2->info;
            if (obj.getEnrollment() == obj1.getEnrollment())
            {
                cout << "\t" << obj1.getResult();
                total += obj1.getResult();
            }
        }
        cout << "\t" << total;
    }
    cout << "\n\t\t\t";
    system("pause");
    teacherLab(s1, course);
}

string decrypted(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = str[i] - 3;
    }
    return str;
}

string encrypted(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = str[i] + 3;
    }
    return str;
}