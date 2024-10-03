#include<iostream>
using namespace std;

class Jiadian{
protected:
	int id,gl;
public:
	Jiadian(){}  //虚拟继承爷爷类要加无参构造 
	Jiadian(int idd,int gll):
		id(idd),gl(gll){}
	
	void display()
	{
		cout<<"编号"<<id<<"--功率"<<gl<<"W"<<endl; 
	}
};

class Fan:virtual public Jiadian{
protected:
	int fx,fl;
public:
	Fan(int fxx,int fll):
		fx(fxx),fl(fll){}
	
	void controlFX(int op)
	{
		fx=op;
	}
	
	void controlFL(int op)
	{
		fl=op;
	} 
};

class WetMechine:virtual public Jiadian{
protected:
	float realwater,maxwater;
public:
	WetMechine(float rw,float mw):
		realwater(rw),maxwater(mw){}
	
	int alarm()
	{
		float temp=realwater/maxwater;
		if(temp>=0.5) return 1;
		else if(temp>=0.1) return 2;
		else return 3;
	} 
};

class WetFan:public Fan,public WetMechine{
private:
	int dw;
public:
	WetFan(int id,int gl,int fx,int fl,float rw,float mw,int dww):
		Jiadian(id,gl),Fan(fx,fl),WetMechine(rw,mw),dw(dww){}
	
	void controlDW(int op)
	{
		dw=op;
		
		if(dw==1)
		{
			controlFX(0);
			controlFL(1);
		}
		else if(dw==2)
		{
			controlFX(1);
			controlFL(2);
		}
		else if(dw==3)
		{
			controlFX(1);
			controlFL(3);
		}
	} 
	
	void display()
	{
		cout<<"加湿风扇--档位"<<dw<<endl;
		
		Jiadian::display();
		
		if(fx==0) cout<<"定向吹风";
		else if(fx==1) cout<<"旋转吹风";
		cout<<"--风力"<<fl<<"级"<<endl; 
		
		cout<<"实际水容量"<<realwater<<"升--";
		if(alarm()==1) cout<<"水量正常";
		else if(alarm()==2) cout<<"水量偏低";
		else if(alarm()==3) cout<<"水量不足";
		
		cout<<endl; 
	}
	
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int id,gl,fx,fl;
		float rw,mw;
		int dw;
		cin>>id>>gl>>fx>>fl>>rw>>mw>>dw;
		
		WetFan myfan(id,gl,fx,fl,rw,mw,dw);
		
		int op;
		cin>>op;
		myfan.controlDW(op);
		myfan.display();
	}
	return 0;
}

/*
3
1001 1000 1 2 3 4 0
1
2002 2000 0 1 1 12 0
3
3003 3000 0 3 2 10 0
0

*/

//output
/*
加湿风扇--档位1\n
编号1001--功率1000W\n
定向吹风--风力1级\n
实际水容量3升--水量正常\n
加湿风扇--档位3\n
编号2002--功率2000W\n
旋转吹风--风力3级\n
实际水容量1升--水量不足\n
加湿风扇--档位0\n
编号3003--功率3000W\n
定向吹风--风力3级\n
实际水容量2升--水量偏低\n
*/
