#include<iostream>
using namespace std;

template <typename RT, typename T2, typename T1>  //class也可以 
RT Add(T1 a, T2 b)         //RT作为返回类型
{
    return static_cast<RT>(a+b);
}

int main()
{
	cout<<Add<int>('a',100)<<endl;
	
	return 0;
} 
