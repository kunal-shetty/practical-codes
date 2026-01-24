#include <iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5},n=5,key=4,l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==key){cout<<"Found at "<<m; return 0;}
        if(a[m]<key) l=m+1; else r=m-1;
    }
    cout<<"Not Found";
}
