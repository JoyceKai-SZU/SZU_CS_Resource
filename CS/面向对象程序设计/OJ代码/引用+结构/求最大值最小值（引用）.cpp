#include<iostream>
using namespace std;

void find(int *num,int n,int &minIndex,int &maxIndex)
{
	int Mx=num[0];
	for(int i=0;i<n;i++)
	{
		if(Mx<num[i])
		{
			 Mx=num[i];
			 maxIndex=i;
		}
	}
	
	int Min=num[0];
	for(int i=0;i<n;i++)
	{
		if(Min>num[i])
		{
			 Min=num[i];
			 minIndex=i;
		}
	}
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int *num=new int[n];
		for(int i=0;i<n;i++) cin>>num[i];
		
		int minIndex=0, maxIndex=0;
		find(num,n,minIndex,maxIndex);
		cout<<"min="<<num[minIndex]<<" "<<"minindex="<<minIndex<<endl;
		cout<<"max="<<num[maxIndex]<<" "<<"maxindex="<<maxIndex<<endl;
		cout<<endl;
		delete[] num;    //动态分配内存最后要delete掉 
	} 
	return 0;
}
