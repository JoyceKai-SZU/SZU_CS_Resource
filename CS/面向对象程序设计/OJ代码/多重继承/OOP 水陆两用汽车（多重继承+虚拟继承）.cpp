#include<iostream>
using namespace std;

class Vehicle{
protected:
	int weight;
public:
	Vehicle(){}
	Vehicle(int w):weight(w)
	{
		cout<<"载入Vehicle类构造函数"<<endl;
	}
	void setWeight(int w)
	{
		cout<<"重新设置重量"<<endl;
		weight=w;
	}
	void display()
	{
		cout<<"重量："<<weight<<"吨"; 
	}
};


class Car:virtual public Vehicle{
protected:
	int aird;
public:
	Car(int a):aird(a)
	{
		cout<<"载入Car类构造函数"<<endl;
	} 
	void setAird(int a)
	{
		cout<<"重新设置空气排量"<<endl;
		aird=a;
	}
	void display()
	{
		cout<<"空气排量："<<aird<<"CC";
	}
};

class Boat:virtual public Vehicle{
protected:
	float tonnage;
public:
	Boat(float t):tonnage(t)
	{
		cout<<"载入Boat类构造函数"<<endl;
	}
	void setTonnage(float t)
	{
		cout<<"重新设置排水量"<<endl;
		tonnage=t;
	}
	void display()
	{
		cout<<"排水量："<<tonnage<<"吨";
	}
};

class AmphibianCar:public Car,public Boat{
public:
	AmphibianCar(int w,int a,float t):
		Vehicle(w),
		Car(a),
		Boat(t)
	{
		cout<<"载入AmphibianCar类构造函数"<<endl;
	}
	void display()
	{
		Vehicle::display();
		cout<<"，";
		Car::display();
		cout<<"，";
		Boat::display();
		cout<<endl;
	}
};

int main()
{
	int w,a;
	float t;
	cin>>w>>a>>t;
	AmphibianCar mycar(w,a,t);
	mycar.display();
	
	cin>>w>>a>>t;
	mycar.setWeight(w);
	mycar.setAird(a);
	mycar.setTonnage(t);
	mycar.display();
	return 0;
}
