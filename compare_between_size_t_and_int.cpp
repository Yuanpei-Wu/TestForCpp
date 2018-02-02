#include <vector>
#include <iostream>
using namespace std;
int main(){
	vector<int> a={1,2};
	int i=-1;
	if(i<a.size()){
		if(i<0)
			cout<<"1"<<endl;
		else
			cout<<"2"<<endl;
	}
	else{
		cout<<"else"<<endl;
	}
	int j=a.size();
	if(i<j){
		if(i<0)
			cout<<"3"<<endl;
		else
			cout<<"4"<<endl;
	}
	cout<<"end"<<endl;
	return 0;
}
