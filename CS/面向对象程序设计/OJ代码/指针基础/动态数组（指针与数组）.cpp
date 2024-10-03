#include<iostream>
#include<iomanip>
using namespace std;




int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		char type;
		cin>>type>>n; 
		if(type=='C')
		{
			char *a=new char [n];
			for(int i=0;i<n;i++) cin>>*(a+i);
			char mx=*a;
			for(int i=0;i<n;i++) 
			{
				if(mx<*(a+i)) mx=*(a+i);
			}
			cout<<mx<<endl;
			
		}
		else if(type=='I')
		{
			int *b=new int[n];
			for(int i=0;i<n;i++) cin>>*(b+i);
			double sum=0;
			for(int i=0;i<n;i++) sum+=*(b+i);
			cout<<fixed<<setprecision(0)<<sum/n<<endl;
			
		}
		else
		{
			float *c=new float [n];
			for(int i=0;i<n;i++) cin>>*(c+i);
			float Min=*c;
			for(int i=0;i<n;i++) 
			{
				if(Min>*(c+i)) Min=*(c+i);
			}
			cout<<fixed<<setprecision(1)<<Min<<endl;
		}
	}
	return 0;
}
