#include<iostream>
using namespace std;


class stack{
private:
	int *sp,top,max;
	void inflate(int lenth);  //栈扩容 
public:
	stack(int size=10);
	int pop();
	void push(int value);
	stack & operator = (stack & rightValue);
	void show(); 
};

stack::stack(int size):max(size)
{
	top=-1;   //空栈 
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
	
	delete[] sp;   //法二，直接让sp指向temp 
	sp=temp;
	
	max+=lenth;
}

int stack::pop()
{
	return sp[top--];
}

stack & stack::operator = (stack & rightValue)  //赋值不扩容
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
	
	//压栈建议外面赋值，因为它是有默认参数的构造函数
	//后面便于创建临时栈temp 
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
	
	//必须这么写
	//不能stack temp=stk2, 这样调用的是拷贝构造函数 
	stack temp;
	
	//这样写才能调用重载赋值运算符 
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
