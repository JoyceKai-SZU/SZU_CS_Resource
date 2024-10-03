#include<iostream>
#include<map> 
using namespace std;

const int maxn=1e3+10;

class CSet{
private:
	int n;
	int *data;
public:
	CSet(){data=new int[maxn];}
	CSet(int num)
	{
		n=num;
		data=new int[maxn];
		for(int i=0;i<n;i++) cin>>data[i];
	} 
	
	CSet(const CSet &a)
	{
		n=a.n;
		data=new int[maxn];
		for(int i=0;i<n;i++) data[i]=a.data[i];
	}
	
	~CSet()
	{
		n=0;
		delete[] data;
	}
	
	CSet operator +(const CSet &a)   //注意要去重 
	{
		map<int,int> mp;
		CSet temp=*this;
		int k=temp.n;
		for(int i=0;i<temp.n;i++) mp[temp.data[i]]=1;
		
		for(int i=0;i<a.n;i++)
		{
			if(!mp[a.data[i]]) temp.data[k++]=a.data[i];
		}
		temp.n=k;
		return temp;
	}
	
	CSet operator -(const CSet &a)
	{
		CSet b=*this;
		CSet temp;
		int k=0;
		for(int i=0;i<b.n;i++)
		{
			bool flag=true;
			for(int j=0;j<a.n;j++)
			{
				if(b.data[i]==a.data[j])
				{
					flag=false;
					break;
				}
			}
			
			if(flag)
			{
				temp.data[k++]=b.data[i];
			} 
		}
		
		temp.n=k;
		return temp;
	}
	
	CSet operator *(const CSet &a)
	{
		CSet b=*this;
		CSet temp;
		int k=0;
		for(int i=0;i<b.n;i++)
		{
			for(int j=0;j<a.n;j++)
			{
				if(b.data[i]==a.data[j])
				{
					temp.data[k++]=b.data[i];
					break;
				}
			}
		}
		
		temp.n=k;
		return temp;
	}
	
	friend ostream& operator << (ostream &output,const CSet &a);
	
};

ostream& operator << (ostream &output,const CSet &a)
{
	for(int i=0;i<a.n;i++)
	{
		output<<a.data[i];
		if(i!=a.n-1) output<<" ";
	}
	return output;
} 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int num;
		cin>>num;
		CSet A(num);
		cin>>num;
		CSet B(num);
		
		cout<<"A:";
		cout<<A<<endl;
		
		cout<<"B:";
		cout<<B<<endl;
		
		cout<<"A+B:";
		CSet one=A+B;
		cout<<one<<endl;
		
		cout<<"A*B:";
		CSet two=A*B;
		cout<<two<<endl;
		
		cout<<"(A-B)+(B-A):";
		CSet three=(A-B)+(B-A);
		cout<<three<<endl;
		
		cout<<endl;
	} 
	
	
	return 0;
}
