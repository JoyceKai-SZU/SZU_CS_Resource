#include<iostream>
using namespace std;

int N,M;
int a[110][110];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)
			for(int ans=0;ans<M;ans++)
				cin>>a[i][ans];
		
		for(int ans=M-1;ans>=0;ans--)
		{
			for(int i=0;i<N;i++)
			{
				cout<<a[i][ans];
				if(i!=N-1) cout<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
