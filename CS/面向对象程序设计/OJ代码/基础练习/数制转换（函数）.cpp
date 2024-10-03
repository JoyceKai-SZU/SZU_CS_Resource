#include<iostream>
using namespace std;

int len;
long change(char s[])
{
	int res=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			res=res*16+(s[i]-'0');
		}
		else
		{
			res=res*16+(s[i]-'A'+10);
		}
	}
	return res;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		len=str.size();
		char s[110];
		for(int i=0;i<len;i++) s[i]=str[i];
		s[len]='\0';
		long ans=change(s);
		cout<<ans<<endl;
	}
	return 0;
} 
