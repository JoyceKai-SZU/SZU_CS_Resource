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
		
		string temp=a.num;  		//除前导字符'0' 
		char sign='+'; 
		if(*temp.begin()=='-')   	//出现像-0001这种情况 
		{
			temp.erase(temp.begin());
			sign='-';
		}
		int k=0;
		for(int i=0;i<temp.size();i++)
		{
			if(temp[i]!='0')   //字符'0' 
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
		
		if(a.checkZero(a.num)) out<<0;        //对全0的情况，只输出0 
		else out<<a.num;
		
		if(*a.num.begin()=='-') out<<")";
		return out;
	}
	
	CBigInteger operator + (CBigInteger &a)  //高精度加法 
	{
		char sign='+';
		string s1=this->num;
		string s2=a.num; 
		//处理两数的正负问题 
		if(s1[0]=='-'&&s2[0]=='-')  //如果两数都是负数 
		{
			sign='-';
			s1.erase(s1.begin());
			s2.erase(s2.begin());
		}
		else if(s1[0]=='-'&&s2[0]!='-')   //前负后正 
		{
			s1.erase(s1.begin());
			CBigInteger b1(s1);
			CBigInteger b2(s2);
			return b2-b1;
		}
		else if(s1[0]!='-'&&s2[0]=='-')  //前正后负 
		{
			s2.erase(s2.begin());
			CBigInteger b1(s1);
			CBigInteger b2(s2);
			return b1-b2;
		}
		
		//以下是两数都正的情况 
		
		int a1[maxn],a2[maxn],a3[maxn];   //memset只适用于静态数组 
		
		//初始化 
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		memset(a3,0,sizeof a3);
		//反向存储 
		for(int i=0;i<s1.size();i++) a1[i]=(s1[s1.size()-1-i]-'0');
		for(int i=0;i<s2.size();i++) a2[i]=(s2[s2.size()-1-i]-'0');
		
		int len=max(s1.size(),s2.size());
		
		//加法计算 
		for(int i=0;i<len;i++)
		{
			a3[i]+=a1[i]+a2[i];
			if(a3[i]>=10)     //进位处理 
			{
				a3[i+1]+=a3[i]/10;
				a3[i]%=10;
			}
		} 
		
		if(a3[len]!=0) len++;
		
		//保存结果 
		string ans="";
		
		if(sign=='-') ans+=sign;
		
		
		for(int i=len-1;i>=0;i--)
		{
			ans+=to_string(a3[i]);
		}
		
		CBigInteger temp(ans);
		return temp;
	}
	
	CBigInteger operator - (CBigInteger &a)  //s1-s2    //高精度减法 
	{
		char sign='+';
		string s1=this->num;
		string s2=a.num;
		 
		//处理两数的正负问题 
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
		else if(s1[0]=='-'&&s2[0]=='-')  //-s1-(-s2)=s2-s1，相当于互换位置 
		{
			s1.erase(s1.begin());
			s2.erase(s2.begin());
			swap(s1,s2);
		}
		
		
		
		//以下是两数都正的情况
		int a1[maxn],a2[maxn],a3[maxn];
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		memset(a3,0,sizeof a3);
		
		//判断两数大小 
		if(s1.size()<s2.size()||(s1.size()==s2.size()&&s1<s2))
		{
			sign='-';
			swap(s1,s2);
		}
		
		for(int i=0;i<s1.size();i++) a1[i]=s1[s1.size()-i-1]-'0';
		for(int i=0;i<s2.size();i++) a2[i]=s2[s2.size()-i-1]-'0';
		
		//减法计算 
		for(int i=0;i<s1.size();i++)
		{
			if(a1[i]<a2[i])
			{
				a1[i+1]-=1;
				a1[i]+=10;
			}
			a3[i]=a1[i]-a2[i];
		}
		
		//保存结果 
		string ans="";
		if(sign=='-') ans+='-';
		
		int st=s1.size();
		for(int i=s1.size();i>=0;i--)  //找数组最大权值对应下标
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
	
	CBigInteger operator * (CBigInteger &a)      //高精度乘法 
	{
		char sign='+';
		
		string s1=this->num;
		string s2=a.num;
		
		//处理字符串正负问题 
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
		
		//初始化 
		int a1[maxn],a2[maxn],a3[maxn];
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		memset(a3,0,sizeof a3);
		
		for(int i=0;i<s1.size();i++) a1[i]=s1[s1.size()-i-1]-'0';
		for(int i=0;i<s2.size();i++) a2[i]=s2[s2.size()-i-1]-'0';
		
		
		//乘法运算 
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
		
		//找数组最大权值对应下标
		int st=s1.size()+s2.size()-1;
		for(int i=s1.size()+s2.size()-1;i>=0;i--)
		{
			if(a3[i])
			{
				st=i;
				break;
			}
		} 
		
		//保存运算结果 
		string ans="";
		
		if(sign=='-') ans+=sign; 
		
		for(int i=st;i>=0;i--)
		{
			ans+=to_string(a3[i]);
		}
		
		CBigInteger temp(ans);
		return temp;
	}
	
	
	bool checkZero(string str)const   //检查该字符串是否全0 
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
