#include<iostream>
using namespace std;

template<class T>
T add(T& t1,T& t2, int n)
{
	T temp=t1+t2;
	return temp;
}

class CClock{
private:
	int h,m,s;
public:
	CClock(){}
	CClock(int hh,int mm,int ss):
		h(hh),m(mm),s(ss){}
	
	CClock& operator + (const CClock &a)
	{
		int sum1=h*3600+m*60+s;
		int sum2=a.h*3600+a.m*60+a.s;
		
		int sum=sum1+sum2;
		
		h=sum/3600%24;
		m=sum/60%60;
		s=sum%60;
		return *this; 
	}
	friend ostream & operator << (ostream& output, const CClock &a)
	{
		output<<a.h<<" "<<a.m<<" "<<a.s<<endl;
		return output;
	}
};

class CRmb{
private:
	int y,j,f;
public:
	CRmb(){}
	CRmb(int yy,int jj,int ff):
		y(yy),j(jj),f(ff){}
	
	CRmb& operator + (const CRmb &a)
	{
		int sum1=y*100+j*10+f;
		int sum2=a.y*100+a.j*10+a.f;
		
		int sum=sum1+sum2;
		
		y=sum/100%10;
		j=sum/10%10;
		f=sum%10;
		return *this; 
	}
	
	friend ostream& operator << (ostream& output, const CRmb &a)
	{
		output<<a.y<<" "<<a.j<<" "<<a.f<<endl;
		return output;
	}
};

int main()
{
	int h1,m1,s1;
	int h2,m2,s2;
	cin>>h1>>m1>>s1;
	cin>>h2>>m2>>s2;
	CClock c1(h1,m1,s1), c2(h2,m2,s2),c;
	
//	c=add<CClock>(c1,c2,60);
	c=add(c1,c2,60);
	cout<<c<<endl;
	
	int y1,j1,f1;
	int y2,j2,f2;
	cin>>y1>>j1>>f1;
	cin>>y2>>j2>>f2;
	CRmb r1(y1,j1,f1), r2(y2,j2,f2),r;
	
//	r=add<CRmb>(r1,r2,10);
	r=add(r1,r2,10);
	cout<<r<<endl;
	
	return 0;
}

/*
15 34 25
7 25 36
5 6 7
3 4 5
*/

//output
/*
23 0 1
9 1 2
*/
