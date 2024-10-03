#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;

string ss[]={"����","С��","����","����","÷��","����"}; 
string w[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A","0","1"};

int findw(string s)
{
	for(int i=0;i<13;i++)
	{
		if(w[i]==s) return i;
	}
	return -1;
}


int findtype(string s)
{
	for(int i=0;i<6;i++)
	{
		if(ss[i]==s) return i;
	}
	return -1;
}

struct poke{
	string mainstr; 
	int type;
	int value;
}s[110];

bool cmp(poke &a, poke &b)    //�������� 
{

	if(a.type!=b.type) return a.type<b.type;
	else if(a.value!=b.value) return a.value>b.value;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			string str,v;
			cin>>str;
			
			string name=str.substr(0,4); //ojһ������ռ3���ֽڣ���dev��2���ֽ� 
			if(str=="С��")  s[i]={str,findtype(name),findw("0")};
			else if(str=="����") s[i]={str,findtype(name),findw("1")};
			else 
			{
				v=str.substr(4);    //��סoj����substr��ȡ�����ַ���Ҫ�� 
				s[i]={str,findtype(name),findw(v)};
			}
			
		}
		
		sort(s,s+n,cmp);
		
		for(int i=0;i<n;i++)
		{
			cout<<s[i].mainstr;
			if(i!=n-1) cout<<" ";
		}
		cout<<endl;
	} 
	return 0;
}

/*
3
5
����4 ����10 ÷��Q ����K ����A
10
���� ÷��10 ����K ����9 ����8 ÷��A ����Q С�� ����2 ����J
5
����K ÷��K ����K ����K С��
*/

//output
/*
����A ����4 ����10 ÷��Q ����K\n
���� С�� ����J ����8 ����2 ����K ÷��A ÷��10 ����Q ����9\n
С�� ����K ����K ÷��K ����K\n
*/ 
