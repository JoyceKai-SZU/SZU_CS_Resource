#include<iostream>
using namespace std;


class stack{
private:
	int *sp,top,max;
	void inflate(int lenth);  //ջ���� 
public:
	stack(int size=10);
	int pop();
	void push(int value);
	stack & operator = (stack & rightValue);
	void show(); 
};

stack::stack(int size):max(size)
{
	top=-1;   //��ջ 
	sp=new int [max];
}

void stack::push(int value)
{
	top++;
	if(top>=max) inflate(max);
	
	sp[top]=value;
}

void stack::inflate(int lenth)
{
	int *temp=new int [max+lenth];
	for(int i=0;i<max;i++) temp[i]=sp[i];
	
//	sp=new int [max+lenth];
//	for(int i=0;i<max;i++) sp[i]=temp[i];
	
	delete[] sp;   //������ֱ����spָ��temp 
	sp=temp;
	
	max+=lenth;
}

int stack::pop()
{
	return sp[top--];
}

stack & stack::operator = (stack & rightValue)  //��ֵ������
{
	if(sp) delete [] sp;
	
	sp=new int [rightValue.max];
	for(int i=0;i<=rightValue.top;i++)
		sp[i]=rightValue.sp[i];
	
	top=rightValue.top;
	max=rightValue.max;
	
	return *this;
}

void stack::show()
{
	for(int i=0;i<=top;i++) cout<<sp[i];
	
	cout<<endl;
} 


int main()
{
	int mx1,mx2;
	cin>>mx1>>mx2;
	
	stack stk1(mx1), stk2(mx2);
	
	//ѹջ�������渳ֵ����Ϊ������Ĭ�ϲ����Ĺ��캯��
	//������ڴ�����ʱջtemp 
	for(int i=0;i<mx1;i++)   
	{
		int num;
		cin>>num;
		stk1.push(num);
	}
	
	for(int i=0;i<mx2;i++)
	{
		int num;
		cin>>num;
		stk2.push(num);
	}
	
	stk2.pop();
	
	//������ôд
	//����stack temp=stk2, �������õ��ǿ������캯�� 
	stack temp;
	
	//����д���ܵ������ظ�ֵ����� 
	temp=stk2;
	stk2=stk1;
	stk1=temp;
	
	stk1.show();
	stk2.show(); 
	return 0;
}


/*
3 4  
1 2 3
4 5 6 7
*/

//output
/*
456
123
*/
