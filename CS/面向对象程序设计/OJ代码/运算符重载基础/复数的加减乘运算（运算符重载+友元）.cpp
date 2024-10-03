#include<iostream>
using namespace std;

class Complex{
private:
	int real,image;
public:
	Complex(int r,int i):real(r),image(i){}
	void show()
	{
		cout<<"Real="<<real<<" Image="<<image<<endl;
	}
	friend Complex operator +(const Complex &c1,const Complex &c2);
	friend Complex operator -(const Complex &c1,const Complex &c2);
	friend Complex operator *(const Complex &c1,const Complex &c2);
}; 

Complex operator + (const Complex &c1,const Complex &c2)
{
	return Complex(c1.real+c2.real,c1.image+c2.image);
}

Complex operator - (const Complex &c1,const Complex &c2)
{
	return Complex(c1.real-c2.real,c1.image-c2.image);
}

Complex operator * (const Complex &c1,const Complex &c2)
{
	return Complex(c1.real*c2.real-c1.image*c2.image,c1.real*c2.image+c1.image*c2.real);
}


int main()
{
	int r1,r2,i1,i2;
	cin>>r1>>i1>>r2>>i2;
	Complex c1(r1,i1);
	Complex c2(r2,i2);
	Complex c3=c1+c2, c4=c1-c2, c5=c1*c2;
	c3.show();
	c4.show();
	c5.show();
	return 0;
}
