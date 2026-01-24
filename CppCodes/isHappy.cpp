#include<iostream>
#include<unordered_set>
using namespace std;
bool Ishappy(int n){
	unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        int sum = 0;
        while (n != 0) {
            int rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }
        n = sum;
    }
    return n == 1;
}
int main(){
	cout<<Ishappy(19);
	return 0;
}