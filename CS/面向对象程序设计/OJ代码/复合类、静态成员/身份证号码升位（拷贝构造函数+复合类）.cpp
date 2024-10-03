#include<iostream>
#include<cstring>
using namespace std;

int ff[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char gg[]={'1','0','X','9','8','7','6','5','4','3','2'}; 

class CDate{
private:
	int year, month, day;
public:
	CDate(){};
	CDate(int,int,int);
	bool check(); //���������Ƿ�Ϸ�
	bool isLeap();
	void print();
	int getYear(){return year;}
	int getMonth(){return month;}
	int getDay(){return day;}
};

CDate::CDate(int y,int m,int d):year(y),month(m),day(d){}
bool CDate::isLeap()
{
	return year%400==0||(year%100!=0&&year%4==0);
}
bool CDate::check()
{
	int D[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(isLeap()) D[2]=29;
	else D[2]=28;
	
	if(month<1||month>12) return false;
	if(day<1||day>D[month]) return false;
	
	return true;
}

void CDate::print()
{
	cout<<year<<"��"<<month<<"��"<<day<<"��"; 
}



class CStudentID{
private:
	char *p_id, *p_name; //���֤���룬����
	CDate birthday; //��������
	int registered; //�ǼǷ�
public:
	CStudentID(char *p_idval, char *p_nameval, CDate &day); 
	//���캯������:���ڷǷ�;������id���ڲ���;id�зǷ��ַ�;id����15λ��18λ;id��18λ�������벻��,�����"illegal id"����registered=0�����������������Բ���registered=1.
	CStudentID(const CStudentID &r); //�������캯������r.p_idΪ15λ������18λ(����ݵ�19��У��λ)
	bool checked() { return registered; }
	~CStudentID();
};

CStudentID::CStudentID(char *p_idval, char *p_nameval, CDate &day):birthday(day)
{
	p_id=new char[30];
	p_name=new char[30];
	strcpy(p_id,p_idval);
	strcpy(p_name,p_nameval);
	
	int flag=1;
	if(!birthday.check()) flag=0;
	
	int idlen=strlen(p_id);
	for(int i=0;i<idlen;i++)
	{
		if(!isdigit(p_id[i]))
		{
			flag=0;
			break;
		}
	}
	
	if(idlen!=15&&idlen!=18) flag=0;
	
	if(idlen==15)
	{
		int y=birthday.getYear()%100;
		int m=birthday.getMonth();
		int d=birthday.getDay();
		
		int yy=(p_id[6]-'0')*10+(p_id[7]-'0');
		int mm=(p_id[8]-'0')*10+(p_id[9]-'0');
		int dd=(p_id[10]-'0')*10+(p_id[11]-'0');
		
		if(y!=yy||m!=mm||d!=dd) flag=0;
	}
	
	if(idlen==18)
	{
		int y=birthday.getYear()%100;
		int m=birthday.getMonth();
		int d=birthday.getDay();
		
		int yy=(p_id[8]-'0')*10+(p_id[9]-'0');
		int mm=(p_id[10]-'0')*10+(p_id[11]-'0');
		int dd=(p_id[12]-'0')*10+(p_id[13]-'0');
		
		if(y!=yy||m!=mm||d!=dd) flag=0;
		
		int sum=0;
		for(int i=0;i<17;i++)
		{
			sum+=(p_id[i]-'0')*ff[i];
		}
		
		sum%=11;
		if(gg[sum]!=p_id[17]) flag=0;
		
	}
	
	if(!flag)
	{
		cout<<p_name<<" illegal id"<<endl;
		registered=0;
	}
	else
	{
		cout<<p_name<<" ";
		birthday.print();
		cout<<" "<<p_id<<endl;
		registered=1;
	}
	
}

CStudentID::~CStudentID()
{
	delete [] p_id;
	delete [] p_name;
}

CStudentID::CStudentID(const CStudentID &r)
{
	p_id=new char[30];
	p_name=new char[30];
	birthday=r.birthday;
	strcpy(p_name,r.p_name);
	
	int len=strlen(r.p_id);
	if(len==15)
	{
		string s=r.p_id;
		s.insert(6,"19");
		
		int sum=0;
		for(int i=0;i<17;i++)
		{
			sum+=(s[i]-'0')*ff[i];
		}
		s+=gg[sum%11];
		strcpy(p_id,s.c_str());
	}
	else
	{
		strcpy(p_id,r.p_id);
	}
	
	registered=r.registered;
	
	cout<<p_name<<" ";
	birthday.print();
	cout<<" "<<p_id<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int year,month,day;
		char *name=new char[30];
		char *id=new char[30];
		cin>>year>>month>>day;
		cin>>name>>id;
		
		CDate date(year,month,day);
		CStudentID s(id,name,date);
		
		if(s.checked())
		{
			CStudentID s1(s);
		}
	}
	
	return 0;
}


/*
6
2018 2 29
���� 440301180229113
1997 4 30
���� 440301980808554
1920 5 8
���� 530102200508011
1980 1 1
���� 340524198001010012
1988 11 12
Ǯ�� 1102038811120A4
1964 11 15
��� 432831641115081


*/


//output
/*
���� illegal id\n
���� illegal id\n
���� 1920��5��8�� 530102200508011\n
���� 1920��5��8�� 53010219200508011X\n
���� illegal id\n
Ǯ�� illegal id\n
��� 1964��11��15�� 432831641115081\n
��� 1964��11��15�� 432831196411150810
*/
