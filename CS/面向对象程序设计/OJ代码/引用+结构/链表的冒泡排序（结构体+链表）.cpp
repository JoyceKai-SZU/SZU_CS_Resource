#include<iostream>
using namespace std;

struct ListNode{
	string data;
	ListNode *next;
	ListNode(string data="", ListNode *next=NULL)   //Ĭ�ϲ��� 
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
		head=new ListNode;    //����ָ��һ��Ҫ��ʼ�� 
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
	
	void swap(ListNode* p)   //p��Ҫ��������������ǰһ����� 
	{
		ListNode *p1=p->next, *p2=p1->next;
		ListNode *q=p2->next;
		p->next=p2;
		p2->next=p1;
		p1->next=q;
		 
		
	}
	
	void BBsort()   //�����ð������ 
	{
		for(int i=0;i<num-1;i++)
		{
			bool flag=0;     //�Ƿ��������ı�� 
			ListNode *pre;   //ǰ����� 
			int j;
			for(j=0,pre=head;j<num-i-1;j++,pre=pre->next)
			{
				if(pre->next->data < pre->next->next->data)
				{
					swap(pre);
					flag=1;
				}
			}
			
			if(!flag) break;    //��������Ѿ�ȫ���������� 
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
