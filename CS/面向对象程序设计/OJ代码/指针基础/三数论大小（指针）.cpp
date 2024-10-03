#include<iostream>
using namespace std;

int *a,*b,*c;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		a=new int;
		b=new int;
		c=new int;
		cin>>*a>>*b>>*c;
		if(*a<*b)
		{
			int temp=*b;
			*b=*a;
			*a=temp;
		}
		if(*a<*c)
		{
			int temp=*c;
			*c=*a;
			*a=temp;
		}
		if(*b<*c)
		{
			int temp=*c;
			*c=*b;
			*b=temp;
		}
		cout<<*a<<" "<<*b<<" "<<*c<<" "<<endl;
	}
	return 0;
}
