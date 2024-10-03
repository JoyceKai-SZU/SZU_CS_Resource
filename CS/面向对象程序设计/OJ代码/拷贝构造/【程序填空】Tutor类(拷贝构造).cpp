#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//���ʵ����STU�Ķ���
/********** Write your code here! **********/

class STU{
private:
	string name;
public:
	STU(string name);
	STU(const STU& b);
	~STU();
};


STU::STU(string name):name(name)
{
	cout<<"Construct student "<<name<<endl;
}

STU::STU(const STU& b):name(b.name+"_copy")
{
	cout<<"Construct student "<<name<<endl;
}


STU::~STU()
{
	cout<<"Destruct student "<<name<<endl;
}


/*******************************************/
//������������
int IDs; //ȫ�ֱ�����������������ʾ
class Tutor {
private:
	STU stu;
public:
	Tutor(STU & s): stu(s)
	{	cout<<"Construct tutor "<<IDs<<endl;	}
	~Tutor()
	{	cout<<"Destruct tutor "<<IDs<<endl;	}

};
void fuc(Tutor x)
{	cout<<"In function fuc()"<<endl;	}

int main()
{	cin>>IDs;
	STU s1("Tom"); //����ѧ������Tom
	Tutor t1(s1);
	IDs++;
	cout<<"Calling fuc()"<<endl;
	fuc(t1);

	return 0;
}

/*
100
*/

//output
/*
Construct student Tom\n
Construct student Tom_copy\n
Construct tutor 100\n
Calling fuc()\n
Construct student Tom_copy_copy\n
In function fuc()\n
Destruct tutor 101\n
Destruct student Tom_copy_copy\n
Destruct tutor 101\n
Destruct student Tom_copy\n
Destruct student Tom\n
*/
