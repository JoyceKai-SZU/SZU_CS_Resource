#include<iostream>
#include<vector>
using namespace std;

class CBoxObject {
protected:
    string type; // ��¼������Ϣ
public:
    CBoxObject(string _type) : type(_type) {}
    virtual void show(ostream&) const = 0; // ���������Ϣ
};

ostream& operator << (ostream &out,const CBoxObject &a)
{
	a.show(out);
	return out; 
} 


ostream & operator << (ostream & out,const CBoxObject* a ) //����������<<һ��Ҫ 
{
	a->show(out);
	return out;
}

template<class T>
class CBox:public CBoxObject{
private:
	T val;
public:
	CBox(string type,T v):CBoxObject(type),val(v){}
	
	void show(ostream& out)const  //Ҫ�����ص�<<���õ�,Ҫ��const 
	{
		out<<"{"<<type<<": "<<val<<"}";
	}
	
	void setVal(T _val)
	{
		val=_val;
	}
	

};

template<>     //ģ��ƫ�ػ� 
class CBox<CBoxObject *> :public CBoxObject{
private:
	CBoxObject * val;
public:
	CBox(string type,CBoxObject * v):CBoxObject(type),val(v){}
	
	void show(ostream& out)const //Ҫ�����ص�<<���õ�,Ҫ��const 
	{
		if(!val) out<<"{}";
		else out<<"{"<<type<<": "<<val<<"}";
	}
	
	void setVal(CBoxObject * _val)
	{
		val=_val;
	}
};


template<typename T>
void pushBox(istream& in, vector<CBoxObject*>& container, const string& type) {
    T val;
    in >> val;
    container.emplace_back(new CBox<T>(type, val));
}
int main() 
{
    string type; // ��������
    int n, index; // nΪ���������indexΪvector�����±�
    cin >> n;
    vector<CBoxObject*> pBoxes;
    pBoxes.reserve(n); // Ԥ�ȷ����㹻�Ŀռ�(pBoxes.size()==0��Ȼ����)
    while (n-- > 0) {
        cin >> type;
        // �����������ͷֱ��װ
        if (type == "char") pushBox<char>(cin, pBoxes, type);
        else if (type == "int") pushBox<int>(cin, pBoxes, type);
        else if (type == "double") pushBox<double>(cin, pBoxes, type);
        else if (type == "string") pushBox<string>(cin, pBoxes, type);
        // ���Ǿ���һ������Ҳ�ǿ��԰�װ��һ�����ӵ�
        // Ϊ�˱����������ǲ��ú���ָ������ʾ���Ӽ�İ�װ��ϵ
        else if (type == "box") {
            cin >> index;
            auto box = new CBox<CBoxObject*>("box", nullptr);
            // ����index��pBoxes���еĺ�����ѡ��һ�����º��Ӱ�װ
            if (0 <= index && index < pBoxes.size()) {
                box->setVal(pBoxes[index]);
                // ��ʵ�к����ǲ����Լ���װ�Լ���
                // �ڱ����У���������Լ���װ�Լ�����ָ��ֵ����Ϊ��
                // �����ݲ���������ɻ�����
            }
            pBoxes.emplace_back(box);            
        }
        index = (int)pBoxes.size() - 1;
        cout << *pBoxes[index] << endl;
    }
    for (CBoxObject*& box : pBoxes) delete box;
    return 0;
}

/*
10
string hello
int 666
char c
double 3.14
box 3
box 4
box 6
box 6
box 9
box -1
*/

//output
/*
{string: hello}\n
{int: 666}\n
{char: c}\n
{double: 3.14}\n
{box: {double: 3.14}}\n
{box: {box: {double: 3.14}}}\n
{}\n
{box: {}}\n
{}\n
{}
*/ 
