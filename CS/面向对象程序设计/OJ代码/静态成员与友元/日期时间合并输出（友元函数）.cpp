#include<iostream>
#include<iomanip>
using namespace std;

class CTime;    //ÌáÇ°ÉùÃ÷ 
class CDate{
private:
	int y,m,d;
public:
	CDate(){}
	CDate(int y,int m,int d);
	friend void Display(CDate &, CTime &);
};

CDate::CDate(int y,int m,int d):y(y),m(m),d(d){}

class CTime{
private:
	int h,m,s;
public:
	CTime(){}
	CTime(int h,int m,int s);
	friend void Display(CDate &, CTime &);
};

CTime::CTime(int h,int m,int s):h(h),m(m),s(s){}

void Display(CDate &date, CTime &time)
{
	cout<<setfill('0')<<setw(4)<<date.y<<"-";
	cout<<setfill('0')<<setw(2)<<date.m<<"-";
	cout<<setfill('0')<<setw(2)<<date.d<<" ";
	
	cout<<setfill('0')<<setw(2)<<time.h<<":";
	cout<<setfill('0')<<setw(2)<<time.m<<":";
	cout<<setfill('0')<<setw(2)<<time.s;
	cout<<endl;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int year,month,day,hour,minute,second;
		cin>>year>>month>>day>>hour>>minute>>second;
		CDate date(year,month,day);
		CTime time(hour,minute,second);
		Display(date,time);
	}
	return 0;
}
