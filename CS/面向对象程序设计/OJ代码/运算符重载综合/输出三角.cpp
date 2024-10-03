#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int k=n;  //Ã¶¾Ù"*"ÊıÁ¿  
	
	for(int i=0;i<=n/2;i++)
	{
		for(int j=0;j<(n-k)/2;j++) cout<<" ";
		for(int j=0;j<k;j++) cout<<"*";
		cout<<endl; 
		k=k-2;
	} 
	
	k=3;  
	for(int i=1;i<=n/2;i++)
	{
		for(int j=0;j<(n-k)/2;j++) cout<<" ";
		for(int j=0;j<k;j++) cout<<"*";
		cout<<endl;
		k=k+2;
	}
	
	return 0;
} 
