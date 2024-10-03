#include<iostream>
using namespace std;

template<class T>
void myfunc(T *mm, T*dao,int n)
{
	for(int i=0;i<n;i++) cout<<dao[i];
	for(int i=0;i<n;i++) cout<<mm[i];
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char op;
		int n;
		cin>>op>>n;
		if(op=='I')
		{
			int *mm=new int[n];
			int *dao=new int[n];
			for(int i=0;i<n;i++) cin>>mm[i];
			for(int i=0;i<n;i++) cin>>dao[i];
			myfunc(mm,dao,n);
			
		}
		else if(op=='D')
		{
			double *mm=new double[n];
			double *dao=new double[n];
			for(int i=0;i<n;i++) cin>>mm[i];
			for(int i=0;i<n;i++) cin>>dao[i];
			myfunc(mm,dao,n);
		}
		else if(op=='C')
		{
			char *mm=new char[n];
			char *dao=new char[n];
			for(int i=0;i<n;i++) cin>>mm[i];
			for(int i=0;i<n;i++) cin>>dao[i];
			myfunc(mm,dao,n);
		}
	}
	return 0;
}
