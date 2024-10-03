#include<iostream>
using namespace std;

class CPoint{
private:
	int x,y;
public:
	CPoint(){}
	CPoint(int px,int py):x(px),y(py){}
}; 

class CCircle:public CPoint{
private:
	int r;
public:
	CCircle(){}
	CCircle(int px,int py,int cr):CPoint(px,py),r(cr){}
	double getArea();
};

double CCircle::getArea()
{
	return 3.14*r*r;
}

class CCylinder:public CCircle{
private:
	int h;
public:
	CCylinder(){}
	CCylinder(int px,int py,int cr,int hh):CCircle(px,py,cr),h(hh){}
	double getVolume();
};

double CCylinder::getVolume()
{
	return getArea()*h;
}

int main()
{
	int cx,cy,cr;
	cin>>cx>>cy>>cr;
	CCircle cir(cx,cy,cr);
	cout<<"Circle:("<<cx<<","<<cy<<"),"<<cr<<endl;
	cout<<"Area:"<<cir.getArea()<<endl;
	
	int ch;
	cin>>cx>>cy>>cr>>ch;
	CCylinder cyl(cx,cy,cr,ch);
	cout<<"Cylinder:("<<cx<<","<<cy<<"),"<<cr<<","<<ch<<endl;
	cout<<"Volume:"<<cyl.getVolume()<<endl;
	
	return 0;
}
