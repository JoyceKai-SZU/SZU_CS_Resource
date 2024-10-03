#include<iostream>
#include<iomanip>
using namespace std;

float dollar=6.2619;
float eu=6.6744;
float jp=0.0516;
float hk=0.8065;

const float *d;

int main()
{
	int t;
	char type;
	float num;
	cin>>t;
	while(t--)
	{
		cin>>type>>num;
		switch(type)
		{
			case 'D':d=&dollar;cout<<fixed<<setprecision(4)<<num*(*d)<<endl;break;
			case 'E':d=&eu;cout<<fixed<<setprecision(4)<<num*(*d)<<endl;break;
			case 'Y':d=&jp;cout<<fixed<<setprecision(4)<<num*(*d)<<endl;break;
			case 'H':d=&hk;cout<<fixed<<setprecision(4)<<num*(*d)<<endl;break;
		} 
	} 
	return 0;
}
