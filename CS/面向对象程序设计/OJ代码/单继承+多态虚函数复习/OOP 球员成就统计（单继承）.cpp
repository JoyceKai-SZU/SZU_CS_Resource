#include<iostream>
#include<vector>
using namespace std;

class Player{
protected:
	string name;
	double height,weight;  //样例的坑 
public:
	Player(){}
	Player(string n,double h,double w):
		name(n),height(h),weight(w){}
	
	void show()
	{
		cout<<"球员姓名:"<<name<<" 身高:"<<height<<" 体重:"
			<<weight<<endl;
	}
}; 

class MVP:public Player{
private:
	int mvpyear;
	double score,lb,zg;
public:
	MVP(int my,double sc,double lbb,double zgg):
		mvpyear(my),score(sc),lb(lbb),zg(zgg){}
	
	bool judgeMVP()
	{
		return score>25&&lb>6&&zg>6;
	}
	
	void show()
	{	cout<<"MVP年份:"<<mvpyear; 
	
		cout.setf(ios::fixed);
		cout.precision(1);
		cout<<" 得分:"<<score<<" 篮板:"
			<<lb<<" 助攻:"<<zg<<endl;
	}
};

class DPOY:public Player{
private:
	int dpyear;
	double lb,qd,gm; 
public:
	DPOY(int dy,double lbb,double qdd,double gmm):
		dpyear(dy),lb(lbb),qd(qdd),gm(gmm){}
	
	
	bool judgeDPOY()
	{
		return lb>12&&gm>2.5&&qd>1.5;
	}
	
	void show()
	{
		cout<<"DPOY年份:"<<dpyear;
		cout.setf(ios::fixed);
		cout.precision(1);
		cout<<" 盖帽:"<<gm<<" 篮板:"
			<<lb<<" 抢断:"<<qd<<endl;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string name;
	double height,weight;
	cin>>name>>height>>weight;
	
	Player myplayer(name,height,weight);

	int year=2010;
	vector<MVP> mvp;
	vector<DPOY> dpoy;
	for(int i=1;i<=12;i++)
	{
		double score,lb,zg,gm,qd;  //注意是double 
		cin>>score>>lb>>zg>>gm>>qd;
		
		mvp.emplace_back(year,score,lb,zg);
		dpoy.emplace_back(year,lb,qd,gm);
		
		year++;
		
	}

	myplayer.show();
	for(int i=0;i<mvp.size();i++)
	{
		if(mvp[i].judgeMVP()) mvp[i].show();
	}
	
	for(int i=0;i<dpoy.size();i++)
	{
		if(dpoy[i].judgeDPOY()) dpoy[i].show();
	}
	
	
	return 0;
}

/*
ads 198.5 96.2
30 30 30 30 30
30 30 30 30 30
30 30 30 30 30
22.7 10.8 5.2 21.7 0.8
26.6 8.1 6.22 21.4 0.9
248.8 9.5 53.82 1.2 11.6
243.2 12.3 10.5 2.7 11.8
225.2 10.9 7.1 1.4 2.4
212.4 15.6 43.0 1.92 1.2
232.8 123.0 4.8 12.1 0.6
28.9 10.7 8.6 10.5 1.7
26.2 5.9 62.12 11.2 2.1
*/

//output
/*
球员姓名:ads 身高:198.5 体重:96.2
MVP年份:2010 得分:30.0 篮板:30.0 助攻:30.0
MVP年份:2011 得分:30.0 篮板:30.0 助攻:30.0
MVP年份:2012 得分:30.0 篮板:30.0 助攻:30.0
MVP年份:2014 得分:26.6 篮板:8.1 助攻:6.2
MVP年份:2015 得分:248.8 篮板:9.5 助攻:53.8
MVP年份:2016 得分:243.2 篮板:12.3 助攻:10.5
MVP年份:2017 得分:225.2 篮板:10.9 助攻:7.1
MVP年份:2018 得分:212.4 篮板:15.6 助攻:43.0
MVP年份:2020 得分:28.9 篮板:10.7 助攻:8.6
DPOY年份:2010 盖帽:30.0 篮板:30.0 抢断:30.0
DPOY年份:2011 盖帽:30.0 篮板:30.0 抢断:30.0
DPOY年份:2012 盖帽:30.0 篮板:30.0 抢断:30.0
DPOY年份:2016 盖帽:2.7 篮板:12.3 抢断:11.8
*/
