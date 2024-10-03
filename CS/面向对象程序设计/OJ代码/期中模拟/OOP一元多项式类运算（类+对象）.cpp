#include<iostream>
#include<vector>
using namespace std;

class node{
private:
	int data;
	int index;
public:
	node(){}
	node(int data,int index):data(data),index(index){}
	friend vector<node> add(vector<node> list1,vector<node> list2);
	friend vector<node> sub(vector<node> list1,vector<node> list2);
	friend vector<node> mul(vector<node> list1,vector<node> list2);
	friend void show(vector<node> list);
};

vector<node> add(vector<node> list1,vector<node> list2)
{
	int i=0,j=0;
	vector<node> list;
	while(i<list1.size()&&j<list2.size())
	{
		int l1data=list1[i].data;
		int l1index=list1[i].index;
		int l2data=list2[j].data;
		int l2index=list2[j].index;
		
		if(l1index<l2index)
		{
			node temp(l1data,l1index);
			list.push_back(temp);
			i++;
		}
		else if(l1index>l2index)
		{
			node temp(l2data,l2index);
			list.push_back(temp);
			j++;
		}
		else
		{
			int sum=l1data+l2data;
			if(!sum)
			{
				i++;
				j++;
			}
			else
			{
				node temp(sum,l1index);
				list.push_back(temp);
				i++;j++;
			}
		}
	}
	
	while(i<list1.size())
	{
		node temp(list1[i].data,list1[i].index);
		list.push_back(temp);
		i++;
	}
	
	while(j<list2.size())
	{
		node temp(list2[j].data,list2[j].index);
		list.push_back(temp);
		j++;
	}
	
	return list;
}

vector<node> sub(vector<node> list1,vector<node> list2)
{
	int i=0,j=0;
	vector<node> list;
	while(i<list1.size()&&j<list2.size())
	{
		int l1data=list1[i].data;
		int l1index=list1[i].index;
		int l2data=list2[j].data;
		int l2index=list2[j].index;
		
		if(l1index<l2index)
		{
			node temp(l1data,l1index);
			list.push_back(temp);
			i++;
		}
		else if(l1index>l2index)
		{
			node temp(-l2data,l2index);
			list.push_back(temp);
			j++;
		}
		else
		{
			int sum=l1data-l2data;
			if(!sum)
			{
				i++;
				j++;
			}
			else
			{
				node temp(sum,l1index);
				list.push_back(temp);
				i++;j++;
			}
		}
	}
	
	while(i<list1.size())
	{
		node temp(list1[i].data,list1[i].index);
		list.push_back(temp);
		i++;
	}
	
	while(j<list2.size())
	{
		node temp(-list2[j].data,list2[j].index);
		list.push_back(temp);
		j++;
	}
	
	return list;
}

vector<node> mul(vector<node> list1,vector<node> list2)
{
	vector<node> list;
	int i=0;
	while(i<list1.size())
	{
		int j=0;
		vector<node> templist;
		while(j<list2.size())
		{
			int data=list1[i].data*list2[j].data;
			int index=list1[i].index+list2[j].index;
			node temp(data,index);
			templist.push_back(temp);
			j++;
		}
		
		list=add(list,templist);
		i++;
	} 
	return list;
}

void show(vector<node> list)
{
	if(!list.size()) cout<<0;   //如果没有元素 
	else
	{
		for(int i=0;i<list.size();i++)
		{
			int data=list[i].data;
			int index=list[i].index;
			
			if(i!=0&&data>0) cout<<"+";
			
			if(index>0)
			{
				if(index==1) 
				{
					if(data==1)cout<<"x";
					else if(data==-1) cout<<"-x";
					else cout<<data<<"x";
				}
				else
				{
					if(data==1) cout<<"x^"<<index;
					else if(data==-1) cout<<"-x^"<<index;
					else  cout<<data<<"x^"<<index;
				}
			}
			else if(index<0)  //指数为负数一定要加括号 
			{
				if(data==1) cout<<"x^("<<index<<")";
				else if(data==-1) cout<<"-x^("<<index<<")";
				else  cout<<data<<"x^("<<index<<")";
			}
			else
			{
				cout<<data;
			}
		}
	}
	cout<<endl;
} 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int t;
	cin>>t;
	while(t--)
	{
		vector<node> l1,l2;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int data,index;
			cin>>data>>index;
			if(data==0) continue;
			node temp(data,index);
			l1.push_back(temp);
		}
		
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int data,index;
			cin>>data>>index;
			if(data==0) continue;
			node temp(data,index);
			l2.push_back(temp);
		}
		vector<node> addlist=add(l1,l2);
		vector<node> sublist=sub(l1,l2);
		vector<node> mullist=mul(l1,l2);
		
		show(addlist);
		show(sublist);
		show(mullist);
		
	}
	return 0;
}

/*
2
3 -9 0 4 1 -3 5
1 -7 0
2 1 0 -1 3
3 1 0 1 1 -1 2

*/

//output
/*
-16+4x-3x^5\n
-2+4x-3x^5\n
63-28x+21x^5\n
2+x-x^2-x^3\n
-x+x^2-x^3\n
1+x-x^2-x^3-x^4+x^5
*/ 
