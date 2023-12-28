#pragma once
#include"student.h"
/*************************************************
Copyright (C), 2010, Tyut
File name:     undergraduate.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   本科生类
(4)从Student类中派生出UnderGraduate（本科生）类，添加属性：
major（专业）。
*************************************************/
class  Undergraduate :virtual public Student{
private:
	string major;
public:
	string getStudentNo() {
		return studentno;
	}
	virtual void inputData() {
		Student::inputData();
		cout << "输入专业："; 
		cin >> major;
	}
	virtual void displayDetails() {
		Student::displayDetails();
		cout << "专业：" << major << endl;
	}
};