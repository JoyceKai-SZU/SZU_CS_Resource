#include<iostream>
using namespace std;

class CXGraph{
private:
	int n;   //n行
public:
	CXGraph(int nn):n(nn){}
	
	CXGraph& operator ++()
	{
		if(n!=21)
		{
			n+=2;
		}
		return *this;
	}
	
	CXGraph operator ++(int)
	{
		CXGraph temp=*this;
		if(n!=21)
		{
			n+=2;
		}
		return temp;
	}
	
	CXGraph& operator --()
	{
		if(n!=1)
		{
			n-=2;
		}
		return *this;
	} 
	
	CXGraph operator --(int)
	{
		CXGraph temp=*this;
		if(n!=1)
		{
			n-=2;
		}
		return temp;
	} 
	
	
	friend ostream& operator <<(ostream &stream,const CXGraph &a);
	
};

ostream& operator <<(ostream &stream,const CXGraph &a)
{
	int i,j,k=a.n;    //  k枚举每行X的数目 ,(n-k)/2是每行前半部分空格数目 
	for(i=0;i<=a.n/2;i++)
	{
		for(j=0;j<(a.n-k)/2;j++)
			stream<<" ";
		for(j=0;j<k;j++)
			stream<<"X";
		
		stream<<endl;
		k=k-2;
	}
	k=3;
	for(i=1;i<=a.n/2;i++)
	{
		for(j=0;j<(a.n-k)/2;j++)
			stream<<" ";
		for(j=0;j<k;j++)
			stream<<"X";
		
		stream<<endl;
		k=k+2;
	}
	return stream;
}


int main()
{
	int t,n;
	string command;
	
	cin>>n;
	CXGraph xGraph(n);
	
	cin>>t;
	while(t--)
	{
		cin>>command;
		
		if(command=="show++")
			cout<<xGraph++<<endl;
		else if(command=="++show")
			cout<<++xGraph<<endl;
		else if(command=="show--")
			cout<<xGraph--<<endl;
		else if(command=="--show")
			cout<<--xGraph<<endl;
		else if(command=="show")
			cout<<xGraph<<endl;
	}
	return 0;
} 


/*
3
5
show
show++
show++
++show
--show
*/




//output
/*
XXX\n
 X\n
XXX\n
\n
XXX\n
 X\n
XXX\n
\n
XXXXX\n
 XXX\n
  X\n
 XXX\n
XXXXX\n
\n
XXXXXXXXX\n
 XXXXXXX\n
  XXXXX\n
   XXX\n
    X\n
   XXX\n
  XXXXX\n
 XXXXXXX\n
XXXXXXXXX\n
\n
XXXXXXX\n
 XXXXX\n
  XXX\n
   X\n
  XXX\n
 XXXXX\n
XXXXXXX\n
\n
*/
