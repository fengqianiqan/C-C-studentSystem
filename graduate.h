#pragma once
#include"student.h"
/*************************************************
Copyright (C), 2010, Tyut
File name:     graduate.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   �о�����
��Student����������Graduate���о������࣬������ԣ�direction���о����򣩣�adviserName����ʦ��������
*************************************************/
class Graduate :virtual public Student {
public:
    string direction;
    string adviserName;
    virtual void displayDetails();
    virtual void inputData();
    string getStudentNo() {
        return studentno;
    }
   
};
void Graduate::inputData()
{
    Student::inputData();
    cout << "�о�����";
    cin >> direction;
    cout << "��ʦ������";
    cin >> adviserName;
    

}

void Graduate::displayDetails()
{
    Student::displayDetails();
    cout << "�о�����" << direction << endl;
    cout << "��ʦ������" << adviserName << endl;
    
}