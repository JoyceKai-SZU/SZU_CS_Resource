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
	
	cout<<round(a*100)/100<<endl;  // �������뵽С�������λ 
	cout<<round(b*100)/100<<endl;
	cout<<floor(a)<<endl<<ceil(a)<<endl; 
	cout<<floor(b)<<endl<<ceil(b)<<endl; 
	
	printf("%.2f %.2f\n",a,b);     // Ҳ�߱���������Ĺ���
	cout<<setprecision(2)<<a<<" "<<b<<endl;   // ����fixed��Ч���� 
	cout<<fixed<<setprecision(2)<<a<<" "<<b<<endl; // ��fixed��ȷ��С�������λ 
	return 0;
}
