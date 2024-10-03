#include<iostream>
#include<map>
using namespace std;

template<class T>
void search(T *arr,int n)
{
	map<T,int> mp;
	for(int i=0;i<n;i++) mp[arr[i]]++;
	
	int idx=0;
	for(int i=1;i<n;i++)
	{
		if(mp[arr[i]]>mp[arr[idx]]) idx=i;
	}
	cout<<arr[idx]<<" "<<mp[arr[idx]]<<en
dl;
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
			search(arr,n);
		}
		else if(op=='C')
		{
			char *arr=new char[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			search(arr,n);
		}
		else if(op=='S')
		{
			string *arr=new string[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			search(arr,n);
		}
	}
	
	return 0;
}
