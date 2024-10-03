#include<iostream>
using namespace std;

bool check(int num)
{
	if(num%6==0||num%10==6) return true;
	int x=num,ans=0;
	while(x)
	{
		ans++;
		x/=10;
	}
	if(ans==6) return true;
	return false;
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int num;
		cin>>num;
		if(check(num)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
