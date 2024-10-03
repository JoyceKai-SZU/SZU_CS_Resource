#include<iostream>
#include<cstring>
using namespace std;
const int maxn=10;

string sub(string s1,string s2)  //s1-s2
{
	char sign='+';
	int a1[maxn],a2[maxn],a3[maxn];
	memset(a1,0,sizeof a1);
	memset(a2,0,sizeof a2);
	memset(a3,0,sizeof a3);
	
	//判断两数大小 
	if(s1.size()<s2.size()||(s1.size()==s2.size()&&s1<s2))
	{
		sign='-';
		swap(s1,s2);
	}
	
	for(int i=0;i<s1.size();i++) a1[i]=s1[s1.size()-i-1]-'0';
	for(int i=0;i<s2.size();i++) a2[i]=s2[s2.size()-i-1]-'0';
	
	//减法计算 
	for(int i=0;i<s1.size();i++)
	{
		if(a1[i]<a2[i])
		{
			a1[i+1]-=1;
			a1[i]+=10;
		}
		a3[i]=a1[i]-a2[i];
	}
	
	//保存结果 
	string ans="";
	if(sign=='-') ans+='-';
	
	int st=s1.size();
	for(int i=s1.size();i>=0;i--)  //找数组最大项对应下标 
	{
		if(a3[i])
		{
			st=i;
			break;
		}
	}
	
	for(int i=st;i>=0;i--) ans+=to_string(a3[i]);
	return ans; 
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<sub(s1,s2)<<endl;
	return 0;
} 
