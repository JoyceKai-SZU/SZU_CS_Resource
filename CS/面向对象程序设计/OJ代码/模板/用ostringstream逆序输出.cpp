#include<iostream>
#include<sstream>
#include<algorithm> 
using namespace std;

int main()
{
	double num;
	cin>>num;
	ostringstream o;
	o<<num;
	string str=o.str();
	reverse(str.begin(),str.end());
	if(num<0)
	{
		str.pop_back();
		str.insert(str.begin(),'-');
	}
	
	//cout<<stod(str)<<endl;  //除前导0法一 
	
	//除前导0法二 
	for(auto it=str.begin();it!=str.end();it++)
	{
		if(*it!='0') break;
		str.erase(it);
	} 
	
	cout<<str<<endl;
	return 0;
} 
