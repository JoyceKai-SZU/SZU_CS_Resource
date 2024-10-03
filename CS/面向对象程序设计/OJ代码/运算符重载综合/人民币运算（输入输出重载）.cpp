#include <iostream>
using namespace std;

class RMB;
ostream & operator <<(ostream &, RMB &);
istream & operator >>(istream &, RMB &);

class RMB{
protected:
	int yuan, jiao, fen;
public:
	RMB(double a=0.0);
	RMB (int, int, int); 
	bool operator > (RMB &);
	friend ostream & operator <<(ostream &, RMB&); //һ��������޻���
	friend istream & operator >>(istream &, RMB&);
	friend RMB operator +(RMB&, RMB&);
};
//��������ඨ������
/********** Write your code here! **********/

RMB::RMB(double a)
{
	a+=0.005;
	int temp=(int)(a*100);
	yuan=temp/100;
	jiao=temp/10%10;
	fen=temp%10; 
} 

RMB::RMB(int y,int j,int f):yuan(y),jiao(j),fen(f){}

bool RMB::operator > (RMB &a)
{
	if(yuan!=a.yuan) return yuan>a.yuan;
	else if(jiao!=a.jiao) return jiao>a.jiao;
	else if(fen!=a.fen) return fen>a.fen;
}

ostream & operator <<(ostream &output, RMB &a)
{
	
	output<<a.yuan<<"yuan"<<a.jiao<<"jiao"<<a.fen<<"fen"; 
	return output;
}

istream & operator >>(istream &input, RMB &a)
{
	input>>a.yuan>>a.jiao>>a.fen; 
	return input;
}


RMB operator +(RMB &a, RMB &b)
{
	int m1=a.yuan*100+a.jiao*10+a.fen;
	int m2=b.yuan*100+b.jiao*10+b.fen;
	int m=m1+m2;
	return RMB(m/100,m/10%10,m%10);
	
}


/*******************************************/
//������
int main()
{	int t;
	double val_yuan; 
	cin>>t;
	while (t--)
	{	cin>>val_yuan;	//����һ��������������1.23 
		RMB r1(val_yuan); //������һ������1.23�������ɶ���r1��1Ԫ2��3�� 
		RMB r2;
		cin>>r2;	//����һ������������������Ԫ���ǡ������� 

		if (r1>r2) 		cout<<r1<<" > "<<r2<<endl;
		else 			cout<<r1<<" <= "<<r2<<endl;
		RMB r3 =r1+r2;
		cout<<r1<<" + "<<r2<<" = "<<r3<<endl;
	}
	return 0;
}

