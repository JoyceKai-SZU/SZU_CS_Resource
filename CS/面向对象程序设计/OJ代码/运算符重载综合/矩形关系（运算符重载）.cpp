#include<iostream>
#include<cmath>
using namespace std;


class CPoint{
protected:
	int x,y;
public:
	CPoint(int xx,int yy):x(xx),y(yy){}
	int getX(){return x;}
	int getY(){return y;}
	
	bool operator == (CPoint &a)
	{
		return x==a.x&&y==a.y;
	}
};


class CRectangle{
private:
	CPoint leftPoint,rightPoint;  //���Ͻǣ����½� 
public:
	CRectangle(int x1,int y1,int x2,int y2):leftPoint(x1,y1),rightPoint(x2,y2){}
	friend ostream & operator << (ostream &output,CRectangle &a);
	
	operator int()
	{
		int a=abs(rightPoint.getX()-leftPoint.getX());
		int b=abs(rightPoint.getY()-leftPoint.getY());
		
		return a*b;
	}
	
	bool operator == (CRectangle &a)  //����������ȣ����������Ͻǵ�����½ǵ�ֱ��Ӧ��� 
	{
		return leftPoint==a.leftPoint&&rightPoint==a.rightPoint;
	}
	
	bool operator * (CRectangle &a)   //�ж����������Ƿ����ص�����
	{
		//����1 
		int up1=max(leftPoint.getY(),rightPoint.getY());
		int down1=min(leftPoint.getY(),rightPoint.getY());
		int left1=min(leftPoint.getX(),rightPoint.getX());
		int right1=max(leftPoint.getX(),rightPoint.getX());
		
		//����2
		int up2=max(a.leftPoint.getY(),a.rightPoint.getY());
		int down2=min(a.leftPoint.getY(),a.rightPoint.getY());
		int left2=min(a.leftPoint.getX(),a.rightPoint.getX());
		int right2=max(a.leftPoint.getX(),a.rightPoint.getX());
		
		if(up1<down2||up2<down1) return false;
		if(right1<left2||right2<left1) return false;
		
		return true;
	} 
	
	bool operator > (CPoint &a)
	{
		int up=max(leftPoint.getY(),rightPoint.getY());
		int down=min(leftPoint.getY(),rightPoint.getY());
		int left=min(leftPoint.getX(),rightPoint.getX());
		int right=max(leftPoint.getX(),rightPoint.getX());
		
		int ax=a.getX(), ay=a.getY();
		return ax>=left&&ax<=right&&ay>=down&&ay<=up;
	}
	
	bool operator > (CRectangle &r)
	{
		return *this>r.leftPoint&& *this>r.rightPoint;
	}
	
	
};

ostream & operator << (ostream &output,CRectangle &a)
{
	
	output<<a.leftPoint.getX()<<" "<<a.leftPoint.getY()<<" "
		  <<a.rightPoint.getX()<<" "<<a.rightPoint.getY();
		  
	return output;
}



int main()
{
	int t,x1,x2,y1,y2;
	cin>>t;
	
	while(t--)
	{
		cin>>x1>>y1>>x2>>y2;
		CRectangle rect1(x1,y1,x2,y2);
		cin>>x1>>y1>>x2>>y2;
		CRectangle rect2(x1,y1,x2,y2);
		
		cout<<"����1:"<<rect1<<" "<<(int)rect1<<endl;
		cout<<"����2:"<<rect2<<" "<<(int)rect2<<endl;
		
		if(rect1==rect2)
			cout<<"����1�;���2���"<<endl;
		else if(rect2>rect1) 
			cout<<"����2��������1"<<endl;
		else if(rect1>rect2) 
			cout<<"����1��������2"<<endl;
		else if(rect1*rect2)
			cout<<"����1�;���2�ཻ"<<endl;
		else
			cout<<"����1�;���2���ཻ"<<endl;
		cout<<endl; 
	} 
	
	return 0;
}

/*
2
1 4 4 1
2 3 3 2
1 4 4 1
0 3 5 2
*/


//output
/*
����1:1 4 4 1 9\n
����2:2 3 3 2 1\n
����1��������2\n
\n
����1:1 4 4 1 9\n
����2:0 3 5 2 5\n
����1�;���2�ཻ
*/ 
