#include<iostream>
using namespace std;

const int m=2,n=3;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int **a=new int* [m];
		for(int i=0;i<m;i++)
		{
			a[i]=new int[n];
			for(int j=0;j<n;j++) cin>>a[i][j];
		}
		
		for(int j=n-1;j>=0;j--)
		{
			for(int i=0;i<m;i++)
			{
				cout<<*(*(a+i)+j)<<" "; 
			}
			cout<<endl;
		}
		
		
		
	}
	
	
	return 0;
} 
