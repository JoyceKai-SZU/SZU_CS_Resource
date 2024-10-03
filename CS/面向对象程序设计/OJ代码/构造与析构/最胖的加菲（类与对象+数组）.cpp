#include<iostream>
#include<algorithm>
using namespace std;

class Cat{
private:
	string name;
	int w;
public:
	Cat();
	int getW();
	string getName();
	void set(string name,int w);
//	bool operator < (const Cat &b) const
//	{
//		return w<b.w;
//	}
};

Cat::Cat(){}
int Cat::getW()
{
	return w;
}

string Cat::getName()
{
	return name;
}

void Cat::set(string name,int w)
{
	this->name=name;
	this->w=w;
}

bool cmp(Cat &a,Cat &b)
{
	return a.getW()<b.getW();
}

int main()
{
	int n;
	cin>>n;
	Cat *cat=new Cat[n];
	for(int i=0;i<n;i++)
	{
		string name;
		int w;
		cin>>name>>w;
		cat[i].set(name,w);
	}
	
	sort(cat,cat+n,cmp);
	for(int i=0;i<n;i++)
	{
		cout<<cat[i].getName();
		if(i!=n-1) cout<<" ";
 	}
 	cout<<endl;
 	delete [] cat;
	return 0;
} 
