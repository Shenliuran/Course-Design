#include "employee.h"
#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	Employee *head = new Employee;
	Employee *tail;
	head = head->initLinkList(head);
	tail = head;
	fstream ioFile;
	ioFile.open("C:\\c++�ļ�\\ְ��������Ϣ.txt", ios::in | ios::out | ios::app);

	Employee *p = new Employee;
	if (!ioFile.eof())
	{
		ioFile << p->m_workID << p->m_name << p->m_sex << p->m_dept << p->m_phoneNum << p->m_wage;
	}

	/*do
	{
		p->next = NULL;
		tail->next = p;
		tail = p;
		p = new Employee;
		ioFile << p->m_workID << p->m_name << p->m_sex << p->m_dept << p->m_phoneNum << p->m_wage;
	} while (ioFile.peek() != EOF);
	delete p;*/
	//************************************************************************************
	int select;
	while (true)

	{
		cout << "***********************************" << endl;
		cout << "*              �˵�               *" << endl;
		cout << "***********************************" << endl;
		cout << "*   1��ְ����Ϣ����               *" << endl;
		cout << "*   2���������Ų�ѯ               *" << endl;
		cout << "*   3����������ѯ                 *" << endl;
		cout << "*   4�������Ҳ�ѯ                 *" << endl;
		cout << "*   5����������ҵ�ƽ������       *" << endl;
		cout << "*   6�����ҷ������               *" << endl;
		cout << "*   7�����ݹ����޸�ְ����Ϣ       *" << endl;
		cout << "*   8�����ݹ���ɾ��ְ����Ϣ       *" << endl;
		cout << "*   9�����ݹ�������               *" << endl;
		cout << "*   10������ְ����Ϣ              *" << endl;
		cout << "*   11���������ܹ���              *" << endl;
		cout << "*   0���˳�	                  *" << endl;
		cout << "***********************************" << endl;
		cout << "��������Ҫ�Ĳ�����" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			cout << "�˳�ϵͳ" << endl;
			return 0;
		case 1:
			tail = head->addMember(head);
			break;
		case 2:
			head->searchByWorkID(head);
			break;
		case 3:
			head->searchByName(head);
			break;
		case 4:
			head->searchByDept(head);
			break;
		case 5:
			head->aveByDept(head);
			break;
		case 6:
			head->statisticByDept(head);
			break;
		case 7:
			tail = head->modifyByWorkID(head);
			break;
		case 8:
			tail = head->deleteByWorkID(head);
			break;
		case 9:
			head->sortByWage(head);
			break;
		case 10:
			head->saveFile(head);
			break;
		case 11:
			head->sumByDept(head);
			break;
		default:
			cout << "ѡ��������������룡" << endl;
			break;
		}
	}
	do
	{
		p->next = NULL;
		tail->next = p;
		tail = p;
		p = new Employee;
		ioFile << p->m_workID << p->m_name << p->m_sex << p->m_dept << p->m_phoneNum << p->m_wage;
	} while (ioFile.peek() != EOF);
	delete (head);
	//************************************************************************************
	ioFile.close();

	return 0;
}
