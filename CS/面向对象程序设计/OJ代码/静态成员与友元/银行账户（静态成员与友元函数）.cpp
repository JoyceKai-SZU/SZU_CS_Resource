#include<iostream>
#include<string>
using namespace std;

class Account{
private:
	static int count;
	static float InterestRate;
	string _accno,_accname;
	float _balance;
	static float total;
public:
	Account(string accno,string name,float balance);
	~Account();
	void Deposit(float amount);
	void Withdraw(float amount);
	float GetBalance();
	void show();
	static int GetCount();
	static float GetInterestRate();
	friend void Update(Account& a);
	
	static void setRate(){cin>>InterestRate;}
	void addTotal(){total+=_balance;}   //更新银行账户总余额 
	static float getTotal(){return total;}
};

int Account::count=0;
float Account::InterestRate=0.0;
float Account::total=0;


Account::Account(string accno,string name,float balance): _accno(accno), _accname(name),_balance(balance){count++;}
Account::~Account()
{
	count=0;
	InterestRate=0.0;
}

void Account::Deposit(float amount)
{
	_balance+=amount;
}

void Account::Withdraw(float amount)
{
	_balance-=amount;
}

float Account::GetBalance()
{
	return _balance;
}

void Account::show()
{
	cout<<_accno<<" "<<_accname<<" ";
}

int Account::GetCount()
{
	return count;
}

float Account::GetInterestRate()
{
	return InterestRate;
}

void Update(Account& a)  //友元函数 
{
	a._balance*=(1+Account::InterestRate);
}

int main()
{
	Account::setRate();
	int n;
	cin>>n;
	Account **s=new Account*[n];  //指针数组
	for(int i=0;i<n;i++)
	{
		string accno,name;
		float balance;
		float save,take;
		cin>>accno>>name>>balance>>save>>take;
		s[i]=new Account(accno,name,balance);
		s[i]->show();
		s[i]->Deposit(save);
		cout<<s[i]->GetBalance()<<" ";
		Update(*s[i]);
		cout<<s[i]->GetBalance()<<" ";
		s[i]->Withdraw(take);
		cout<<s[i]->GetBalance()<<endl;
		s[i]->addTotal(); 
	} 
	cout<<Account::getTotal()<<endl;
	
	if(s)    //析构掉 
	{
		for(int i=0;i<n;i++) delete s[i];
		delete[] s; 
	}
	
	return 0;
}


/*
0.01
3
201501 张三 10000 1000 2000
201502 李四 20000 2000 4000
201503 王二 80000 4000 6000
*/

//output
/*
201501 张三 11000 11110 9110\n
201502 李四 22000 22220 18220\n
201503 王二 84000 84840 78840\n
106170
*/
