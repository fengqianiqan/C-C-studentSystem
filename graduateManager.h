#pragma once
#pragma once
/*************************************************
Copyright (C), 2010, Tyut
File name:     GradateManager.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   �о���������
*************************************************/
//#ifndef UNDERGRADUATE_MANAGER_H
#define UNDERGRADUATE_MANAGER_H
#include <iostream>
#include <string>
#include <fstream>
#include"graduate.h"
using namespace std;
/* Define a Class : GradateManager �о���������*/
class GradateManager
{
private:
    int top; //��¼ָ��
    Graduate graduates[100]; //�о�����¼
public:
    GradateManager();//���캯��,��Undergraduate.txt����undergraduates[]��  
    int queryByNo(string sno);//���о����Ų��� //�ҵ������������±�//û�ҵ�������-1
    void clearStudent();  //ɾ�������о�����Ϣ    
    int addStudent(Graduate s); //����о���,��Ҫ�Ȳ����Ƿ���� 
    int modifyStudent(string sno);  //�޸�ѧ����Ϣ ,��Ҫ�Ȳ����Ƿ����
    int deleteStudent(string sno);//ɾ���о�����ɾ��ǰ�Ȳ������Ƿ���� 
    int queryStudent(string sno);//�����о���,�鵽����ʾ,������ʾδ�鵽   
    void displayAll();//��������о�����Ϣ
    void dataManage(); //�о�����ά��
    void dataSave();
    void dataRead();
    ~GradateManager();//��������,��undergraduates[]д��Undergraduate.txt�ļ���
};
//���캯��,��Undergraduate.txt����undergraduates[]��    
GradateManager::GradateManager()
{
    dataRead();
}
//���о����Ų���
//�ҵ������������±�
//û�ҵ�������-1 
int GradateManager::queryByNo(string sno)
{
    for (int i = 0; i <= top; i++)
        if (graduates[i].getStudentNo() == sno)
            return i;
    return -1;
}
//ɾ�����б�������Ϣ 
void GradateManager::clearStudent()
{
    top = -1;
}
//����о���,��Ҫ�Ȳ����Ƿ����
int GradateManager::addStudent(Graduate s)
{
    int p = queryByNo(s.getStudentNo());
    if (p == -1)
    {
        top++;
        graduates[top] = s;
        dataSave();//����       
        return 1;
    }
    else
    {
        cout << "--------->��ѧ���Ѿ����� !<----------" << endl << endl;
        return 0;
    }
}
//�޸��о�����ɾ��ǰ�Ȳ������Ƿ����
int GradateManager::modifyStudent(string  sno)
{
    int p = queryByNo(sno);
    if (p == -1)
    {
        cout << "--------->��ѧ�������� !<----------" << endl << endl;
        return 0;
    }
    else
    {
        cout << "���������������Ϣ: " << endl << endl;
        graduates[p].inputData();
        dataSave();//���� 
        return 1;
    }

}
//ɾ���о�����ɾ��ǰ�Ȳ������Ƿ���� 
int GradateManager::deleteStudent(string sno)
{
    int p = queryByNo(sno);
    if (p == -1)
    {
        cout << "--------->��ѧ�������� !<----------" << endl << endl;
        return 0;
    }
    else
    {
        for (int i = p; i < top; i++)
            graduates[i] = graduates[i + 1];
        top--;
        cout << "--------->ɾ�����!<----------" << endl << endl;
        dataSave();//����       
        return 1;
    }
}
//�����о���
int GradateManager::queryStudent(string sno)
{
    int p = queryByNo(sno);
    if (p == -1)
    {
        cout << "--------->��ѧ�������� !<----------" << endl << endl;
        return 0;
    }
    else
    {
        cout << "--------->��ѧ������:<----------" << endl << endl;
        graduates[p].displayDetails();
        return 1;
    }
}
//��������о�����Ϣ
void GradateManager::displayAll()
{
    for (int i = 0; i <= top; i++)
    {
        cout << "--------��" << i << "��ѧ�����----------" << endl << endl;
        graduates[i].displayDetails();

    }
}
//��������,��undergraduates[]д��Undergraduate.txt�ļ���
GradateManager::~GradateManager()
{
    dataSave();
}
void GradateManager::dataManage()
{
    int choice = 1;
    string sstudentNo;
    Graduate s;

    while (choice != 0)
    {
        cout << "********************************************" << endl;
        cout << "\t\t�о���ά��\n";
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << "\n \t\t 1:���� ";
        cout << "\n \t\t 2:�޸� ";
        cout << "\n \t\t 3:ɾ�� ";
        cout << "\n \t\t 4:���� ";
        cout << "\n \t\t 5:��ʾ ";
        cout << "\n \t\t 6:ȫ��ɾ�� ";
        cout << "\n \t\t 0:�˳� ";
        cout << endl;
        cout << "*********************************************" << endl;
        cout << "��ѡ��" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.inputData();
            addStudent(s);
            break;
        case 2:
            cout << " ������ѧ��:";
            cin >> sstudentNo;
            modifyStudent(sstudentNo);
            break;
        case 3:
            cout << " ������ѧ��:";
            cin >> sstudentNo;
            deleteStudent(sstudentNo);
            break;
        case 4:
            cout << " ������ѧ��:";
            cin >> sstudentNo;
            queryStudent(sstudentNo);
            break;
        case 5:
            displayAll();
            break;
        case 6:
            clearStudent();
            break;
        default:
            break;
        }
    }
}
void GradateManager::dataSave()//�洢���Ϻ���,��read[]д��Undergraduate.txt�ļ���
{
    fstream file("C:\\Undergraduate.dat", ios::out);
    for (int i = 0; i <= top; i++)
        file.write((char*)&graduates[i], sizeof(graduates[i]));
    file.close();
}
void GradateManager::dataRead() //���캯��,��Undergraduate.txt����read[]��
{
    Graduate s;
    top = -1;
    fstream file("C:\\graduate.dat", ios::in);
    while (1)
    {
        file.read((char*)&s, sizeof(s));
        if (!file) break;
        top++;
        graduates[top] = s;
    }
    file.close();
}
//#endif //UNDERGRADUATE_MANAGER_H