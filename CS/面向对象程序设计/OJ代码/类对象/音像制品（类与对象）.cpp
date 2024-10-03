#include<iostream>
using namespace std;

class Product{
private:
	int type;
	string name;
	int rent;
	int state;
public:
	Product(int type,string name,int rent,int state);
	void Print();
	int countRent(int d); 
	int getState();
	string getType();
};

Product::Product(int type,string name,int rent,int state)
{
	this->type=type;
	this->name=name;
	this->rent=rent;
	this->state=state;	
}

void Product::Print()
{
	cout<<getType()<<"["<<name<<"]"<<(state==0?"not rented":"rented")<<endl;
}

int Product::countRent(int d)
{
	return d*rent;
}

int Product::getState(){return state;} 

string Product::getType()
{
	switch(type)
	{
		case 1:return "BF";
		case 2:return "CD";
		case 3:return "VCD";
		case 4:return "DVD";
	}
}


int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int type,rent,state;
		string name;
		cin>>type>>name>>rent>>state;
		Product p(type,name,rent,state);
		
		int d;
		cin>>d;
		if(!d) p.Print();
		else
		{
			p.Print();
			if(!p.getState()) cout<<"No rental"<<endl;
			else cout<<"Rental: "<<p.countRent(d)<<endl;
		}
	}
	return 0;
}
