#include<iostream>
using namespace std;

template<class T>
T Max(T arr[],int len)
{
	T mx=-1;
	for(int i=0;i<len;i++)
	{
		mx=max(mx,arr[i]);
	}
	return mx;
}

template<class T>
class Cryption {
private: 
	T ptxt[100];//明文
	T ctxt[100];//密文
	T key;//密钥
	int len;//长度
public:
	Cryption(T tk, T tt[], int tl); //参数依次对应密钥、明文、长度
	void Encrypt(); //加密
	void Print() //打印，无需改造
	{
		int i;
		for (i=0; i<len-1; i++)
			cout<<ctxt[i]<<" ";
		cout<<ctxt[i]<<endl;

	}
};

//外面定义类模板成员函数格式
//1.template<class T>都要加
//2.类模板名称空间要带<T> 

template<class T>   
Cryption<T>::Cryption(T tk, T tt[], int tl):len(tl),key(tk)
{
	for(int i=0;i<len;i++) ptxt[i]=tt[i];
}

template<class T>
void Cryption<T>::Encrypt()
{
	T mx=Max(ptxt,len);
	
	T temp[100];
	for(int i=0;i<len;i++)
	{
		temp[i]=ptxt[i];
		temp[i]=mx-temp[i];
	}
	
	for(int i=0;i<len;i++) ctxt[i]=key+temp[i];
}


//支持三种类型的主函数

int main()
{
	int i;
	int length; //长度
	int ik, itxt[100];
	double dk, dtxt[100];
	char ck, ctxt[100];

	//整数加密
	cin>>ik>>length;
	for (i=0; i<length; i++)
		cin>>itxt[i];
	Cryption<int> ic(ik, itxt, length);  //要补上<---> 
	ic.Encrypt();
	ic.Print();

	//浮点数加密
	cin>>dk>>length;
	for (i=0; i<length; i++)
		cin>>dtxt[i];
	Cryption<double> dc(dk, dtxt, length);
	dc.Encrypt();
	dc.Print();

	//字符加密
	cin>>ck>>length;
	for (i=0; i<length; i++)
		cin>>ctxt[i];
	Cryption<char> cc(ck, ctxt, length);
	cc.Encrypt();
	cc.Print();
	return 0;
}

/*
10 5 1 2 3 4 5
11.11 4 1.1 2.2 3.3 4.4
O 3 a b c
*/

//output
/*
14 13 12 11 10
14.41 13.31 12.21 11.11
Q P O
*/

