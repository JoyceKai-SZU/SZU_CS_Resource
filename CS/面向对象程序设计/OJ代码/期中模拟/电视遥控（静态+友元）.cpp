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
			cout << "TVģʽ--";
		else if (moshi == 2)
			cout << "DVDģʽ--";
		cout << "Ƶ��" << pindao << "--";
		cout << "����" << yinliang << endl;
	}

	static void print() {
		cout << "���ŵ��ӵĵ��ӻ�����Ϊ" << cntTV << endl;
		cout << "����DVD�ĵ��ӻ�����Ϊ" << cntDVD << endl;
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
		cout << "��" << i << "�ŵ��ӻ�--";
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
��3�ŵ��ӻ��CTVģʽ�CƵ��11�C����70
��4�ŵ��ӻ��CDVDģʽ�CƵ��99�C����30
��5�ŵ��ӻ��CDVDģʽ�CƵ��99�C����100
��5�ŵ��ӻ��CTVģʽ�CƵ��55�C����40
��6�ŵ��ӻ��CDVDģʽ�CƵ��99�C����0
���ŵ��ӵĵ��ӻ�����Ϊ8
����DVD�ĵ��ӻ�����Ϊ2
*/

