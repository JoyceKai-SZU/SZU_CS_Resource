#include<iostream>
#include<cstring>
using namespace std;

class CPeople{
protected:
	char id[20];
	char name[10];
public:
	CPeople(){}    //虚继承要有 
	CPeople(char *_id,char *_name)
	{
		strcpy(id,_id);
		strcpy(name,_name);
	}
	
};

//网上账户 
class CInternetUser:virtual public CPeople{
protected:
	char password[20];
public:
	CInternetUser(){}
	CInternetUser(char *pwd)
	{
		strcpy(password,pwd);
	}
	
	void registerUser(char *_name,char *_id,char *pwd)
	{
		strcpy(id,_id);
		strcpy(name,_name);
		strcpy(password,pwd);
	} 
	
	bool login(char *_id,char *pwd)
	{
//		int lenid=strlen(id);
//		int len_id=strlen(_id);
//		int lenpd=strlen(password);
//		int len_pd=strlen(pwd);
//		
//		if(lenid!=len_id||lenpd!=len_pd) return false;  //长度不等 
//		
//		bool flag=true;
//		for(int i=0;i<lenid;i++)
//		{
//			if(id[i]!=_id[i])
//			{
//				flag=false;
//				break;
//			}
//		} 
//		
//		for(int i=0;i<lenpd;i++)
//		{
//			if(password[i]!=pwd[i])
//			{
//				flag=false;
//				break;
//			}
//		}
//		
//		if(!flag) return false;
//		
//		return true;

		return strcmp(id,_id)==0&&strcmp(password,pwd)==0; 
		
	}
};

//银行账户 
class CBankCustomer:virtual public CPeople{
protected:
	double balance;
public:
	CBankCustomer(){balance=0.0;}
	CBankCustomer(double b):balance(b){}
	void openAccount(char *_name,char *_id)
	{
		strcpy(id,_id);
		strcpy(name,_name);
	}
	
	void deposit(double d){balance+=d;}
	bool withdraw(double d)
	{
		if(d>balance) return false;
		
		balance-=d;
		return true;
	}
};

//互联网金融,在这里才有收益 
class CInternetBankCustomer:public CInternetUser,public CBankCustomer{
private:
	double _balance;	//余额 
	double yesbalance;	//前一日余额 
	double profit;		//当日收益 
	double wanprofit;	//今日万元收益 
	double yesprofit;	//上一日万元收益 
public:
	CInternetBankCustomer()
	{
		_balance=yesbalance=profit=0;
	}
	void setInterest(double interest)
	{
		wanprofit=interest/10000.0;
	}
	
	//银行向互联网账户存钱 
	bool deposit(double d)
	{
		if(d>balance) return false;
		
		balance-=d;
		_balance+=d; 
		return true;
	}
	
	//互联网账户向银行转钱 
	bool withdraw(double d)
	{
		if(d>_balance) return false;
		
		balance+=d;
		_balance-=d;
		return true;	
	}
	
	void calculateProfit()
	{
		profit=yesbalance*yesprofit;
		_balance+=profit;
		yesbalance=_balance;  //更新前一日余额 
		yesprofit=wanprofit;  //更新万元收益 
	}
	
	void print()
	{
		cout<<"Name: "<<name<<" ID: "<<id<<endl;
		cout<<"Bank balance: "<<balance<<endl;
		cout<<"Internet bank balance: "<<_balance<<endl;
	}
};

int main() {
    int t, no_of_days, i;
    char  *i_xm, *i_id, *i_mm, *b_xm, *b_id, *ib_id, *ib_mm;
    i_xm=new char[20],i_id=new char[20];
    i_mm=new char[20],b_xm=new char[20],b_id=new char[20];
    ib_id=new char[20],ib_mm=new char[20];
    double money, interest;char op_code;//输入测试案例数t
    cin >> t;
    while (t--){//输入互联网用户注册时的用户名,id,登陆密码
       cin >> i_xm >> i_id >> i_mm;//输入银行开户用户名,id
       cin >> b_xm >> b_id;//输入互联网用户登陆时的id,登陆密码
       cin >> ib_id >> ib_mm;
       CInternetBankCustomer ib_user;
       ib_user.registerUser(i_xm, i_id, i_mm);
       ib_user.openAccount(b_xm, b_id);
       if (!ib_user.login(ib_id, ib_mm)) //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
        { cout << "Password or ID incorrect" << endl;
          continue;
        }//输入天数
        cin >> no_of_days;
        for (i=0; i < no_of_days; i++){//输入操作代码, 金额, 当日万元收益
          cin >> op_code >> money >> interest;
          switch (op_code){
              case 'S': //从银行向互联网金融帐户存入
              case 's': if (!ib_user.deposit(money)){
                            cout << "Bank balance not enough" << endl;
                            continue;
                         }
                         break;
               case 'T': //从互联网金融转入银行帐户
               case 't':if (!ib_user.withdraw(money)){
                            cout << "Internet bank balance not enough" << endl;
                            continue;
                         }
                         break;
               case 'D': //直接向银行帐户存款
               case 'd':ib_user.CBankCustomer::deposit(money);
                        break;
               case 'W': //直接从银行帐户取款
               case 'w':if (!ib_user.CBankCustomer::withdraw(money)){
                            cout << "Bank balance not enough" << endl;
                            continue;
                        }
                        break;
               default:cout << "Illegal input" << endl;
                       continue;
           }
           ib_user.setInterest(interest);
           ib_user.calculateProfit();//输出用户名,id//输出银行余额 //输出互联网金融账户余额
           ib_user.print();
           cout << endl;
        }
    }
    return 0;
}
