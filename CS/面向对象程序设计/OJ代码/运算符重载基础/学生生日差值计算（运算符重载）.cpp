#include<iostream>
#include<vector>
using namespace std;


class CDate{
private:
	int y,m,d;
public:
	CDate(){}
	CDate(int y,int m,int d):y(y),m(m),d(d){}
	bool isleap(int y)
	{
		return y%400==0||(y%100!=0&&y%4==0);
	}
	bool operator < (const CDate &b)const
	{
		if(y!=b.y) return y<b.y;
		else if(m!=b.m) return m<b.m;
		else if(d!=b.d) return d<b.d;
	}
	
	bool operator == (const CDate &b)const
	{
		return y==b.y&&m==b.m&&d==b.d;
	}
	
	bool operator != (const CDate &b)const
	{
		return !(*this==b);
	}
	
	CDate& operator ++ ()   //++CDate,不能加第三个const 
	{
		int D[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		if(isleap(y)) D[2]=29;
		else D[2]=28;
		
		if(m==12&&d==D[m])
		{
			y++;
			m=1;
			d=1;
		}
		else if(d==D[m])
		{
			m++;
			d=1;
		}
		else d++;
		
		return *this;
	}
	
	int operator - (CDate b)
	{
		int ans=0;
		CDate a=*this;
		if(b<a) swap(a,b);
		
		while(a!=b)
		{
			ans++;
			++a;
		}
		
		return ans;
	}
	 
};

class Student{
private:
	string name;
	CDate birth;
public:
	Student(string name,int y,int m,int d):name(name),birth(y,m,d){}
	string getName(){return name;}
	CDate getBirth(){return birth;}
	
};

int main()
{
	int n;
	string name;
	int y,m,d;
	vector<Student> stu;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>name>>y>>m>>d;
		Student temp(name,y,m,d);
		stu.push_back(temp);
	} 
	
	int mx=-1,id1=-1,id2=-1;
	for(int i=0;i<stu.size();i++)
	{
		for(int j=i+1;j<stu.size();j++)
		{
			if(mx<stu[i].getBirth()-stu[j].getBirth())
			{
				mx=stu[i].getBirth()-stu[j].getBirth();
				id1=i;
				id2=j;
			}
		}
	}
	
	cout<<stu[id1].getName()<<"和"<<""<<stu[id2].getName()<<"年龄相差最大，为"<<mx<<"天。";
	
	return 0;
}
