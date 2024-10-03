#include<iostream>
using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate(){}   //不要忘了 
	CDate(int y, int m, int d) { year = y; month = m; day = d; }
	bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	int getDayofYear()         //计算日期从当年1月1日算起的天数
	{
		int i, sum=day;
		int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
		
		if (isLeapYear())
		for(i=0;i<month;i++)   sum +=b[i];
		else
		for(i=0;i<month;i++)   sum +=a[i];
		
		return sum;
	}
	
	bool operator< (const CDate &b)const
	{
		if(year!=b.year) return year<b.year;
		else if(month!=b.month) return month<b.month;
		else return day<b.day;
	}
	
};

class SoftWare{
private:
	string name;
	char type;
	CDate date;
	char media;
public:
	SoftWare(string name,char type,char medium,int y,int m,int d);
	SoftWare(const SoftWare &b);
	void Print();
	int countDay(CDate &d);
};



SoftWare::SoftWare(string name,char type,char media,int y,int m,int d):date(y,m,d)
{
	this->name=name;
	this->type=type;
	this->media=media;
}

SoftWare::SoftWare(const SoftWare &b)
{
	name=b.name;
	type='B';
	media='H';
	date=b.date;
}

int SoftWare::countDay(CDate &d)
{
	return date.getDayofYear()-d.getDayofYear();
}

void SoftWare::Print()
{
	cout<<"name:"<<name<<endl;
	
	cout<<"type:";
	if(type=='O') cout<<"original";
	else if(type=='T') cout<<"trial";
	else cout<<"backup";
	cout<<endl;
	
	cout<<"media:";
	if(media=='D') cout<<"optical disk";
	else if(media=='H') cout<<"hard disk";
	else cout<<"USB disk";
	cout<<endl;
	
	if(date.getYear()==0&&date.getMonth()==0&&date.getMonth()==0)
	{
		cout<<"this software has unlimited use"<<endl;
		return;
	}
	
	CDate d0(2015,4,7);
	if(date<d0)
	{
		cout<<"this software has expired"<<endl;
		
	}
	else
	{
		cout<<"this software is going to be expired in "<<countDay(d0)<<" days"<<endl;
	}
	
	
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string name;
		char type,media;
		int y,m,d;
		cin>>name>>type>>media>>y>>m>>d;
		SoftWare s1(name,type,media,y,m,d);
		s1.Print();
		cout<<endl;
		SoftWare s2(s1);
		s2.Print();
		cout<<endl; 
	}
	return 0;
}
