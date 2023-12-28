#pragma once
#include"graduate.h"
#include"teacher.h"
/*************************************************
Copyright(C), 2010, Tyut
File name : ta.h
Author : gaobaolu      Version : 1.0     Date : 2010.6.28
Description : 助教博士生类
* ************************************************/
class ta :virtual public Graduate, virtual public Teacher {
public:
    virtual void displayDetails();
    virtual void inputData();
};
void ta::inputData()
{
    Teacher::inputData();
    Graduate::inputData();
}

void ta::displayDetails()
{
    Teacher::displayDetails();
    Graduate::displayDetails();
}