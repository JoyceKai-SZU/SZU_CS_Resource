#include<iostream>
using namespace std;


class Member{
protected:
	int id,credit;
	string name;
public:
	Member(int i,int c,string nm):
		id(i),credit(c),name(nm){}
	virtual void Add(int d)
	{
		credit+=d;
	}
	
	virtual int Exchange(int num)
	{
		int temp=num/100;
		credit-=temp*100;
		return temp; 
	} 
	
	virtual void Print()
	{
		cout<<"普通会员"<<id<<"--"<<name<<"--"<<credit<<endl; 
	}
	
};

class VIP:public Member{
private:
	int addbl,exbl;
public:
	VIP(int i,int c,string nm,int ab,int eb):
		Member(i,c,nm),addbl(ab),exbl(eb){}
	
	void Add(int d)
	{
		credit+=d*addbl; 
	}
	
	int Exchange(int num)
	{
		int temp=num/exbl;
		credit-=temp*exbl;
		return temp; 
	} 

	
	void Print()
	{
		cout<<"贵宾会员"<<id<<"--"<<name<<"--"<<credit<<endl; 
	}
};


int main()
{
	Member *pm;
	int id,credit;
	string name;
	cin>>id>>name>>credit;
	Member mm(id,credit,name);
	pm=&mm;
	int d,num;
	cin>>d>>num;
	pm->Add(d);   //细心，指针用  -> 
	pm->Exchange(num);
	pm->Print();
	
	int addbl,exbl;
	cin>>id>>name>>credit>>addbl>>exbl;
	VIP vv(id,credit,name,addbl,exbl);
	pm=&vv;
	cin>>d>>num;
	pm->Add(d);
	pm->Exchange(num);
	pm->Print();
	
	return 0;
}

/*
1001 John 500
244 300 
8001 Jane 300 2 90
100 420

*/

//output
/*
普通会员1001--John--444\n
贵宾会员8001--Jane--140\n
*/
