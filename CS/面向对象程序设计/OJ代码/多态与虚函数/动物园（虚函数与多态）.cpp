#include<iostream>
using namespace std;

class Animal{
protected:
	string name;
	int age;
public:
	Animal(string name,int age):name(name),age(age){}
	virtual void Speak()=0;
};

class Tiger:public Animal{
public:
	Tiger(string name,int age):Animal(name,age){}
	void Speak()
	{
		cout<<"AOOO";
	}
};

class Dog:public Animal{
public:
	Dog(string name,int age):Animal(name,age){}
	void Speak()
	{
		cout<<"WangWang";
	}
};

class Duck:public Animal{
public:
	Duck(string name,int age):Animal(name,age){}
	void Speak()
	{
		cout<<"GAGA";
	}
};

class Pig:public Animal{
public:
	Pig(string name,int age):Animal(name,age){}
	void Speak()
	{
		cout<<"HENGHENG";
	}
};

int main()
{
	int t;
	cin>>t;
	Animal *ani;
	while(t--)
	{
		string type,name;
		int age;
		cin>>type>>name>>age;
		if(type=="Tiger")
		{
			Tiger t(name,age);
			ani=&t;
			cout<<"Hello,I am "<<name<<",";
			ani->Speak();
			cout<<"."<<endl;
		}
		else if(type=="Pig")
		{
			Pig p(name,age);
			ani=&p;
			cout<<"Hello,I am "<<name<<",";
			ani->Speak();
			cout<<"."<<endl;
		}
		else if(type=="Duck")
		{
			Duck d(name,age);
			ani=&d;
			cout<<"Hello,I am "<<name<<",";
			ani->Speak();
			cout<<"."<<endl;
		} 
		else if(type=="Dog")
		{
			Dog dg(name,age);
			ani=&dg;
			cout<<"Hello,I am "<<name<<",";
			ani->Speak();
			cout<<"."<<endl;
		}
		else
		{
			cout<<"There is no "<<type<<" in our Zoo."<<endl;
		}
	}
	
	return 0;
}
