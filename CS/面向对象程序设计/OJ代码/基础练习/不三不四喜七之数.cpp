#include<iostream>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i%3!=0&&i%4!=0&&i%7==0) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
