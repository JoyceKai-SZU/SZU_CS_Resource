#include<iostream>
#include<cstring>
using namespace std;
const int maxn=300;


string add(string s1,string s2)
{
	char sign='+';
	//�����ַ���������޸�
	if(s1[0]=='-'&&s2[0]=='-')  //������Ǹ��� 
	{
		sign='-';
		s1.erase(s1.begin());
		s2.erase(s2.begin());
	}
	
	
	int a1[maxn],a2[maxn],a3[maxn];   //memsetֻ�����ھ�̬���� 
	
	//��ʼ�� 
	memset(a1,0,sizeof a1);
	memset(a2,0,sizeof a2);
	memset(a3,0,sizeof a3);
	//����洢 
	for(int i=0;i<s1.size();i++) a1[i]=(s1[s1.size()-1-i]-'0');
	for(int i=0;i<s2.size();i++) a2[i]=(s2[s2.size()-1-i]-'0');
	
	int len=max(s1.size(),s2.size());
	
	//�ӷ����� 
	for(int i=0;i<len;i++)
	{
		a3[i]+=a1[i]+a2[i];
		if(a3[i]>=10)     //��λ���� 
		{
			a3[i+1]+=a3[i]/10;
			a3[i]%=10;
		}
	} 
	
	if(a3[len]!=0) len++;
	
	//������ 
	string ans="";
	
	if(sign=='-') ans+=sign;
	
	
	for(int i=len-1;i>=0;i--)
	{
		ans+=to_string(a3[i]);
	}
	return ans;
	

}


int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<add(s1,s2)<<endl;
	return 0;
} 
