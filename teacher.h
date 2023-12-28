/*************************************************
Copyright (C), 2010, Tyut
File name:     teacher.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   教师类
从Person类派生出Teacher（教师）类，添加属性：
teacherNo（教师编号），schoolName（学校），department（部门）。
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
    char teacherNo[5];    //教师编号 
    char schoolName[20];  //学校名称 
    char department[20];  //部门 
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
    virtual void inputData();//输入数据 
    virtual void displayDetails();	//显示数据  
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
    cout << "教师编号："; cin >> teacherNo;
    cout << "学校："; cin >> schoolName;
    cout << "部门："; cin >> department;
}
void Teacher::displayDetails()
{
    Person::displayDetails();
    cout << "教师编号：" << teacherNo << endl;
    cout << "学校：" << schoolName << endl;
    cout << "部门：" << department << endl;
}
#endif //TEACHER_H