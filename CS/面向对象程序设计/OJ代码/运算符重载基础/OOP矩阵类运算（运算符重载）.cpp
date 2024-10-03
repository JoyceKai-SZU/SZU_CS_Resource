#include<iostream>
using namespace std;

class Matrix{
private:
	int m,n;
	int **g; 
public:
	Matrix(const Matrix &b)  //拷贝构造,注意是深拷贝 
	{
		m=b.m;
		n=b.n;
		g=new int*[m];
		for(int i=0;i<m;i++)
		{
			g[i]=new int[n];
			for(int j=0;j<n;j++)
			{
				g[i][j]=b.g[i][j];
			}
		}
		
		
	}
	Matrix(int m,int n):m(m),n(n)
	{
		g=new int*[m];
		for(int i=0;i<m;i++)
		{
			g[i]=new int[n];
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
	}
	
	void display()
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	Matrix operator + (const Matrix &b)
	{
		Matrix temp(b); 
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				temp.g[i][j]+=g[i][j];
			}
		}
		return temp;
	}
	
	Matrix operator - (const Matrix &b)
	{
		Matrix temp(*this); 
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				temp.g[i][j]-=b.g[i][j];
			}
		}
		return temp;
	}
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int row,col;
		cin>>row>>col;
		Matrix mp1(row,col);
		Matrix mp2(row,col);
		Matrix mpadd=mp1+mp2 ,mpsub=mp1-mp2;
		cout<<"Add:"<<endl;
		mpadd.display();
		cout<<"Minus:"<<endl;
		mpsub.display();
		cout<<"-----------------"<<endl;
	}
	return 0;
}



/*
2
4 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
9 8 7 6 5
4 3 2 1 0
-1 5 6 9 1
2 0 2 1 6
4 5
9 8 7 6 5
4 3 2 1 0
-1 5 6 9 1
2 0 2 1 6
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
*/

//output
/*
Add:\n
10 10 10 10 10 \n
10 10 10 10 10 \n
10 17 19 23 16 \n
18 17 20 20 26 \n
Minus:\n
-8 -6 -4 -2 0 \n
2 4 6 8 10 \n
12 7 7 5 14 \n
14 17 16 18 14 \n
-----------------\n
Add:\n
10 10 10 10 10 \n
10 10 10 10 10 \n
10 17 19 23 16 \n
18 17 20 20 26 \n
Minus:\n
8 6 4 2 0 \n
-2 -4 -6 -8 -10 \n
-12 -7 -7 -5 -14 \n
-14 -17 -16 -18 -14 \n
-----------------
*/ 
