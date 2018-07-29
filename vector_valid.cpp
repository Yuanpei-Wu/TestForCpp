#include <vector>
#include <iostream>
using namespace std;
int main(){
	vector<int> a({1,2,3,4});
	int num=4;
	for(auto i=a.begin();i!=a.end();){
		a.push_back(num);
		num++;
		if(num%2) i++;
		cout<<*i<<endl;
	}
	return 0;
}
