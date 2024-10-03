#include<iostream>
#include<iomanip>
using namespace std;

class CDate{
private:
	int y,m,d;
public:
	CDate(){}
	CDate(int yy,int mm,int dd):y(yy),m(mm),d(dd){}
	bool operator < (const CDate &b)const
	{
		if(y!=b.y) return y<b.y;
		else if(m!=b.m) return m<b.m;
		else if(d!=b.d) return d<b.d;
	}
	bool isleap(int y)
	{
		return y%400==0||(y%100!=0&&y%4==0);
	}
	int getDay(CDate day)
	{
		int D[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		int ans=0;
		bool flag=true;
		for(int year=day.y;year<=y;year++)
		{
			if(isleap(year)) D[2]=29;
			else D[2]=28;
			for(int month=day.m;month<=12;month++)
			{
				int date;
				if(flag)
				{
					date=day.d;
					flag=false;
				}
				else date=1;
				
				for(;date<=D[month];date++)
				{
					if(year==y&&month==m&&date==d) 	return ans;
					ans++;
				}
			}
		}
	}
};

class Pet{  //基类 
protected:
	string name;//姓名
	float length;//身长
	float weight;//体重
	CDate current;//开始记录时间

//（日期类CDate包含年、月、日三个私有数据，其他方法根据需要自拟。）

public:
	Pet(string n,float l,float w,int y,int m,int d):name(n),length(l),weight(w),current(y,m,d){}
	virtual void display(CDate day)=0;//输出目标日期时宠物的身长和体重
	
};

class Cat:public Pet{
public:
	Cat(string n,float l,float w,int y,int m,int d):Pet(n,l,w,y,m,d){}
	void display(CDate day)
	{
		if(current<day)
		{
			cout<<"error"<<endl;
		}
		else
		{
			int Time=current.getDay(day);
			length+=Time*0.1;
			weight+=Time*0.2;
			cout<<fixed<<setprecision(2)<<name<<" after "<<Time<<" day: length="<<length<<",weight="<<weight<<endl;
		}
	}
}; 

class Dog:public Pet{
public:
	Dog(string n,float l,float w,int y,int m,int d):Pet(n,l,w,y,m,d){}
	void display(CDate day)
	{
		if(current<day)
		{
			cout<<"error"<<endl;
		}
		else
		{
			int Time=current.getDay(day);
			length+=Time*0.2;
			weight+=Time*0.1;
			cout<<fixed<<setprecision(2)<<name<<" after "<<Time<<" day: length="<<length<<",weight="<<weight<<endl;
		}
	}
}; 


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int y,m,d;
	int t;
	cin>>t;
	cin>>y>>m>>d;
	CDate d0(y,m,d);
	Pet *pt;
	while(t--)
	{
		int op;
		string n;
		float l,w;
		cin>>op>>n>>l>>w>>y>>m>>d;
		if(op==1)
		{
			Cat c(n,l,w,y,m,d);
			pt=&c;
			pt->display(d0);
		}
		else
		{
			Dog dg(n,l,w,y,m,d);
			pt=&dg;
			pt->display(d0);
		} 
	}
	return 0;
}


/*
3
2019 5 5
1 tony 10 10 2018 12 30
2 jerry 5 6 2019 5 10
1 tom 3 4 2019 6 1
*/

//output
/*
error\n
jerry after 5 day: length=6.00,weight=6.50\n
tom after 27 day: length=5.70,weight=9.40\n
*/
