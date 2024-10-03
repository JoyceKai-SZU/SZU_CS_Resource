#include<iostream>
#include<iomanip>
#include<list> 
using namespace std;

class Goods{
private:
	string id,name,colour,size;
	double cost;
	int num;
public:
	Goods(){}
	Goods(string id,string name,string colour,string size,double cost,int num)
	{his->colour=colour;this->size=size;
		this->cost=cost;this->num=num
		this->id=id;this->name=name;t; 
	}
	double Calsum(){return num*cost;}
	
	string getid(){return id;}
	int getNum(){return num;}
	void addNum(int d){num+=d;}
	void delNum(int d){num-=d;}
	double getCost(){return cost;}
	void show()
	{
		cout<<name<<","<<colour<<","<<size<<","<<fixed<<setprecision(2)<<cost<<","<<num<<","
			<<Calsum()<<endl;
	}
};


class GWC{
private:
	list<Goods> s;
	int goodnum;
	double allcost;
public:
	GWC():goodnum(0),allcost(0){}
	void add(Goods &g)
	{
		for(auto &t:s)
		{
			if(t.getid()==g.getid())
			{
				t.addNum(g.getNum());
				goodnum+=g.getNum();
				allcost+=g.Calsum();
				//cout<<goodnum<<endl; 
				return;
			}
		}
		
		s.push_front(g);
		goodnum+=g.getNum();
		allcost+=g.Calsum();
		//cout<<goodnum<<endl;
	}
	
	void del(string id)
	{
		for(list<Goods>::iterator t=s.begin();t!=s.end();t++)
		{
			if(t->getid()==id)
			{

				goodnum-=t->getNum();
				allcost-=t->Calsum();
				s.erase(t);
				//cout<<goodnum<<endl;
				return;
			}
		}
		
	}
	
	void up(string id)
	{
		for(auto &t:s)
		{
			if(t.getid()==id)
			{
				t.addNum(1);
				goodnum++;
				allcost+=t.getCost();
				//cout<<goodnum<<endl;
				return;
			}
		}
	}
	
	void down(string id)
	{
		for(auto &t:s)
		{
			if(t.getid()==id)
			{
				t.delNum(1);
				goodnum--;
				allcost-=t.getCost();
				//cout<<goodnum<<endl;
				return;
			}
		}
	}
	
	void display()
	{
		cout<<"商品清单:"<<endl;
		cout<<"商品,颜色,尺码,单价,数量,小计"<<endl;
		for(auto &t: s)
		{
			t.show();
		}
		cout<<"----------"<<endl;
		cout<<goodnum<<"件商品,总商品金额"<<fixed<<setprecision(2)<<allcost<<endl;
	}
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		GWC gwc; 
		while(n--)
		{
			string op;
			string id,name,colour,size;
			double cost;
			int num;
			
			cin>>op;
			if(op=="ADD")
			{
				cin>>id>>name>>colour>>size>>cost>>num;
				Goods p(id,name,colour,size,cost,num);
				gwc.add(p);
			}
			else if(op=="DELETE")
			{
				cin>>id;
				gwc.del(id);
			}
			else if(op=="UP")
			{
				cin>>id;
				gwc.up(id);
				
			} 
			else if(op=="DOWN")
			{
				cin>>id;
				gwc.down(id);
			}
		}
		gwc.display();
		cout<<endl;
	}
	return 0;
}

/*
1
8
ADD 2018040801 格力变频冷暖空调KFR-26GW  大1匹  变频挂机  2999  1
ADD 2018040802 长虹65D2P高清HDR平板LED液晶 1 1 4799 1
ADD 2018040803 康佳LED55X9人工智能平板电视机 null 55寸 4999 1
UP 2018040802
UP 2018040803
DOWN 2018040803
DELETE 2018040802
ADD 2018040802 长虹65D2P高清HDR平板LED液晶 1 1 4799 2
*/


//output
/*
商品清单:\n
商品,颜色,尺码,单价,数量,小计\n
长虹65D2P高清HDR平板LED液晶,1,1,4799.00,2,9598.00\n
康佳LED55X9人工智能平板电视机,null,55寸,4999.00,1,4999.00\n
格力变频冷暖空调KFR-26GW,大1匹,变频挂机,2999.00,1,2999.00\n
----------\n
4件商品,总商品金额17596.00\n
\n
*/
