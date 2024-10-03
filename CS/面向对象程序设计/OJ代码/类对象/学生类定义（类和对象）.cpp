#include<iostream>
using namespace std;

class Stu{
private:
	string name;
	long long id;
	string college,major,sex,addr;
	long long phone;
public:
	Stu(string name,long long id,string college,string major,string sex,string addr,long long phone);
	void Print();
};

Stu::Stu(string name,long long id,string college,string major,string sex,string addr,long long phone)
{
	this->name=name;
	this->id=id;
	this->college=college;
	this->major=major;
	this->sex=sex;
	this->addr=addr;
	this->phone=phone; 
}

void Stu::Print()
{
	cout<<name<<" "<<id<<" "<<college<<" "<<major<<" "<<sex<<" "<<addr<<" "<<phone<<endl;
}

int main()
{
	int n;
	cin>>n;
	
    while(n--)
    {
    	string name;
		long long id;
		string college,major,sex,addr;
		long long phone;
		cin>>name>>id>>college>>major>>sex>>addr>>phone;
		Stu s(name,id,college,major,sex,addr,phone);
		s.Print(); 
	}
	
	return 0;
} 
