#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char *s1=new char[11];
		char *s2=new char[11];
		char *s3=new char[11];
		char *s=new char[50];
		cin>>s1>>s2>>s3;
		int l1,l2,l3;
		int r1,r2,r3;
		cin>>l1>>r1;
		cin>>l2>>r2;
		cin>>l3>>r3;
		
		int idx=0;
		char *p=s;    //·¨¶þ 
		for(int i=l1-1;i<=r1-1;i++)
		{
			*p=*(s1+i);
			p++;
		}
		for(int i=l2-1;i<=r2-1;i++)
		{
			*p=*(s2+i);
			p++;
		}
		for(int i=l3-1;i<=r3-1;i++)
		{
			*p=*(s3+i);
			p++;
		}
		cout<<s<<endl;
	}
	return 0;
}
/*
2
abcdefghij
ABCDEFGHIJ
aabbccddee
3 5
2 6
8 10
AABBCCDDEE
ffgghhiijj
FFGGHHIIJJ
1 4
5 8
2 7
*/

//output
/*
cdeBCDEFdee\n
AABBhhiiFGGHHI\n
*/ 

