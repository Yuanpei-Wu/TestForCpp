#include <iostream>
using namespace std;
class ParaTest{
	private:
		int val;
	public:
		ParaTest(int value=0):val(value){}
		/**this will not work
		void ParaTestFunc(int para=val){
			cout<<"para test func, para:"<<para<<endl;
		}
		**/
		void ParaTestFunc(){
			ParaTestFunc(val);
		}
		void ParaTestFunc(int para){
			cout<<"para test func, para:"<<para<<endl;
		}
		
		/**this will not work
		void ParaTestFunc2(int a, int b=a){
			cout<<"para test func2, a:"<<a<<" b:"<<b<<endl;
		}
		**/
		void ParaTestFunc2(int a){
			ParaTestFunc2(a,a);
		}
		void ParaTestFunc2(int a, int b){
			cout<<"para test func2, a:"<<a<<" b:"<<b<<endl;
		}
};

int main(){
	ParaTest p;
	p.ParaTestFunc();
	p.ParaTestFunc(2);
	p.ParaTestFunc2(1);
	p.ParaTestFunc2(1,2);
	return 0;
}
