#include<iostream>
#include<cstring>
using namespace std;


int isNumber(char *c)
{
	int len=strlen(c);
	bool flag=true;
	for(int i=0;i<len;i++)
	{
		if(c[i]<'0'||c[i]>'9') 
		{
			flag=false;
			break;
		}
	}
	
	if(!flag) return -1;
	else
	{
		int ans=0;
		for(int i=0;i<len;i++)
		{
			ans=ans*10+c[i]-'0';
		}
		return ans;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char *str=new char[50];   //Òª¿ªÄÚ´æ 
		cin>>str;
		cout<<isNumber(str)<<endl;
	}
	return 0;
}
