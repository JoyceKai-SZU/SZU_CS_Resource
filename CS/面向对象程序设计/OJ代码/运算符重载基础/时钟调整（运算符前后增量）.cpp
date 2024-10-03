#include<iostream>
using namespace std;

class Myclock{
private:
	int h,m,s;
public:
	Myclock(int h,int m,int s):h(h),m(m),s(s){}
	void display()
	{
		cout<<h<<":"<<m<<":"<<s<<endl;
	}
	
	Myclock& operator ++()  //前缀+ 
	{
		if(h==11&&m==59&&s==59)
		{
			h=0;
			m=0;
			s=0;
		}
		else if(m==59&&s==59)
		{
			++h;
			m=0;
			s=0;
		}
		else if(s==59)
		{
			++m;
			s=0;
		}
		else ++s;
		return *this;    //*this可以当作引用变量返回 
	} 
	
	Myclock operator --(int)  //后缀- 
	{
		Myclock temp=*this;
		if(h==0&&m==0&&s==0)
		{
			h=11;
			m=59;
			s=59;
		}
		else if(m==0&&s==0)
		{
			h--;
			m=59;
			s=59;
		}
		else if(s==0)
		{
			m--;
			s=59;
		}
		else s--;
		return temp;     //局部变量不能返回引用变量 
	} 
};



int main()
{
	int hour,minute,second;
	cin>>hour>>minute>>second;
	Myclock myclock(hour,minute,second);
	int t;
	cin>>t;
	while(t--)
	{
		int pass;
		cin>>pass;
		if(pass>0)
		{
			for(int i=0;i<pass;i++) ++myclock;
		}
		else
		{
			pass=-pass;
			for(int i=0;i<pass;i++) myclock--;
		} 
		
		myclock.display();
	}
	return 0;
}


/*
11 58 46
4
5 70 -22 -55
*/

//output
/*
11:58:51
0:0:1
11:59:39
11:58:44
*/
