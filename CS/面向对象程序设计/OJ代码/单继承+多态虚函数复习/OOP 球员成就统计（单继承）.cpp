#include<iostream>
#include<vector>
using namespace std;

class Player{
protected:
	string name;
	double height,weight;  //�����Ŀ� 
public:
	Player(){}
	Player(string n,double h,double w):
		name(n),height(h),weight(w){}
	
	void show()
	{
		cout<<"��Ա����:"<<name<<" ���:"<<height<<" ����:"
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
	{	cout<<"MVP���:"<<mvpyear; 
	
		cout.setf(ios::fixed);
		cout.precision(1);
		cout<<" �÷�:"<<score<<" ����:"
			<<lb<<" ����:"<<zg<<endl;
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
		cout<<"DPOY���:"<<dpyear;
		cout.setf(ios::fixed);
		cout.precision(1);
		cout<<" ��ñ:"<<gm<<" ����:"
			<<lb<<" ����:"<<qd<<endl;
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
		double score,lb,zg,gm,qd;  //ע����double 
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
��Ա����:ads ���:198.5 ����:96.2
MVP���:2010 �÷�:30.0 ����:30.0 ����:30.0
MVP���:2011 �÷�:30.0 ����:30.0 ����:30.0
MVP���:2012 �÷�:30.0 ����:30.0 ����:30.0
MVP���:2014 �÷�:26.6 ����:8.1 ����:6.2
MVP���:2015 �÷�:248.8 ����:9.5 ����:53.8
MVP���:2016 �÷�:243.2 ����:12.3 ����:10.5
MVP���:2017 �÷�:225.2 ����:10.9 ����:7.1
MVP���:2018 �÷�:212.4 ����:15.6 ����:43.0
MVP���:2020 �÷�:28.9 ����:10.7 ����:8.6
DPOY���:2010 ��ñ:30.0 ����:30.0 ����:30.0
DPOY���:2011 ��ñ:30.0 ����:30.0 ����:30.0
DPOY���:2012 ��ñ:30.0 ����:30.0 ����:30.0
DPOY���:2016 ��ñ:2.7 ����:12.3 ����:11.8
*/
