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
		cout<<tt1.getH()<<"ʱ"<<tt1.getM()<<"��"<<tt1.getS()<<"��--"
			<<tt2.getH()<<"ʱ"<<tt2.getM()<<"��"<<tt2.getS()<<"��ʱ���Ϊ"<<get(&tt1,&tt2)<<"��\n";
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
1ʱ2��3��--4ʱ5��6��ʱ���Ϊ10983��\n
1ʱ1��1��--1ʱ1��1��ʱ���Ϊ0��\n
23ʱ44��55��--12ʱ23��45��ʱ���Ϊ40870��\n
*/
