#include <iostream>
using namespace std;
int main() {
	int n = 5;
    for (int i = 1; i <= n; i++){
	if(i == 1 || i == n)
	cout<<string(n, '*')<<endl;
	else
	cout<<"*"<<string(n - 2, ' ')<<"*"<<endl;
}
    return 0;
}