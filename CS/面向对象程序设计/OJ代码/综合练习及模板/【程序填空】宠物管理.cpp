#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Pet { //基类，也是抽象类
protected:
	string kind; //宠物类型
	int ID;	//宠物编号，固定长度为5位正整数	
public:
	Pet(): kind("unset"), ID(-1) { }
	virtual void set(string tk, int ti)=0; //宠物必须设置类型和编号
	virtual void print()	{ cout<<"NONE"<<endl; }
};

//完成类Cat和类Dog的填空
/********** Write your code here! **********/


class Cat:public Pet{
private:
	string name,food;
public:
	Cat(string n,string f):name(n),food(f){}
	void set(string tk,int ti)
	{
		kind=tk;
		ID=ti;
	}
	
	void print()
	{
		cout<<kind<<"'s ID=";
		int temp=ID+10000;
		cout<<temp<<endl;
		cout<<name<<" likes "<<food<<endl;
	}
};

class Dog:public Pet{
private:
	string name;
	int size;
public:
	Dog(string n,int s):name(n),size(s){}
	void set(string tk,int ti)
	{
		kind=tk;
		ID=ti;
	}
	
	void print()
	{
		cout<<kind<<"'s ID=";
		int temp=ID+20000;
		cout<<temp<<endl;
		cout<<name<<" is ";
		if(size==1) cout<<"small";
		else if(size==2) cout<<"medium";
		else cout<<"big";
		
		cout<<endl;
	}
};







/*******************************************/
//主函数和输出的全局函数如下：
void print_pet(Pet &pr)
{	pr.print();	}

int main()
{	string tk, ts, tf;
	int t, ti, tt;
	char ptype;
	cin>>t;
	while (t--)
	{	cin>>ptype;
		if (ptype=='C')
		{	cin>>tk>>ti>>ts>>tf; //类型、编号、姓名、食物
			Cat cc(ts, tf);
			cc.set(tk, ti);
			print_pet(cc);
		}
		if (ptype=='D')
		{	cin>>tk>>ti>>ts>>tt; //类型、编号、姓名、犬大小
			Dog dd(ts, tt);
			dd.set(tk, ti);
			print_pet(dd);
		}
	}
	
	return 0;
}

