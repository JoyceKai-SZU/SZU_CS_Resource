#include<iostream>
#include<cstring>
using namespace std;

char *str=new char[100];
char *key=new char[100];
char *ans=new char[100];

char *p,*q,*s; 

char get(char* c,char* n)
{
	int numb=*n-'0';
	if(*c>='A'&&*c<='Z')
	{
		if(*c+numb>'Z'&&*c+numb<'a')
		{
			*c=(*c-'A'+numb)%26+'A';
		}
		else *c=*c+numb;
	}
	
	if(*c>='a'&&*c<='z')
	{
		if(*c+numb>'z')
		{
			*c=(*c-'a'+numb)%26+'a';
		}
		else *c=*c+numb;
	}
	return *c;
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>str>>key;
		int lens=strlen(str);
		int lenk=strlen(key);
		
		p=str,q=key,s=ans;    //数组名是常量，得用新的指针引用 
		int k=0;    //k是key的索引
		for(int i=0;i<lens;i++)
		{
			*s=get(p+i,q+k);
			s++;
			k=(k+1)%lenk;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
/*
2
abcde
234
XenOS
56
*/

//output
/*
cegfh\n
CksUX\n
*/ 
