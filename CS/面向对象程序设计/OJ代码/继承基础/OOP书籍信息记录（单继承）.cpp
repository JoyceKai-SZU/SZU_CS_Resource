#include<iostream>
using namespace std;

class Document{
protected:       //建议父类都用protected 
	string name;
public:
	Document(){cout<<"Create Document Class"<<endl;}
	Document(string name):name(name)
	{
		cout<<"Create Document Class"<<endl;
	} 
	~Document()
	{
		cout<<"Delete Document Class"<<endl;
	}
	void Print()
	{
		cout<<"Document Name is "<<name<<endl;
	}
};

class Book:public Document{
private:
	int PageCount;
public:
	Book(){cout<<"Create Book Class"<<endl;}
	Book(string name,int pc):Document(name),PageCount(pc)
	{
		cout<<"Create Book Class"<<endl;
	}
	~Book()
	{
		cout<<"Delete Book Class"<<endl;
	}
	void Print()
	{
		cout<<"Document Name is "<<name<<endl;
		cout<<"PageCount is "<<PageCount<<endl;
	}
};


int main()
{
	string name;
	int pc;
	cin>>name>>pc;
	Book b(name,pc);
	b.Print(); 
	return 0;
}
