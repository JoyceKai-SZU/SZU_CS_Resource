#include<iostream>
using namespace std;


class Student{   //������� 
protected:
	string id,name;
public:
	Student(string i,string n):
		id(i),name(n){}
	
	virtual void display()=0;
	virtual double average()=0;  
	static double mx;  //��ߵ�ƽ���֣������� 
};

double Student::mx=0.0;

class GroupA:public Student{
private:
	int s1,s2;
public:
	GroupA(string i,string n,int sc1,int sc2):
		Student(i,n),s1(sc1),s2(sc2)
	{
		mx=max(mx,average());
	}
	
	void display()
	{
		if(mx==average()) cout<<id<<" "<<name<<endl;
	}
	
	double average()  //�̳��˳����࣬��Ҫ��дvirtual���� 
	{
		return (s1+s2)/2.0; 
	}
	
};


class GroupB:public Student{
private:
	int s1,s2;
	char gs;
public:
	GroupB(string i,string n,int sc1,int sc2,char gss):
		Student(i,n),s1(sc1),s2(sc2),gs(gss)
	{
		mx=max(mx,average());
	}
	
	void display()
	{
		if(mx==average()) cout<<id<<" "<<name<<endl; 
		else if(average()>=mx*0.7&&gs=='A')
			cout<<id<<" "<<name<<endl;
	}
	
	double average()  //�̳��˳����࣬��Ҫ��дvirtual���� 
	{
		return (s1+s2)/2.0; 
	}
};

class GroupC:public Student{
private:
	int s1,s2,s3,s4,s5;
public:
	GroupC(string i,string n,int sc1,int sc2,int sc3,int sc4,int sc5):
		Student(i,n),s1(sc1),s2(sc2),s3(sc3),s4(sc4),s5(sc5){}
	
	
	void display()
	{
		if(average()>=mx*0.9) cout<<id<<" "<<name<<endl;
	}
	
	double average()  //�̳��˳����࣬��Ҫ��дvirtual���� 
	{
		return (s1+s2+s3+s4+s5)/5.0; 
	}
};



int main()
{
    const int Size = 50;
    string num, name;
    int i, ty, s1, s2, s3, s4, s5;
    char gs;
    Student *pS[Size];
    int count = 0;
    for (i = 0; i < Size; i++)
    {
        cin >> ty;
        if (ty == 0)
            break;
        cin >> num >> name >> s1 >> s2;
        switch (ty)
        {
        case 1:
            pS[count++] = new GroupA(num, name, s1, s2);
            break;
        case 2:
            cin >> gs;
            pS[count++] = new GroupB(num, name, s1, s2, gs);
            break;
        case 3:
            cin >> s3 >> s4 >> s5;
            pS[count++] = new GroupC(num, name, s1, s2, s3, s4, s5);
            break;
        }
    }
    for (i = 0; i < count; i++)
    {
        pS[i]->display();
        delete pS[i];
    }
    return 0;
}
