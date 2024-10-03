#include<iostream>
using namespace std;

int **arr;
int m,n;

int findmax()
{
	int res=arr[0][0];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(res<arr[i][j]) res=arr[i][j];
		}
	}
	return res;
}

int findmin()
{
	int res=arr[0][0];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(res>arr[i][j]) res=arr[i][j];
		}
	}
	return res;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		arr=new int*[m];
		for(int i=0;i<m;i++) 
		{
			arr[i]=new int[n];
			for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
			}
		}
		
		int MAX=findmax();
		int MIN=findmin();
		cout<<MIN<<" "<<MAX<<endl;
		
	}
	
	return 0;
} 
