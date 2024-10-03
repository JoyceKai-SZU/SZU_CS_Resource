#include<iostream>
using namespace std;

template<class T>
void search(T *arr,int n,T key)
{
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(key==arr[i])
		{
			cout<<i+1<<endl;
			flag=true;
			break;
		}
	}
	
	if(!flag) cout<<0<<endl;
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
			int *arr=new int[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			int key;
			cin>>key;
			search(arr,n,key);
		}
		else if(op=='D')
		{
			double *arr=new double[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			double key;
			cin>>key;
			search(arr,n,key);
		}
		else if(op=='C')
		{
			char *arr=new char[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			char key;
			cin>>key;
			search(arr,n,key);
		}
		else if(op=='S')
		{
			string *arr=new string[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			string key;
			cin>>key;
			search(arr,n,key);
		}
	} 
	return 0;
}
