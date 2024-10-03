//头文件和日期类声明
#include<iostream>
#include<iomanip>
using namespace std;
 
class TDate {
private:
    int year,month,day;
public:
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}
    void set(int y,int m,int d);
    void print();
    void addOneDay();
};

//----在以下区域完成部分成员函数的类外定义----
/********** Write your code here! **********/
void TDate::set(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
}

void TDate::print()
{
	cout<<year;
	if(month<10) cout<<0<<month;
	else cout<<month;
	
	if(day<10) cout<<0<<day;
	else cout<<day;
}

void TDate::addOneDay()
{
	int D[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(year%400==0||(year%100!=0&&year%4==0)) D[2]=29;
	if(month==12&&day==31)
	{
		year++;
		month=1;
		day=1;
	}
	else if(day+1>D[month])
	{
		day=1;
		month++;
	}
	else day++;
	
	
}



/*******************************************/
//主函数如下
int main()
{   int t, y,m,d;
    cin>>t;
    while(t--)
    {	TDate d1;
		cin>>y>>m>>d;
		d1.set(y, m, d);
        cout<<"Today-";
        d1.print();
        d1.addOneDay();
        cout<<" Tomorrow-";
        d1.print();
		cout<<endl;
    }
    return 0;
}

