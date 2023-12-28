#pragma once
/*************************************************
Copyright (C), 2010, Tyut
File name:     taManager.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   ���̲�ʿ����
*************************************************/
//#ifndef UNDERGRADUATE_MANAGER_H
#define UNDERGRADUATE_MANAGER_H
#include <iostream>
#include <string>
#include <fstream>
#include"ta.h"
using namespace std;
/* Define a Class : taManager ���̲�ʿ����*/
class taManager
{
private:
    int top; //��¼ָ��
    ta tas[100]; //���̲�ʿ�����¼
public:
    taManager();//���캯��,��Undergraduate.txt����undergraduates[]��  
    int queryByNo(string sno);//�����̲�ʿ����Ų��� //�ҵ������������±�//û�ҵ�������-1
    void clearStudent();  //ɾ���������̲�ʿ������Ϣ    
    int addStudent(ta s); //������̲�ʿ����,��Ҫ�Ȳ����Ƿ���� 
    int modifyStudent(string sno);  //�޸�ѧ����Ϣ ,��Ҫ�Ȳ����Ƿ����
    int deleteStudent(string sno);//ɾ�����̲�ʿ���࣬ɾ��ǰ�Ȳ������Ƿ���� 
    int queryStudent(string sno);//�������̲�ʿ����,�鵽����ʾ,������ʾδ�鵽   
    void displayAll();//������б�������Ϣ
    void dataManage(); //���̲�ʿ�����ά��
    void dataSave();
    void dataRead();
    ~taManager();//��������,��undergraduates[]д��Undergraduate.txt�ļ���
};
//���캯��,��Undergraduate.txt����undergraduates[]��    
taManager::taManager()
{
    dataRead();
}
//���������Ų���
//�ҵ������������±�
//û�ҵ�������-1 
int taManager::queryByNo(string sno)
{
    for (int i = 0; i <= top; i++)
        if (tas[i].getStudentNo() == sno)
            return i;
    return -1;
}
//ɾ���������̲�ʿ������Ϣ 
void taManager::clearStudent()
{
    top = -1;
}
//������̲�ʿ����,��Ҫ�Ȳ����Ƿ����
int taManager::addStudent(ta s)
{
    int p = queryByNo(s.getStudentNo());
    if (p == -1)
    {
        top++;
        tas[top] = s;
        dataSave();//����       
        return 1;
    }
    else
    {
        cout << "--------->��ѧ���Ѿ����� !<----------" << endl << endl;
        return 0;
    }
}
//�޸Ŀ�����ɾ��ǰ�Ȳ������Ƿ����
int taManager::modifyStudent(string  sno)
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
        tas[p].inputData();
        dataSave();//���� 
        return 1;
    }

}
//ɾ�����̲�ʿ���࣬ɾ��ǰ�Ȳ������Ƿ���� 
int taManager::deleteStudent(string sno)
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
            tas[i] = tas[i + 1];
        top--;
        cout << "--------->ɾ�����!<----------" << endl << endl;
        dataSave();//����       
        return 1;
    }
}
//���ҿ���
int taManager::queryStudent(string sno)
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
        tas[p].displayDetails();
        return 1;
    }
}
//������б�������Ϣ
void taManager::displayAll()
{
    for (int i = 0; i <= top; i++)
    {
        cout << "--------��" << i << "��ѧ�����----------" << endl << endl;
        tas[i].displayDetails();

    }
}
//��������,��undergraduates[]д��Undergraduate.txt�ļ���
taManager::~taManager()
{
    dataSave();
}
void taManager::dataManage()
{
    int choice = 1;
    string sstudentNo;
    ta s;

    while (choice != 0)
    {
        cout << "********************************************" << endl;
        cout << "\t\t���̲�ʿ����ά��\n";
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
void taManager::dataSave()//�洢���Ϻ���,��read[]д��Undergraduate.txt�ļ���
{
    fstream file("C:\\Undergraduate.dat", ios::out);
    for (int i = 0; i <= top; i++)
        file.write((char*)&tas[i], sizeof(tas[i]));
    file.close();
}
void taManager::dataRead() //���캯��,��Undergraduate.txt����read[]��
{
    ta s;
    top = -1;
    fstream file("C:\\graduate.dat", ios::in);
    while (1)
    {
        file.read((char*)&s, sizeof(s));
        if (!file) break;
        top++;
        tas[top] = s;
    }
    file.close();
}
//#endif //UNDERGRADUATE_MANAGER_H