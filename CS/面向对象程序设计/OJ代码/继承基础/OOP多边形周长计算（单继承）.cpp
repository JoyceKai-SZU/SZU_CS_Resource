#include<iostream>
using namespace std;

class polygon{ 
protected:
   int number;//边数，最多不超过100条边
private:
   int side_length[100];//边长数组
public:
   polygon(){};//构造函数根据需要重载
   int perimeter();//计算多边形周长
   void display();//输出多边形边数和周长
   polygon(int num):number(num){}
   void setSide(int i,int s);
};

int polygon::perimeter()
{
	int sum=0;
	for(int i=0;i<number;i++)
	{
		sum+=side_length[i];
	}
	return sum;
}

void polygon::setSide(int i,int s)
{
	side_length[i]=s;
	number++;
} 

void polygon::display()
{
	cout<<number<<" "<<perimeter()<<endl;
}


class rectangle:public polygon{  //矩形边长为4 
private:
	int height;
	int width;
public:
	 rectangle(){}
	 rectangle(int num,int h,int w):polygon(num),height(h),width(w){}
	 int perimeter();
	 void display();    //display方法一定要重载，不能直接用polygon的display 
};


int rectangle::perimeter()
{
	return 2*(height+width);
}

void rectangle::display()
{
	cout<<number<<" "<<perimeter()<<endl;
}

class equal_polygon:public polygon{
private:
	int side_len;
public:
	equal_polygon(){}
	equal_polygon(int num,int side):polygon(num),side_len(side){}
	int perimeter();
	void display();      //display方法一定要重载，不能直接用polygon的display 
};

int equal_polygon::perimeter()
{
	return number*side_len;
}

void equal_polygon::display()
{
	cout<<number<<" "<<perimeter()<<endl;
}

int main()
{
	int t,op;
	cin>>t;
	while(t--)
	{
		cin>>op;
		if(op==0)
		{
			int s,k=0;
			polygon pp(k); 
			while(1)
			{
				cin>>s;
				if(s==-1) break;
				pp.setSide(k,s);
				k++;
			}
			
			pp.display();
			
		}
		else if(op==1)
		{
			int h,w;
			cin>>h>>w;
			rectangle rr(4,h,w);
			rr.display();
		}
		else
		{
			int n,side;
			cin>>n>>side;
			equal_polygon ee(n,side);
			ee.display(); 
		}
	}
	return 0; 
}

/*
3
0 32 54 76 88 24 -1
1 32 54
2 3 32
*/

//output
/*
5 274\n
4 172\n
3 96
*/
