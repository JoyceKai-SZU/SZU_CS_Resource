#include<iostream>
using namespace std;

template <typename RT, typename T2, typename T1>  //classҲ���� 
RT Add(T1 a, T2 b)         //RT��Ϊ��������
{
    return static_cast<RT>(a+b);
}

int main()
{
	cout<<Add<int>('a',100)<<endl;
	
	return 0;
} 
