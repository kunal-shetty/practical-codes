#include <iostream>
using namespace std;
class Demo {
public:
    Demo() {
        cout << "Constructor called!" << endl;
    }
    ~Demo() {
        cout << "Destructor called!" << endl;
    }
};
void test() {
    Demo obj;
    cout << "Inside test function." << endl;
}
int main() {
    test();
    cout << "Back in main function." << endl;
    return 0;
} 
