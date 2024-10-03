#include<iostream>
using namespace std;



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int len=str.length();
		for(int i=0;i<len;i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
			{
				if(str[i]+4>'Z'&&str[i]+4<'a')  //大写转换 
				{
					str[i]=((str[i]-'A')+4)%26+'A';

				}
				else str[i]=(str[i]-'A')+4+'A';
				
				
			}
			if(str[i]>='a'&&str[i]<='z')
			{
				if(str[i]+4>'z')  //小写转换 
				{
					str[i]=((str[i]-'a')+4)%26+'a';

				}
				else str[i]=(str[i]-'a')+4+'a';
			}
		}
		
		cout<<str<<endl;
		
	}
	return 0;
}


//((str[i]-'A')+4)+'A'
