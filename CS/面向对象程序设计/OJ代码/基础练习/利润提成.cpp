#include<iostream>
using namespace std;

int main()
{
	int num;
	cin>>num;
	int ans=0;
	int x=num/100000;
	if(x>=10) x=10;
	switch(x)
	{
		case 0:ans=num*0.1;break;
		case 1:ans=100000*0.1+(num-100000)*0.075;break;
		case 2:
		case 3:ans=100000*0.1+(200000-100000)*0.075+(num-200000)*0.05;break;
		case 4:
		case 5:ans=100000*0.1+(200000-100000)*0.075+(400000-200000)*0.05+(num-400000)*0.03;break;
		case 6:
		case 7:
		case 8:
		case 9:ans=100000*0.1+(200000-100000)*0.075+(400000-200000)*0.05+(600000-400000)*0.03+(num-600000)*0.015;break;
		case 10:ans=100000*0.1+(200000-100000)*0.075+(400000-200000)*0.05+(600000-400000)*0.03+(1000000-600000)*0.015+(num-1000000)*0.01;

	}
	cout<<ans<<endl;
	return 0;
}
