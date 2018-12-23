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
	ioFile.open("C:\\c++文件\\职工工资信息.txt", ios::in | ios::out | ios::app);

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
		cout << "*              菜单               *" << endl;
		cout << "***********************************" << endl;
		cout << "*   1、职工信息输入               *" << endl;
		cout << "*   2、按工作号查询               *" << endl;
		cout << "*   3、按姓名查询                 *" << endl;
		cout << "*   4、按科室查询                 *" << endl;
		cout << "*   5、计算各科室的平均工资       *" << endl;
		cout << "*   6、科室分类输出               *" << endl;
		cout << "*   7、根据工号修改职工信息       *" << endl;
		cout << "*   8、根据工号删除职工信息       *" << endl;
		cout << "*   9、根据工资排序               *" << endl;
		cout << "*   10、保存职工信息              *" << endl;
		cout << "*   11、各科室总工资              *" << endl;
		cout << "*   0、退出	                  *" << endl;
		cout << "***********************************" << endl;
		cout << "请输入需要的操作：" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			cout << "退出系统" << endl;
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
			cout << "选择错误，请重新输入！" << endl;
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
