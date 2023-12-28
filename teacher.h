/*************************************************
Copyright (C), 2010, Tyut
File name:     teacher.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   ��ʦ��
��Person��������Teacher����ʦ���࣬������ԣ�
teacherNo����ʦ��ţ���schoolName��ѧУ����department�����ţ���
*************************************************/
#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include <string>
#include <cstring>
#include "person.h"
using namespace std;
/* Define a Class : Teacher */
/* with attributes:   */
/* operations:   */
class Teacher : virtual public Person
{
protected:
    char teacherNo[5];    //��ʦ��� 
    char schoolName[20];  //ѧУ���� 
    char department[20];  //���� 
public:
    Teacher();
    Teacher(char* sname, char* sid, char* sgender, int yy, int mm, int dd
        , char* steacherNo, char* sschool, char* sdepartment);
    ~Teacher() {}
    void setTeacherNo(char* sno) { strcpy(teacherNo, sno); }
    char* getTeacherNo() { return teacherNo; }
    void setSchoolName(char* sschool) { strcpy(schoolName, sschool); }
    char* getSchoolName() { return schoolName; }
    void setDepartment(char* sdepartment) { strcpy(department, sdepartment); }
    char* getDepartment() { return department; }
    virtual void inputData();//�������� 
    virtual void displayDetails();	//��ʾ����  
};
Teacher::Teacher() :Person()
{
    strcpy(teacherNo, "001");
    strcpy(schoolName, "defaultSchoolName");
    strcpy(department, "defaultDepartment");
}
Teacher::Teacher(char* sname, char* sid, char* sgender, int yy, int mm, int dd
    , char* steacherNo, char* sschool, char* sdepartment)
    :Person(sname, sid, sgender, yy, mm, dd)
{
    strcpy(teacherNo, steacherNo);
    strcpy(schoolName, sschool);
    strcpy(department, sdepartment);
}
void Teacher::inputData()
{
    Person::inputData();
    cout << "��ʦ��ţ�"; cin >> teacherNo;
    cout << "ѧУ��"; cin >> schoolName;
    cout << "���ţ�"; cin >> department;
}
void Teacher::displayDetails()
{
    Person::displayDetails();
    cout << "��ʦ��ţ�" << teacherNo << endl;
    cout << "ѧУ��" << schoolName << endl;
    cout << "���ţ�" << department << endl;
}
#endif //TEACHER_H