#include<iostream>
using namespace std;

template<class T>
T add(T &t1,T &t2,int n)
{
	T temp=t1+t2;
	return temp;
}

class CClock{
private:
	int h,m,s;
public:
	CClock(){}
	CClock(int hh,int mm,int ss):h(hh),m(mm),s(ss){}
	
	CClock operator + (CClock &a)
	{
		int sum1=h*3600+m*60+s;
		int sum2=a.h*3600+a.m*60+a.s;
		int sum=sum1+sum2;
		return CClock(sum/3600%24,sum/60%60,sum%60);
	}
	
	friend ostream& operator << (ostream &out,const CClock &a)
	{
		out<<a.h<<" "<<a.m<<" "<<a.s;
		return out; 
	}
};

class CRmb{
private:
	int y,j,f;
public:
	CRmb(){}
	CRmb(int yy,int jj,int ff):y(yy),j(jj),f(ff){}
	
	CRmb operator + (CRmb &a)
	{
		int sum1=y*100+j*10+f;
		int sum2=a.y*100+a.j*10+a.f;
		int sum=sum1+sum2;
		return CRmb(sum/100%10,sum/10%10,sum%10);
	}
	
	friend ostream& operator << (ostream &out,const CRmb &a)
	{
		out<<a.y<<" "<<a.j<<" "<<a.f;
		return out; 
	}
};



int main()
{
	int h1,m1,s1;
	int h2,m2,s2;
	cin>>h1>>m1>>s1>>h2>>m2>>s2;
	CClock c1(h1,m1,s1), c2(h2,m2,s2), c;
	c=add(c1,c2,60);
	cout<<c<<endl;
	
	int y1,j1,f1;
	int y2,j2,f2;
	cin>>y1>>j1>>f1>>y2>>j2>>f2;
	CRmb r1(y1,j1,f1), r2(y2,j2,f2), r;
	r=add(r1,r2,10);
	cout<<r<<endl;
	 
	return 0;
}
