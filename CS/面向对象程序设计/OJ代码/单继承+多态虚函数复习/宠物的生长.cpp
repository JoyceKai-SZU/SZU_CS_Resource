#include<iostream>
#include<iomanip>
using namespace std;

class CDate{
private:
	int y,m,d;
public:
	CDate(){}
	CDate(int yy,int mm,int dd):
		y(yy),m(mm),d(dd){}
	
	bool isleap(){return y%400==0||(y%100!=0&&y%4==0);}
	
	CDate operator ++ ()
	{
		int D[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		if(isleap()) D[2]=29;
		else D[2]=28;
		
		if(m==12&&d==D[m])
		{
			++y;
			m=1;
			d=1;
		}
		else if(d==D[m])
		{
			++m;
			d=1;
		}
		else ++d;
		
		return *this;
	}
	
	bool operator < (const CDate &b)const
	{
		if(y!=b.y) return y<b.y;
		else if(m!=b.m) return m<b.m;
		else if(d!=b.d) return d<b.d;
	}
	
	bool operator != (const CDate &b)const
	{
		return (y!=b.y)||(m!=b.m)||(d!=b.d);
	}
	
	int getDay(CDate day)
	{
		if(*this<day) return -1;
		
		int ans=0;
		while(*this!=day)
		{
			ans++;
			++day;
		}
		return ans;
	}
	
	
};

class Pet{
protected:
	string name;//姓名
	float length;//身长
	float weight;//体重
	CDate current;//开始记录时间
public:
	Pet(string n,float l,float w,int y,int m,int d):
		name(n),length(l),weight(w),current(y,m,d){}
	virtual void display(CDate day)=0;//输出目标日期时宠物的身长和体重
};

class Cat:public Pet{
public:
	Cat(string n,float l,float w,int y,int m,int d):
		Pet(n,l,w,y,m,d){}
	
	void display(CDate day)
	{
		int pass=current.getDay(day);
		if(pass==-1)
		{
			cout<<"error"<<endl;
			return;
		}
		for(int i=1;i<=pass;i++)
		{
			length+=0.1;
			weight+=0.2;
		}
		
		cout<<name<<" after "<<pass<<" day: length="
			<<fixed<<setprecision(2)<<length<<",weight="
			<<weight<<endl;
	}
};

class Dog:public Pet{
public:
	Dog(string n,float l,float w,int y,int m,int d):
		Pet(n,l,w,y,m,d){}
	
	void display(CDate day)
	{
		int pass=current.getDay(day);
		if(pass==-1)
		{
			cout<<"error"<<endl;
			return;
		}
		for(int i=1;i<=pass;i++)
		{
			length+=0.2;
			weight+=0.1;
		}
		
		cout<<name<<" after "<<pass<<" day: length="
			<<fixed<<setprecision(2)<<length<<",weight="
			<<weight<<endl;
	}
};



int main()
{
	int t;
	cin>>t;
	int y0,m0,d0;
	cin>>y0>>m0>>d0;
	Pet *pt;
	CDate date0(y0,m0,d0);
	while(t--)
	{
		int op;
		string n;
		float l,w;
		int y,m,d;
		cin>>op>>n>>l>>w>>y>>m>>d;
		if(op==1)
		{
			Cat c(n,l,w,y,m,d);
			pt=&c;
			pt->display(date0);
		}
		else if(op==2)
		{
			Dog dg(n,l,w,y,m,d);
			pt=&dg;
			pt->display(date0);
		}
		
	}
	return 0;
}
