#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;

string ss[]={"大王","小王","黑桃","红桃","梅花","方块"}; 
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

bool cmp(poke &a, poke &b)    //降序排列 
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
			
			string name=str.substr(0,4); //oj一个汉字占3个字节，在dev是2个字节 
			if(str=="小王")  s[i]={str,findtype(name),findw("0")};
			else if(str=="大王") s[i]={str,findtype(name),findw("1")};
			else 
			{
				v=str.substr(4);    //记住oj上用substr截取汉字字符串要改 
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
黑桃4 红桃10 梅花Q 方块K 黑桃A
10
大王 梅花10 红桃K 方块9 黑桃8 梅花A 方块Q 小王 黑桃2 黑桃J
5
红桃K 梅花K 黑桃K 方块K 小王
*/

//output
/*
黑桃A 黑桃4 红桃10 梅花Q 方块K\n
大王 小王 黑桃J 黑桃8 黑桃2 红桃K 梅花A 梅花10 方块Q 方块9\n
小王 黑桃K 红桃K 梅花K 方块K\n
*/ 
