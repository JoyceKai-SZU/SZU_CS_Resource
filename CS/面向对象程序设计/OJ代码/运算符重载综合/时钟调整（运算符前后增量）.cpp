#include<iostream>
using namespace std;

class Myclock{
private:
	int h,m,s;
public:
	Myclock(int h,int m,int s):h(h),m(m),s(s){}
	void show()
	{
		cout<<h<<":"<<m<<":"<<s<<endl; 
	}
	
	Myclock& operator ++()  //Ç°×º+ 
	{
		if(h==11&&m==59&&s==59)
		{
			h=0;m=0;s=0;
		} 
		else if(m==59&&s==59)
		{
			++h;m=0;s=0;
		}
		else if(s==59)
		{
			++m;s=0;
		}
		else ++s;
		
		return *this;
	}
	
	Myclock operator --(int)  //ºó×º- 
	{
		Myclock temp=*this;
		
		if(h==0&&m==0&&s==0)
		{
			h=11;m=59;s=59;
		} 
		else if(m==0&&s==0)
		{
			h--;m=59;s=59;
		}
		else if(s==0)
		{
			m--;s=59;
		}
		else s--;
		
		return temp;
	} 
}; 

int main()
{
	int h,m,s;
	cin>>h>>m>>s;
	Myclock myclock(h,m,s);
	
	int t;
	cin>>t;
	while(t--)
	{
		int op;
		cin>>op;
		if(op>0)
		{
			for(int i=0;i<op;i++) ++myclock;
		}
		else
		{
			op=-op;
			for(int i=0;i<op;i++) myclock--;
		} 
		
		myclock.show();
	}
	return 0;
}
