#include <iostream>
using namespace std; 

int main(){
	struct S{
		S* next;
		int i;
	};
	class C{
		public:
			C* next;
			int i;
	};

	S* s1=new S[2];
	S s2[2];
	C* c1=new C[2];
	int *i=new int[2];
	cout<<sizeof(*s1)<<endl;
	cout<<sizeof(s2)<<endl;
	cout<<sizeof(*c1)<<endl;
	cout<<sizeof(*i)<<endl;
	cout<<sizeof(i[0])<<endl;
}
