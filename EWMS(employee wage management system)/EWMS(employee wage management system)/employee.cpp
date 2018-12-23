#include "employee.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//1、注册员工信息
Employee * Employee::addMember(Employee * tail)
{
	Employee * p;
	char ch;
	int i = 1;
	//****************************
	int workID;//工作号
	string name;//姓名
	string sex;//性别
	string dept;//所在部门
	int phoneNum;//电话号码
	double wage;//工资
//*****************************
	do
	{
		p = new Employee;
		cout << "请输入第 " << i << " 名员工的信息：" << endl;
		cout << "工作号：";		cin >> workID;		cout << endl;
		cout << "姓名：";		cin >> name;		cout << endl;
		cout << "性别：";		cin >> sex;			cout << endl;
		cout << "所在部门：";	cin >> dept;		cout << endl;
		cout << "电话号码：";	cin >> phoneNum;	cout << endl;
		cout << "工资：";		cin >> wage;		cout << endl;

		p->m_workID = workID;
		p->m_name = name;
		p->m_sex = sex;
		p->m_dept = dept;
		p->m_phoneNum = phoneNum;
		p->m_wage = wage;

		p->next = NULL;
		tail->next = p;
		tail = p;
		cout << "是否想要继续？" << endl;
		cin >> ch;
		i++;
		cout << endl;
	} while (ch == 'y');

	return tail;
}

//初始化列表
Employee * Employee::initLinkList(Employee * head)
{
	head = new Employee;
	head->next = NULL;
	return head;
}

//2、按工作号查询
Employee * Employee::searchByWorkID(Employee * head)
{
	Employee *p;
	int searchID;
	cout << "请输入需要查询的员工的职工号：" << endl;
	cin >> searchID;
	p = head->next;
	cout << "查询结果：" << endl;
	while (p)
	{
		if (p->m_workID == searchID)
		{
			display(p);
			return p;
		}
		p = p->next;
	}
	cout << "没有此员工！" << endl;
	return false;
}

//3、按姓名查询
bool Employee::searchByName(Employee * head)
{
	Employee *p;
	string searchName;
	cout << "请输入需要查询的员工的姓名：" << endl;
	cin >> searchName;
	p = head->next;
	cout << "查询结果：" << endl;
	while (p)
	{
		if (p->m_name == searchName)
		{
			display(p);
			return true;
		}
		p = p->next;
	}
	cout << "没有此员工！" << endl;
	return false;
}

//4、按科室查询
bool Employee::searchByDept(Employee * head)
{
	Employee * p;
	p = head->next;
	cout << "请输入需要查找的科室：" << endl;
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
		cout << "无此科室信息！" << endl;
		return false;
	}

}

//5、计算各科室的平均工资
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

	cout << "人事部的平均工资为：" << ave0 << endl;
	cout << "科技部的平均工资为：" << ave1 << endl;
}

//6、分科室输出计算各科室的总工资
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
	cout << "科技部：" << endl;
	while (p_m)
	{
		display(p_m);
		p_m = p_m->next;
	}
	cout << "人事部：" << endl;
	while (p_t)
	{
		display(p_t);
		p_t = p_t->next;
	}
}
//7、根据工号修改职工信息
Employee * Employee::modifyByWorkID(Employee * head)
{

	Employee * p = new Employee;
	p = searchByWorkID(head);

	//****************************
	int workID;//工作号
	string name;//姓名
	string sex;//性别
	string dept;//所在部门
	int phoneNum;//电话号码
	double wage;//工资
//*****************************	
	if (p)
	{
		cout << "请修改该员工的信息：" << endl;
		cout << "工作号：";		cin >> workID;		cout << endl;
		cout << "姓名：";		cin >> name;		cout << endl;
		cout << "性别：";		cin >> sex;			cout << endl;
		cout << "所在部门：";	cin >> dept;		cout << endl;
		cout << "电话号码：";	cin >> phoneNum;	cout << endl;
		cout << "工资：";		cin >> wage;		cout << endl;

		p->m_workID = workID;
		p->m_name = name;
		p->m_sex = sex;
		p->m_dept = dept;
		p->m_phoneNum = workID;
		p->m_wage = wage;
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	return head;
}

//8、根据工号删除职工信息
Employee * Employee::deleteByWorkID(Employee * head)
{
	int searchWorkID;
	Employee * parentp;
	Employee * p_front;

	cout << "请输入需要修改的职工的工作号：" << endl;
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

//9、根据职工的工资排序输出
Employee * Employee::sortByWage(Employee * head)
{
	if ((head->next == NULL) || (head->next->next) == NULL)
	{
		cout << "数据个数少于两个，无需排序" << endl;
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
	cout << "从高到低排序成功！" << endl;
	return head;
}

//10、显示信息
void Employee::display(Employee * head)
{
	cout << "该职员的信息如下：" << endl;
	cout << "工作号：" << head->m_workID << endl;
	cout << "姓名：" << head->m_name << endl;
	cout << "性别：" << head->m_sex << endl;
	cout << "所在部门：" << head->m_dept << endl;
	cout << "电话号码：" << head->m_phoneNum << endl;
	cout << "工资：" << head->m_wage << endl;
}

//将信息保存为文件
void Employee::saveFile(Employee * head)
{
	ofstream oFile;
	oFile.open("C:\\c++文件\\职工工资信息.txt");
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

	cout << "数据保存成功！" << endl;
}
//11、各科室总工资
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

	cout << "人事部的总工资为：" << sum0 << endl;
	cout << "科技部的总工资为：" << sum1 << endl;
}