#include<iostream>
#include<cstring>
using namespace std;

class CDate{
private:
	int y,m,d;
public:
	CDate(int num=0)
	{
		if(!num)    //Ҫ�ӣ����������� 
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
		printf("%d��%02d��%02d��\n",y,m,d);
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
		((C1>C2)?C1:C2).Print(); //���ڴ��������ڴ���C1>C2�У����Զ���C1��C2ת��Ϊ�������бȽ�
	}
	return 0;
}
