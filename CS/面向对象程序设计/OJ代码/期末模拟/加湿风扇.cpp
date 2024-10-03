#include<iostream>
using namespace std;

class Jiadian{
protected:
	int id,gl;
public:
	Jiadian(){}  //����̳�үү��Ҫ���޲ι��� 
	Jiadian(int idd,int gll):
		id(idd),gl(gll){}
	
	void display()
	{
		cout<<"���"<<id<<"--����"<<gl<<"W"<<endl; 
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
		cout<<"��ʪ����--��λ"<<dw<<endl;
		
		Jiadian::display();
		
		if(fx==0) cout<<"���򴵷�";
		else if(fx==1) cout<<"��ת����";
		cout<<"--����"<<fl<<"��"<<endl; 
		
		cout<<"ʵ��ˮ����"<<realwater<<"��--";
		if(alarm()==1) cout<<"ˮ������";
		else if(alarm()==2) cout<<"ˮ��ƫ��";
		else if(alarm()==3) cout<<"ˮ������";
		
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
��ʪ����--��λ1\n
���1001--����1000W\n
���򴵷�--����1��\n
ʵ��ˮ����3��--ˮ������\n
��ʪ����--��λ3\n
���2002--����2000W\n
��ת����--����3��\n
ʵ��ˮ����1��--ˮ������\n
��ʪ����--��λ0\n
���3003--����3000W\n
���򴵷�--����3��\n
ʵ��ˮ����2��--ˮ��ƫ��\n
*/
