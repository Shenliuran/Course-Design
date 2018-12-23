#pragma once
#include<string>

/* 3����ѯ���ܣ�
		   1���ܹ����ݹ��ž�ȷ��ѯְ����Ϣ��
		   2���ܹ��������������Ҳ�ѯְ����Ϣ
		   3���ֿ��ҽ��й���ͳ�ƣ���������ҵ�ƽ������
	   4������ְ���Ĺ����������
	   5�����ݹ����޸�ְ����Ϣ
	   6�����ݹ���ɾ��ְ����Ϣ*/
using namespace std;

class Employee
{
public:
	int m_workID;//������
	string m_name;//����
	string m_sex;//�Ա�
	string m_dept;//���ڲ���
	int m_phoneNum;//�绰����
	double m_wage;//����

	Employee * next;
	Employee * initLinkList(Employee * head);//��ʼ���б�
	Employee * addMember(Employee * head);//1��ע��ְ��
	Employee * searchByWorkID(Employee * head);//2���������Ų�ѯ
	bool searchByName(Employee * head);//3����������ѯ
	bool searchByDept(Employee * head);//4�������Ҳ�ѯ
	void aveByDept(Employee * head);//5����������ҵ�ƽ������
	void statisticByDept(Employee * head);//6���ֿ��ҽ��й���ͳ��
	Employee * modifyByWorkID(Employee * head);//7�����ݹ����޸�ְ����Ϣ
	Employee * deleteByWorkID(Employee * head);//8�����ݹ���ɾ��ְ����Ϣ
	Employee * sortByWage(Employee * head);//9������ְ���Ĺ����������
	void display(Employee * head);//��ʾ��Ϣ
	void saveFile(Employee * head);//10������Ϣ����Ϊ�ļ�
	void sumByDept(Employee * head);
};
