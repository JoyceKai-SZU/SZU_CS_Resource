#include<iostream>
using namespace std;

class CBook{
private:
	string id,name;
	int snum,remain;
public:
	CBook();
	void set(string id,string name,int snum,int remain);
	string borrow();
	void display(); 
	int getRemain();
	int getSnum();
	string getName();
	string getId();
};

CBook::CBook(){}
void CBook::set(string id,string name,int snum,int remain)
{
	this->id=id;this->name=name;
	this->snum=snum;this->remain=remain;
}

int CBook::getSnum(){return snum;}
int CBook::getRemain(){return remain;}
string CBook::getName(){return name;}
string CBook::getId(){return id;}

string CBook::borrow()
{
	if(remain>=1)
	{
		remain--;
		return id;
	}
	else return "";
}

void CBook::display()
{
	cout<<id<<" "<<name<<" "<<snum<<" "<<remain<<endl;
}


int main()
{
	int haveborrow=0;
	int nowremain=0;
	
	int n,m;
	cin>>n;
	
	CBook *p=new CBook[n]; 
	for(int i=0;i<n;i++)
	{
		string id,name;
		int snum,remain;
		cin>>id>>name>>snum>>remain;
		p[i].set(id,name,snum,remain);
	}
	
	cin>>m;
	while(m--)
	{
		string str;
		cin>>str;
		for(int i=0;i<n;i++)
		{
			if(str==p[i].getName())
			{
				if(p[i].borrow()=="")
				{
					cout<<str<<" "<<"该书已全部借出"<<endl;
				}
				else
				{
					cout<<str<<" "<<"索取号: "<<p[i].getId()<<endl;
				}
				
				break;
			}
		}
		
	}
	
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
		haveborrow+=p[i].getSnum()-p[i].getRemain();
		nowremain+=p[i].getRemain();
		p[i].display();
	}
	cout<<"借出图书: "<<haveborrow<<"本  剩余馆藏图书: "<<nowremain<<"本"<<endl; 
	
	return 0;
}



/*
4
TP312JA-43/L99 Java语言程序设计教程 3 0
TP312PH/Q68b PHP7内核剖析 3 2
TP311.561-43/L93 Python大学教程 3 1
TP311.5-43/M18a1(2) 软件工程基础 3 3
4
Java语言程序设计教程
软件工程基础
Python大学教程
Python大学教程


*/

//output
/*
Java语言程序设计教程 该书已全部借出\n
软件工程基础 索取号: TP311.5-43/M18a1(2)\n
Python大学教程 索取号: TP311.561-43/L93\n
Python大学教程 该书已全部借出\n
\n
TP312JA-43/L99 Java语言程序设计教程 3 0\n
TP312PH/Q68b PHP7内核剖析 3 2\n
TP311.561-43/L93 Python大学教程 3 0\n
TP311.5-43/M18a1(2) 软件工程基础 3 2\n
借出图书: 8本  剩余馆藏图书: 4本
*/ 
