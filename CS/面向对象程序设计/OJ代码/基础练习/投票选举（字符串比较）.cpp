#include<iostream>
#include<map>
using namespace std;

map<string,int> mp;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string name;
		cin>>name;
		mp[name]++;
	}
	cout<<"Li"<<":"<<mp["Li"]<<endl;
	cout<<"Zhang"<<":"<<mp["Zhang"]<<endl;
	cout<<"Fu"<<":"<<mp["Fu"]<<endl;
	return 0;
} 
