#include<iostream>
#include<cstring>
using namespace std;

class CTelNumber{
private:
	char *num;
public:
	CTelNumber(const char *n);
	~CTelNumber();
	void Print();
	CTelNumber(const CTelNumber &b);
};

CTelNumber::CTelNumber(const char *n)
{
	num=new char[20];
	strcpy(num,n);
}


CTelNumber::~CTelNumber()
{
	delete [] num;
}

CTelNumber::CTelNumber(const CTelNumber &b)
{
	
	num=new char[20];
	
	if(b.num[0]=='2'||b.num[0]=='3'||b.num[0]=='4') num[0]='8';
	else num[0]='2';
	
	strcpy(num+1,b.num);    //numÒª¼ÓÒ» 
	
}

void CTelNumber::Print()
{
	cout<<num<<endl;
} 


bool check(char *a)
{

	int flag=1;
	int len=strlen(a);
	if(len!=7) flag=0;
	
	if(a[0]=='0'||a[0]=='1'||a[0]=='9') flag=0;
	
	for(int i=0;i<len;i++)
	{
		if(!isdigit(a[i]))
		{
			flag=0;
			break;
		}
	} 
	
	if(!flag)
	{
		return false;
	}
	else return true;
} 


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char *a=new char[20];
		cin>>a;
		CTelNumber c1(a);
		if(check(a))
		{			
			CTelNumber c2(c1);
			c2.Print();
			
		}
		else cout<<"Illegal phone number"<<endl;
	}
	return 0;
}

/*
3
6545889
3335656
565655
*/

//output
/*
26545889\n
83335656\n
Illegal phone number
*/
