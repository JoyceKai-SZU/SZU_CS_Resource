#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Point{  //µã¶ÔÏó 
private:
	double x,y;
public:
	Point(){}
	double getDis()
	{
		return sqrt(x*x+y*y);
	}
	
	bool operator > (Point &a)
	{
		return getDis()>a.getDis();
	}
	
	friend istream& operator >>(istream &input,Point &a)
	{
		input>>a.x>>a.y;
		return input;
	}
	
	friend ostream& operator <<(ostream &out,const Point &a)
	{
		out<<"("<<fixed<<setprecision(1)<<a.x<<", "<<a.y<<")";
		return out;
	}
};

template<class T>
void mysort(T *arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
		}
	}
}

template<class T>
void display(T *arr,int n)
{
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char op;
		int n;
		cin>>op>>n;
		if(op=='I')
		{
			int *arr=new int[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			mysort(arr,n);
			display(arr,n);
		}
		else if(op=='S')
		{
			string *arr=new string[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			mysort(arr,n);
			display(arr,n);
		}
		else if(op=='D')
		{
			double *arr=new double[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			mysort(arr,n);
			display(arr,n);
		}
		else if(op=='P')
		{
			Point *arr=new Point[n];
			for(int i=0;i<n;i++) cin>>arr[i];
			mysort(arr,n);
			display(arr,n);
		}
	}
	
	return 0;
}

/*
4
I 10
15 3 51 27 9 35 78 14 65 8
D 3
-11.3 25.42 13.2
P 6
1.1 2.2 2.4 -6.5 12 32 1.2 1.3 -3.5 0.1 9.2 1.1
S 4
sandy david eason cindy
*/

//output
/*
3 8 9 14 15 27 35 51 65 78 \n
-11.3 13.2 25.42 \n
(1.2, 1.3) (1.1, 2.2) (-3.5, 0.1) (2.4, -6.5) (9.2, 1.1) (12.0, 32.0) \n
cindy david eason sandy \n
*/
