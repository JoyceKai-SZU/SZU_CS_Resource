#include<iostream>
using namespace std;

class Student {
private:
	int id;//ѧ��
	int score; //�ɼ�
	static int maxscore;//��߷���
	static int maxid;//��߷���ѧ��ѧ��
public:
	Student(int ti=0,int ts=0):id(ti), score(ts){}
	static void findMax(Student & st); //Ѱ����߳ɼ���ѧ��
	static int getMaxScore(); //������߳ɼ�
	static int getMaxID();//������߳ɼ���ѧ��
};

int Student::maxscore=0;  //ǰ��Ҫ������ 
int Student::maxid=0;

void Student::findMax(Student & st)
{
	if(maxscore<st.score)
	{
		maxscore=st.score;
		maxid=st.id;
	}
}

int Student::getMaxScore(){return maxscore;}
int Student::getMaxID(){return maxid;}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int id,score;
		cin>>id>>score;
		Student s(id,score);
		Student::findMax(s);
	}
	
	cout<<Student::getMaxID()<<"--"<<Student::getMaxScore()<<endl;
	return 0;
}
