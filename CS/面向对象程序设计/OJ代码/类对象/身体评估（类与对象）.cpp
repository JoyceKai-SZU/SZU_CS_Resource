#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Person{
private:
	string name;
	double h,w,wid;
public:
	Person(string name,double h,double w,double wid);
	int BMICount();
	double BFR();
	void Print();
};

Person::Person(string name,double h,double w,double wid)
{
	this->name=name;
	this->h=h;
	this->w=w;
	this->wid=wid;
}

int Person::BMICount()
{
	return round(w/(h*h));   //ËÄÉáÎåÈë 
}

double Person::BFR()
{
	double a=wid*0.74;
	double b=w*0.082+34.89;
	double kg=a-b;
	return kg/w;
}

void Person::Print()
{
	cout<<name<<"'s "<<"BMI: "<<BMICount()<<"--"<<"BFR: "<<fixed<<setprecision(2)<<BFR()<<endl; 
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string name;
		double h,w,wid;
		cin>>name>>h>>w>>wid;
		Person p(name,h,w,wid);
		p.Print();
	}
	return 0;
}
