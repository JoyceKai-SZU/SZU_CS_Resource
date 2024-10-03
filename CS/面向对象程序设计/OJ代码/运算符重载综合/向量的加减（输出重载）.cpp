#include<iostream>
using namespace std;

class Vector{
private:
	int *data;
public:
	Vector()
	{
		data=new int[10];
		for(int i=0;i<10;i++) cin>>data[i];
	}
	
	Vector(const Vector& a)   //Éî¿½±´ 
	{
		data=new int [10];
		for(int i=0;i<10;i++) data[i]=a.data[i];
	}
	
	Vector operator + (const Vector &a)
	{
		Vector temp=*this;
		for(int i=0;i<10;i++) temp.data[i]+=a.data[i];
		return temp;
	}
	
	Vector operator - (const Vector &a)
	{
		Vector temp=*this;
		for(int i=0;i<10;i++) temp.data[i]-=a.data[i];
		return temp;
	}
	
	~Vector()
	{
		delete [] data;
	} 
	
	friend ostream& operator << (ostream &output, const Vector &a);
};

ostream& operator << (ostream &output, const Vector &a)
{
	
	for(int i=0;i<10;i++)
	{
		output<<a.data[i];
		if(i!=9) output<<" ";
	}
	return output;
}

int main()
{
	Vector v1,v2;
	cout<<(v1+v2)<<endl;
	cout<<(v1-v2)<<endl;
	return 0;
}
