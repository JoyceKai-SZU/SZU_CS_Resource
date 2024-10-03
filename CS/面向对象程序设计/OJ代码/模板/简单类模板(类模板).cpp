#include<iostream>
#include<cstring>
using namespace std;

template<class T>
class List{
private:
	T arr[100];
	int size;
public:
	List()
	{
		memset(arr,-1,sizeof arr);
		cin>>size;
		for(int i=0;i<size;i++) cin>>arr[i];
	}
	
	void insert(int idx,T num)
	{
		if(idx>=0&&idx<100&&size+1<=100)
		{
			for(int i=size-1;i>=idx;i--) arr[i+1]=arr[i];  //利用旧状态 
			
			arr[idx]=num;
		}
		size++;
	}
	
	void del(int idx)
	{
		if(idx>=0&&idx<100&&size-1>=0)
		{
			for(int i=idx;i<size;i++) arr[i]=arr[i+1];  //利用旧状态
		}
		size--;
	}
	
	
	void show()
	{
		for(int i=0;i<size;i++)
		{
			cout<<arr[i];
			if(i!=size-1) cout<<" ";
		}
		cout<<endl;
	}
	
};



int main()
{
	List<int> l1;
	
	int idx,num;
	cin>>idx>>num;
	l1.insert(idx,num);
	
	cin>>idx;
	l1.del(idx);
	l1.show();
	
	List<double> l2;
	
	double dnum;
	cin>>idx>>dnum;
	l2.insert(idx,dnum);
	
	cin>>idx;
	l2.del(idx);
	l2.show();
	
	return 0;
}


/*
5 11 22 33 44 55
2 888
4
5 1.1 2.2 3.3 4.4 5.5
2 88.8
3
*/

//output
/*
11 22 888 33 55
1.1 2.2 88.8 4.4 5.5
*/
