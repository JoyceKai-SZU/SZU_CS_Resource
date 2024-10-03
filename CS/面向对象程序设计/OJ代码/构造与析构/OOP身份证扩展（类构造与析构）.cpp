#include<iostream>
#include<cstring>
using namespace std;

class IDcard{
private:
	string id;
public:
	IDcard(string pid);
	~IDcard();
	void upgrade();
};

IDcard::IDcard(string pid)
{
	id=pid;
	cout<<"construct ID="<<id<<endl;
}

IDcard::~IDcard()
{
	cout<<"destruct ID="<<id.substr(14,4)<<endl;
}

void IDcard::upgrade()
{
	char f[]={'1','0','X','9','8','7','6','5','4','3','2'};  //×¢ÒâÊÇ×Ö·û 
	int g[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	id.insert(6,"19");
	int sum=0;
	for(int i=0;i<17;i++)
	{
		sum+=(id[i]-'0')*g[i];
		cout<<sum<<endl;
	}
//	cout<<sum<<endl;
//	cout<<sum%11<<endl;
	id+=f[sum%11]; 
	
	cout<<"upgrade ID="<<id<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string input;
		cin>>input;
		IDcard card(input);
		card.upgrade();
	}
	return 0;
}

/*
2
340524800101001
310001000101452
*/

//output

/*
construct ID=340524800101001\n
upgrade ID=34052419800101001X\n
destruct ID=001X\n
construct ID=310001000101452\n
upgrade ID=310001190001014527\n
destruct ID=4527\n
*/
