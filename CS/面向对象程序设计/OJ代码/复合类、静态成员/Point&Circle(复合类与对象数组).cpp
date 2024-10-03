#include<iostream>
#include<cmath>
using namespace std;

class Point{
	double x,y;
public:
	Point();         //不管写什么类都要写无参构造函数 
	Point(double x_value,double y_value);
	double getX();
	double getY();
	void setXY(double x1,double y1);
	void setX(double x_value);
	void setY(double y_value);
	double getDisTo(Point &p);
	~Point();
};

Point::Point():x(0),y(0){}
Point::Point(double x_value,double y_value):x(x_value),y(y_value){}
double Point::getX(){return x;}
double Point::getY(){return y;}
void Point::setXY(double x1,double y1){x=x1;y=y1;}
void Point::setX(double x_value){x=x_value;}
void Point::setY(double y_value){y=y_value;}
Point::~Point(){x=0;y=0;}
double Point::getDisTo(Point &p)
{
	return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}


class Circle{
	Point centre;
	double radius;
public:
	Circle();
	Circle(double x,double y,double r);
	double getArea();
	void moveCentreTo(double x1,double y1);
	int contain(Point &p);
};

Circle::Circle():radius(1)
{
	centre.setXY(0,0);
}

Circle::Circle(double x,double y,double r):centre(x,y),radius(r){}

void Circle::moveCentreTo(double x1,double y1)
{
	centre.setXY(x1,y1);
}

double Circle::getArea()
{
	return 3.14*radius*radius;
}

int Circle::contain(Point &p)
{
	return centre.getDisTo(p)<=radius;

}

int main()
{
	double cx,cy,r;
	int n;
	cin>>cx>>cy>>r;
	Circle c(cx,cy,r);
	cin>>n;
	Point *s=new Point[n];
	for(int i=0;i<n;i++)
	{
		double x,y;
		cin>>x>>y;
		s[i].setXY(x,y);
	}
	
	for(int i=0;i<n;i++)
	{
		if(c.contain(s[i])) cout<<"inside"<<endl;
		else cout<<"outside"<<endl;
	}
	
	cin>>cx>>cy;
	c.moveCentreTo(cx,cy);
	cout<<"after move the centre of circle:"<<endl;
	
	for(int i=0;i<n;i++)
	{
		if(c.contain(s[i])) cout<<"inside"<<endl;
		else cout<<"outside"<<endl;
	}
	
	return 0;
}

/*0 0 5
4
1 1
2 2
5 0
-6 0
-1 0
*/

//output
/*
inside\n
inside\n
inside\n
outside\n
after move the centre of circle:\n
inside\n
inside\n
outside\n
inside\n
*/
