#include<iostream>
using namespace std;

class CRect;  //要提前声明 
class CPoint{
private:
	int x,y;
public:
	CPoint(){}
	CPoint(int px,int py):x(px),y(py){}
	friend bool isoverlap(CRect &r1,CRect &r2);
};

class CRect{
private:
	CPoint p1,p2;
public:
	CRect(){}
	CRect(CPoint pp1,CPoint pp2):p1(pp1),p2(pp2){}
	friend bool isoverlap(CRect &r1,CRect &r2);
};

bool isoverlap(CRect &r1,CRect &r2)
{
	int r1up=max(r1.p1.y,r1.p2.y);
	int r1down=min(r1.p1.y,r1.p2.y);
	int r1left=min(r1.p1.x,r1.p2.x);
	int r1right=max(r1.p1.x,r1.p2.x);
	
	int r2up=max(r2.p1.y,r2.p2.y);
	int r2down=min(r2.p1.y,r2.p2.y);
	int r2left=min(r2.p1.x,r2.p2.x);
	int r2right=max(r2.p1.x,r2.p2.x);
	
	if(r1up<r2down) return false;
	if(r2up<r1down) return false;
	if(r1right<r2left) return false;
	if(r2right<r1left) return false; 
	
	return true;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		CPoint p1(x1,y1);
		CPoint p2(x2,y2);
		CRect r1(p1,p2);
		
		cin>>x1>>y1>>x2>>y2;
		CPoint p3(x1,y1);
		CPoint p4(x2,y2);
		CRect r2(p3,p4);
		
		if(isoverlap(r1,r2)) cout<<"overlapped"<<endl;
		else cout<<"not overlapped"<<endl;
	}
	return 0;
}


/*
3
1 5 2 9
1 3 2 4
5 6 7 8
5 7 7 7
2 5 1 0
9 4 2 9
*/

//output
/*
not overlapped\n
overlapped\n
overlapped\n
*/
