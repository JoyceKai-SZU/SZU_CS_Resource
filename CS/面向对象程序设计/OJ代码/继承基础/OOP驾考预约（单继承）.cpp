#include<iostream>
using namespace std;
typedef long long ll;

class CPerson{
protected:
	string name;
	ll phone;
public:
	CPerson(){}
	CPerson(string name,ll phone):name(name),phone(phone){}
	
};

class Stu:public CPerson{
protected:
	int Atime[12];  //单位是分钟 
public:
	Stu(){}
	Stu(string name,ll phone,int *arr):CPerson(name,phone)
	{
		for(int i=0;i<12;i++) Atime[i]=arr[i];
	} 
	void check()
	{
		int sum=0;
		for(int i=0;i<12;i++)
		{
			int temp=Atime[i]/60;
			if(temp>1) temp=1;
			sum+=temp;
		}
		
		if(sum>=10) cout<<name<<"达到学时要求可以预约！电话"<<phone<<endl;
		else cout<<name<<"未达到学时要求不能预约！电话"<<phone<<endl;
	}
};

class VIP:public Stu{
private:
	int Btime[12];  //单位是分钟 
public:
	VIP(){}
	VIP(string name,ll phone,int *arrA,int *arrB):Stu(name,phone,arrA)
	{
		for(int i=0;i<12;i++) Btime[i]=arrB[i];
	}
	
	void check()
	{
		int sum=0;
		for(int i=0;i<12;i++)
		{
			int temp=Atime[i]/60;
			if(temp>1) temp=1;
			sum+=temp;
		}
		
		for(int i=0;i<12;i++)
		{
			int temp=Btime[i]/60;
			if(temp>2) temp=2;
			sum+=temp;
		}
		
		if(sum>=10) cout<<name<<"达到学时要求可以预约！电话"<<phone<<endl;
		else cout<<name<<"未达到学时要求不能预约！电话"<<phone<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	char type;
	while(t--)
	{
		string name;
		ll phone;
		
		cin>>type>>name>>phone;
		if(type=='F')
		{
			int arrA[12];
			for(int i=0;i<12;i++) cin>>arrA[i];
			Stu s1(name,phone,arrA);
			s1.check();
		}
		else
		{
			int arrA[12],arrB[12];
			for(int i=0;i<12;i++) cin>>arrA[i];
			for(int i=0;i<12;i++) cin>>arrB[i];
			VIP s2(name,phone,arrA,arrB);
			s2.check();
		}
	}
	return 0;
}
