#include<iostream>
using namespace std;

class Counter{
protected:
	int value;
public:
	Counter(){}
	~Counter(){}
	Counter(int v=0):value(v){}   //value默认为0 
	void increment(){value++;}
	int getValue(){return value;}
};

class Cyclecounter:public Counter{
private:
	int min_value;
	int max_value;
public:
	~Cyclecounter(){}
	Cyclecounter(int v,int Min,int Max):Counter(v),min_value(Min),max_value(Max){}
	bool increment()   //要改为bool类型 
	{
		value++;
		if(value>=max_value)   //从头开始 
		{
			value=min_value;
			return true; 
		}
		return false;
	}
};

class ClockCounter{
private:
	Cyclecounter hour,minute,second;
public:
	~ClockCounter(){}
	ClockCounter(int h,int m,int s):hour(h,0,24),minute(m,0,60),second(s,0,60){}
	void time(int s)  //经过几秒时间 
	{
		if(s==0) return ;
		else
		{
			while(s--)
			{
				if(second.increment())
				{
					if(minute.increment())
					{
						hour.increment();
					}
				}
			}
		}
	}
	void display()
	{
		cout<<hour.getValue()<<":"<<minute.getValue()<<":"<<second.getValue()<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int h,m,s,pass;
		cin>>h>>m>>s;
		cin>>pass;
		ClockCounter cc(h,m,s);
		cc.time(pass);
		cc.display();
	}
	
	return 0;
}

/*
2
8 19 20
20
23 30 0
1801
*/

//output
/*
8:19:40\n
0:0:1\n
*/
