#pragma once
/*************************************************
Copyright (C), 2010, Tyut
File name:     person.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   ��Ա��
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
//����Ϊ����� 
class Person
{
protected:
    char name[20];//���� 
    char id[18];  //���֤�� 
    char gender[2];//�Ա� 
    Date birthday;//�������� 
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
    virtual void inputData();//�������� 
    virtual void displayDetails();	//��ʾ���� 

};
Person::Person()
{
    strcpy(name, "NA");
    strcpy(gender, "��");
    strcpy(id, "000");
    //ע�⣺����û�и�birthday��ֵ,ϵͳ�������Ĭ�Ϲ��캯��   
    //Ҳ���� 
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
    cout << "������";
    cin >> name;
    cout << "���֤�ţ�";
    cin >> id;
    cout << "�Ա�";
    cin >> gender;
    cout << "�������ڣ�" << endl;
    birthday.inputDate();
}

void Person::displayDetails()
{
    cout << "������" << name << endl;
    cout << "���֤�ţ�" << id << endl;
    cout << "�Ա�" << gender << endl;
    cout << "�������ڣ�";
    birthday.displayDate();
}
#endif //PERSON_H