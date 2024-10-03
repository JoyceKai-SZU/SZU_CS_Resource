#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Customer{
public:
	Customer(char *name);
	~Customer();
	static void changeYear(int r);
	void Display();
private:
	static int TotalCustNum;
	static int Rent;
	static int Year;
	int CustID;
	char *CustName;
};

int Customer::TotalCustNum=0;
int Customer::Rent=150;
int Customer::Year=2014;

Customer::Customer(char *name)
{
	CustName=new char[10];
	strcpy(CustName,name);
	TotalCustNum++;
	CustID=TotalCustNum;
}

Customer::~Customer()
{
	delete [] CustName;
}

void Customer::changeYear(int r)
{
	Year=r;
}

void Customer::Display()
{
	cout<<CustName<<" "<<Customer::Year;
	cout<<setfill('0')<<setw(4)<<CustID<<" ";
	cout<<Customer::TotalCustNum<<" "<<Customer::Rent<<endl;
	Customer::Rent+=150;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int y;
		cin>>y;
		Customer::changeYear(y);
		char *name=new char[10];
		string str;
		cin>>str;
		while(1)
		{
			strcpy(name,str.c_str());
			Customer c(name);
			c.Display();
			cin>>str;
			if(str=="0") break;
		}
	}
	return 0;
}
