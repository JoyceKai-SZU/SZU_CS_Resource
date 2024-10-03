#include<iostream>
using namespace std;

class node{
private:
	int value;
public:
	node();
	node(int value);
	node(const node &b);
};


node::node():value(0)
{
	cout<<"Constructed by default, value = 0"<<endl;
}

node::node(int value):value(value)
{
	cout<<"Constructed using one argument constructor, value = "<<value<<endl;
}

node::node(const node &b):value(b.value)
{
	cout<<"Constructed using copy constructor, value = "<<value<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int op,v;
		cin>>op;
		if(op==0)
		{
			node s;
		}
		else if(op==1)
		{
			cin>>v;
			node s(v);
		}
		else
		{
			cin>>v;
			node s1(v);
			node s2(s1);
		}
	}
	
	return 0;
}
