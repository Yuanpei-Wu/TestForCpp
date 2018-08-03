#include <iostream>
using namespace std;
	class A{
		private:
			int num;
		public:
			A(int n):num(n){
			}
			friend ostream& operator<<(ostream& o, const A& a);
	};
	ostream& operator<<(ostream& o, const A& a){
		o<<a.num;
		return o;
	}
int main(){
	auto a=(A)-1;
	cout<<a<<endl;
}
