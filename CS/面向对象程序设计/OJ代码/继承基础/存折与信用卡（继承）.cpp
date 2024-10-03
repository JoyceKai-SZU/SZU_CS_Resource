#include<iostream>
#include<cstring>
using namespace std;

class CAccount{
protected:
	long account;
	char name[10];
	float balance;  //”‡∂Ó 
public:
	CAccount(){}
	CAccount(long a,char *n,float b):account(a),balance(b)
	{
		strcpy(name,n);
	}
	void deposit(float d)
	{
		 balance+=d;
		 cout<<"saving ok!" <<endl;
	}
	void withdraw(float d)
	{
		if(balance-d<0) cout<<"sorry! over balance!"<<endl;
		else
		{
			balance-=d;
			cout<<"withdraw ok!"<<endl;
		}
	}
	void check()
	{
		cout<<"balance is "<<balance<<endl;
	}
}; 

class CCreditcard:public CAccount{
private:
	float limit;
public:
	CCreditcard(){}
	CCreditcard(long a,char *n,float b,float lim):CAccount(a,n,b),limit(lim){}
	void withdraw(float d)
	{
		if(balance-d<(-limit)) cout<<"sorry! over limit!"<<endl;
		else
		{
			balance-=d;
			cout<<"withdraw ok!"<<endl;
		}	
	}
};

int main()
{
	char *name=new char[10];
	long acco;
	float bal;
	float d;    //¥ÊøÓ£¨»°øÓ 
	cin>>acco>>name>>bal;
	CAccount ca(acco,name,bal);
	ca.check();
	cin>>d;
	ca.deposit(d);
	ca.check();
	cin>>d;
	ca.withdraw(d);
	ca.check();
	
	float lim;
	cin>>acco>>name>>bal>>lim;
	CCreditcard cc(acco,name,bal,lim);
	cc.check();
	cin>>d;
	cc.deposit(d);
	cc.check();
	cin>>d;
	cc.withdraw(d);
	cc.check();
	
	return 0;
}
