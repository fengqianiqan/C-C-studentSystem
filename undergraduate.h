#pragma once
#include"student.h"
/*************************************************
Copyright (C), 2010, Tyut
File name:     undergraduate.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   ��������
(4)��Student����������UnderGraduate�����������࣬������ԣ�
major��רҵ����
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
		cout << "����רҵ��"; 
		cin >> major;
	}
	virtual void displayDetails() {
		Student::displayDetails();
		cout << "רҵ��" << major << endl;
	}
};