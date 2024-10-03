#include<iostream>
#include<vector> 
using namespace std;

class Record{
protected:
	string name;
	int passtime;
	int passnum;
public:
	Record(string n,int pt,int pn):
		name(n),passtime(pt),passnum(pn){}
		
	void addpass(int d){passnum+=d;}  //注意不要有返回值，否则OJ不过 
	int getPass(){return passnum;}
	
};

class SZUOJ:public Record{
private:
	string id;
public:
	SZUOJ(string n,int pt,int pn,string _id):
		Record(n,pt,pn),id(_id){}
	
	string getID(){return id;}
	

	
};

class Codeforces:public Record{
private:
	string email;
public:
	Codeforces(string n,int pt,int pn,string em):
		Record(n,pt,pn),email(em){}
	
	string getEmail(){return email;}
	
	
};

class Student:public Record{
private:
	int totalpass;
public:
	Student(string n,int pt,int pn,int tp):
		Record(n,pt,pn),totalpass(tp)
	{
		
	}
	void addnum(int d){totalpass+=d;}
	void display()
	{
		cout<<name<<", "<<totalpass;
		
		if(totalpass<=1) cout<<" problem solved, ";
		else cout<<" problems solved, ";
		
		if(totalpass>=1000) cout<<"Legendary Grandmaster";
		else if(totalpass>=500) cout<<"Master";
		else if(totalpass>=200) cout<<"Expert";
		else if(totalpass>=100) cout<<"Specialist";
		else if(totalpass>=0) cout<<"Pupil";
		
		cout<<endl;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;
	vector<Student> stu;
	vector<SZUOJ> szuoj;
	vector<Codeforces> cf;
	
	for(int i=0;i<n;i++)
	{
		string name,id,email;
		cin>>name>>id>>email;
		stu.emplace_back(name,0,0,0);
		szuoj.emplace_back(name,0,0,id);
		cf.emplace_back(name,0,0,email);
	}
	

	while(m--)
	{
		string op;
		string name,id,email,pst;
		int pass;
		cin>>op;
		if(op=="SZUoj")
		{
			cin>>id>>pass>>pst;
			for(int i=0;i<szuoj.size();i++)
			{
				if(id==szuoj[i].getID())
				{
					szuoj[i].addpass(pass);
					break;
				}
			}
		}
		else if(op=="Codeforces")
		{
			cin>>email>>pass>>pst;
			for(int i=0;i<cf.size();i++)
			{
				if(email==cf[i].getEmail())
				{
					cf[i].addpass(pass);
					break;
				}
			}
		}
	}
	
	for(int i=0;i<stu.size();i++)
	{
		stu[i].addnum(szuoj[i].getPass()+cf[i].getPass());
		stu[i].display();
	}
	
	
	return 0;
}

/*
3 7
yxdl 2019150000 yxdlakwf@qq.com
qwq 2019150001 yxdlyyds@qq.com
cb 2019150003 wtcl@136.com
SZUoj 2019150000 8 2021/8/5
SZUoj 2019150001 1 2021/8/6
Codeforces yxdlakwf@qq.com 100 2021/8/9
Codeforces yxdlakwf@qq.com 9 2021/8/8
Codeforces wtcl@136.com 1 2021/1/5
Codeforces yxdlakwf@qq.com 999 2021/8/10
SZUoj 2019150001 200 2021/8/6
*/

//output
/*
yxdl, 1116 problems solved, Legendary Grandmaster\n
qwq, 201 problems solved, Expert\n
cb, 1 problem solved, Pupil
*/

/*
5 9
yxdl 2019150000 yxdlakwf@qq.com
qwq 2019150001 yxdlyyds@qq.com
qaq 2019150002 yxdltqlorz@qq.com
cb 2019150003 wtcl@136.com
ovo 2019150004 111@qq.com
SZUoj 2019150000 8 2021/8/5
SZUoj 2019150001 1 2021/8/6
Codeforces yxdlakwf@qq.com 100 2021/8/9
Codeforces yxdlakwf@qq.com 9 2021/8/8
Codeforces wtcl@136.com 1 2021/1/5
Codeforces yxdlakwf@qq.com 999 2021/8/10
SZUoj 2019150001 200 2021/8/6
Codeforces  yxdltqlorz@qq.com 99 2021/8/10
SZUoj 2019150003 11 1990/2/3
*/

//output
/*
yxdl, 1116 problems solved, Legendary Grandmaster
qwq, 201 problems solved, Expert
qaq, 99 problems solved, Pupil
cb, 12 problems solved, Pupil
ovo, 0 problem solved, Pupil
*/
