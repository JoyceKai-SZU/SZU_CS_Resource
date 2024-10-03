#include<iostream>
#include<cstdio>
using namespace std;

class CFraction{
private:
	int fz, fm;
public:
	CFraction(int fz_val, int fm_val) ;
	CFraction add(const CFraction &r);
	CFraction sub(const CFraction &r);
	CFraction mul(const CFraction &r);
	CFraction div(const CFraction &r);
	int getGCD();   // 求对象的分子和分母的最大公约数
	void print();
};

int CFraction::getGCD()
{
	int a=fz,b=fm;
	if(a<0) a=-a;
	if(b<0) b=-b;
	if(b>a) swap(a,b);
	while(b)
	{
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}

CFraction::CFraction(int fz_val, int fm_val)
{
	fz=fz_val, fm=fm_val;
	int num=getGCD();
	fz/=num;
	fm/=num;
}
CFraction CFraction::add(const CFraction &r) 
{
	return CFraction(fz*r.fm+fm*r.fz,fm*r.fm);    //可以直接返回构造函数 
}

CFraction CFraction::sub(const CFraction &r) 
{
	return CFraction(fz*r.fm-fm*r.fz,fm*r.fm);
}

CFraction CFraction::mul(const CFraction &r) 
{
	return CFraction(fz*r.fz,fm*r.fm);
}

CFraction CFraction::div(const CFraction &r) 
{
	return CFraction(fz*r.fm,fm*r.fz);
}

void CFraction::print()
{
	cout<<fz<<"/"<<fm<<endl;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int fz1,fm1;
		int fz2,fm2;
		scanf("%d/%d",&fz1,&fm1);
		scanf("%d/%d",&fz2,&fm2);
		CFraction s1(fz1,fm1);
		CFraction s2(fz2,fm2);
		s1.add(s2).print();
		s1.sub(s2).print();
		s1.mul(s2).print();
		s1.div(s2).print();
		cout<<endl;
	}

	return 0;
}


/*
3
1/2
2/3
3/4
5/8
21/23
8/13
*/

//output

/*
7/6\n
-1/6\n
1/3\n
3/4\n
\n
11/8\n
1/8\n
15/32\n
6/5\n
\n
457/299\n
89/299\n
168/299\n
273/184\n
\n
*/
