#include<iostream>
using namespace std;
char* m[]={"","January","February","March","April","May","June","July","August","September","October","November","December"};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int id;
		cin>>id;
		if(id<1||id>12) cout<<"error"<<endl;
		else cout<<m[id]<<endl;
	}
	return 0;
}

 
