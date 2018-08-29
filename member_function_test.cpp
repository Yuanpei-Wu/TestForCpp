#include <iostream>
using namespace std;
	class D  
    {  
    public:  
        void printA()  
        {  
            cout<<"printA"<<endl;  
        }  
        virtual void printB()  
        {  
            cout<<"printB"<<endl;  
        }  
    };  
    int main(void)
    {
    	D *d=NULL;
    	d->printA();	//print A
    	d->printB();	//segment fault
    }
