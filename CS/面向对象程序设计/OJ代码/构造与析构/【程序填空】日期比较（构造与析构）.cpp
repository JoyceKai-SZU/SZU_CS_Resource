//头文件和类声明
#include <iostream>
using namespace std;

class MyDate {
private:
	int year;
	int month;
	int day;
public:
	MyDate(); //无参构造，默认日期2022-4-1，输出相关构造信息
	MyDate(int ty, int tm, int td); //有参构造，根据参数初始化，输出相关构造信息
	~MyDate(); 
	bool Before(MyDate &rd);
	void print()
	{ cout<<year<<"-"<<month<<"-"<<day; }
};
//下面填写类实现和主函数
/********** Write your code here! **********/

MyDate::MyDate()
{
	year=2022;month=4;day=1;
	cout<<"Date ";
	print();
	cout<<" default constructed"<<endl; 
}

MyDate::MyDate(int ty,int tm,int td)
{
	year=ty;month=tm;day=td;
	cout<<"Date ";
	print();
	cout<<" constructed"<<endl; 
}

MyDate::~MyDate()
{
	cout<<"Date ";
	print();
	cout<<" destructed"<<endl;
}

bool MyDate::Before(MyDate &rd)  //在类里不管是其他对象的private是可以直接用的 
{
	if(year!=rd.year) return year<rd.year;
    else if(month!=rd.month) return month<rd.month;
    else return day<rd.day;

}




int main()
{
	MyDate d0;
	int t;
	cin>>t;
	while(t--)
	{
		int y,m,day;
		cin>>y>>m>>day;
		MyDate d(y,m,day);
		if(d.Before(d0))
		{
			d.print();
			cout<<" before ";
			d0.print();
			cout<<endl;
		}
		else
		{
			d0.print();
			cout<<" before ";
			d.print();
			cout<<endl;
		}
	} 
	return 0;
} 

/*******************************************/
//main end 

