#include<iostream>
#include<cmath> 
using namespace std;


class Myclass{
private:
	int num;
public:
	Myclass(){}
	Myclass(int n):num(n){}
	void setNum(int n){num=n;}
	int getNum(){return num;}
	Myclass operator + (const Myclass &b)
	{
		string n1=to_string(num);
		string n2=to_string(b.num);
		int num1=0,num2=0;
		for(int i=0;i<n1.size();i++)
		{
			num1+=(n1[i]-'0')*pow(4,n1.size()-i-1);
		}
		
		for(int i=0;i<n2.size();i++)
		{
			num2+=(n2[i]-'0')*pow(4,n2.size()-i-1);
		}
		
		int ans=num1+num2;
		
		string res="";
		while(ans)
		{
			res=to_string(ans%4)+res;
			ans/=4;
		}
		
		Myclass temp(stoi(res));
		return temp;
	} 
};




int main()
{
	int n;
	cin>>n;
	Myclass *s=new Myclass[n];
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		s[i].setNum(num);
	}
	
	Myclass sum(0);
	for(int i=0;i<n;i++)
	{
		sum=sum+s[i];   //ÀàÀÛ¼Ó 
	}
	
	cout<<sum.getNum()<<endl;
	return 0;
}
