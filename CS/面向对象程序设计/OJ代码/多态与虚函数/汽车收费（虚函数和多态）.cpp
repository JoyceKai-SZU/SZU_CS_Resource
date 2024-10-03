#include<iostream>
using namespace std;

class Vehicle{
protected:
	string no;//编号
public:
	Vehicle(string no):no(no){}
	virtual void display()=0;//应收费用

};

class Car:public Vehicle{
private:
	int load,w;
public:
	Car(string no,int load,int w):Vehicle(no)
	{
		this->load=load;this->w=w; 
	}
	void display()
	{
		cout<<no<<" "<<(load*8+w*2)<<endl;
	}
	
};

class Truck:public Vehicle{
private:
	int w;
public:
	Truck(string no,int w):Vehicle(no)
	{
		this->w=w; 
	}
	void display()
	{
		cout<<no<<" "<<(w*5)<<endl;
	}
};

class Bus:public Vehicle{
private:
	int load;
public:
	Bus(string no,int load):Vehicle(no)
	{
		this->load=load; 
	}
	void display()
	{
		cout<<no<<" "<<(load*3)<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	Vehicle *pv;
	while(t--)
	{
		int op;
		string no;
		cin>>op;
		switch(op)
		{
			case 1:
			{
				int load,w;
				cin>>no>>load>>w;
				Car c(no,load,w);
				pv=&c;
				pv->display();
				break;
			}
			case 2:
			{
				int w;
				cin>>no>>w;
				Truck t(no,w);
				pv=&t;
				pv->display();
				break;
			}
			case 3:
			{
				int load;
				cin>>no>>load;
				Bus b(no,load);
				pv=&b;
				pv->display();
				break;
			}
		}
	}
	
	return 0;
	
}
