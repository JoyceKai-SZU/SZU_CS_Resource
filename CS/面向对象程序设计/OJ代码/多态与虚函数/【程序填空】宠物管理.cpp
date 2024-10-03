#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Pet { //���࣬Ҳ�ǳ�����
protected:
	string kind; //��������
	int ID;	//�����ţ��̶�����Ϊ5λ������	
public:
	Pet(): kind("unset"), ID(-1) { }
	virtual void set(string tk, int ti)=0; //��������������ͺͱ��
	virtual void print()	{ cout<<"NONE"<<endl; }
};

//�����Cat����Dog�����
/********** Write your code here! **********/

class Cat:public Pet{
private:
	string name,food;
public:
	Cat(string name,string food):name(name),food(food){}  //�޲εļ̳п��Բ�д 
	
	void set(string tk,int ti)
	{
		kind=tk;
		ID=ti;
	}
	
	void print()
	{
		cout<<kind<<"'s ID=1"; 
		printf("%04d\n",ID);
		cout<<name<<" likes "<<food<<endl;
	} 
	
};

class Dog:public Pet{
private:
	string name;
	int size;
public:
	Dog(string name,int size):name(name),size(size){}  //�޲εļ̳п��Բ�д 
	
	void set(string tk,int ti)
	{
		kind=tk;
		ID=ti;
	}
	
	void print()
	{
		cout<<kind<<"'s ID=2";
		printf("%04d\n",ID);
		cout<<name<<" is ";
		
		if(size==1) cout<<"small"<<endl;
		else if(size==2) cout<<"medium"<<endl;
		else cout<<"big"<<endl;
	} 
	
};

/*******************************************/
//�������������ȫ�ֺ������£�
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
		{	cin>>tk>>ti>>ts>>tf; //���͡���š�������ʳ��
			Cat cc(ts, tf);
			cc.set(tk, ti);
			print_pet(cc);
		}
		if (ptype=='D')
		{	cin>>tk>>ti>>ts>>tt; //���͡���š�������Ȯ��С
			Dog dd(ts, tt);
			dd.set(tk, ti);
			print_pet(dd);
		}
	}
	
	return 0;
}

