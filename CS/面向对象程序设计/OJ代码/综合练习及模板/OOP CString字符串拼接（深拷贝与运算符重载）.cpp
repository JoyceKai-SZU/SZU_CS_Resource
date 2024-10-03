#include<iostream>
#include<cstring>
using namespace std;

class CString{
private:
	char *s;
	int n;
public:
	CString(char *const _s=nullptr):s(nullptr),n(0)
	{
		if (!_s) return;
		n = strlen(_s);
		s = new char[n + 1]{};
		strncpy(s, _s, n);      
	}
	
	CString(const CString &a):n(a.n)//深拷贝 
	{
		s = new char[n + 1]{};
		strncpy(s,a.s,n);  
	}
	
	CString operator + (const CString &a)
	{
		CString temp;
		temp.s=new char[n+a.n+1];
		strncpy(temp.s,s,this->n);
		strncpy(temp.s+n,a.s,a.n);
		temp.s[n+a.n]='\0';   //要加上，否则跑不出来 
		temp.n=n+a.n;         //同上 
		return temp;
	}
	
	friend ostream & operator << (ostream &out,const CString &a)
	{
		out<<a.s;
		return out;
	}
	
	
	CString operator = (const CString &p)  //坑 
	{
		if(n!=0) delete s;  //先清空原来的串 
		n=p.n;
		s=new char[n+1];
		strcpy(s,p.s);
		return *this;
	}
};


int main()
{
	int n;
	char input[64 + 1]{}; // ! strlen(s) + 1
	cin >> n;
	while (n--) {
		cin >> input;
		CString s1(input);
		cin >> input;
		CString s2(input);
		
		CString sEmpty; // !
		delete new CString(s1 = s1+s2); // !
		
		cout << s1 + sEmpty << endl
			 << sEmpty + s2 << endl
			 << s1 + s2 << endl
			 << endl;
		
	}
	return 0;
} 
