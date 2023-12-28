#pragma once
/*************************************************
Copyright (C), 2010, Tyut
File name:     person.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   人员类
*************************************************/
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cstring>
#include <string>
#include"date.h"
using namespace std;
/* Define a Class : Person */
/* with attributes: name, id,gender, birthday */
/* operations: getName, getId, and setId. */
/* person is the base class */
//该类为虚基类 
class Person
{
protected:
    char name[20];//姓名 
    char id[18];  //身份证号 
    char gender[2];//性别 
    Date birthday;//出生日期 
public:
    Person();
    Person(char* sname, char* sid, char* sgender, int yy, int mm, int dd);
    ~Person() {}
    void setName(char* sname) { strcpy(name, sname); }
    char* getName() { return name; }
    void setId(char* sid) { strcpy(id, sid); }
    char* getId() { return id; }
    void setGender(char* sgender) { strcpy(gender, sgender); }
    char* getGender() { return gender; }
    void setBirthday(Date d) { birthday = d; }
    Date getBirthday() { return birthday; }
    virtual void inputData();//输入数据 
    virtual void displayDetails();	//显示数据 

};
Person::Person()
{
    strcpy(name, "NA");
    strcpy(gender, "男");
    strcpy(id, "000");
    //注意：这里没有给birthday赋值,系统会调用其默认构造函数   
    //也可以 
    //Date d(1980,1,1);
    //birthday = d;               
}
Person::Person(char* sname, char* sid, char* sgender, int yy, int mm, int dd) :birthday(yy, mm, dd)
{
    strcpy(name, sname);
    strcpy(id, sid);
    strcpy(gender, sgender);
}
void Person::inputData()
{
    cout << "姓名：";
    cin >> name;
    cout << "身份证号：";
    cin >> id;
    cout << "性别：";
    cin >> gender;
    cout << "出生日期：" << endl;
    birthday.inputDate();
}

void Person::displayDetails()
{
    cout << "姓名：" << name << endl;
    cout << "身份证号：" << id << endl;
    cout << "性别：" << gender << endl;
    cout << "出生日期：";
    birthday.displayDate();
}
#endif //PERSON_H