#include<iostream>
#include<cstring>
using namespace std;

class CAccount{
private:
	long account;
	char name[10];
	float balance;  //”‡∂Ó
public:
	CAccount(long a,char *str,float b);
	void deposit(int m);
	void withdraw(int m);
	void check(); 
	
}; 

CAccount::CAccount(long a,char *str,float b):account(a),balance(b)
{
	strcpy(name,str);
}

void CAccount::deposit(int m)
{
	balance+=m;
	cout<<"saving ok!"<<endl;
}

void CAccount::withdraw(int m)
{
	if(balance-m<0)
	{
		cout<<"sorry! over limit!"<<endl;
		return;
	}
	
	balance-=m;
	cout<<"withdraw ok!"<<endl;
}

void CAccount::check()
{
	cout<<name<<"'s balance is "<<balance<<endl;
}

int main()
{
	long a1,a2;
	char *name1=new char[10];
	char *name2=new char[10];
	float b1,b2;
	cin>>a1>>name1>>b1;
	CAccount p1(a1,name1,b1);
	p1.check();
	int save,take;
	cin>>save;
	p1.deposit(save);
	p1.check();
	cin>>take;
	p1.withdraw(take);
	p1.check();
	
	cin>>a2>>name2>>b2;
	CAccount p2(a2,name2,b2);
	p2.check();
	cin>>save;
	p2.deposit(save);
	p2.check();
	cin>>take;
	p2.withdraw(take);
	p2.check();
	
	
	
	
	return 0;
}






