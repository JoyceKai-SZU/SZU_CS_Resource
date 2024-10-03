#include<iostream>
#include<cstring> 
using namespace std;

class CN; //提前声明
class EN; //提前声明

class Weight{ //抽象类
protected:
	char kind[20]; //计重类型
	int gram; //克
public:
	Weight (char tk[]="no name", int tg=0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	
	virtual void Print(ostream & out) = 0; //输出不同类型的计重信息

};


class CN: public Weight { //中国计重
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
		out<<kind<<":"<<jing<<"斤"<<liang<<"两"<<qian<<"钱"
		   <<gram<<"克"<<endl;
	}
	
	friend ostream & operator << (ostream &out,CN &a); 
	
	
};

class EN: public Weight { //英国计重
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
		out<<kind<<":"<<bang<<"磅"<<angsi<<"盎司"<<dalan<<"打兰"
		   <<gram<<"克"<<endl;
	}
	
	friend ostream & operator << (ostream &out,EN &a);
	
	operator CN()   //类型转换运算符 
	{
		EN a=*this;
		int g=a.bang*512+a.angsi*32+a.dalan*2+a.gram;
		return CN(g/5/10/10,g/5/10%10,g/5%10,g%5,"中国计重"); 
	}

};

//以全局函数方式重载输出运算符，代码3-5行…自行编写

//重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用
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

//重载函数必须调用参数Weight对象的Print方法

int main()//主函数
{
	int tw;
	//创建一个中国计重类对象cn
	//构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind

	CN cn(0,0,0,0, "中国计重");
	cin>>tw;
	cn.Convert(tw); //把输入的克数转成中国计重
	cout<<cn;

	//创建英国计重类对象en
	//构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind

	EN en(0,0,0,0,"英国计重");
	cin>>tw;
	en.Convert(tw); //把输入的克数转成英国计重
	cout<<en;
	cn=en; //把英国计重转成中国计重
	cout<<cn;
	return 0;
}

/*
1234
2345
*/

//output
/*
中国计重:2斤4两6钱4克\n
英国计重:4磅9盎司4打兰1克\n
中国计重:4斤6两9钱0克\n
*/

