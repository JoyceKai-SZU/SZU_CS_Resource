#include<iostream>
#include<cstring> 
using namespace std;

class CN; //��ǰ����
class EN; //��ǰ����

class Weight{ //������
protected:
	char kind[20]; //��������
	int gram; //��
public:
	Weight (char tk[]="no name", int tg=0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	
	virtual void Print(ostream & out) = 0; //�����ͬ���͵ļ�����Ϣ

};


class CN: public Weight { //�й�����
private:
	int jing,liang,qian;
public:
	CN(int j,int l,int q,int g,char tk[]):
		jing(j),liang(l),qian(q),Weight(tk,g){}
	
	void Convert(int g)
	{
		jing=g/5/10/10;
		liang=g/5/10%10;
		qian=g/5%10;
		gram=g%5; 
	}
	
	void Print(ostream & out)
	{
		out<<kind<<":"<<jing<<"��"<<liang<<"��"<<qian<<"Ǯ"
		   <<gram<<"��"<<endl;
	}
	
	friend ostream & operator << (ostream &out,CN &a); 
	
	
};

class EN: public Weight { //Ӣ������
private:
	int bang,angsi,dalan;
public:
	EN(int b,int as,int dl,int g,char tk[]):
		bang(b),angsi(as),dalan(dl),Weight(tk,g){}
	
	void Convert(int g)
	{
		bang=g/2/16/16;
		angsi=g/2/16%16;
		dalan=g/2%16;
		gram=g%2; 
	}
	
	void Print(ostream & out)
	{
		out<<kind<<":"<<bang<<"��"<<angsi<<"��˾"<<dalan<<"����"
		   <<gram<<"��"<<endl;
	}
	
	friend ostream & operator << (ostream &out,EN &a);
	
	operator CN()   //����ת������� 
	{
		EN a=*this;
		int g=a.bang*512+a.angsi*32+a.dalan*2+a.gram;
		return CN(g/5/10/10,g/5/10%10,g/5%10,g%5,"�й�����"); 
	}

};

//��ȫ�ֺ�����ʽ������������������3-5�С����б�д

//���غ�����������������ostream������Weight����󣬲��������Ƕ�����������
ostream & operator << (ostream &out,CN &a)
{
	a.Print(out);
	return out;
}

ostream & operator << (ostream &out,EN &a)
{
	a.Print(out);
	return out;
}

//���غ���������ò���Weight�����Print����

int main()//������
{
	int tw;
	//����һ���й����������cn
	//���������Ӧ�����Ǯ���ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind

	CN cn(0,0,0,0, "�й�����");
	cin>>tw;
	cn.Convert(tw); //������Ŀ���ת���й�����
	cout<<cn;

	//����Ӣ�����������en
	//���������Ӧ������˾���������ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind

	EN en(0,0,0,0,"Ӣ������");
	cin>>tw;
	en.Convert(tw); //������Ŀ���ת��Ӣ������
	cout<<en;
	cn=en; //��Ӣ������ת���й�����
	cout<<cn;
	return 0;
}

/*
1234
2345
*/

//output
/*
�й�����:2��4��6Ǯ4��\n
Ӣ������:4��9��˾4����1��\n
�й�����:4��6��9Ǯ0��\n
*/

