#include <iostream>
#include <stdio.h>
using namespace std;

class A {
	public:
    virtual void foo() { printf("A::foo(): this = 0x%p\n", this); }
};
class B :public A{
	public:
    virtual void foo() { printf("B::foo(): this = 0x%p\n", this); }
    virtual void bar() { printf("B::bar(): this = 0x%p\n", this); }
    virtual void foo(int i) { printf("B::bar(): this = 0x%p\n", this); }
};

void (A::*pafoo)() = &A::foo;   // ptr: 1, adj: 0
void (B::*pbfoo)() = &B::foo;   // ptr: 1, adj: 0
void (B::*pbbar)() = &B::bar;   // ptr: 9, adj: 0
void (B::*pbfoo2)(int) = &B::foo;   // ptr: 11, adj: 0

int main(){
	A* a = new A;
	B* b = new B;
	a->foo();
	b->foo();
	b->bar();
	printf("A::foo->ptr: %1x\n",((unsigned int*)&pafoo)[0]);
	printf("A::foo->adj: %1x\n",((unsigned int*)&pafoo)[1]);
	printf("B::foo->ptr: %1x\n",((unsigned int*)&pbfoo)[0]);
	printf("B::foo->adj: %1x\n",((unsigned int*)&pbfoo)[1]);
	printf("B::bar->ptr: %1x\n",((unsigned int*)&pbbar)[0]);
	printf("B::bar->adj: %1x\n",((unsigned int*)&pbbar)[1]);
	printf("B::foo2->ptr: %1x\n",((unsigned int*)&pbfoo2)[0]);
	printf("B::foo2->adj: %1x\n",((unsigned int*)&pbfoo2)[1]);
}
