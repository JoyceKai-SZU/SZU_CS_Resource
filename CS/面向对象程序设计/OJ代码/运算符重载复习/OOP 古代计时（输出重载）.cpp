#include<iostream>
#include<iomanip> 
using namespace std;

const char* f[12]={"子","丑","寅","卯","辰","巳",
    "午","未","申","酉","戌","亥" }; 

class CTraditionalTime{
private:
	int h,m;
public:
	CTraditionalTime(int hh,int mm):h(hh),m(mm)
	{
		if(m>=60)
		{
			h=(h+m/60)%24;
			m%=60;
		}
		
		if(h>=24) h%=24;
	}
	
	friend ostream & operator << (ostream &out,const CTraditionalTime &a)
	{
		switch(a.h)
		{
			case 23:
			case 0:out<<f[0];break;
			case 1:	
			case 2:out<<f[1];break;
			case 3:
			case 4:out<<f[2];break;
			case 5:
			case 6:out<<f[3];break;
			case 7:
			case 8:out<<f[4];break;
			case 9:
			case 10:out<<f[5];break;
			case 11:
			case 12:out<<f[6];break;
			case 13:
			case 14:out<<f[7];break;
			case 15:
			case 16:out<<f[8];break;
			case 17:
			case 18:out<<f[9];break;
			case 19:
			case 20:out<<f[10];break;
			case 21: 
			case 22:out<<f[11];break;
		}
		
		out<<"时";
		out<<"("<<setfill('0')<<setw(2)<<a.h<<":"<<setfill('0')<<setw(2)<<a.m<<")";
		//setfill和setw只对一个数有效 
		return out;
	}
}; 

int main() {
    int n, h, min;
    char ignoredchar;
    cin >> n;
    while (n-- > 0) {
        cin >> h >> ignoredchar >> min;
        cout << CTraditionalTime(h, min) << endl;
    }
    return 0;
}
