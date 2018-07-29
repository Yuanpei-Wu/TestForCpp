#include <vector>
#include <iostream>

using namespace std;

class myClass{
	public:
		myClass(int n):num(n){};
	//	myClass(myClass& a)=delete;
		myClass& operator=(myClass& a)= delete;
		void print(){cout<<num<<endl;}
	private:
		int num;

};
int main(){
	vector<myClass> test;
	cout<<&test<<endl; 
	myClass a(1);
	test.push_back(a);
	cout<< &(*test.begin()) <<endl;
	test.begin()->print();
	return 0;

}
