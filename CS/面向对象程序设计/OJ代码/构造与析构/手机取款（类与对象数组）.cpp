#include<iostream>
using namespace std;

class Account{
private:
	int id,phone,key,money;
public:
	Account();
	void set(int id,int phone,int key,int money);
	void withdraw(int d);
	bool check(int pwd);
	int getPhone(){return phone;}
	
};

Account::Account():id(0),phone(0),key(0),money(0){}
void Account::set(int id,int phone,int key,int money)
{
	this->id=id;this->phone=phone;this->key=key;this->money=money; 
}


void Account::withdraw(int d)
{
	if(money-d<0) cout<<"����"<<id<<"-����"<<endl;
	else
	{
		money-=d;
		cout<<"����"<<id<<"-���"<<money<<endl;
	}
}


bool Account::check(int pwd)   //�������Ƿ��Ӧ���� 
{
	return pwd==key;
}



int main()
{
	int n,k;
	cin>>n;
	Account *s=new Account[n];
	for(int i=0;i<n;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		s[i].set(a,b,c,d);
	}
	
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int sphone,skey,take;
		cin>>sphone>>skey>>take;
		
		int flag=0;
		
		for(int j=0;j<n;j++)   //�鵽���û���������� 
		{
			if(s[j].getPhone()==sphone)
			{
				flag=1;
				if(!s[j].check(skey))
				{
					cout<<"�������"<<endl;
					break; 
				} 
				
				s[j].withdraw(take);
			}
		}
		
		if(!flag)
		{
			cout<<"�ֻ��Ų�����"<<endl;	
		} 
	}
	
	return 0;
} 
