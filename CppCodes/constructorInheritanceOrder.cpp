//Write a C++ program illustrating how the constructors are implemented and the order in which they are called when the classses are inherited
#include<iostream>
using namespace std;
class Alpha{
    public:
        Alpha(){
            cout<<"Constructor of Alpha is called"<<endl;
        }
}; 
class Beta{
    public:
        Beta(){
            cout<<"Constructor of Beta is called"<<endl;
        }
}; 
class Gamma : public Alpha, public Beta{
    public:
        Gamma(){
            cout<<"Constructor of Gamma is called"<<endl;
        }
};
int main(){
    Gamma g;
    return 0;
}
