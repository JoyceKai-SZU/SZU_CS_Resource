#include<iostream>
using namespace std;


class Metal{
private:
	int h;  //硬度 
	int w;	//重量 
	int v;	//体积 
public:
	Metal(int hh,int ww,int vv):
		h(hh),w(ww),v(vv){}
	
	Metal operator + (Metal &a)   //不能直接用*this，会改变原值 
	{
		Metal temp=*this;
		temp.h+=a.h;
		temp.w+=a.w;
		temp.v+=a.v;
		return temp;
	}
	
	Metal operator * (int n)	  //同上 
	{
		Metal temp=*this; 
		temp.v*=n;
		return temp;
	}
	
	Metal& operator ++ ()  //前缀+ 
	{
		++h;
		w*=1.1;
		v*=1.1;
		return *this;
	}
	
	Metal& operator -- ()  //前缀- 
	{
		--h;
		w*=0.9;
		v*=0.9;
		return *this;
	}
	
	void Print()
	{
		cout<<"硬度"<<h<<"--重量"<<w<<"--体积"<<v<<endl; 
	} 
	
	
};



int main()
{
	int h,w,v;
	cin>>h>>w>>v;
	Metal m1(h,w,v);
	
	cin>>h>>w>>v;
	Metal m2(h,w,v);
	
	int n;
	cin>>n;
	
	(m1+m2).Print();
	(m1*n).Print();
	(++m1).Print();
	(--m2).Print();	 
	 
	return 0;
}

/*运算符重载经验：
1.+、-、*、/建议开临时变量
2.++、--建议用*this
3.+=、-=、*=、/=建议用*this 

*/
 

/*
3 3000 300
5 5000 500
2

*/

//output
/*
硬度8--重量8000--体积800\n
硬度3--重量3000--体积600\n
硬度4--重量3300--体积330\n
硬度4--重量4500--体积450\n
*/
