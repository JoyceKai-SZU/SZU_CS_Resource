#include<iostream>
using namespace std;


struct person{
	string name;
	int time;
	int sum;
}s[6];

int main()
{
	for(int i=0;i<5;i++)
	{
		cin>>s[i].name>>s[i].time>>s[i].sum; 
	}
	
	cout<<"ԭʼ����"<<endl;
	cout<<"���� ���� ����"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<s[i].name<<" "<<s[i].time<<" "<<s[i].sum<<endl;
	} 
	
	cout<<"��н����"<<endl;
	cout<<"���� ���� ����"<<endl;
	for(int i=0;i<5;i++)
	{
		if(s[i].time>=30) s[i].sum+=100; 
		cout<<s[i].name<<" "<<s[i].time<<" "<<s[i].sum<<endl;
	} 
	return 0;
}
