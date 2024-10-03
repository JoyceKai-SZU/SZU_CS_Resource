#include<iostream>
using namespace std;

class CPeople{
protected:
	string name;
	char sex;
	int age;
public:
	CPeople(string name,char sex,int age):name(name),sex(sex),age(age){}
	void Print()
	{
		cout<<"People:"<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Sex: "<<sex<<endl;
		cout<<"Age: "<<age<<endl;
	}
};


class CStudent:virtual public CPeople{
protected:
	int no;
	double score;
public:
	CStudent(string name,char sex,int age,int no,double score):
		CPeople(name,sex,age),
		no(no),
		score(score)
	{
		
	}
	
	void Print()
	{
		cout<<"Student:"<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Sex: "<<sex<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"No.: "<<no<<endl;
		cout<<"Score: "<<score<<endl; 
	} 
};

class CTeacher:virtual public CPeople{
protected:
	string position,department;
public:
	CTeacher(string name,char sex,int age,string position,string department):
		CPeople(name,sex,age),
		position(position),
		department(department)
	{
		
	}
	
	void Print()
	{
		cout<<"Teacher:"<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Sex: "<<sex<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"Position: "<<position<<endl;
		cout<<"Department: "<<department<<endl;
	}
};

class CGradOnWork:public CStudent,public CTeacher{
private:
	string direction,tutor;
public:
	CGradOnWork(string name,char sex,int age,int no,double score,string position,string department,string direction,string tutor):
		CPeople(name,sex,age),
		CStudent(name,sex,age,no,score),
		CTeacher(name,sex,age,position,department),
		direction(direction),
		tutor(tutor)
	{
		
	}
	
	void Print()
	{
		cout<<"GradOnWork:"<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Sex: "<<sex<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"No.: "<<no<<endl;
		cout<<"Score: "<<score<<endl; 
		cout<<"Position: "<<position<<endl;
		cout<<"Department: "<<department<<endl;
		cout<<"Direction: "<<direction<<endl;
		cout<<"Tutor: "<<tutor<<endl;
	}
};

int main()
{
	string name;
	char sex;
	int age,no;
	double score;
	string position,department,direction,tutor;
	cin>>name>>sex>>age>>no>>score>>position>>department>>direction>>tutor;
	
	CPeople(name,sex,age).Print();
	cout<<endl;
	CStudent(name,sex,age,no,score).Print();
	cout<<endl;
	CTeacher(name,sex,age,position,department).Print();
	cout<<endl;
	CGradOnWork(name,sex,age,no,score,position,department,direction,tutor).Print();
	return 0;
} 
