#include <iostream>
using namespace std;

void modifyValues(int* ptr, int& ref) {
    *ptr = *ptr * 2;   
    ref = ref + 5;     
}

int main() {
    int a = 10, b = 20;
    int* p = &a;
    int& r = b;

    modifyValues(p, r);

    p = &b;  
    modifyValues(p, a);

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;

    return 0;
}
