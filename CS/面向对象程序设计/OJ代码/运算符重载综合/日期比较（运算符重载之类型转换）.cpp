#include<iostream>
#include<cstring>
using namespace std;

class CDate{
private:
	int y,m,d;
public:
	CDate(int num=0)
	{
		if(!num)    //要加，否则会出问题 
		{
			y=m=d=0;
			return;
		}
		
		string str=to_string(num);
		y=stoi(str.substr(0,4));
		m=stoi(str.substr(4,2));
		d=stoi(str.substr(6,2));
	}
	
	operator int()
	{
		return y*10000+m*100+d;
	}
	
	void Print()
	{
		printf("%d年%02d月%02d日\n",y,m,d);
	}
};




int main()
{
	int t, t1, t2;
	CDate C1, C2;
	cin>>t;
	while (t--)
	{
		cin>>t1>>t2;
		C1 = t1;
		C2 = t2;
		((C1>C2)?C1:C2).Print(); //日期大的输出，在代码C1>C2中，会自动把C1和C2转换为整数进行比较
	}
	return 0;
}
