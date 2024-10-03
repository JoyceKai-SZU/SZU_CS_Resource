#include<iostream>
#include<iomanip> 
using namespace std;

class Vehicle{
protected:
	int id;
	int rentday;
	int rent;    //²é±íµÄ 
public:
	Vehicle(){}
	Vehicle(int _id,int rd):
		id(_id),rentday(rd){}
	
	double getTotalRent(){return rent*rentday;}
};

class Car:virtual public Vehicle{
private:
	int zkl;
public:
	Car(int id,int rd):Vehicle(id,rd)
	{
		switch(id)
		{
			case 1:rent=800;zkl=5;break;
			case 2:rent=400;zkl=5;break;
			case 3:rent=800;zkl=5;break;
			case 4:rent=1300;zkl=51;break;
			case 5:rent=1500;zkl=55;break;
			case 6:rent=500;zkl=5;break;
			case 7:rent=450;zkl=5;break;
		}
	}
	
	int getTotalZKL(){return zkl*rentday;}
	//double getTotalRent(){return rent*rentday;}
	
};

class Trunk:virtual public Vehicle{
private:
	double zhl;
public:
	Trunk(int id,int rd):Vehicle(id,rd)
	{
		switch(id)
		{
			case 6:rent=500;zhl=0.45;break;
			case 7:rent=450;zhl=2.0;break;
			case 8:rent=200;zhl=3;break;
			case 9:rent=1500;zhl=25;break;
			case 10:rent=2000;zhl=35;break;
		}
	}
	
	int getTotalZHL(){return zhl*rentday;}
	//double getTotalRent(){return rent*rentday;}
};


class Pickup:public Car,public Trunk{
public:
	Pickup(int id,int rd):Car(id,rd),Trunk(id,rd){}
	
};



int main()
{
	int op;
	cin>>op;
	if(!op) cout<<"0 0.00 0"<<endl;
	else
	{
		int N;
		int totalnum=0;
		double totalweight=0.00;
		int totalrent=0;
		cin>>N;
		for(int i=0;i<N;i++)
		{
			int id,n;
			cin>>id>>n;
			if(id>=1&&id<=5)
			{
				Car c(id,n);
				totalnum+=c.getTotalZKL();
				totalrent+=c.getTotalRent();
			}
			else if(id>=6&&id<=7)
			{
				Pickup pk(id,n);
				totalnum+=pk.getTotalZKL();
				totalweight+=pk.getTotalZHL();
				totalrent+=pk.getTotalRent();
			}
			else
			{
				Trunk t(id,n);
				totalweight+=t.getTotalZHL();
				totalrent+=t.getTotalRent(); 
			}
		}
		cout<<totalnum<<" "<<fixed<<setprecision(2)<<totalweight<<" "
			<<totalrent<<endl;
	}
	
	return 0;
}

/*
1
2
1 1
2 2
*/

//output
/*
15 0.00 1600\n
*/
