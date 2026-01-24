#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,1,4,2},n=5,key=4;
    for(int i=0;i<n;i++) if(a[i]==key){cout<<"Found at "<<i; return 0;}
    cout<<"Not Found";
}
