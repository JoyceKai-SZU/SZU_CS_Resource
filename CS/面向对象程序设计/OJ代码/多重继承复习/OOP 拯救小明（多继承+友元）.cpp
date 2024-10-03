#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Date{
protected:
	int year,month,day;
public:
	Date(int y,int m,int d):
		year(y),month(m),day(d){}
	
};

class Time{
protected:
	int hour,minute,second;
public:
	Time(int h,int m,int s):
		hour(h),minute(m),second(s){}
	
}; 

class Work:public Date,public Time{
private:
	int ID;
public:
	Work(int id,int y,int mo,int d,int h,int mi,int s):
		ID(id),Date(y,mo,d),Time(h,mi,s){}
	
	
	void display()
	{
		cout<<"No."<<ID<<": ";
		printf("%d/%02d/%02d %02d:%02d:%02d",year,month,day,hour,minute,second);
	}
	
	friend bool before(const Work& w1,const Work& w2);
	
};

bool before(const Work& w1,const Work& w2)
{
	if(w1.year!=w2.year) return w1.year<w2.year;
	else if(w1.month!=w2.month) return w1.month<w2.month;
	else if(w1.day!=w2.day) return w1.day<w2.day;
	else if(w1.hour!=w2.hour) return w1.hour<w2.hour;
	else if(w1.minute!=w2.minute) return w1.minute<w2.minute;
	else return w1.second<w2.second; 
}

int main()
{
	int id;
	vector<Work> p;
	while(true)
	{
		cin>>id;
		if(!id) break;
		int y,mo,d,h,mi,s;
		cin>>y>>mo>>d>>h>>mi>>s;
		p.emplace_back(id,y,mo,d,h,mi,s);
		
	}
	
	sort(p.begin(),p.end(),before);
	
	cout<<"The urgent Work is ";
	(*p.begin()).display();
	return 0;
}
