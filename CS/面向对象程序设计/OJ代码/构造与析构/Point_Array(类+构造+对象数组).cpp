#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Point{
private:
	double x,y;
public:
	Point();
	Point(double x_value,double y_value);
	double getX();
	double getY();
	void setXY(double x1,double y1);
	void setX(double x_value);
	void setY(double y_value);
	double getDisTo(Point &p);
	~Point();
};


Point::Point()
{
	cout<<"Constructor."<<endl;
	
}
Point::~Point()
{
	cout<<"Distructor."<<endl;
}

Point::Point(double x_value,double y_value):x(x_value),y(y_value)
{
	cout<<"Constructor."<<endl;
}

double Point::getX(){return x;}
double Point::getY(){return y;}
void Point::setX(double x_value){x=x_value;}
void Point::setY(double y_value){y=y_value;}
void Point::setXY(double x1,double y1){x=x1;y=y1;}

double Point::getDisTo(Point &p)
{
	return sqrt((x-p.getX())*(x-p.getX())+(y-p.getY())*(y-p.getY()));
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Point *p=new Point[n];
		for(int i=0;i<n;i++)
		{
			double x,y;
			cin>>x>>y;
			p[i].setXY(x,y);
		} 
		
		double mx=0.0;
		int id1=0,id2=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				double dis=p[i].getDisTo(p[j]);
				if(mx<dis)
				{
					mx=dis;
					id1=i;
					id2=j;
				}
			}
		}
		
		cout<<"The longeset distance is "<<fixed<<setprecision(2)<<mx<<",between p["<<id1<<"] and p["<<id2<<"].\n";
		
		delete [] p;
	}
	return 0;
}
