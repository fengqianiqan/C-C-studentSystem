#include <cstdlib>
#include <iostream>
#include "date.h"
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "undergraduate.h"
#include "graduate.h"
#include "ta.h"
#include "undergraduateManager.h"
#include"graduateManger.h"
#include"taManger.h"
using namespace std;

int main(int argc, char* argv[])
{
    int choiceN;
    UndergraduateManager unMan;
    GradateManager unman1;
    taManager unman2;
    cout << "********************************************************" << endl;
    cout << "*|*|                                                |*|*" << endl;
    cout << "*|*|              ��ӭ��ʹ��ѧ������ϵͳ            |*|*" << endl;
    cout << "*|*|                                                |*|*" << endl;
    cout << "********************************************************" << endl;
    do {
        cout << "<---------------------------------------------------->" << endl;
        cout << " \n \t\t 1:���������� ";
        cout << " \n \t\t 2:�о�������  ";
        cout << " \n \t\t 3.���̲�ʿ������ ";
        cout << " \n \t\t 0:�뿪    ";
        cout << endl;
        cout << "<---------------------------------------------------->" << endl;
        cout << "��ѡ��" << endl;
        cin >> choiceN;
        switch (choiceN)
        {
        case 1:
            unMan.dataManage();
            break;
        case 2:
            unman1.dataManage();
            break;
        case 3:
            unman2.dataManage();
            break;
        default:
            break;
        }
    } while (choiceN != 0);
    cout << " **********************************************************" << endl;
    cout << "*|*|               ��лʹ��ѧ������ϵͳ                  |*|*" << endl;
    cout << " **********************************************************\a" << endl;
    system("pause")
}







