#include<iostream>
using namespace std;


class Metal{
private:
	int h;  //Ӳ�� 
	int w;	//���� 
	int v;	//��� 
public:
	Metal(int hh,int ww,int vv):
		h(hh),w(ww),v(vv){}
	
	Metal operator + (Metal &a)   //����ֱ����*this����ı�ԭֵ 
	{
		Metal temp=*this;
		temp.h+=a.h;
		temp.w+=a.w;
		temp.v+=a.v;
		return temp;
	}
	
	Metal operator * (int n)	  //ͬ�� 
	{
		Metal temp=*this; 
		temp.v*=n;
		return temp;
	}
	
	Metal& operator ++ ()  //ǰ׺+ 
	{
		++h;
		w*=1.1;
		v*=1.1;
		return *this;
	}
	
	Metal& operator -- ()  //ǰ׺- 
	{
		--h;
		w*=0.9;
		v*=0.9;
		return *this;
	}
	
	void Print()
	{
		cout<<"Ӳ��"<<h<<"--����"<<w<<"--���"<<v<<endl; 
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

/*��������ؾ��飺
1.+��-��*��/���鿪��ʱ����
2.++��--������*this
3.+=��-=��*=��/=������*this 

*/
 

/*
3 3000 300
5 5000 500
2

*/

//output
/*
Ӳ��8--����8000--���800\n
Ӳ��3--����3000--���600\n
Ӳ��4--����3300--���330\n
Ӳ��4--����4500--���450\n
*/
