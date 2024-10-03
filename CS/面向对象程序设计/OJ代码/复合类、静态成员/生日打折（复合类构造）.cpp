#include<iostream>
using namespace std;

class Date{
private:
	int year,month,day;
public:
	Date(){}
	Date(int year,int month,int day):year(year),month(month),day(day){}
	int getYear(){return year;}
	int getMonth(){return month;}
	int getDay(){return day;}
};

class VIP{
private:
	int id;
	Date birth;
public:
	VIP(){}
	VIP(int id,int y,int m,int d):id(id),birth(y,m,d){}
	double Discount(Date &d0)
	{
		if(birth.getMonth()==d0.getMonth()&&birth.getDay()==d0.getDay())
			return 0.5;
		else
			return 0.95;
	}
	
};

int main()
{
	int y,m,d;
	cin>>y>>m>>d;
	Date d0(y,m,d);
	
	int t;
	cin>>t;
	while(t--)
	{
		int id;
		double cost;
		cin>>id>>y>>m>>d;
		cin>>cost;
		VIP v(id,y,m,d);
		cout<<id<<"'s consumption is "<<(int)(cost*v.Discount(d0))<<endl;
	}
	return 0;
}
