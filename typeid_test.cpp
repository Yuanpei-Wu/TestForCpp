#include <iostream>
#include <typeinfo>
using namespace std;

class Zero
{
public:
    virtual void f111() { }
};

class Base : public Zero
{
public:
    virtual void f() { }
};

class Deri1234567890ve : public Base
{
};

typedef unsigned long DWORD;

struct PMD
{
    int mdisp;  //member displacement
    int pdisp;  //vbtable displacement
    int vdisp;  //displacement inside vbtable
};

struct RTTIBaseClassDescriptor
{
    struct TypeDescriptor* pTypeDescriptor; //type descriptor of the class
    DWORD numContainedBases; //number of nested classes following in the Base Class Array
    struct PMD where;        //pointer-to-member displacement info
    DWORD attributes;        //flags, usually 0
};


struct TypeDescriptor
{
    DWORD ptrToVTable;
    DWORD spare;
    char name[ ];
};

struct RTTIClassHierarchyDescriptor
{
    DWORD signature;      //always zero?
    DWORD attributes;     //bit 0 set = multiple inheritance, bit 1 set = virtual inheritance
    DWORD numBaseClasses; //number of classes in pBaseClassArray
    struct RTTIBaseClassArray* pBaseClassArray;
};

struct RTTICompleteObjectLocator

{

    DWORD signature; //always zero ?

    DWORD offset;    //offset of this vtable in the complete class

    DWORD cdOffset;  //constructor displacement offset

    struct TypeDescriptor* pTypeDescriptor; //TypeDescriptor of the complete class

    //int * ptr;
    struct RTTIClassHierarchyDescriptor* pClassDescriptor; //describes inheritance hierarchy

};


class AClass{
	public:
		virtual void print(){};
};
class BClass:public AClass{
	public:
		virtual void print(){};
};


int main(){
	AClass* a=new BClass;
	BClass* b=new BClass;
	cout<<"typeinfo.name of A"<<typeid(a).name()<<endl;
	int **ptrvb_a=(int**)a;
	RTTICompleteObjectLocator* s=(RTTICompleteObjectLocator*)((int*)ptrvb_a[0]);
	cout<<"typeinfo.name of A"<<s->pTypeDescriptor->name<<endl;
	int **ptrvb_b=(int**)b;
	RTTICompleteObjectLocator* s2=(RTTICompleteObjectLocator*)((int*)ptrvb_b[0]);
	cout<<"typeinfo.name of B"<<s2->pTypeDescriptor->name<<endl;
	return 0;
}
