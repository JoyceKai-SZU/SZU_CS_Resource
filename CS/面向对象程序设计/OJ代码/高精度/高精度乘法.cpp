#include<iostream>
#include<cstring>
using namespace std;
const int maxn=300;


string mul(string s1,string s2)
{
	char sign='+';
	
	//处理字符串正负问题 
	if(s1[0]=='-'&&s2[0]=='-')
	{
		s1.erase(s1.begin());
		s2.erase(s2.begin());
	}
	else if(s1[0]=='-'&&s2[0]!='-')
	{
		sign='-';
		s1.erase(s1.begin());
	}
	else if(s1[0]!='-'&&s2[0]=='-')
	{
		sign='-';
		s2.erase(s2.begin());
	}
	
	
	int a1[maxn],a2[maxn],a3[maxn];
	memset(a1,0,sizeof a1);
	memset(a2,0,sizeof a2);
	memset(a3,0,sizeof a3);
	
	for(int i=0;i<s1.size();i++) a1[i]=s1[s1.size()-i-1]-'0';
	for(int i=0;i<s2.size();i++) a2[i]=s2[s2.size()-i-1]-'0';
	
	
	//乘法运算 
	for(int i=0;i<s1.size();i++)
	{
		for(int j=0;j<s2.size();j++)
		{
			a3[i+j]+=a1[i]*a2[j];
			if(a3[i+j]>=10)
			{
				a3[i+j+1]+=a3[i+j]/10;
				a3[i+j]%=10;
			}
		}
	}
	
	//找数组最大项对应下标
	int st=s1.size()+s2.size()-1;
	for(int i=s1.size()+s2.size()-1;i>=0;i--)
	{
		if(a3[i])
		{
			st=i;
			break;
		}
	} 
	
	string ans="";
	
	if(sign=='-') ans+=sign; 
	
	for(int i=st;i>=0;i--)
	{
		ans+=to_string(a3[i]);
	}
	
	return ans;
	
	
} 

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<mul(s1,s2)<<endl;
	return 0;
}
