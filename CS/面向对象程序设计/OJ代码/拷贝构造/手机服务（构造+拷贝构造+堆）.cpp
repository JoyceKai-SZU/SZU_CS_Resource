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
		cout<<"类型="; 
		
		if(type=='A') cout<<"机构";
		else if (type=='B') cout<<"企业";
		else if (type=='C')cout<<"个人";
		else cout<<"备份"; 
		
		cout<<"||号码=" <<num<<"||State=";
		
		if(state==1) cout<<"在用";
		else if(state==2) cout<<"未用"; 
		else  cout<<"停用";
		
		if(state==3)
		{
			cout<<" ||停机日期=";
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
