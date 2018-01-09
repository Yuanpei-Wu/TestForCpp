#include<iostream>
#include<functional>

using namespace std;
using namespace std::placeholders;
int add(int a, int b, int& r){
	r=a+b;
}

void functest(int a){
	++a;
}
/**
template<typename T>
void functest2(T a){
	cout<< "functest3" <<endl;
}

template<typename T>
void functest2(T& a){
	cout<< "functest4" <<endl;
}
**/
template<typename T>
T& functest3(T& a){
	a+=1;
	return a;
}
template<typename T>
void functest4(T a){
	++a;
}

template<typename T>
void functest5(T a){
	a.get().incre();
}
class objTest{
	private:
		int number;
	public:
		objTest(int n=0):number(n){			
		}
		friend ostream& operator<<(ostream& o,const objTest& obj){
			o<< obj.number;
			return o;
		}
		void incre(){
			++number;
		}
};
int main(){
	int result=0;
    auto f1 = bind(add, _1, 20, result);
    f1(80);
    cout << result << endl;
     
    auto f2 = bind(add, _1, 20, ref(result));
	f2(80);
    cout << result << endl;

	int& result_ref=result;
    auto f3 = bind(add, _1, 20, result_ref);
	f3(80);
    cout << result_ref << endl;

	int a=1;
	int& b=a;
	double c=2;
	double& d=c;
//	functest(a);
//	functest(b);
//	functest2(c);
//	functest2(d);

	cout<< functest3(a)<< endl;
	cout<< functest3(b)<< endl;
	
	functest4(a);
	cout<< a<<endl;
	functest4(ref(a));
	cout<< b<<endl;

	functest(a);
	cout<< a<<endl;
	functest(ref(a));
	cout<<a<<endl;
	
	objTest o(1);
//	functest5(o);
//	cout<< o<<endl;
	functest5(ref(o));
	reference_wrapper<decltype(o)> r=o;
	functest5(r);
	cout<< o<<endl;
}
