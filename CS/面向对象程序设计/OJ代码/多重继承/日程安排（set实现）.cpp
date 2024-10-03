#include<iostream>
#include<set> 
using namespace std;

class Date{
protected:
	int year,month,day;
public:
	Date(int y,int m,int d):year(y),month(m),day(d){}
};

class Time{  //12Сʱ�� 
protected:
	int hour,minute,second;
public:
	Time(int h,int m,int s):hour(h),minute(m),second(s){}
	
};

class Schedule:public Date,public Time{
private:
	int ID;
public:
	Schedule(int id,int y,int mo,int d,int h,int mi,int s):
		ID(id), 
		Date(y,mo,d),
		Time(h,mi,s)
	{
		
	}	
	
	void show()
	{
		printf("No.%d: %d/%02d/%02d %02d:%02d:%02d\n",ID,year,month,day,hour,minute,second);
	}
	
	friend bool before(const Schedule & s1,const Schedule & s2);  //��Ԫ���� 
	bool operator <(const Schedule &b)const
	{
		return before(*this,b);
	}
};

bool before(const Schedule & s1,const Schedule & s2)
{
	if (s1.year != s2.year)
		return s1.year < s2.year;
	else if (s1.month != s2.month)
		return s1.month < s2.month;
	else if (s1.day != s2.day)
		return s1.day < s2.day;
	else if (s1.hour != s2.hour)
		return s1.hour < s2.hour;
	else if (s1.minute != s2.minute)
		return s1.minute < s2.minute;
	else if (s1.second != s2.second)
		return s1.second < s2.second;
}


int main()
{
	int id,y,mo,d,h,mi,s;
	set<Schedule> t;
	while(true)
	{
		cin>>id;
		if(!id) break;
		cin>>y>>mo>>d>>h>>mi>>s;
		Schedule temp(id,y,mo,d,h,mi,s);
		t.insert(temp);
	}
	
	cout<<"The urgent schedule is ";
	Schedule ans=*t.begin();
	ans.show();
	      
	return 0;
} 
