#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x1,y1,z1;
		int x2,y2,z2; 
		cin>>x1>>y1>>z1;
		cin>>x2>>y2>>z2;
		if((x1<=x2&&y1<=y2&&x1*y1*z1<=x2*y2*z2)||(x1>=x2&&y1>=y2&&x1*y1*z1>=x2*y2*z2)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		
	}
	return 0;
}
