#pragma once
#include"student.h"
/*************************************************
Copyright (C), 2010, Tyut
File name:     graduate.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   研究生类
从Student类中派生出Graduate（研究生）类，添加属性：direction（研究方向），adviserName（导师姓名）。
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
    cout << "研究方向：";
    cin >> direction;
    cout << "导师姓名：";
    cin >> adviserName;
    

}

void Graduate::displayDetails()
{
    Student::displayDetails();
    cout << "研究方向：" << direction << endl;
    cout << "导师姓名：" << adviserName << endl;
    
}