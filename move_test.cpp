#include <iostream>
using namespace std;
class Foo{
	public:
			Foo(){
				cout<<"this is default constructor"<<endl;
			}
			~Foo(){
				cout<<"this is destroyer"<<endl;
			}
			Foo(const Foo& f){
				cout<<"this is copy constructor"<<endl;
			}
			Foo(Foo&& f){
				cout<<"this is move constructor"<<endl;
			}
			Foo& operator=(const Foo& f){
				cout<<"this is copy assigment operator"<<endl;
				return *this;
			}
			Foo& operator=(Foo&& f){
				cout<<"this is move assignment operator "<<endl;
				return *this;
			}
};
Foo Test(){
	Foo f;
	cout<<"this is test"<<endl;
	return f;
}
int main(){
	cout<<"output for 'Foo f1=Test()'---------------------------:"<<endl;
	Foo f1=Test();
	cout<<"output for 'Foo f2;f2=Test()'------------------------:"<<endl;
	Foo f2;
	f2=Test();
	cout<<"this is end------------------------------------------"<<endl;
	return 0;
}
