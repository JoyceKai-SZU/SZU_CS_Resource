#include<iostream>
#include<sstream>
using namespace std;


int main()
{
	ostringstream os;    //��ס��ostringstream 
	int x;
	cin>>x;
	os<<x;
	string a="aaa";
	string b=a+os.str();
	cout<<b<<endl;
	
	
	
	return 0;
}
