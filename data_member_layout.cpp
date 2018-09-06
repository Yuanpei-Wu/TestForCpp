#include <iostream>
using namespace std;
class Base{

};
class Derive:public Base{
	public:
		int value;
		virtual void func(){}
};
int main(){
	//基类指针指向派生类对象是否有偏移
	Derive d;
	cout<<&d<<endl;
	Base *b=&d;
	cout<<b<<endl;

	//指针表示偏移位
	int Derive::* p = &Derive::value;
	cout<< p <<endl;
}
