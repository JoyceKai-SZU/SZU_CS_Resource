#include<iostream>
using namespace std;

class Node2D{
protected:
	string location;
public:
	Node2D(){}    //ÐéÄâÒªÐ´ 
	Node2D(string l):location(l){}
};

class Body:virtual public Node2D{
protected:
	int maxHealth,health,defense;
public:
	Body(int mh,int df):maxHealth(mh),health(mh),defense(df){}
};

class Weapon:virtual public Node2D{
protected:
	string w_name;
	int damage;
public:
	Weapon(string wn,int d):w_name(wn),damage(d){}
}; 

class Player:public Body,public Weapon{
private:
	string name;
public:
	Player(string l,string nm,int mh,int df,string wn,int wd):
		Node2D(l),Body(mh,df),Weapon(wn,wd),name(nm){}
		
	void attack(Player &a)  //*this attack a
	{
		int shanghai=damage-a.defense;
		a.health-=shanghai;
		
		cout<<name<<" deal "<<shanghai<<" damage to "<<a.name<<endl;
		if(a.health>0)
		{
			cout<<a.name<<" still have "<<a.health<<" health"<<endl;
			cout<<endl;
		}
		else
		{
			displayWin(a);
		}
	}
	
	int getHealth(){return health;}
	
	void displayWin(Player &a)
	{
		cout<<name<<" defeated "<<a.name<<" by "<<w_name<<" in "<<location; 
	}
};

int changePlayer(int t)
{
	if(t==1) return 2;
	else return 1;
}

int main()
{
	string location;
	cin>>location;
	string name;
	int mh,df;
	string wn;
	int wd;
	cin>>name>>mh>>df>>wn>>wd;
	
	Player p1(location,name,mh,df,wn,wd);
	
	cin>>name>>mh>>df>>wn>>wd;
	Player p2(location,name,mh,df,wn,wd);
	
	int t=1;
	
	while(true)
	{
		if(t==1)
		{
			p1.attack(p2);
			if(p2.getHealth()<=0) break;
		}
		else if(t==2)
		{
			p2.attack(p1);
			if(p1.getHealth()<=0) break;
		}
		
		t=changePlayer(t);
		
	}
	
	return 0;
} 
