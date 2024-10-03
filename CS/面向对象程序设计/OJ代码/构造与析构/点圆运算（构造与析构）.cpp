#include<iostream>
using namespace std;

class Point{
private:
	int x,y;
public:
	Point();
	Point(int px,int py);
	void setXY(int px,int py);
	int getX();
	int getY();
	~Point(); 
};

Point::Point(){}
Point::Point(int px,int py):x(px),y(py){}
Point::~Point()
{
	x=0,y=0;
	cout<<"point clear"<<endl;
}
int Point::getX(){return x;}
int Point::getY(){return y;}
void Point::setXY(int px,int py){x=px;y=py;}


class Circle{
private:
	int x,y,r;
public:
	Circle(int cx,int cy,int cr);
	~Circle();
	bool contain(int px,int py);
};

Circle::Circle(int cx,int cy,int cr):x(cx),y(cy),r(cr){}
Circle::~Circle()
{
	x=0,y=0,r=0;
	cout<<"circle clear"<<endl;
}

bool Circle::contain(int px,int py)
{
	return (x-px)*(x-px)+(y-py)*(y-py)<=r*r;
}

int main()
{
	int x1,y1;
	cin>>x1>>y1;
	Point p1(x1,y1);
	
	int n;
	cin>>n;
	Point *p=new Point[n];
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		p[i].setXY(x,y);
	}
	
	int cx,cy,r;
	cin>>cx>>cy>>r;
	Circle cir(cx,cy,r);
	
	if(cir.contain(p1.getX(),p1.getY())) cout<<"in"<<endl;
	else cout<<"out"<<endl;
	
	for(int i=0;i<n;i++)
	{
		if(cir.contain(p[i].getX(),p[i].getY())) cout<<"in"<<endl;
		else cout<<"out"<<endl;
	}
	
	return 0;
}
