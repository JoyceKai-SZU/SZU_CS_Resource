#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	string a="东南西北";
	cout<<a.substr(0,2)<<endl;   //一个汉字oj三个字节 ,dev是2个字节 
	return 0;
}
