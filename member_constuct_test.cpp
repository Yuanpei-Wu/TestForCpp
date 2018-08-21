#include <iostream>
using namespace std;
class B{
	public:
			B(){
				cout<< "this is constructor without parameter of B" <<endl;
			}
			B(int num):k(num){
				cout<< "this is constructor with parameter of B" <<endl;
			}
			B(const B& b){
				k=b.k;
				cout<< "this is copy constructor of B"<<endl;
			}
			B& operator=(const B& b){
				k=b.k;
				cout << "this is operator= of B" <<endl;
				return *this;
			}
			~B(){
				cout<< "this is destroyor of B"<<endl;
			}
	private:
			int k;

};
class A{
	public:
			A(int num):k(num){}
			A(){
				k=2;
			}
	private:
			B k;

};
B func(){
	B b;
	return b;	
}
int main(){
	cout<< "result of A(1)--------------"<<endl;
	A* a1=new A(1);
	delete a1;
	cout<< "result of A()---------------"<<endl;
	A* a2=new A();
	delete a2;
	cout<< "result of func(b)-----------"<<endl;
	B b=func();
	return 0;

}
