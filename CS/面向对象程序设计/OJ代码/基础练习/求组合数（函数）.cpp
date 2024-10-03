#include<iostream>
using namespace std;

int fac(int num)
{
	int ans=1;
	for(int i=2;i<=num;i++)
	{
		ans*=i;
	}
	return ans;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		int x=fac(m);
		int y=fac(n);
		int z=fac(m-n);
		cout<<x/y/z<<endl; 
		
	}
	return 0;
}
