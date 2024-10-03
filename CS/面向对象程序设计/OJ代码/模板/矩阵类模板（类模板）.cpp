#include<iostream>
using namespace std;

template<class T>
class Matrix{    
private:
	T **g;
	int m,n;
public:
	Matrix(int mm,int nn):m(mm),n(nn) 
	{
		//cin>>m>>n;
		g=new T* [m];
		for(int i=0;i<m;i++)
		{
			g[i]=new T [n];
			for(int j=0;j<n;j++) cin>>g[i][j];
		}
	} 
	
	~Matrix()
	{
		for(int i=0;i<m;i++) delete[] g[i];
		
		delete[] g;
	}
	
	Matrix(const Matrix &a):m(a.m),n(a.n)  //Éî¿½±´ 
	{
		g=new T* [m];
		for(int i=0;i<m;i++)
		{
			g[i]=new T [n];
			for(int j=0;j<n;j++) g[i][j]=a.g[i][j];
		}
	}
	
	void transport()
	{
		Matrix temp=*this;
		
		swap(m,n);
		
		g=new T* [m];
		for(int i=0;i<m;i++)
		{
			g[i]=new T [n];
			for(int j=0;j<n;j++) g[i][j]=temp.g[j][i];
		}
		
	}
	
	void print()
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<g[i][j];
				if(j!=n-1) cout<<" ";
			}
			cout<<endl;
		}
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char op;
		int m,n;
		cin>>op>>m>>n;
		if(op=='I')
		{
			Matrix<int> mp(m,n);
			mp.transport();
			mp.print();
		}
		else if(op=='D')
		{
			Matrix<double> mp(m,n);
			mp.transport();
			mp.print();
		}
		else if(op=='C')
		{
			Matrix<char> mp(m,n);
			mp.transport();
			mp.print();
		}
	}
	return 0;
}

/*
2
I 2 3
1 2 3
4 5 6
C 3 3
a b c
d e f
g h i
*/

//output
/*
1 4\n
2 5\n
3 6\n
a d g\n
b e h\n
c f i
*/
