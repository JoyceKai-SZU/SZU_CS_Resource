#include<iostream>
#include<cstring>
using namespace std;

class str{
private:
	char *p;
public:
	str();
	str(char *s);
	friend bool operator > (str &a,str &b)
	{
		return strcmp(a.p,b.p)>0;
	}
	
	friend bool operator < (str &a,str &b)
	{
		return strcmp(a.p,b.p)<0;
 
	}
	
	friend bool operator ==(str &a,str &b)
	{
		return strcmp(a.p,b.p)==0;
	}
	
	void show()
	{
		cout<<p;
	} 
};

str::str(){p=new char [50];}
str::str(char *s)
{
	p=new char [50];
	strcpy(p,s);
}

int main()
{
	char *a=new char [50];
	char *b=new char [50];
	char *c=new char [50];
	
	cin.getline(a,50);   //以行为单位输入，不能直接cin，因为有空格 
	cin.getline(b,50);   //getline可以吸收输入的回车 
	cin.getline(c,50);
	
	
	str aa(a), bb(b), cc(c);
	
	if(aa>bb) aa.show();
	else bb.show();
	
	cout<<endl;
	
	if(aa<cc) aa.show();
	else cc.show();
	
	cout<<endl;
	
	if(bb==cc) bb.show();
	else cc.show();
	
	return 0;
}



/*
i am a student
i love China
i love China
*/

//output
/*
i love China
i am a student
i love China
*/
