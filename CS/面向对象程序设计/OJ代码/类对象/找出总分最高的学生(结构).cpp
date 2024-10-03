#include<iostream>
using namespace std;
struct stu{
	int id;
	string name;
	int score1,score2,score3;
}s[20];

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>s[i].id>>s[i].name>>s[i].score1>>s[i].score2>>s[i].score3;
	
	stu mx=s[0];
	int mxscore=mx.score1+mx.score2+mx.score3,t=0;
	for(int i=0;i<N;i++)
	{
		if(s[i].score1+s[i].score2+s[i].score3>mxscore)
		{
			t=i;
			mxscore=s[i].score1+s[i].score2+s[i].score3;
		}
	}
	cout<<s[t].name<<" "<<s[t].id<<" "<<mxscore;
	return 0;
} 
