#pragma once
/*************************************************
Copyright (C), 2010, Tyut
File name:     student.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   ѧ����
*************************************************/
/*(3)��Person��������Student��ѧ�����࣬������ԣ� 
studentNo��ѧ�ţ���schoolName��ѧУ����classIn (�༶)��*/
#include"person.h"
class Student :virtual public Person{
public:
    string studentno;
	char schoolName[20];
	int classIn;
    virtual void displayDetails();
    virtual void inputData();
    
};
void Student::inputData()
{
    Person::inputData();
    cout << "ѧ�ţ�";
    cin >> studentno;
    cout << "ѧУ��";
    cin >> schoolName;
    cout << "�༶��";
    cin >> classIn;

}

void Student::displayDetails()
{
    Person::displayDetails();
    cout << "ѧ�ţ�" << studentno << endl;
    cout << "ѧУ��" << schoolName << endl;
    cout << "�༶��" << classIn << endl;
}