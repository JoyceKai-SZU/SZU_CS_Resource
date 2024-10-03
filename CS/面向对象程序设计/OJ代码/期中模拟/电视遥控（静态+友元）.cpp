#include<iostream>
using namespace std;

class Tel {
	static int cntTV, cntDVD;
	int yinliang, pindao;
	int moshi;
public:
	Tel() {
		moshi = 1;
		cntTV++;
		pindao = 0;
		yinliang = 50;
	}

	void changeYin(int v) {
		yinliang += v;
		if (yinliang > 100)
			yinliang = 100;
		else if (yinliang < 0)
			yinliang = 0;
	}

	void print1() {
		if (moshi == 1)
			cout << "TV模式--";
		else if (moshi == 2)
			cout << "DVD模式--";
		cout << "频道" << pindao << "--";
		cout << "音量" << yinliang << endl;
	}

	static void print() {
		cout << "播放电视的电视机数量为" << cntTV << endl;
		cout << "播放DVD的电视机数量为" << cntDVD << endl;
	}

	//2 DVD
	//1 TV
	friend void yaokongqi(Tel* p, int moshi, int pindao, int bianyin) {
		if (p->moshi != moshi) {

			if (p->moshi == 1)
				p->cntTV--;
			else if (p->moshi == 2)
				p->cntDVD--;

			p->moshi = moshi;

			if (p->moshi == 1)
				p->cntTV++;
			else
				p->cntDVD++;

		}
		p->pindao = pindao;

		p->changeYin(bianyin);
		p->print1();

	}
};



int Tel::cntTV = 0;
int Tel::cntDVD = 0;

int main() {
	int n, t;
	cin >> n >> t;
	Tel* p = new Tel[n];
	while (t--)
	{
		int i, k, x, delta;
		cin >> i >> k >> x >> delta;
		cout << "第" << i << "号电视机--";
		i--;
		yaokongqi(p + i, k, x, delta);
	}
	Tel::print();
	return 0;
}

/*
10
5
3 1 11 20
4 2 99 -20
5 2 99 80
5 1 55 -60
6 2 99 -70
*/

//output
/*
第3号电视机–TV模式–频道11–音量70
第4号电视机–DVD模式–频道99–音量30
第5号电视机–DVD模式–频道99–音量100
第5号电视机–TV模式–频道55–音量40
第6号电视机–DVD模式–频道99–音量0
播放电视的电视机数量为8
播放DVD的电视机数量为2
*/

