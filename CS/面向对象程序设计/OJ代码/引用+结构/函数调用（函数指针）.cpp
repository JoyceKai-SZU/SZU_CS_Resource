#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int Pow(int num)
{
	return num*num;
}

float getsqrt(float num)
{
	return sqrt(num);
}

void change(char *str)
{
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			str[i]-=32;
		}
	}
}

int main()
{
	int t;
	cin>>t;
	int (*fp)(int num);
	float (*fs)(float num);
	void (*fc)(char *str);
	
	fp=Pow;fs=getsqrt;fc=change;
	
	while(t--)
	{
		char type;
		cin>>type;
		if(type=='I')
		{
			int num;
			cin>>num;
			cout<<fp(num)<<endl;
		}
		else if(type=='F')
		{
			float num;
			cin>>num;
			cout<<fs(num)<<endl;
		}
		else
		{
			char *str=new char[110];
			cin>>str;
			fc(str);
			cout<<str<<endl;
		}
	}
	return 0; 
}
