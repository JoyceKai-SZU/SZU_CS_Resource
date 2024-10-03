#include<iostream>
using namespace std;

class complex{
private:
	double real;
	double imag;
public:
	complex();
	complex(double r,double i);
	friend complex addCom(complex c1,complex c2);
	friend complex minusCom(complex c1,complex c2);
	friend void outCom(complex c);
};

complex::complex(){}
complex::complex(double r,double i):real(r),imag(i){}
complex addCom(complex c1,complex c2)
{
	int r=c1.real+c2.real;
	int i=c1.imag+c2.imag;
	complex c(r,i);
	return c;
}

complex minusCom(complex c1,complex c2)
{
	int r=c1.real-c2.real;
	int i=c1.imag-c2.imag;
	complex c(r,i);
	return c;
}

void outCom(complex c)
{
	cout<<"("<<c.real<<","<<c.imag<<")"<<endl;
}

int main()
{
	int r,i,t;
	cin>>r>>i;
	complex c0(r,i);
	cin>>t;
	while(t--)
	{
		char op;
		cin>>op>>r>>i;
		complex c1(r,i);
		if(op=='+')
		{
			complex temp=addCom(c0,c1);
			outCom(temp);
			c0=temp;   //更新原来的复数 
		}
		else
		{
			complex temp=minusCom(c0,c1);
			outCom(temp);
			c0=temp;   //更新原来的复数 
		} 

	}
	return 0;
}
