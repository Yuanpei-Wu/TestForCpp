#include <iostream>
#include <stdio.h>
using namespace std;

class A {
	public:
	void common(){}
    virtual void foo() { printf("A::foo(): this = 0x%p\n", this); }
};
class B :public A{
	public:
    virtual void foo() { printf("B::foo(): this = 0x%p\n", this); }
    virtual void bar() { printf("B::bar(): this = 0x%p\n", this); }
    virtual void foo(int i) { printf("B::bar(): this = 0x%p\n", this); }
};
class C{
	public:
	virtual void bar(){}
};	
class D:public C,public A{
	public:
	virtual void foo(){}
	virtual void bar(){}
};

void (A::*pafoo)() = &A::foo;   // ptr: 1, adj: 0
void (B::*pbfoo)() = &B::foo;   // ptr: 1, adj: 0
void (B::*pbbar)() = &B::bar;   // ptr: 9, adj: 0
void (B::*pbfoo2)(int) = &B::foo;   // ptr: 11, adj: 0
void (A::*pcommon)() = &A::common;
void (D::*pdfoo)() = &D::foo;
void (D::*pdbar)() = &D::bar;
int main(){
	A* a = new A;
	B* b = new B;
	a->foo();
	b->foo();
	b->bar();
	printf("A::commont: %x\n",pcommon);
	printf("A::foo: %x\n",pafoo);
	printf("B::foo: %x\n",pbfoo);
	printf("B::bar: %x\n",pbbar);
	printf("A::foo->ptr: %x\n",((unsigned int*)&pafoo)[0]);
	printf("A::foo->adj: %x\n",((unsigned int*)&pafoo)[1]);
	printf("B::foo->ptr: %1x\n",((unsigned int*)&pbfoo)[0]);
	printf("B::foo->adj: %1x\n",((unsigned int*)&pbfoo)[1]);
	printf("B::bar->ptr: %1x\n",((unsigned int*)&pbbar)[0]);
	printf("B::bar->adj: %1x\n",((unsigned int*)&pbbar)[1]);
	printf("B::foo2->ptr: %1x\n",((unsigned int*)&pbfoo2)[0]);
	printf("B::foo2->adj: %1x\n",((unsigned int*)&pbfoo2)[1]);
	printf("D::foo->ptr: %x\n",((long*)&pdfoo)[0]);
	printf("D::foo->adj: %x\n",((long*)&pdfoo)[2]);
	printf("D::foo->ptr: %x\n",((long*)&pdbar)[0]);
	printf("D::foo->adj: %x\n",((long*)&pdbar)[2]);
}
