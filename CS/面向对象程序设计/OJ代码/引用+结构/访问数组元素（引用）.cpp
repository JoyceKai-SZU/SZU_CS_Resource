#include<iostream>
using namespace std;
#define N 1000

int & put(int *num,int i)
{
	return num[i];
}


int main()
{
	int num[N];
	int t,n,sum,i;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			//int &temp=num[i];cin>>temp;   
			cin>>put(num,i);    //等价与上面的式子 
		}
		for(sum=0,i=0;i<n;i++)
			sum+=num[i];
		cout<<"sum="<<sum<<endl;
	}
	return 0;
}

/*
3
4 10 20 30 40
10 1 2 3 -1 -2 -3 1 2 3 4
5 0 0 0 0 10
*/

//output
/*
sum=100\n
sum=10\n
sum=10\n
*/ 
