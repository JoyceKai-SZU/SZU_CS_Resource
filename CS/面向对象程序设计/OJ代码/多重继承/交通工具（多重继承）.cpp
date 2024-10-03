#include<iostream>
using namespace std;

class CVehicle{
protected:
	int max_speed,speed,weight;
public:
	CVehicle(int ms,int s,int w):
		max_speed(ms),
		speed(s),
		weight(w)
	{
		
	}
	
	void display()
	{
		cout<<"Vehicle:"<<endl;
		cout<<"max_speed:"<<max_speed<<endl;
		cout<<"speed:"<<speed<<endl;
		cout<<"weight:"<<weight<<endl;
	}
};

class CBicycle:virtual public CVehicle{
protected:
	int height;
public:
	CBicycle(int ms,int s,int w,int h):
		CVehicle(ms,s,w),
		height(h)
	{
		
	}
	void display()
	{
		cout<<"Bicycle:"<<endl;
		cout<<"max_speed:"<<max_speed<<endl;
		cout<<"speed:"<<speed<<endl;
		cout<<"weight:"<<weight<<endl;
		cout<<"height:"<<height<<endl;
	}
	
};

class CMotocar:virtual public CVehicle{
protected:
	int seat_num;
public:
	CMotocar(int ms,int s,int w,int sn):
		CVehicle(ms,s,w),
		seat_num(sn)
	{
		
	}
	
	void display()
	{
		cout<<"Motocar:"<<endl;
		cout<<"max_speed:"<<max_speed<<endl;
		cout<<"speed:"<<speed<<endl;
		cout<<"weight:"<<weight<<endl;
		cout<<"seat_num:"<<seat_num<<endl;
	}
		
};

class CMotocycle:public CBicycle,public CMotocar{
public:
	CMotocycle(int ms,int s,int w,int h,int sn):
		CVehicle(ms,s,w),
		CBicycle(ms,s,w,h),
		CMotocar(ms,s,w,sn)
	{
		
	}
	
	void display()
	{
		cout<<"Motocycle:"<<endl;
		cout<<"max_speed:"<<max_speed<<endl;
		cout<<"speed:"<<speed<<endl;
		cout<<"weight:"<<weight<<endl;
		cout<<"height:"<<height<<endl;
		cout<<"seat_num:"<<seat_num<<endl;
	}
	
};

int main()
{
	int ms,s,w,h,sn;
	cin>>ms>>s>>w>>h>>sn;
	CVehicle(ms,s,w).display();
	cout<<endl;
	CBicycle(ms,s,w,h).display();
	cout<<endl;
	CMotocar(ms,s,w,sn).display();
	cout<<endl;
	CMotocycle(ms,s,w,h,sn).display(); 
	return 0;
}
