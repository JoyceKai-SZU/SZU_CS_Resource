#include<iostream>
#include<cstring> 
using namespace std;

class Customer{
private:
	static int TotalCusNum;
	static int Rent;
	static int Year;
	int CustID;
	
	char* CustName;
public:
	Customer(char *name);
	~Customer();
	
	static void changeYear(int r);
	void Display();
}; 

int Customer::TotalCusNum=0;
int Customer::Rent=150;
int Customer::Year=2014;


Customer::Customer(char *name)
{
	CustName=new char[10];
	strcpy(CustName,name);
	TotalCusNum++;
	CustID=Year*10000+TotalCusNum;
}

void Customer::changeYear(int r)
{
	Year=r;
}

void Customer::Display()
{
	cout<<CustName<<" "<<CustID<<" "<<TotalCusNum<<" "<<Rent<<endl;
	Rent+=150; 
}

Customer::~Customer()
{
	delete [] CustName;
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
		while(1)
		{
			cin>>name;
			if(strcmp(name,"0")==0) break;  //ÅÐ¶Ïchar´®ÏàµÈ 
			
			Customer c(name);
			c.Display();
		} 
	}
	return 0;
} 
