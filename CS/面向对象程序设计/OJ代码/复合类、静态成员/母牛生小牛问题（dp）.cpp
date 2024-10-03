#include<iostream>
using namespace std;

const int maxn=50;   
int f[maxn];


int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		f[1]=1;
		for(int i=2;i<=n;i++)
		{
			f[i]=f[i-1];
			if(i>=11)     //排除死去的母牛才能生小母牛 
			{
				for(int j=i;j>=i-10;j--)
				{
					f[j]-=f[i-10]; 
				}
			}
			if(i>=4) f[i]+=f[i-3];   //母牛生小母牛 
		}
		cout<<f[n]<<endl;
	}
	return 0;
} 


/*
3
7
30
25
*/

//output
/*
6\n
28364\n
4530\n
*/
