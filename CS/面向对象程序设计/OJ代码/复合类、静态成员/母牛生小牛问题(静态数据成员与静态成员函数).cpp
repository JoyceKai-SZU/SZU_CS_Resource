#include<iostream>
using namespace std;

class Cow{
private:
	int num;
	static int total;    //当前母牛总数 
public:
	Cow(){}
	~Cow()
	{
		total=0;
	}
	void setNum(int n){num=n;}
	int getNum(){return num;}
	
	static void setTotal(int n){total=n;}
	static int getTotal(){return total;}
	
	void addnum(int d){num+=d;}
	static void addTotal(int d){total+=d;}
};

int Cow::total=0;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int cnt;
		cin>>cnt;
		Cow *p=new Cow[cnt+1];   //p[i]:前i年母牛的总数 
		p[1].setNum(1);
		Cow::setTotal(1);
		for(int i=2;i<=cnt;i++)    //有动态规划的味道 
		{
			p[i].setNum(p[i-1].getNum());
			
		
			if(i>=11)  //母牛寿命到了 
			{
				p[i].addTotal(-p[i-10].getNum());  //总数得减 
				for(int j=i;j>=i-10;j--)
					p[j].addnum(-p[i-10].getNum());   //更新一下p[i] 
				
			} 
			
			
			if(i>=4)   //母牛生小母牛 (剩下活着的母牛才能生，不能和上面换顺序)
			{
				p[i].addnum(p[i-3].getNum());
				p[i].addTotal(p[i-3].getNum());
			}
			
			
		}
		
		cout<<Cow::getTotal()<<endl;
		delete [] p;
	}

	return 0;
}
