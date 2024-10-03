#include<iostream>
using namespace std;

struct ListNode{
	string data;
	ListNode *next;
	ListNode(string data="", ListNode *next=NULL)   //默认参数 
	{
		this->data=data;
		this->next=next;
	} 
};

class LinkList{
private:
	ListNode *head;
	int num;
public:
	LinkList(int n)
	{
		head=new ListNode;    //链表指针一定要初始化 
		num=n;
		ListNode *p=head; 
		for(int i=0;i<num;i++)
		{
			string str;
			cin>>str;
			ListNode *s=new ListNode(str);
			p->next=s;
			p=s; 
		} 
	}
	
	~LinkList()
	{
		ListNode *p=head;
		ListNode *q;
		while(p)
		{
			q=p;
			p=p->next;
			delete q;
		}
	}
	
	void Print()
	{
		ListNode *p=head->next;
		while(p)
		{
			cout<<p->data<<endl;
			p=p->next;
		}
	}
	
	void swap(ListNode* p)   //p是要交换的两个结点的前一个结点 
	{
		ListNode *p1=p->next, *p2=p1->next;
		ListNode *q=p2->next;
		p->next=p2;
		p2->next=p1;
		p1->next=q;
		 
		
	}
	
	void BBsort()   //链表的冒泡排序 
	{
		for(int i=0;i<num-1;i++)
		{
			bool flag=0;     //是否结束排序的标记 
			ListNode *pre;   //前驱结点 
			int j;
			for(j=0,pre=head;j<num-i-1;j++,pre=pre->next)
			{
				if(pre->next->data < pre->next->next->data)
				{
					swap(pre);
					flag=1;
				}
			}
			
			if(!flag) break;    //如果链表已经全部降序排序 
		}
	} 
	
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		LinkList mylist(n);
		mylist.BBsort();
		mylist.Print();
		cout<<endl;
	}
	return 0;
}
