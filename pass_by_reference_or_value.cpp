#include <iostream>
#include <vector>

using namespace std;

class Window{
	public:
		virtual void show(){
			cout<<"this is Window"<<endl;
		}

};
class WindowWithBar:public Window{
	public:
		virtual void show(){
			cout<<"this is WindowWithBar"<<endl;
		}

};

int main(){
	WindowWithBar wb;
	Window& w1=wb;
	Window w2=wb;
	w1.show();
	w2.show();
}
