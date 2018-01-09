#include<iostream>
using namespace std;
int main(){
	#if defined(__GNUC__)
		cout<<"__GNUC__:"<<__GNUC__<<" "<<__GNUC_MINOR__<<endl;
	#endif
	#ifdef __STL_STATIC_TEMPLATE_MEMBER_BUG
		std::cout<<"def __STL_STATIC_TEMPLATE_MEMBER_BUG"<<std::endl;
	#else
		std::cout<<"undef __STL_STATIC_TEMPLATE_MEMBER_BUG"<<std::endl;
	#endif
	#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
		std::cout<<"def __STL_CLASS_PARTIAL_SPECIALIZATION"<<std::endl;
	#else
		std::cout<<"undef __STL_CLASS_PARTIAL_SPECIALIZATION"<<std::endl;
	#endif
}

