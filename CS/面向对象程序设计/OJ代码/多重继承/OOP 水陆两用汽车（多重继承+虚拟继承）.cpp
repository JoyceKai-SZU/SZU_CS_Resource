#include<iostream>
using namespace std;

class Vehicle{
protected:
	int weight;
public:
	Vehicle(){}
	Vehicle(int w):weight(w)
	{
		cout<<"����Vehicle�๹�캯��"<<endl;
	}
	void setWeight(int w)
	{
		cout<<"������������"<<endl;
		weight=w;
	}
	void display()
	{
		cout<<"������"<<weight<<"��"; 
	}
};


class Car:virtual public Vehicle{
protected:
	int aird;
public:
	Car(int a):aird(a)
	{
		cout<<"����Car�๹�캯��"<<endl;
	} 
	void setAird(int a)
	{
		cout<<"�������ÿ�������"<<endl;
		aird=a;
	}
	void display()
	{
		cout<<"����������"<<aird<<"CC";
	}
};

class Boat:virtual public Vehicle{
protected:
	float tonnage;
public:
	Boat(float t):tonnage(t)
	{
		cout<<"����Boat�๹�캯��"<<endl;
	}
	void setTonnage(float t)
	{
		cout<<"����������ˮ��"<<endl;
		tonnage=t;
	}
	void display()
	{
		cout<<"��ˮ����"<<tonnage<<"��";
	}
};

class AmphibianCar:public Car,public Boat{
public:
	AmphibianCar(int w,int a,float t):
		Vehicle(w),
		Car(a),
		Boat(t)
	{
		cout<<"����AmphibianCar�๹�캯��"<<endl;
	}
	void display()
	{
		Vehicle::display();
		cout<<"��";
		Car::display();
		cout<<"��";
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
