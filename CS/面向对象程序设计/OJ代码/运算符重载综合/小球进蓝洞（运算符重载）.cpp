#include<iostream>
using namespace std;

const int maxn=15;

class CPoint{
protected:
	int x,y,dir;  
public:
	CPoint(){}
	CPoint(int xx,int yy,int dirc):x(xx),y(yy),dir(dirc){}
	int getX(){return x;}
	int getY(){return y;}
	int getDir(){return dir;}
	void setDir(int d){dir=d;}
	friend ostream & operator << (ostream & output, const CPoint &a); 
	
};

ostream & operator << (ostream & output, const CPoint &a)
{
	output<<a.x<<" "<<a.y<<" "<<a.dir<<endl;
	return output;
}


class CHole:public CPoint{
public:
	CHole(){}
	CHole(int xx,int yy,int dirc):CPoint(xx,yy,dirc){}
};

class CTriangle:public CPoint{  //ע�������εķ���Ͷ��ķ�������� 
public:
	CTriangle(){}
	CTriangle(int xx,int yy,int dirc):CPoint(xx,yy,dirc){}
	void setAll(int xx,int yy,int dirc)
	{
		x=xx;y=yy;dir=dirc;
	} 
	
	CTriangle& operator ++ ()
	{
		if(dir==4) dir=1;
		else ++dir;	
		
		return *this;
	} 
};


class CBall:public CPoint{
public:
	CBall(){}
	CBall(int xx,int yy,int dirc):CPoint(xx,yy,dirc){}
	CBall(CHole &a):CPoint(a.getX(),a.getY(),a.getDir()){}
	bool operator *= (CTriangle &t)   //ʵ��С���������ο���ײ�Ĺ��ܣ��ı�С��ǰ�з���
	{
		if(t.getDir()==1)
		{
			if(dir==3&&x<t.getX()&&y==t.getY())
			{
				dir=2;
				return true;
			}
			else if(dir==0&&x==t.getX()&&y<t.getY())
			{
				dir=1;
				return true;
			}
			else if(dir==1&&x>t.getX()&&y==t.getY())
			{
				dir=3;
				return true;
			}
			else if(dir==2&&x==t.getX()&&y>t.getY())
			{
				dir=0;
				return true;
			}
			
			return false;
		}
		else if(t.getDir()==2)
		{
			if(dir==0&&x==t.getX()&&y<t.getY())
			{
				dir=2;
				return true;
			}
			else if(dir==1&&x>t.getX()&&y==t.getY())
			{
				dir=3;
				return true;
			}
			else if(dir==2&&x==t.getX()&&y>t.getY())
			{
				dir=1;
				return true;
			}
			else if(dir==3&&x<t.getX()&&y==t.getY())
			{
				dir=0;
				return true;
			}
			
			return false;
			
		}
		else if(t.getDir()==3)
		{
			if(dir==0&&x==t.getX()&&y<t.getY())
			{
				dir=2;
				return true;
			}
			else if(dir==1&&x>t.getX()&&y==t.getY())
			{
				dir=0;
				return true;
			}
			else if(dir==2&&x==t.getX()&&y>t.getY())
			{
				dir=3;
				return true;
			}
			else if(dir==3&&x<t.getX()&&y==t.getY())
			{
				dir=1;
				return true;
			}
			
			return false;
		}
		else if(t.getDir()==4)
		{
			if(dir==0&&x==t.getX()&&y<t.getY())
			{
				dir=3;
				return true;
			}
			else if(dir==1&&x>t.getX()&&y==t.getY())
			{
				dir=2;
				return true;
			}
			else if(dir==2&&x==t.getX()&&y>t.getY())
			{
				dir=0;
				return true;
			}
			else if(dir==3&&x<t.getX()&&y==t.getY())
			{
				dir=1;
				return true;
			}
			
			return false;
		}
	} 
	
	bool tohole(CHole &t)
	{
		if(dir==0&&t.getDir()==2&&x==t.getX()&&y<t.getY())
			return true;
		else if(dir==1&&t.getDir()==3&&x>t.getX()&&y==t.getY())
			return true;
		else if(dir==2&&t.getDir()==0&&x==t.getX()&&y>t.getY())
			return true;
		else if(dir==3&&t.getDir()==1&&x<t.getX()&&y==t.getY())
			return true;	
			
		return false;
	}
};


class Game{
private:
	int n,m;  //�����Сn,m
	CHole red,blue;   //CHole����춴������
	int k;    //�����ο����k
	CTriangle trig[maxn];   //�����ο�������飨�洢�����ο����ݣ�
	bool visit[maxn];  //�ж��������Ƿ���ʹ������� 
public:
	Game(){}
	Game(int nn,int mm,CHole r,CHole b,int kk,CTriangle tr[]):
		n(nn),m(mm),k(kk),red(r),blue(b)
	{
		for(int i=0;i<k;i++)
		{
			trig[i]=tr[i];
			visit[i]=false;
		}
	}
	
	friend ostream & operator << (ostream &output, const Game &a);
	
	bool isOver()  //�ж���Ϸ�Ƿ���� 
	{
		for(int i=0;i<k;i++)
		{
			if(!visit[i]) return false;
		} 
		return true;
	}
	
	bool play()
	{
		CBall ball(red);
		return dfs(ball);
	}
	
	bool dfs(CBall ball)  //���� 
	{
		int flag=4;  //һ�������η�������4��
		for(int i=0;i<k;i++)
		{
			int predir=ball.getDir();
			if(!visit[i]) 
			{
				if(ball*=trig[i])  //��ײ���������� 
				{
					visit[i]=true;
					CBall b(trig[i].getX(),trig[i].getY(),ball.getDir());
					
					if(!dfs(b))  //û���������ø���������ת�������ݵ�ײ��������֮ǰ��״̬ 
					{
						++trig[i]; //��ת������
						--flag;
						visit[i]=false;    
						ball.setDir(predir);
						if(flag!=0)
							i--;
						else flag=4;
					}
					else 
						return true;
				}
			}
		} 
		
		return isOver()&&ball.tohole(blue);
	}
	
};

ostream & operator << (ostream &output, const Game &a)
{
	for(int i=0;i<a.k;i++)
	{
		output<<a.trig[i];
	}
	return output;
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int rx,ry,rdir,bx,by,bdir;
		cin>>rx>>ry>>rdir>>bx>>by>>bdir;
		CHole red(rx,ry,rdir);
		CHole blue(bx,by,bdir);
		
		int k;
		cin>>k;
		
		CTriangle tg[maxn];
		for(int i=0;i<k;i++)
		{
			int x,y,dir;
			cin>>x>>y>>dir;
			tg[i].setAll(x,y,dir);
		}
		
		Game game(n,m,red,blue,k,tg);
		
		if(game.play())
		{
			cout<<game;
		}
		else
		{
			cout<<"no solution"<<endl;
		}
		cout<<endl;
	}
	return 0;
}


/*
3
3 4
1 0 0
0 3 2
1
1 2 4
3 3
2 0 0
0 2 3
1
2 2 1
5 5
1 0 0
4 4 2
4
0 1 4
1 1 3
0 3 4
4 3 1
*/

//output
/*
no solution\n
\n
2 2 1\n
\n
0 1 3\n
1 1 1\n
0 3 4\n
4 3 2
*/
