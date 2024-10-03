#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<string,int> mp1;   //�γ���->�����±� 
map<int,string> mp2;   //�����±�->�γ��� 

const int maxn=50;
class Course{
private:
	string name;
	string coursename;
	static int k;  //��ǰ����ӿγ��������� 
	static vector<string> g[maxn];  //�±��1��ʼ 
public:

	Course(string n,string cn):name(n),coursename(cn)
	{
		if(!mp1[coursename])
		{
			mp1[coursename]=k;
			mp2[k]=coursename; 
			g[k].push_back(name);
			k++;
		}
		else
		{
			g[mp1[coursename]].push_back(name); 
		}
		
	}
	
	static int getK(){return k;}
	static void show()
	{
		for(int i=1;i<k;i++)
		{
			cout<<mp2[i]<<":";
			for(int j=0;j<g[i].size();j++)
			{
				cout<<" "<<g[i][j];
			}
			cout<<endl;
		} 
	}
	
}; 

int Course::k=1;
vector<string> Course::g[maxn];  //static��������Ҫ���� 

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string name,coursename;
		cin>>name>>coursename;
		Course temp(name,coursename); 
	}
	
	Course::show(); 
	
	return 0;
}

/*
15
ջ ���ݽṹ
��ͼͿɫ �㷨��������
������ ���ݽṹ��������
���������㷨 �㷨��������
ջ �㷨��������
ָ�� �������������
���� ������������ƣ�������
�쳣���� Java�������
˫����� ������������ƣ�������
���� ���ݽṹ
ѭ�� ������ƻ���
�� �������������
�̳� �������������
�̳� Java�������
�� Java�������
*/

//output
/*
���ݽṹ: ջ ����\n
�㷨��������: ��ͼͿɫ ���������㷨 ջ\n
���ݽṹ��������: ������\n
�������������: ָ�� �� �̳�\n
������������ƣ�������: ���� ˫�����\n
Java�������: �쳣���� �̳� ��\n
������ƻ���: ѭ��
*/
