#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
	int id1,id2;
	char sex;
	string name;
	float sum;
	cin>>id1>>id2>>sex>>name>>sum;
	cout<<name<<endl;
	cout<<id1<<" "<<id2<<endl;
	cout<<sex<<endl;
	cout<<fixed<<setprecision(1)<<sum<<endl;
	return 0; 
	 
} 
