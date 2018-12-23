#include "employee.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//1��ע��Ա����Ϣ
Employee * Employee::addMember(Employee * tail)
{
	Employee * p;
	char ch;
	int i = 1;
	//****************************
	int workID;//������
	string name;//����
	string sex;//�Ա�
	string dept;//���ڲ���
	int phoneNum;//�绰����
	double wage;//����
//*****************************
	do
	{
		p = new Employee;
		cout << "������� " << i << " ��Ա������Ϣ��" << endl;
		cout << "�����ţ�";		cin >> workID;		cout << endl;
		cout << "������";		cin >> name;		cout << endl;
		cout << "�Ա�";		cin >> sex;			cout << endl;
		cout << "���ڲ��ţ�";	cin >> dept;		cout << endl;
		cout << "�绰���룺";	cin >> phoneNum;	cout << endl;
		cout << "���ʣ�";		cin >> wage;		cout << endl;

		p->m_workID = workID;
		p->m_name = name;
		p->m_sex = sex;
		p->m_dept = dept;
		p->m_phoneNum = phoneNum;
		p->m_wage = wage;

		p->next = NULL;
		tail->next = p;
		tail = p;
		cout << "�Ƿ���Ҫ������" << endl;
		cin >> ch;
		i++;
		cout << endl;
	} while (ch == 'y');

	return tail;
}

//��ʼ���б�
Employee * Employee::initLinkList(Employee * head)
{
	head = new Employee;
	head->next = NULL;
	return head;
}

//2���������Ų�ѯ
Employee * Employee::searchByWorkID(Employee * head)
{
	Employee *p;
	int searchID;
	cout << "��������Ҫ��ѯ��Ա����ְ���ţ�" << endl;
	cin >> searchID;
	p = head->next;
	cout << "��ѯ�����" << endl;
	while (p)
	{
		if (p->m_workID == searchID)
		{
			display(p);
			return p;
		}
		p = p->next;
	}
	cout << "û�д�Ա����" << endl;
	return false;
}

//3����������ѯ
bool Employee::searchByName(Employee * head)
{
	Employee *p;
	string searchName;
	cout << "��������Ҫ��ѯ��Ա����������" << endl;
	cin >> searchName;
	p = head->next;
	cout << "��ѯ�����" << endl;
	while (p)
	{
		if (p->m_name == searchName)
		{
			display(p);
			return true;
		}
		p = p->next;
	}
	cout << "û�д�Ա����" << endl;
	return false;
}

//4�������Ҳ�ѯ
bool Employee::searchByDept(Employee * head)
{
	Employee * p;
	p = head->next;
	cout << "��������Ҫ���ҵĿ��ң�" << endl;
	string searchDept;
	cin >> searchDept;
	if (p)
	{
		while (p)
		{
			if (p->m_dept == searchDept)
			{
				display(p);
			}
			p = p->next;
		}
		return true;
	}
	else
	{
		cout << "�޴˿�����Ϣ��" << endl;
		return false;
	}

}

//5����������ҵ�ƽ������
void Employee::aveByDept(Employee * head)
{
	Employee * p;
	p = head->next;
	int count0 = 0;
	int count1 = 0;
	int i, j;
	double *STA[2];
	double ave0 = 0;
	double ave1 = 0;
	//STA = new double[2];

	for (i = 0; i < 2; i++)
	{
		STA[i] = new double[100];
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 100; j++)
		{
			STA[i][j] = 0;
		}
	}

	while (p)
	{
		if (p->m_dept == "TPD")
		{
			STA[0][count0] = p->m_wage;
			count0++;
			p = p->next;
		}
		else if (p->m_dept == "MOST")
		{
			STA[1][count1] = p->m_wage;
			count1++;
			p = p->next;
		}
	}

	for (i = 0; i <= count0; i++)
	{
		ave0 += STA[0][i];
	}
	for (i = 0; i <= count1; i++)
	{
		ave1 += STA[1][i];
	}
	ave0 /= count0;
	ave1 /= count1;

	cout << "���²���ƽ������Ϊ��" << ave0 << endl;
	cout << "�Ƽ�����ƽ������Ϊ��" << ave1 << endl;
}

//6���ֿ��������������ҵ��ܹ���
void Employee::statisticByDept(Employee * head)
{
	Employee * p;
	Employee *head_m, *p_m, *tail_m;
	Employee *head_t, *p_t, *tail_t;

	p = head->next;
	head_m = tail_m = new Employee;
	p_m = head->next;
	head_t = tail_t = new Employee;
	p_t = head->next;

	while (p)
	{
		if (p->m_dept == "MOST")
		{
			p_m = new Employee;
			p_m->m_dept = p->m_dept;
			p_m->m_name = p->m_name;
			p_m->m_sex = p->m_sex;
			p_m->m_workID = p->m_workID;
			p_m->m_phoneNum = p->m_phoneNum;
			p_m->m_wage = p->m_wage;


			p_m->next = NULL;
			tail_m->next = p_m;
			tail_m = p_m;
		}
		else
		{
			p_t = new Employee;
			p_t->m_dept = p->m_dept;
			p_t->m_name = p->m_name;
			p_t->m_sex = p->m_sex;
			p_t->m_workID = p->m_workID;
			p_t->m_phoneNum = p->m_phoneNum;
			p_t->m_wage = p->m_wage;


			p_t->next = NULL;
			tail_t->next = p_t;
			tail_t = p_t;
		}
		p = p->next;
	}

	p_m = head_m->next;
	p_t = head_t->next;
	cout << "�Ƽ�����" << endl;
	while (p_m)
	{
		display(p_m);
		p_m = p_m->next;
	}
	cout << "���²���" << endl;
	while (p_t)
	{
		display(p_t);
		p_t = p_t->next;
	}
}
//7�����ݹ����޸�ְ����Ϣ
Employee * Employee::modifyByWorkID(Employee * head)
{

	Employee * p = new Employee;
	p = searchByWorkID(head);

	//****************************
	int workID;//������
	string name;//����
	string sex;//�Ա�
	string dept;//���ڲ���
	int phoneNum;//�绰����
	double wage;//����
//*****************************	
	if (p)
	{
		cout << "���޸ĸ�Ա������Ϣ��" << endl;
		cout << "�����ţ�";		cin >> workID;		cout << endl;
		cout << "������";		cin >> name;		cout << endl;
		cout << "�Ա�";		cin >> sex;			cout << endl;
		cout << "���ڲ��ţ�";	cin >> dept;		cout << endl;
		cout << "�绰���룺";	cin >> phoneNum;	cout << endl;
		cout << "���ʣ�";		cin >> wage;		cout << endl;

		p->m_workID = workID;
		p->m_name = name;
		p->m_sex = sex;
		p->m_dept = dept;
		p->m_phoneNum = workID;
		p->m_wage = wage;
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	return head;
}

//8�����ݹ���ɾ��ְ����Ϣ
Employee * Employee::deleteByWorkID(Employee * head)
{
	int searchWorkID;
	Employee * parentp;
	Employee * p_front;

	cout << "��������Ҫ�޸ĵ�ְ���Ĺ����ţ�" << endl;
	cin >> searchWorkID;
	parentp = head;
	p_front = head->next;

	while (p_front)
	{
		if (p_front->m_workID == searchWorkID)
		{
			parentp->next = p_front->next;
			delete p_front;
			return head;
		}
		parentp = p_front;
		p_front = p_front->next;
	}
	return head;
}

//9������ְ���Ĺ����������
Employee * Employee::sortByWage(Employee * head)
{
	if ((head->next == NULL) || (head->next->next) == NULL)
	{
		cout << "���ݸ���������������������" << endl;
		return head;
	}

	Employee * p;
	Employee * p_f;
	Employee * p_n;

	p = head->next->next;
	p_f = head;
	head->next->next = NULL;
	while (p)
	{
		p_n = p->next;
		p_f = head;
		while (p_f->next)
		{
			if (p->m_wage > p_f->next->m_wage)
			{
				p->next = p_f->next;
				p_f->next = p;
				break;
			}
			else
			{
				p_f = p_f->next;
			}
		}
		if (p_f->next == NULL)
		{
			p->next = p_f->next;
			p_f->next = p;
		}
		p = p_n;
	}

	p = head->next;
	while (p)
	{
		display(p);
		p = p->next;
	}
	cout << "�Ӹߵ�������ɹ���" << endl;
	return head;
}

//10����ʾ��Ϣ
void Employee::display(Employee * head)
{
	cout << "��ְԱ����Ϣ���£�" << endl;
	cout << "�����ţ�" << head->m_workID << endl;
	cout << "������" << head->m_name << endl;
	cout << "�Ա�" << head->m_sex << endl;
	cout << "���ڲ��ţ�" << head->m_dept << endl;
	cout << "�绰���룺" << head->m_phoneNum << endl;
	cout << "���ʣ�" << head->m_wage << endl;
}

//����Ϣ����Ϊ�ļ�
void Employee::saveFile(Employee * head)
{
	ofstream oFile;
	oFile.open("C:\\c++�ļ�\\ְ��������Ϣ.txt");
	Employee * p;
	p = head->next;
	while (p)
	{
		oFile << p->m_workID << endl;
		oFile << p->m_name << endl;
		oFile << p->m_sex << endl;
		oFile << p->m_dept << endl;
		oFile << p->m_phoneNum << endl;
		oFile << p->m_wage << endl;

		p = p->next;
	}
	oFile.close();

	cout << "���ݱ���ɹ���" << endl;
}
//11���������ܹ���
void Employee::sumByDept(Employee * head)
{
	Employee * p;
	p = head->next;
	int count0 = 0;
	int count1 = 0;
	int i, j;
	double *STA[2];
	double sum0 = 0;
	double sum1 = 0;
	//STA = new double[2];

	for (i = 0; i < 2; i++)
	{
		STA[i] = new double[100];
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 100; j++)
		{
			STA[i][j] = 0;
		}
	}

	while (p)
	{
		if (p->m_dept == "TPD")
		{
			STA[0][count0] = p->m_wage;
			count0++;
			p = p->next;
		}
		else if (p->m_dept == "MOST")
		{
			STA[1][count1] = p->m_wage;
			count1++;
			p = p->next;
		}
	}

	for (i = 0; i <= count0; i++)
	{
		sum0 += STA[0][i];
	}
	for (i = 0; i <= count1; i++)
	{
		sum1 += STA[1][i];
	}

	cout << "���²����ܹ���Ϊ��" << sum0 << endl;
	cout << "�Ƽ������ܹ���Ϊ��" << sum1 << endl;
}