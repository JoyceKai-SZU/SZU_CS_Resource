#include<iostream>
using namespace std;

class employee{
protected:
	string name,position;
	int grade,year;
public:
	employee(string n,string p,int g,int y):name(n),position(p),grade(g),year(y){}
	virtual int salary()
	{
		return 1000+500*grade+50*year;
	}
	void show()
	{
		cout<<name<<":"<<position<<",Salary:"<<salary()<<endl;
	}
};

class teamleader:public employee{
public:
	teamleader(string n,string p,int g,int y):employee(n,p,g,y){}
	int salary()
	{
		return 3000+800*grade+100*year;
	}
};

class manager:public employee{
public:
	manager(string n,string p,int g,int y):employee(n,p,g,y){}
	int salary()
	{
		return 5000+1000*(grade+year);
	}
};


int main()
{
	int t;
	cin>>t;
	employee *ee;
	while(t--)
	{
		string n,p;
		int g,y;
		cin>>n>>p>>g>>y;
		if(p=="Employee")
		{
			if(g<0||y<0) cout<<"error grade or year."<<endl;
			else
			{
				employee e(n,p,g,y);
				ee=&e;
				ee->show(); //调用方法要在里面，因为是e是局部变量，p虽然放外面但是指向的内存在出去后会被析构 
			}
		}
		else if(p=="Teamleader")
		{
			if(g<0||y<0) cout<<"error grade or year."<<endl;
			else
			{
				teamleader t(n,p,g,y);
				ee=&t;
				ee->show();
			}
		}
		else if(p=="Manager")
		{
			if(g<0||y<0) cout<<"error grade or year."<<endl;
			else
			{
				manager m(n,p,g,y);
				ee=&m;
				ee->show();
			}
		}
		else
		{
			cout<<"error position."<<endl;
		}
	}
	return 0;
}
