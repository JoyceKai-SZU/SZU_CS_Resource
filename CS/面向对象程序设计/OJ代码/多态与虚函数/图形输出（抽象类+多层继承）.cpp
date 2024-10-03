#include<iostream>
using namespace std;
double PI=3.14159;

class Shape{
protected:
	string name;
	double x,y;
public:
	Shape(double xx,double yy):x(xx),y(yy){}
	virtual string getName(){shapeName();return name;}   //在这里调用shapeName比较方便 
	virtual double getX(){return x;}
	virtual double getY(){return y;}
	virtual double getArea(){return 0.0;}
	virtual double getVolume(){return 0.0;}
	virtual void shapeName()=0;                  
};

class Point:public Shape{
public:
	Point(double xx,double yy):Shape(xx,yy){}    //不能设置名称 
	void shapeName()
	{
		name="Point";
	}
	
};

class Circle:public Point{
protected:
	double r;
public:
	Circle(double xx,double yy,double rr):r(rr),Point(xx,yy){}   //不能设置名称
	double getArea(){return PI*r*r;}
	void shapeName()
	{
		name="Circle";
	}
	
};

class Cylinder:public Circle{
protected:
	double h;
public:
	Cylinder(double xx,double yy,double rr,double hh):h(hh),Circle(xx,yy,rr){}   //不能设置名称
	double getArea()
	{
		return 2*PI*r*r+2*PI*r*h;
	}
	
	double getVolume(){return Circle::getArea()*h;}    //有坑 
	
	void shapeName()
	{
		name="Cylinder";
	}
};

void Print(Shape *p)
{
	cout<<p->getName()<<"--("<<p->getX()<<","<<p->getY()<<")--"<<(int)p->getArea()<<"--"<<(int)p->getVolume()<<endl; 
}
int main()
{
	double x,y,r,h;
	cin>>x>>y;
	Shape *p=new Point(x,y);   //抽象类创建
	Print(p);
	cin>>x>>y>>r;
	Shape *c=new Circle(x,y,r); 
	Print(c);
	cin>>x>>y>>r>>h;
	Shape *cy=new Cylinder(x,y,r,h);
	Print(cy);
	return 0;
}


/* 
1.1 2.2
3.3 4.4 5.5
6.6 7.7 8.8 9.9
*/

//output
/*
Point--(1.1,2.2)--0--0\n
Circle--(3.3,4.4)--95--0\n
Cylinder--(6.6,7.7)--1033--2408\n
*/ 
