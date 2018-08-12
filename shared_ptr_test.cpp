#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main(){
	shared_ptr<string> sp1=make_shared<string>("abc");
	shared_ptr<string> sp2(sp1);
	cout<<"count of sp1: "<<sp1.use_count()<<endl;
	cout<<"count of sp2: "<<sp2.use_count()<<endl;
	shared_ptr<string> sp3(new string("def"));
	sp1=sp3;
	cout<<"count of sp1: "<<sp1.use_count()<<endl;
	cout<<"count of sp2: "<<sp2.use_count()<<endl;
	return 0;
}
