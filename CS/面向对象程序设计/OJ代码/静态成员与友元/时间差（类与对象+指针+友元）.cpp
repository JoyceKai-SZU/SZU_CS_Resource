#include<iostream>
#include<cmath> 
using namespace std;

class CTime{
private:
	int h,m,s;
public:
	CTime(int h,int m,int s);
	int getH();
	int getM();
	int getS();
	friend int get(CTime *t1,CTime *t2);
};

CTime::CTime(int h,int m,int s):h(h),m(m),s(s){}
int CTime::getH(){return h;}
int CTime::getM(){return m;}
int CTime::getS(){return s;}

int get(CTime *t1,CTime *t2)
{
	int time1=t1->h*3600+t1->m*60+t1->s;
	int time2=t2->h*3600+t2->m*60+t2->s;
	return abs(time1-time2);
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int h1,m1,s1;
		int h2,m2,s2;
		cin>>h1>>m1>>s1>>h2>>m2>>s2;
		CTime tt1(h1,m1,s1);
		CTime tt2(h2,m2,s2);
		cout<<tt1.getH()<<"时"<<tt1.getM()<<"分"<<tt1.getS()<<"秒--"
			<<tt2.getH()<<"时"<<tt2.getM()<<"分"<<tt2.getS()<<"秒时间差为"<<get(&tt1,&tt2)<<"秒\n";
	}
	return 0;
}

/*
3
1 2 3 4 5 6
1 1 1 1 1 1
23 44 55 12 23 45
*/

//output
/*
1时2分3秒--4时5分6秒时间差为10983秒\n
1时1分1秒--1时1分1秒时间差为0秒\n
23时44分55秒--12时23分45秒时间差为40870秒\n
*/
