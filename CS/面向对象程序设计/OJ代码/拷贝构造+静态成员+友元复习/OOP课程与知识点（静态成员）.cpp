#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<string,int> mp1;   //课程名->数组下标 
map<int,string> mp2;   //数组下标->课程名 

const int maxn=50;
class Course{
private:
	string name;
	string coursename;
	static int k;  //当前已添加课程名的数量 
	static vector<string> g[maxn];  //下标从1开始 
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
vector<string> Course::g[maxn];  //static变量外面要定义 

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
栈 数据结构
地图涂色 算法设计与分析
搜索树 数据结构（荣誉）
多种排序算法 算法设计与分析
栈 算法设计与分析
指针 面向对象程序设计
队列 面向对象程序设计（荣誉）
异常处理 Java程序设计
双向队列 面向对象程序设计（荣誉）
队列 数据结构
循环 程序设计基础
类 面向对象程序设计
继承 面向对象程序设计
继承 Java程序设计
类 Java程序设计
*/

//output
/*
数据结构: 栈 队列\n
算法设计与分析: 地图涂色 多种排序算法 栈\n
数据结构（荣誉）: 搜索树\n
面向对象程序设计: 指针 类 继承\n
面向对象程序设计（荣誉）: 队列 双向队列\n
Java程序设计: 异常处理 继承 类\n
程序设计基础: 循环
*/
