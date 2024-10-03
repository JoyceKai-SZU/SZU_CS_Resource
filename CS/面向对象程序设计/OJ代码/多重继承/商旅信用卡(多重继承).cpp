#include<iostream>
using namespace std;


class VIPCard{
protected:
	int vid,vscore;
public:
	VIPCard(int vid,int vscore=0):vid(vid),vscore(vscore){}   //默认参数 
	void display()
	{
		cout<<vid<<" "<<vscore<<endl;
	}
};

class CreditCard{
protected:
	int cid,balance;  //balance额度
	string name;
	float value;  //金额
	int cscore;   //信用卡积分
public:
	CreditCard(int cid,string name,int balance,float value=0.0,int cscore=0):
		cid(cid),
		name(name),
		balance(balance),
		value(value),
		cscore(cscore)
	{
		
	} 
	void display()
	{
		cout<<cid<<" "<<name<<" "<<value<<" "<<cscore<<endl;
	} 
	
};

class Mycard:public VIPCard,public CreditCard{
public:
	Mycard(int vid,int cid,string name,int balance):
		VIPCard(vid),
		CreditCard(cid,name,balance)
	{
		
	}
	
	void display() 
	{
		VIPCard::display();
		CreditCard::display();
	}
	
	void oo(float m)
	{
		if(value+m>balance) return;
		
		value+=m;
		vscore+=(int)m;
		cscore+=(int)m;
		
	}
	
	void cc(float m)
	{
		if(value+m>balance) return;
		
		value+=m;
		cscore+=(int)m;
		
	}
	
	void qq(float m)
	{
		value-=m;
		cscore-=(int)m;
	}
	
	void tt(float m)
	{
		cscore-=m;   //注意不要忘了要减 
		vscore+=m/2.0;
	}
	
};


int main()
{
	int vid,cid;
	int n;
	string name;
	int balance;
	cin>>vid>>cid>>name>>balance;
	Mycard card(vid,cid,name,balance);
	cin>>n;
	while(n--)
	{
		char op;
		float m;
		cin>>op>>m;
		switch(op)
		{
			case 'o': card.oo(m);break;
			case 'c': card.cc(m);break;
			case 'q': card.qq(m);break;
			case 't': card.tt(m);break;
		} 
	} 
	
	card.display();
	
	
	return 0;
}
