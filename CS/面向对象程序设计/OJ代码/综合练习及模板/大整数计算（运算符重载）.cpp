#include<iostream>
#include<cstring> 
using namespace std;

const int maxn=1001; 

class CBigInteger{
private:
	string num;
public:
	CBigInteger(){num.resize(1001);}
	CBigInteger(string n)
	{
		num.resize(1001);
		num=n;
	}
	
	~CBigInteger(){num.clear();}
	
	friend istream& operator >> (istream &in,CBigInteger &a)
	{
		in>>a.num;
		
		string temp=a.num;  		//��ǰ���ַ�'0' 
		char sign='+'; 
		if(*temp.begin()=='-')   	//������-0001������� 
		{
			temp.erase(temp.begin());
			sign='-';
		}
		int k=0;
		for(int i=0;i<temp.size();i++)
		{
			if(temp[i]!='0')   //�ַ�'0' 
			{
				k=i;
				break;
			}
		} 
		
		temp=temp.substr(k);
		
		if(sign=='-') temp.insert(temp.begin(),sign);
		a.num=temp;
		return in;
	}
	
	friend ostream& operator << (ostream &out,const CBigInteger &a)
	{
		if(*a.num.begin()=='-') out<<"(";
		
		if(a.checkZero(a.num)) out<<0;        //��ȫ0�������ֻ���0 
		else out<<a.num;
		
		if(*a.num.begin()=='-') out<<")";
		return out;
	}
	
	CBigInteger operator + (CBigInteger &a)  //�߾��ȼӷ� 
	{
		char sign='+';
		string s1=this->num;
		string s2=a.num; 
		//������������������ 
		if(s1[0]=='-'&&s2[0]=='-')  //����������Ǹ��� 
		{
			sign='-';
			s1.erase(s1.begin());
			s2.erase(s2.begin());
		}
		else if(s1[0]=='-'&&s2[0]!='-')   //ǰ������ 
		{
			s1.erase(s1.begin());
			CBigInteger b1(s1);
			CBigInteger b2(s2);
			return b2-b1;
		}
		else if(s1[0]!='-'&&s2[0]=='-')  //ǰ���� 
		{
			s2.erase(s2.begin());
			CBigInteger b1(s1);
			CBigInteger b2(s2);
			return b1-b2;
		}
		
		//������������������� 
		
		int a1[maxn],a2[maxn],a3[maxn];   //memsetֻ�����ھ�̬���� 
		
		//��ʼ�� 
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		memset(a3,0,sizeof a3);
		//����洢 
		for(int i=0;i<s1.size();i++) a1[i]=(s1[s1.size()-1-i]-'0');
		for(int i=0;i<s2.size();i++) a2[i]=(s2[s2.size()-1-i]-'0');
		
		int len=max(s1.size(),s2.size());
		
		//�ӷ����� 
		for(int i=0;i<len;i++)
		{
			a3[i]+=a1[i]+a2[i];
			if(a3[i]>=10)     //��λ���� 
			{
				a3[i+1]+=a3[i]/10;
				a3[i]%=10;
			}
		} 
		
		if(a3[len]!=0) len++;
		
		//������ 
		string ans="";
		
		if(sign=='-') ans+=sign;
		
		
		for(int i=len-1;i>=0;i--)
		{
			ans+=to_string(a3[i]);
		}
		
		CBigInteger temp(ans);
		return temp;
	}
	
	CBigInteger operator - (CBigInteger &a)  //s1-s2    //�߾��ȼ��� 
	{
		char sign='+';
		string s1=this->num;
		string s2=a.num;
		 
		//������������������ 
		if(s1[0]!='-'&&s2[0]=='-')   //s1-(-s2)=s1+s2
		{
			s2.erase(s2.begin());
			CBigInteger b1(s1);
			CBigInteger b2(s2);
			return b1+b2;
		} 
		else if(s1[0]=='-'&&s2[0]!='-')   //-s1-s2=(-s1)+(-s2)
		{
			sign='-';
			s2.insert(s2.begin(),sign);
			CBigInteger b1(s1);
			CBigInteger b2(s2);
			return b1+b2;
		}
		else if(s1[0]=='-'&&s2[0]=='-')  //-s1-(-s2)=s2-s1���൱�ڻ���λ�� 
		{
			s1.erase(s1.begin());
			s2.erase(s2.begin());
			swap(s1,s2);
		}
		
		
		
		//�������������������
		int a1[maxn],a2[maxn],a3[maxn];
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		memset(a3,0,sizeof a3);
		
		//�ж�������С 
		if(s1.size()<s2.size()||(s1.size()==s2.size()&&s1<s2))
		{
			sign='-';
			swap(s1,s2);
		}
		
		for(int i=0;i<s1.size();i++) a1[i]=s1[s1.size()-i-1]-'0';
		for(int i=0;i<s2.size();i++) a2[i]=s2[s2.size()-i-1]-'0';
		
		//�������� 
		for(int i=0;i<s1.size();i++)
		{
			if(a1[i]<a2[i])
			{
				a1[i+1]-=1;
				a1[i]+=10;
			}
			a3[i]=a1[i]-a2[i];
		}
		
		//������ 
		string ans="";
		if(sign=='-') ans+='-';
		
		int st=s1.size();
		for(int i=s1.size();i>=0;i--)  //���������Ȩֵ��Ӧ�±�
		{
			if(a3[i])
			{
				st=i;
				break;
			}
		}
		
		for(int i=st;i>=0;i--) ans+=to_string(a3[i]);
		
		CBigInteger temp(ans);
		return temp;
	}
	
	CBigInteger operator * (CBigInteger &a)      //�߾��ȳ˷� 
	{
		char sign='+';
		
		string s1=this->num;
		string s2=a.num;
		
		//�����ַ����������� 
		if(s1[0]=='-'&&s2[0]=='-')
		{
			s1.erase(s1.begin());
			s2.erase(s2.begin());
		}
		else if(s1[0]=='-'&&s2[0]!='-')
		{
			sign='-';
			s1.erase(s1.begin());
		}
		else if(s1[0]!='-'&&s2[0]=='-')
		{
			sign='-';
			s2.erase(s2.begin());
		}
		
		//��ʼ�� 
		int a1[maxn],a2[maxn],a3[maxn];
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		memset(a3,0,sizeof a3);
		
		for(int i=0;i<s1.size();i++) a1[i]=s1[s1.size()-i-1]-'0';
		for(int i=0;i<s2.size();i++) a2[i]=s2[s2.size()-i-1]-'0';
		
		
		//�˷����� 
		for(int i=0;i<s1.size();i++)
		{
			for(int j=0;j<s2.size();j++)
			{
				a3[i+j]+=a1[i]*a2[j];
				if(a3[i+j]>=10)
				{
					a3[i+j+1]+=a3[i+j]/10;
					a3[i+j]%=10;
				}
			}
		}
		
		//���������Ȩֵ��Ӧ�±�
		int st=s1.size()+s2.size()-1;
		for(int i=s1.size()+s2.size()-1;i>=0;i--)
		{
			if(a3[i])
			{
				st=i;
				break;
			}
		} 
		
		//���������� 
		string ans="";
		
		if(sign=='-') ans+=sign; 
		
		for(int i=st;i>=0;i--)
		{
			ans+=to_string(a3[i]);
		}
		
		CBigInteger temp(ans);
		return temp;
	}
	
	
	bool checkZero(string str)const   //�����ַ����Ƿ�ȫ0 
	{
		bool flag=true;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]!='0')
			{
				flag=false;
				break;
			}
		}
		return flag;
	}
	
	
};

int main()
{
	int t;
	char op;
	CBigInteger bigNum1;
	CBigInteger bigNum2;
	
	cin>>t;
	while(t--)
	{
		cin>>bigNum1>>op>>bigNum2;
		cout<<bigNum1<<" "<<op<<" "<<bigNum2<<" = ";
		if(op=='+')
			cout<<bigNum1+bigNum2<<endl;
		else if(op=='-')
			cout<<bigNum1-bigNum2<<endl;
		else if(op=='*')
			cout<<bigNum1*bigNum2<<endl;
	}
	
	return 0;
} 

/*
3
100 * -100
-123456789 + 123456
0001 - -123
*/

//output
/*
100 * (-100) = (-10000)\n
(-123456789) + 123456 = (-123333333)\n
1 - (-123) = 124\n
*/ 
