#include <set>
#include <ctime>
#include <string>
#include <time.h>
#include <iostream>
#include <stdlib.h>
//using namespace std;
class Student{
private:
	std::string name;
	int score;
	int stu_id;
	enum cmp_key{order_by_score, order_by_stu_id, order_by_name};
	enum cmp_mode{normal,reverse};
public:
	//Student();
	//typedef Student::score compare_type;
	Student(std::string n, int s, int id);
	~Student();
	bool operator<(const Student& s) const;
	bool operator==(const Student& s);
	bool operator>(const Student& s);
	Student& operator=(const Student& s);
	friend std::ostream&	operator<<(std::ostream& o,const Student& s);
	int getScore() const{return score;}
	friend class Compare3;
	friend class Compare4<Student>;  //友元模板类？
	typedef reverse mode;
};


Student::Student(std::string n, int s, int id){
	name=n;
	score=s;
	stu_id=id;
}
Student::~Student(){
}

bool Student::operator<(const Student& s) const{
	return score<s.score;
}
bool Student::operator==(const Student& s){
	return stu_id==s.stu_id;
}
bool Student::operator>(const Student& s){
	return stu_id>s.stu_id;
}
Student& Student::operator=(const Student& s){
	if(this==&s)
			return *this;
}
std::ostream& operator<<(std::ostream& o,const Student& s){
		std::cout<<"name:"<<s.name<<" stu_id:"<<s.stu_id<<" score:"<<s.score;
		return o;
}

//Compare1 继承自less<Student>
struct Compare1:std::less<Student>{
	bool	operator()(const Student& s1,const Student& s2){
		return (s1.getScore()<s2.getScore());
	}
};

//Compare2 不继承
struct Compare2{
	bool operator()(const Student& s1,const Student& s2){
		return (s1.getScore()<s2.getScore());
	}
};


//Compare3 带参数
class Compare3{
	public:
			enum cmp_key{order_by_sid, order_by_name, order_by_score};
			enum cmp_mode{normal, reverse};
	private:
			cmp_key key;
			cmp_mode mode;
	public:
			Compare3(cmp_mode m=normal,cmp_key k=order_by_sid):mode(m),key(k){
			}
			bool operator()(const Student& s1,const Student& s2){
				switch(key){
					case order_by_sid:
						return (mode==normal?(s1.stu_id<s2.stu_id):(s1.stu_id>s2.stu_id));	
					case order_by_name:
						return (mode==normal?(s1.name<s2.name):(s1.name>s2.name));
					case order_by_score:
						return (mode==normal?(s1.score<s2.score):(s1.score>s2.score));

				}
			} 
};

//Compare4 模板
template<class T>
class Compare4{
	typedef typename T::cmp_key cmp_key;
	typedef typename T::cmp_mode cmp_mode;
	//enum compare_type{order_by_sid,order_by_name,order_by_score};
	bool operator()(const T& s1, const T& s2){
		return s1.compare_type<s2.compare_type;
	}
};


int main(){
//	Compare3 c3(Compare3::reverse,Compare3::order_by_score);
//	std::set<Student,Compare3> stu_set(c3);
	Compare4<Student> c4;
	std::set<Student,Compare4<Student> > stu_set(c4);
	srand((unsigned)time(NULL));
	for(int i=0;i<100;i++){
		Student s("alice",60+rand()%40,i);
		stu_set.insert(s);
	}
//	clock_t start=clock();
//	for(std::set<Student >::iterator it=stu_set.begin();it!=stu_set.end();++it){
//		std::cout<<it->getScore()<<" ";
//	}
	for(const auto& s:stu_set){
		std::cout<<s<<std::endl;
	}

//	clock_t end=clock();
	//cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
}
