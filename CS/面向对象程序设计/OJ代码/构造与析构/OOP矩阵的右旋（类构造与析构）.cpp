#include<iostream>
using namespace std;

class Matrix{
private:
	int **g;
	int m,n;  //m*n的矩阵
public:
	Matrix(int pm,int pn);
	~Matrix();
	void rotate();
	void show();
};

Matrix::Matrix(int pm,int pn):m(pm),n(pn)
{
	g=new int*[m];
	for(int i=0;i<m;i++)
	{
		g[i]=new int [n];
		for(int j=0;j<n;j++) cin>>g[i][j];
	}
}

Matrix::~Matrix()
{
	for(int i=0;i<m;i++)
	{
		delete [] g[i];
	}
	delete [] g;
}

void Matrix::rotate()  //向右旋转90度
{
	for(int j=0;j<n;j++)
	{
		for(int i=m-1;i>=0;--i)
		{
			cout<<g[i][j];
			if(i) cout<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		Matrix mp(m,n);
		mp.rotate();
		cout<<endl;
	}
	return 0;
} 
