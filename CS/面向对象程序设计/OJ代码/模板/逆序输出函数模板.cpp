#include<iostream>
#include<typeinfo>
#include<algorithm>
using namespace std;

 
class Complex{
private:
	int r,i;
public:
	Complex(int rr,int ii):r(rr),i(ii){}
	friend ostream& operator << (ostream& out,const Complex & a)
	{
		out<<a.r;
		if(a.i>0) out<<"+";
		out<<a.i;
		return out;
	}
	void CReverse()   
	{
		swap(r,i);
	}
};

template<class T>
void reverse(T &t)
{
	if(typeid(t)==typeid(int))
	{
		string temp=to_string(t);
		reverse(temp.begin(),temp.end());
		if(t<0)
		{
			temp.pop_back();
			cout<<"-";
		}
		cout<<stoi(temp)<<endl;	
	}
	else if(typeid(t)==typeid(double))
	{
		string temp=to_string(t);
		reverse(temp.begin(),temp.end());
		if(t<0)
		{
			temp.pop_back();  //删去后面的'-' 
			cout<<"-";
		}
		cout<<stod(temp)<<endl;	//转换回来可以除去前导0 
	}
} 

//对于string和Complex要重载，因为to_string不兼容这两种类型 

void reverse(string &t)  
{
	reverse(t.begin(),t.end());
	cout<<t<<endl; 
}

void reverse(Complex &t) 
{
	t.CReverse();
	cout<<t<<endl;
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char op;
		cin>>op;
		if(op=='I')
		{
			int num;
			cin>>num;
			reverse(num);
		}
		else if(op=='D')
		{
			double num;
			cin>>num;
			reverse(num);
		}
		else if(op=='S')
		{
			string str;
			cin>>str;
			reverse(str);
		}
		else if(op=='C')
		{
			int real,imag;
			cin>>real>>imag;
			Complex c(real,imag);
			reverse(c);
		}
	}
	return 0;
}

/*
5
I 123456
D -235.172
S thisisatest
C -123 456
C 123 -456
*/

//output
/*
654321
-271.532
tsetasisiht
456-123
-456+123
*/
