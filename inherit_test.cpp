#include <iostream>
using namespace std;

class A{
	public:
		virtual void print(){cout<<"A"<<endl;}
};
class B:public A{
	public:
		void print(){cout<<"B"<<endl;}
};
class C:public B{
	public:
		void print(){cout<<"C"<<endl;}
};

int main(){
	A* a=new A();
	a->print();
	A* b=new B();
	b->print();
	A* c=new C();
	c->print();

}
