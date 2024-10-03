#include<iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
using namespace std;

int main()
{
	double a=1.2355;
	double b=-1.2355;
	cout<<round(a)<<endl;
	cout<<round(b)<<endl;
	
	cout<<round(a*100)/100<<endl;  // 四舍五入到小数点后两位 
	cout<<round(b*100)/100<<endl;
	cout<<floor(a)<<endl<<ceil(a)<<endl; 
	cout<<floor(b)<<endl<<ceil(b)<<endl; 
	
	printf("%.2f %.2f\n",a,b);     // 也具备四舍五入的功能
	cout<<setprecision(2)<<a<<" "<<b<<endl;   // 不加fixed有效数字 
	cout<<fixed<<setprecision(2)<<a<<" "<<b<<endl; // 加fixed精确到小数点后两位 
	return 0;
}
