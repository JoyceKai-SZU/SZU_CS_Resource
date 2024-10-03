#include<iostream>
#include<cstring>
using namespace std;


class Time{
protected:
	int h,m,s;
public:
	Time(int hh,int mm,int ss):
		h(hh),m(mm),s(ss){}
}; 

class Time_12hours:public Time{
private:
	char interval[5];   //标识为AM或者PM
public:
	Time_12hours(char type[],int hh,int mm,int ss):
		Time(hh,mm,ss)
	{
		strcpy(interval,type);
	}
	 
	void add()  //加1秒，或者可以重载++运算符 
	{
		if(h==11&&m==59&&s==59)
		{
			h=m=s=0;
			if(strcmp(interval,"AM")==0) strcpy(interval,"PM");
			else strcpy(interval,"AM");
		}
		else if(m==59&&s==59)
		{
			h++;
			m=s=0;
		}
		else if(s==59)
		{
			m++;
			s=0;
		}
		else s++;
	}
	
	void sub()//减1秒，或者可以重载--运算符 
	{
		if(h==0&&m==0&&s==0)
		{
			h=11;
			m=s=59;
			if(strcmp(interval,"AM")==0) strcpy(interval,"PM");
			else strcpy(interval,"AM");
		}
		else if(m==0&&s==0)
		{
			h--;
			m=s=59;
		}
		else if(s==0)
		{
			m--;
			s=59;
		}
		else s--;
	}
	
	void show()
	{
		printf("%s %02d:%02d:%02d\n",interval,h,m,s);
	}
};

int main()
{
	char am[]="AM";
	char pm[]="PM";
	int tp;
	int h,m,s;
	char op;
	int pass;
	while(true)
	{
		cin>>tp;
		if(!tp) break;
		cin>>h>>m>>s>>op>>pass;
		
		if(tp==121)
		{
			Time_12hours mytime(am,h,m,s);
			if(op=='+')
			{
				for(int i=0;i<pass;i++) mytime.add();
			}
			else if(op=='-')
			{
				for(int i=0;i<pass;i++) mytime.sub();
			}
			mytime.show();
			
		}
		else if(tp==122)
		{
			Time_12hours mytime(pm,h,m,s);
			if(op=='+')
			{
				for(int i=0;i<pass;i++) mytime.add();
			}
			else if(op=='-')
			{
				for(int i=0;i<pass;i++) mytime.sub();
			}
			mytime.show();
		}
	}
	
	
	return 0;
}
