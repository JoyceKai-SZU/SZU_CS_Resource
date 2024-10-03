#include<iostream>
#include<vector>
using namespace std;

class CBoxObject {
protected:
    string type; // 记录类型信息
public:
    CBoxObject(string _type) : type(_type) {}
    virtual void show(ostream&) const = 0; // 用于输出信息
};

ostream& operator << (ostream &out,const CBoxObject &a)
{
	a.show(out);
	return out; 
} 


ostream & operator << (ostream & out,const CBoxObject* a ) //这两个重载<<一定要 
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
	
	void show(ostream& out)const  //要被重载的<<调用的,要有const 
	{
		out<<"{"<<type<<": "<<val<<"}";
	}
	
	void setVal(T _val)
	{
		val=_val;
	}
	

};

template<>     //模块偏特化 
class CBox<CBoxObject *> :public CBoxObject{
private:
	CBoxObject * val;
public:
	CBox(string type,CBoxObject * v):CBoxObject(type),val(v){}
	
	void show(ostream& out)const //要被重载的<<调用的,要有const 
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
    string type; // 数据类型
    int n, index; // n为输入次数，index为vector数组下标
    cin >> n;
    vector<CBoxObject*> pBoxes;
    pBoxes.reserve(n); // 预先分配足够的空间(pBoxes.size()==0依然成立)
    while (n-- > 0) {
        cin >> type;
        // 根据数据类型分别包装
        if (type == "char") pushBox<char>(cin, pBoxes, type);
        else if (type == "int") pushBox<int>(cin, pBoxes, type);
        else if (type == "double") pushBox<double>(cin, pBoxes, type);
        else if (type == "string") pushBox<string>(cin, pBoxes, type);
        // 我们觉得一个盒子也是可以包装另一个盒子的
        // 为了便捷起见，我们采用盒子指针来表示盒子间的包装关系
        else if (type == "box") {
            cin >> index;
            auto box = new CBox<CBoxObject*>("box", nullptr);
            // 根据index从pBoxes已有的盒子中选择一个用新盒子包装
            if (0 <= index && index < pBoxes.size()) {
                box->setVal(pBoxes[index]);
                // 现实中盒子是不能自己包装自己的
                // 在本题中，如果盒子自己包装自己，则将指针值设置为空
                // 本题暂不考虑链表成环问题
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
