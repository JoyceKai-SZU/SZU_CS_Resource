#include<iostream>
using namespace std;

class Process{  
private:
	string name;
	int time_wait;
	int time_run;
	int level;
public:
	Process(){}
	void set(string n,int wait,int run);
	void display();
	int getLevel();
};


void Process::set(string n,int wait,int run)
{
	name=n;time_wait=wait;
	time_run=run;
}

void Process::display()
{
	cout<<name<<" "<<time_wait<<" "<<time_run<<" "<<level<<endl;
}

int Process::getLevel()
{
	level=time_wait/time_run;
	return level;
}


int main()

{
	Process *p=new Process[3];
	int mx=-1,t=-1;
	for(int i=0;i<3;i++)
	{
		string name;
		int wait,run;
		cin>>name>>wait>>run;
		p[i].set(name,wait,run);
		if(p[i].getLevel()>mx)
		{
			mx=p[i].getLevel();
			t=i;
		}
	}
	p[t].display();

	return 0;

}

/*
A 20 5
B 10 2
C 18 6
*/

//output
/*
B 10 2 5\n
*/
