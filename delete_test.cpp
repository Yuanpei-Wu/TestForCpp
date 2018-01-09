#include <iostream>
#include <cstring>
using namespace std;
class Test{
	private:
			char* var;
	public:
			Test(const char* c){
				var=new char[strlen(c)+1];
				strcpy(var,c);
			}
			Test& operator=(const Test& t){
				delete [] var;
				var=new char[strlen(t.var)+1];
				strcpy(var,t.var);
				return *this;
			}
			~Test(){
				delete[] var;
			}
			void Say(){
				cout<<var<<endl;
			}
};	

int main(){
//	char* c;
//	delete[] c;
	cout<<"hehe"<<endl;
	
	Test t1("hi");
	t1.Say();
	Test t2;
	t2=t1;
	t2.Say();
	
	return 0;	
}
