#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char c,type,y;
		int x;
		cin>>c>>type;
		cin>>x;
		cin>>y;
		if(type=='+')
		{
			for(int i=1;i<=x-1;i++) cout<<y;
			cout<<c<<endl;
		}
		else
		{
			cout<<c;
			for(int i=1;i<=x-1;i++) cout<<y;
			cout<<endl;
		}
		
	}
	return 0;
}
