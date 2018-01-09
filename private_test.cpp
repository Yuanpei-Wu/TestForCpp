#include <iostream>

class test{
	private:
		int value;
	public:
		int add(const test& t);
};

int test::add(const test& t){
		value+=t.value;
}

class test2{
	private:
			int value;
	public:
		int change(const test& t);
};

int test2::change(const test& t){
	value+=(t.value);
}
int main(){
	test t;
	t.value=2;		
}

