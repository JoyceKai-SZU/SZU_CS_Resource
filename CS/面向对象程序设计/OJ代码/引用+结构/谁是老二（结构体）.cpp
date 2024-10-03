#include<iostream>
#include<algorithm>
using namespace std;

struct student{
	int y;
	int m;
	int d;
	bool operator < (const student& b)const
	{
		if(y!=b.y) return y<b.y;
		else if(m!=b.m) return m<b.m;
		else return d<b.d;
	}
}s[110];


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++) cin>>s[i].y>>s[i].m>>s[i].d;
	
	sort(s,s+t);
	
	cout<<s[1].y<<"-"<<s[1].m<<"-"<<s[1].d<<endl;
	return 0;
} 
