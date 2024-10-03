#include<iostream>
using namespace std;

int N;
int **a;
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int d=0;
int cnt=1;
void dfs(int x,int y)   //深搜 
{
	if(a[x][y]) //遇到已经访问过的了 ,剪枝 
	{
		return;
	}
	
	if(cnt==N*N+1) return;  //结束标志一定等于个数+1 
	
	
	a[x][y]=cnt++;
	int tox=x+dir[d][0], toy=y+dir[d][1];
	if(tox>=0&&tox<N&&toy>=0&&toy<N&&!a[tox][toy])  //!a[tox][toy]要放这里 
	{
	
		dfs(tox,toy);
		
	}
	else
	{
		d=(d+1)%4;
		tox=x+dir[d][0];toy=y+dir[d][1];  //重新赋值
		
		if(tox>=0&&tox<N&&toy>=0&&toy<N&&!a[tox][toy])  //!a[tox][toy]要放这里 
		{
		
			dfs(tox,toy);
			
		}
		
	}
}




int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>N;
		a=new int*[N];
		for(int i=0;i<N;i++)    //动态分配二维数组 
		{
			a[i]=new int [N];
			for(int j=0;j<N;j++) a[i][j]=0; 
		} 
		
		cnt=1;
		d=0;
		dfs(0,0);
		
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
