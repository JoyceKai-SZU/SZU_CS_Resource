#include<iostream>
#include<cstring>
using namespace std;

class Date{
private:
	int y,m,d;
public:
	Date(){}
	Date(int y,int m,int d):y(y),m(m),d(d){}
	void show(){cout<<y<<"."<<m<<"."<<d;}
};


class Phone{
private:
	char type;
	string num;
	int state;
	Date *date=NULL;
public:
	Phone(char type,string num,int state,int y,int m,int d)
	{
		this->type=type;
		this->num=num;
		this->state=state;
		this->date=new Date(y,m,d);
		cout<<"Construct a new phone "<<num<<endl;
	}
	
	Phone(const Phone &b)
	{
		cout<<"Construct a copy of phone "<<b.num<<endl;
		type='D';
		num=b.num;
		num+='X';
		state=b.state;
		date=new Date;
		*date=*b.date;
		
	}
	
	void Print()
	{
		cout<<"����="; 
		
		if(type=='A') cout<<"����";
		else if (type=='B') cout<<"��ҵ";
		else if (type=='C')cout<<"����";
		else cout<<"����"; 
		
		cout<<"||����=" <<num<<"||State=";
		
		if(state==1) cout<<"����";
		else if(state==2) cout<<"δ��"; 
		else  cout<<"ͣ��";
		
		if(state==3)
		{
			cout<<" ||ͣ������=";
			date->show();
			cout<<endl;
		}
		else cout<<endl;
	}
	
	void stop()
	{
		state=3;
		cout<<"Stop the phone "<<num<<endl;
	}
	
	~Phone()
	{
		delete date;
	}
	
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char type;
		string num;
		int state,y,m,d;
		cin>>type>>num>>state>>y>>m>>d;
		Phone p1(type,num,state,y,m,d);
		p1.Print();
		Phone p2(p1);
		p2.Print();
		p1.stop();
		p1.Print();
		cout<<"----"<<endl;
	}
	return 0;
} 
