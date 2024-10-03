#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

template<class T>
void Sort(T *arr,int n,int st,int ed)
{
	sort(arr+st,arr+ed);
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string op;
		int n,st,ed;
		//法一 
//		cin>>op>>n;
//		cin.ignore(2);
//		cin>>st;
//		cin.ignore();
//		cin>>ed;
//		cin.ignore(4);
		cin>>op;
		//法二 
		//scanf("%d [%d,%d) :",&n,&st,&ed);   //注意格式，冒号后面的空格不要管
		
		//法三 
		cin>>n;
		getchar();
		getchar();
		cin>>st;
		getchar();
		cin>>ed;
		getchar();
		getchar();
		getchar();
		
		if(st>ed) swap(st,ed);  //卡样例 
		if(st<0) st=0;
		if(ed>st+n) ed=st+n;
		
		if(op=="int")
		{
			int *arr=new int [n];
			for(int i=0;i<n;i++) cin>>arr[i];
			Sort(arr,n,st,ed);
			
			cout<<"[";
			for(int i=0;i<n;i++)
			{
				cout<<arr[i];
				if(i!=n-1) cout<<", ";
			}
			cout<<"]\n";
		}
		else if(op=="string")
		{
			string *arr=new string [n];
			for(int i=0;i<n;i++) cin>>arr[i];
			Sort(arr,n,st,ed);
			
			cout<<"[";
			for(int i=0;i<n;i++)
			{
				cout<<arr[i];
				if(i!=n-1) cout<<", ";
			}
			cout<<"]\n";
		} 
		else if(op=="float")
		{
			float *arr=new float [n];
			for(int i=0;i<n;i++) cin>>arr[i];
			Sort(arr,n,st,ed);
			
			cout<<"[";
			for(int i=0;i<n;i++)
			{
				cout<<fixed<<setprecision(1)<<arr[i];
				if(i!=n-1) cout<<", ";
			}
			cout<<"]\n";
		}
		
	} 
	return 0;
}

/*
3
int 5 [2,4) : 5 4 3 2 1
string 3 [-4,4) : b c a
float 3 [0,4) : 3.3 1.1 2.2
*/

/*
[5, 4, 2, 3, 1]\n
[a, b, c]\n
[1.1, 2.2, 3.3]
*/

/*
4
int 6 [5,4) : 1 2 3 4 5 6
int 5 [2,3) : 1 2 3 4 5
float 1 [0,1) : 0.0
string 2 [-1,3) : world hello
*/

//output
/*
[1, 2, 3, 4, 5, 6]
[1, 2, 3, 4, 5]
[0.0]
[hello, world]
*/
