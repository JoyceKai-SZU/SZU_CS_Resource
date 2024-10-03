#include<typeinfo>
#include<iostream>
#include<cxxabi.h> 
using namespace std;

template<class T>
void fun(T* a)
{
	//T x, y;
	cout << "T type : " << abi::__cxa_demangle(typeid(T).name(),0,0,0) << endl;
	cout << "a type : " << abi::__cxa_demangle(typeid(a).name(),0,0,0) << endl;
}
int main(void)
{
	int x = 10;
	//fun(x);
	fun(&x);    //Ö¸Õë³£Á¿ 

	return 0;
}

