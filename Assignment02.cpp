#include <iostream>
#include <string.h>
using namespace std;
class student
{
    char *name;
    char *rno;
    char *div;
    char *dob;
    char *bloodgrp;
    char *addr;
    int mob;
    int license_no;
    int marks;
    static int count;

public:
    student();                                                              //default constructor
    student(char *, char *, char *, char *, char *, char *, int, int, int); //parametrized constructor
    student(student &);                                                     //copy constructor
    void getDetails();
    void setDetails();
    //static function
    static int totCount()
    {
        return count;
    }
    ~student(); //destructor
    friend class result;
};
int student::count = 0;
//parametrized constructor
student::student(char *name, char *rno, char *div, char *dob, char *bloodgrp, char *addr, int mob, int license_no,int marks)
{
    int l;
    l = strlen(name);
    this->name = new char[l];
    this->name = name;

    l = strlen(rno);
    this->rno = new char[l];
    this->rno = rno;

    l = strlen(div);
    this->div = new char[l];
    this->div = div;

    l = strlen(dob);
    this->dob = new char[l];
    this->dob = dob;

    l = strlen(bloodgrp);
    this->bloodgrp = new char[l];
    this->bloodgrp = bloodgrp;

    l = strlen(addr);
    this->addr = new char[l];
    this->addr = addr;

    this->mob = mob;
    this->marks = marks;
    this->license_no = license_no;
	
    count++;
}
//default constructor
student::student()
{
    name = new char;
    rno = new char;
    div = new char;
    dob = new char;
    bloodgrp = new char;
    addr = new char;
    int mob = 0;
    int license_no = 0;
    int marks = 0;
    count++;
}
//copy constructor
student::student(student &o)
{
    name = o.name;
    rno = o.rno;
    div = o.div;
    dob = o.dob;
    bloodgrp = o.bloodgrp;
    addr = o.addr;
    mob = o.mob;
    marks = o.marks;
    count++;
}
//destructor
student::~student()
{
    delete name;
    delete rno;
    delete div;
    delete dob;
    delete bloodgrp;
    delete addr;
}
void student::setDetails()
{
    char *name = new char;
    char *rno = new char;
    char *div = new char;
    char *dob = new char;
    char *bloodgrp = new char;
    char *addr = new char;
    int mob;
    int license_no;
    int marks;

    cout << "Enter Name of the student:"<< "\n";
    cin >> this->name;
	
    cout << "Enter Roll Number of student:"<< "\n";
    cin >> this->rno;
	
    cout << "Enter Division of student:"<< "\n";
    cin >> this->div;
	
    cout << "Enter Date of Birth:"<< "\n";
    cin >> this->dob;
	
    cout << "Enter the address of the student:"<< "\n";
    cin >> this->addr;
	
    cout << "Enter Mobile number:"<< "\n";
    cin >> this->mob;
	
	cout << "Enter License number:"<< "\n";
	cin >> this->license_no;
	
    cout << "Enter Marks of the student:"<< "\n";
    cin >> this->marks;
	
    cout << "Enter the blood group of the student :"<<"\n";
	cin >> this-> bloodgrp;
   
}
void student::getDetails()
{
    cout << "***************************" << endl;
    cout << "Name of the student: " << this->name << endl;
    cout << "Roll number: " << this->rno << endl;
    cout << "Blood group: " << this->bloodgrp << endl;
    cout << "Div: " << this->div << endl;
    cout << "Date of birth: " << this->dob << endl;
    cout << "Mobile number: " << this->mob << endl;
    cout << "License number: " << this->license_no << endl;
   
}
class result
{
	public:
		void calPercentage(student &s)
		{
			float percent = (s.marks % 100);
			cout << "Roll number " << s.rno << " has " << percent << " percentage " << endl;
		}
};

int main()
{
    student s1;
	student s2("xyz","21309","se3","1/01/2002","o+","abc",12345687457,987654321,456);
	
    s1.setDetails();
    s1.getDetails();
	s2.setDetails();
    result r1;
    r1.calPercentage(s1);
      cout << "***************************" << endl;

    cout << "Total students are: " << student::totCount;
    return 0;
}
