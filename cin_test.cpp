#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#define Method_Cin
using namespace std;

int main(){
	vector<int> result;
	char c;
	bool indicate=false;
	string s="";
	cout<<"input integers with blank as split"<<endl;
	
#ifdef Method_Getchar
	while((c=getchar())!='\n'){
		if(c!=' '){
			int t=c-'0';
			if(indicate)
				result.back()=result.back()*10+t;
			else
				result.push_back(t);
			indicate=true;
		}else{
			indicate=false;
		
		}
	}
#endif

#ifdef Method_Cin
	do{
		cin>>s;
		//cout<<s<<endl;
		result.push_back(0);
		size_t i=0;
		while(i<s.length()){
			result.back()=result.back()*10+(s[i]-'0');
			i++;
		}
				
	}while((c=getchar())!='\n');

#endif
	copy(result.begin(),result.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	return 0;

}
