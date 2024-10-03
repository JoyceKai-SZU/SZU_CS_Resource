#include<iostream>
using namespace std;

class Fraction{
private:
	int numerator,denominator;
	int common_divisor();
	void contracted();
public:
	Fraction(int=0,int=1);
	Fraction(Fraction&);
	Fraction operator + (Fraction);
	Fraction operator - (Fraction);
	Fraction operator * (Fraction);
	Fraction operator / (Fraction);
	void Set(int=0,int=1);
	void disp()
	{
		cout<<"fraction="<<numerator<<"/"<<denominator<<endl;
	}
};

Fraction::Fraction(int n,int d):numerator(n),denominator(d)
{
	contracted();
}
Fraction::Fraction(Fraction &b):numerator(b.numerator),denominator(b.denominator)
{
	contracted();
}

void Fraction::Set(int n,int d)
{
	numerator=n;denominator=d;
	contracted();
}

int Fraction::common_divisor()
{
	int n=numerator,d=denominator;
	if(n<0) n=-n;
	if(d<0) d=-d;
	if(n<d) swap(n,d);
	while(d)
	{
		int temp=n%d;
		n=d;
		d=temp;	
	}
	return n;
}

void Fraction::contracted()
{
	int temp=common_divisor();
	numerator/=temp;
	denominator/=temp;
}

Fraction Fraction::operator +(Fraction b)
{
	Fraction c=*this;
	c.numerator=numerator*b.denominator+b.numerator*denominator;
	c.denominator=denominator*b.denominator;
	c.contracted();
	return c;
}

Fraction Fraction::operator -(Fraction b)
{
	Fraction c=*this;
	c.numerator=numerator*b.denominator-b.numerator*denominator;
	c.denominator=denominator*b.denominator;
	c.contracted();
	return c;
}

Fraction Fraction::operator *(Fraction b)
{
	Fraction c=*this;
	c.numerator=numerator*b.numerator;
	c.denominator=denominator*b.denominator;
	//c.contracted();      //bug
	return c;
}

Fraction Fraction::operator /(Fraction b)
{
	Fraction c=*this;
	c.numerator=numerator*b.denominator;
	c.denominator=denominator*b.numerator;
	c.contracted();
	return c;
}

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	Fraction s1(a,b);
	Fraction s2(c,d);
	Fraction add,sub,mul,div;
	add=s1+s2;
	sub=s1-s2;
	mul=s1*s2;
	div=s1/s2;
	
	add.disp();
	sub.disp();
	mul.disp();
	div.disp();
	return 0;
}
