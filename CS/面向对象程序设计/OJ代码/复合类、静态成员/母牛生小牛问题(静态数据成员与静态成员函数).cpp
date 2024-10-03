#include<iostream>
using namespace std;

class Cow{
private:
	int num;
	static int total;    //��ǰĸţ���� 
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
		Cow *p=new Cow[cnt+1];   //p[i]:ǰi��ĸţ������ 
		p[1].setNum(1);
		Cow::setTotal(1);
		for(int i=2;i<=cnt;i++)    //�ж�̬�滮��ζ�� 
		{
			p[i].setNum(p[i-1].getNum());
			
		
			if(i>=11)  //ĸţ�������� 
			{
				p[i].addTotal(-p[i-10].getNum());  //�����ü� 
				for(int j=i;j>=i-10;j--)
					p[j].addnum(-p[i-10].getNum());   //����һ��p[i] 
				
			} 
			
			
			if(i>=4)   //ĸţ��Сĸţ (ʣ�»��ŵ�ĸţ�����������ܺ����滻˳��)
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
