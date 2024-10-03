#include<iostream>
#include<cstring>
using namespace std;

int cmp(char *s, char *t)
{
	int lens=strlen(s);
	int lent=strlen(t);
	if(lens>lent) return 1;
	else if(lens<lent) return -1;
	else   //串长度一样 
	{
		int cnt1=0,cnt2=0;
		for(int i=0;i<lens;i++)
		{
			if(*(s+i)>*(t+i)) cnt1++;
			else if(*(s+i)<*(t+i)) cnt2++;
		}
		
		if(cnt1>cnt2) return 1;
		else if(cnt1<cnt2) return -1;
		else return 0;
	}
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char *s=new char[110];
		char *t=new char[110];
		cin>>s>>t;
		cout<<cmp(s,t)<<endl; 
	}
	return 0;
}
