#include<iostream>
using namespace std;


void Sort(int &a, int &b, int &c)
{
	int temp;
	if(a<b)
	{
		temp=b;
		b=a;
		a=temp;
	}
	if(a<c)
	{
		temp=c;
		c=a;
		a=temp;
	}
	if(b<c)
	{
		temp=c;
		c=b;
		b=temp;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		Sort(a,b,c);
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
} 
