#include<iostream>
using namespace std;
#define N 4

class CBlock {
	char arr[N][N]{};
public:
	CBlock(){} // 无参构造
	
	CBlock(const CBlock &a)
	{
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				arr[i][j]=a.arr[i][j];
	}
	
	CBlock& operator ++()
	{
		char temp[N][N];
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				temp[i][j]=arr[i][j];
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				arr[i][j]=temp[N-1-j][i];
		
		return *this;
	}
	
	CBlock operator ++(int)
	{
		CBlock temp(*this);
		
		char temp1[N][N];
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				temp1[i][j]=arr[i][j];
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				arr[i][j]=temp1[N-1-j][i];
		
		return temp;
	}
	
	CBlock& operator --()
	{
		char temp[N][N];
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				temp[i][j]=arr[i][j];
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				arr[i][j]=temp[j][N-1-i];
		
		return *this;
	}
	
	CBlock operator --(int)
	{
		CBlock temp(*this);
		
		char temp1[N][N];
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				temp1[i][j]=arr[i][j];
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				arr[i][j]=temp1[j][N-1-i];
		
		return temp;
	}
	
	friend istream & operator >> (istream &in,CBlock &a)
	{
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				in>>a.arr[i][j];
		
		return in;
	}
	
	friend ostream & operator << (ostream &out,CBlock &a)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				out<<a.arr[i][j];
			}
			if(i!=N-1) out<<endl;  //注意要加，否则格式错误 
		}
		
		return out;
	}
	
}; 


int main() {
	int n;
	cin >> n;
	while (n--) {
		CBlock block;
		cin>>block;
		switch(n&1) {
			case 0:	(++block)++; break;
			case 1: --(block--); break;
		}
		cout<<endl<<block<<endl;
	}
	return 0;
}
