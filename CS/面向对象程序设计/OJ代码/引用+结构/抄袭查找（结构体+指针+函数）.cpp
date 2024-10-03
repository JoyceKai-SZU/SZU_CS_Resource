#include<iostream>
using namespace std;

struct exam{
	int id;
	string one;
	string two;
	string three;
} s[110]; 


int find(exam *a,exam *b)
{
	int res=0;
	
	int len1=a->one.length(), len2=b->one.length();
	
	for(int i=0;i<(len1<len2?len1:len2);i++)
	{
		if(a->one[i]==b->one[i]) res++;
	}
	if((res*1.0/len1)>=0.9||(res*1.0/len2)>=0.9) return 1;

	
	res=0;
	
	len1=a->two.length();
	len2=b->two.length();
	for(int i=0;i<(len1<len2?len1:len2);i++)
	{
		if(a->two[i]==b->two[i]) res++;
	}
	if((res*1.0/len1)>=0.9||(res*1.0/len2)>=0.9) return 2;

	res=0;
	
	len1=a->three.length();
	len2=b->three.length();
	for(int i=0;i<(len1<len2?len1:len2);i++)
	{
		if(a->three[i]==b->three[i]) res++;
	}
	if((res*1.0/len1)>=0.9||(res*1.0/len2)>=0.9) return 3;

	
	return 0; 
}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++) cin>>s[i].id>>s[i].one>>s[i].two>>s[i].three;
	
	for(int i=0;i<t;i++)
	{
		for(int j=i+1;j<t;j++)
		{
			if(find(&s[i],&s[j])) 
			{
				if(s[i].id>s[j].id) cout<<s[j].id<<" "<<s[i].id<<" "<<find(&s[i],&s[j])<<endl;
				else cout<<s[i].id<<" "<<s[j].id<<" "<<find(&s[i],&s[j])<<endl;
			}
		}
	}
	return 0;
}

/*
5
2088150555
aabcdef11
ZZ887766dd
cc33447799ZZ
2088150333
abcdef00
AABBCCDDEE
ZZ668899cc
2088150111
AABBCCDDEE
ZZ668899cc
abcdef00
2088150222
AABBCFDDeE
ZZ889966dd
abcdef000
2088150444
aabcdef00
AABBCDDDEE
cc668899ZZ
*/

//output
/*
2088150333 2088150444 2\n
2088150111 2088150222 3\n
*/
