#include<iostream>
#include<algorithm> 
using namespace std;

template<class T>
void pailie(T *arr,int n)
{
	next_permutation(arr,arr+n); 
} 

template<class T>
void show(T *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
		if(i!=n-1) cout<<" ";
	}
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
			int *arr=new int[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			pailie(arr,n);
			show(arr,n);	
		}
		else if(op=='C')
		{
			char *arr=new char[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			pailie(arr,n);
			show(arr,n);	
		}
		else if(op=='D')
		{
			double *arr=new double[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			pailie(arr,n);
			show(arr,n);	
		}
		else if(op=='S')
		{
			string *arr=new string[n];
			for(int i=0;i<n;i++) cin>>arr[i];		
			pailie(arr,n);
			show(arr,n);
			
		}

	}
	return 0;
}

