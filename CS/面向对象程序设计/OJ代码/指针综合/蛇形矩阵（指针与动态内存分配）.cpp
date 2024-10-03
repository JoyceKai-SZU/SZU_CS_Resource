#include<iostream>
using namespace std;

int **a;
int N;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>N;
		a=new int*[N];
		for(int i=0;i<N;i++)
		{
			a[i]=new int[N];
			for(int j=0;j<N;j++) a[i][j]=0;
		}
		
		
		a[0][0]=1;
		int i=0,j=0;
		int k=1;
		while(k<N*N)
		{
			while(j+1<N&&!a[i][j+1]) a[i][++j]=++k;
			while(i+1<N&&!a[i+1][j]) a[++i][j]=++k;
			while(j-1>=0&&!a[i][j-1]) a[i][--j]=++k;
			while(i-1>=0&&!a[i-1][j]) a[--i][j]=++k;
		}
		
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<a[i][j];
				if(j!=N-1) cout<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
	}
	return 0; 
}

/*
3
3
6
2
*/

//output
/*
1 2 3\n
8 9 4\n
7 6 5\n
\n
1 2 3 4 5 6\n
20 21 22 23 24 7\n
19 32 33 34 25 8\n
18 31 36 35 26 9\n
17 30 29 28 27 10\n
16 15 14 13 12 11\n
\n
1 2\n
4 3
*/ 
