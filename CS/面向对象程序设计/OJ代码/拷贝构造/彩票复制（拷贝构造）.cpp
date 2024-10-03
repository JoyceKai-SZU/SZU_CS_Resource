#include<iostream>
using namespace std;

class lottery{
private:
	int group1[6];
	int num;
	int **groupn;   //动态创建二维整数数组，共9行，每行包含6个号码。
public:
	lottery(int *a,int n);
	lottery(const lottery &b);
	void Print();
};

lottery::lottery(int *a,int n)
{
	num=n;
	for(int i=0;i<6;i++) group1[i]=a[i];
	
}

lottery::lottery(const lottery &b)
{
	num=b.num;
	groupn=new int *[9];
	for(int i=0;i<9;i++) groupn[i]=new int [6];
	
	for(int i=0;i<6;i++) group1[i]=b.group1[i];
	
	for(int j=0;j<6;j++)
	{
		if(j==0) groupn[0][0]=group1[5]+1;
		else groupn[0][j]=group1[j-1]+1; 
	} 
	
	for(int i=1;i<num;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(j==0) groupn[i][0]=groupn[i-1][5]+1;
			else groupn[i][j]=groupn[i-1][j-1]+1; 
		}
	}
	
	
}

void lottery::Print()
{
	for(int i=0;i<6;i++)
	{
		cout<<group1[i];
		if(i!=5) cout<<" ";
	}
	cout<<endl;
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<groupn[i][j];
			if(j!=5) cout<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int t;
	int *a=new int[6];
	cin>>t;
	while(t--)
	{
		int n;
		for(int i=0;i<6;i++) cin>>a[i];
		cin>>n;
		lottery l1(a,n);
		lottery l2(l1);
		l2.Print();
	}
	return 0;
}
