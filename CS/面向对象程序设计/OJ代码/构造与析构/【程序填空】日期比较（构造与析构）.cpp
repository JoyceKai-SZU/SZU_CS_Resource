//ͷ�ļ���������
#include <iostream>
using namespace std;

class MyDate {
private:
	int year;
	int month;
	int day;
public:
	MyDate(); //�޲ι��죬Ĭ������2022-4-1�������ع�����Ϣ
	MyDate(int ty, int tm, int td); //�вι��죬���ݲ�����ʼ���������ع�����Ϣ
	~MyDate(); 
	bool Before(MyDate &rd);
	void print()
	{ cout<<year<<"-"<<month<<"-"<<day; }
};
//������д��ʵ�ֺ�������
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

bool MyDate::Before(MyDate &rd)  //�����ﲻ�������������private�ǿ���ֱ���õ� 
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

