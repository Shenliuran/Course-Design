#pragma once
#include<string>

/* 3、查询功能：
		   1）能够根据工号精确查询职工信息；
		   2）能够根据姓名、科室查询职工信息
		   3）分科室进行工资统计，计算各科室的平均工资
	   4、根据职工的工资排序输出
	   5、根据工号修改职工信息
	   6、根据工号删除职工信息*/
using namespace std;

class Employee
{
public:
	int m_workID;//工作号
	string m_name;//姓名
	string m_sex;//性别
	string m_dept;//所在部门
	int m_phoneNum;//电话号码
	double m_wage;//工资

	Employee * next;
	Employee * initLinkList(Employee * head);//初始化列表
	Employee * addMember(Employee * head);//1、注册职工
	Employee * searchByWorkID(Employee * head);//2、按工作号查询
	bool searchByName(Employee * head);//3、按姓名查询
	bool searchByDept(Employee * head);//4、按科室查询
	void aveByDept(Employee * head);//5、计算各科室的平均工资
	void statisticByDept(Employee * head);//6、分科室进行工资统计
	Employee * modifyByWorkID(Employee * head);//7、根据工号修改职工信息
	Employee * deleteByWorkID(Employee * head);//8、根据工号删除职工信息
	Employee * sortByWage(Employee * head);//9、根据职工的工资排序输出
	void display(Employee * head);//显示信息
	void saveFile(Employee * head);//10、将信息保存为文件
	void sumByDept(Employee * head);
};
