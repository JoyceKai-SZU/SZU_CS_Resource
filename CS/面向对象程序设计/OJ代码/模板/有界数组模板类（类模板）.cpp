#include<iostream>
using namespace std;

template<class T>
class BoundArray{
private:
	T *arr;
	int num;
public:
	BoundArray(T *input,int n):num(n)
	{
		arr=new T [num];
		for(int i=0;i<n;i++) arr[i]=input[i];
	}
	~BoundArray()
	{
		delete[] arr;
		num=0;
	}
	
	void sort()
	{
		for(int i=0;i<num-1;i++)
		{
			for(int j=0;j<num-i-1;j++)
			{
				if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
			}
		}
	}
	
	int search(T key)
	{
		for(int i=0;i<num;i++)
		{
			if(key==arr[i]) return i;
		}
		return -1;
	}
	
	void show()
	{
		for(int i=0;i<num;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char op;
		int num;
		cin>>op>>num;
		if(op=='I')
		{
			int *arr=new int [num];
			for(int i=0;i<num;i++) cin>>arr[i];
			BoundArray<int> bb(arr,num);
			bb.sort();
			bb.show();
			int key;
			cin>>key;
			if(bb.search(key)==-1) cout<<-1<<endl;
			else cout<<bb.search(key)<<endl;
		}
		else if(op=='D')
		{
			double *arr=new double [num];
			for(int i=0;i<num;i++) cin>>arr[i];
			BoundArray<double> bb(arr,num);
			bb.sort();
			bb.show();
			double key;
			cin>>key;
			if(bb.search(key)==-1) cout<<-1<<endl;
			else cout<<bb.search(key)<<endl;
		}
		else if(op=='C')
		{
			char *arr=new char [num];
			for(int i=0;i<num;i++) cin>>arr[i];
			BoundArray<char> bb(arr,num);
			bb.sort();
			bb.show();
			char key;
			cin>>key;
			if(bb.search(key)==-1) cout<<-1<<endl;
			else cout<<bb.search(key)<<endl;
		}
	}
	return 0;
}
