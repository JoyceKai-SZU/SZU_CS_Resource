#include<iostream>
#include<vector>
using namespace std;

class Player{
private:
	string name,position;
	int rate;
	static int sf;
	static int pg;
	static int pf;
	static int sg;
	static int c;
public:
	Player(){}
	Player(string n,string p,int r):name(n),position(p),rate(r)
	{
		if(p=="SF") sf++;
		else if(p=="PG") pg++;
		else if(p=="PF") pf++;
		else if(p=="SG") sg++;
		else if(p=="C") c++; 
	}
//	void set(string n,string p,int r)
//	{
//		name=n;
//		position=p;
//		rate=r;
//		if(p=="SF") sf++;
//		else if(p=="PG") pg++;
//		else if(p=="PF") pf++;
//		else if(p=="SG") sg++;
//		else if(p=="C") c++; 
//	} 
	static int getSF(){return sf;}
	static int getPG(){return pg;}
	static int getSG(){return sg;}
	static int getPF(){return pf;}
	static int getC(){return c;}

	void show()
	{
		cout<<"Name:"<<name<<" "<<"Position:"<<position<<" "<<"Rate:"<<rate<<endl;
	}
};

int Player::sf=0;
int Player::pg=0;
int Player::pf=0;
int Player::sg=0;
int Player::c=0;


int main()
{
	string name,position;
	int rate;
	vector<Player> s;
	while(true)
	{
		cin>>name;
		if(name=="0") break;
		cin>>position>>rate;
		Player p(name,position,rate);
		s.push_back(p);
	}
	for(auto t: s)
	{
		t.show();
	}
	
	cout<<endl;
	cout<<"Total PG Player:"<<Player::getPG()<<endl;
	cout<<"Total SG Player:"<<Player::getSG()<<endl;
	cout<<"Total SF Player:"<<Player::getSF()<<endl;
	cout<<"Total PF Player:"<<Player::getPF()<<endl;
	cout<<"Total C Player:"<<Player::getC()<<endl;
	return 0;
}
