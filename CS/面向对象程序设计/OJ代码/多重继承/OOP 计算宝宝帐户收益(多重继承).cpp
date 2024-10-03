#include<iostream>
#include<cstring>
using namespace std;

class CPeople{
protected:
	char id[20];
	char name[10];
public:
	CPeople(){}    //��̳�Ҫ�� 
	CPeople(char *_id,char *_name)
	{
		strcpy(id,_id);
		strcpy(name,_name);
	}
	
};

//�����˻� 
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
//		if(lenid!=len_id||lenpd!=len_pd) return false;  //���Ȳ��� 
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

//�����˻� 
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

//����������,������������� 
class CInternetBankCustomer:public CInternetUser,public CBankCustomer{
private:
	double _balance;	//��� 
	double yesbalance;	//ǰһ����� 
	double profit;		//�������� 
	double wanprofit;	//������Ԫ���� 
	double yesprofit;	//��һ����Ԫ���� 
public:
	CInternetBankCustomer()
	{
		_balance=yesbalance=profit=0;
	}
	void setInterest(double interest)
	{
		wanprofit=interest/10000.0;
	}
	
	//�����������˻���Ǯ 
	bool deposit(double d)
	{
		if(d>balance) return false;
		
		balance-=d;
		_balance+=d; 
		return true;
	}
	
	//�������˻�������תǮ 
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
		yesbalance=_balance;  //����ǰһ����� 
		yesprofit=wanprofit;  //������Ԫ���� 
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
    double money, interest;char op_code;//������԰�����t
    cin >> t;
    while (t--){//���뻥�����û�ע��ʱ���û���,id,��½����
       cin >> i_xm >> i_id >> i_mm;//�������п����û���,id
       cin >> b_xm >> b_id;//���뻥�����û���½ʱ��id,��½����
       cin >> ib_id >> ib_mm;
       CInternetBankCustomer ib_user;
       ib_user.registerUser(i_xm, i_id, i_mm);
       ib_user.openAccount(b_xm, b_id);
       if (!ib_user.login(ib_id, ib_mm)) //�������û���½,��id�����벻��;�Լ����п���������id�뻥��������������id��ͬ
        { cout << "Password or ID incorrect" << endl;
          continue;
        }//��������
        cin >> no_of_days;
        for (i=0; i < no_of_days; i++){//�����������, ���, ������Ԫ����
          cin >> op_code >> money >> interest;
          switch (op_code){
              case 'S': //�����������������ʻ�����
              case 's': if (!ib_user.deposit(money)){
                            cout << "Bank balance not enough" << endl;
                            continue;
                         }
                         break;
               case 'T': //�ӻ���������ת�������ʻ�
               case 't':if (!ib_user.withdraw(money)){
                            cout << "Internet bank balance not enough" << endl;
                            continue;
                         }
                         break;
               case 'D': //ֱ���������ʻ����
               case 'd':ib_user.CBankCustomer::deposit(money);
                        break;
               case 'W': //ֱ�Ӵ������ʻ�ȡ��
               case 'w':if (!ib_user.CBankCustomer::withdraw(money)){
                            cout << "Bank balance not enough" << endl;
                            continue;
                        }
                        break;
               default:cout << "Illegal input" << endl;
                       continue;
           }
           ib_user.setInterest(interest);
           ib_user.calculateProfit();//����û���,id//���������� //��������������˻����
           ib_user.print();
           cout << endl;
        }
    }
    return 0;
}
