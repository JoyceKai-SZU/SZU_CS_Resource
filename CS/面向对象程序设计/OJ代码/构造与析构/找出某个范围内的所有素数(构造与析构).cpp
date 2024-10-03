#include<iostream>
using namespace std;

class CSieve{
private:
	char *p_sieve;      //��ĿҪ���ַ����飬��ʵ������bool��������� 
	unsigned long num; //num�����Χ
public:
	CSieve(unsigned long n);
	void printPrime();
	~CSieve();
};

CSieve::CSieve(unsigned long n):num(n)
{
	p_sieve=new char[num+1];
	
	for(unsigned long i=2;i<=num;i++) p_sieve[i]='1';  //һ��ʼ��ʼ��ȫΪ���� 
	
	for(unsigned long i=2;i<=num;i++)
	{
		for(unsigned long j=2*i;j<=num;j+=i)
		{
			p_sieve[j]='0';
		}
	}
	
	
}
CSieve::~CSieve()
{
	delete [] p_sieve;
} 

void CSieve::printPrime()
{
	for(unsigned long i=2;i<=num;i++)
	{
		if(p_sieve[i]=='1') cout<<i<<" ";
	} 
	cout<<endl;
} 


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long n;
		cin>>n;
		CSieve p(n);
		p.printPrime();
	}
	return 0;
}
