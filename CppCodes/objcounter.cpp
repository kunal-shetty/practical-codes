#include <iostream>
using namespace std;

class Counter {
    static int object_count ; 
    
public:
    Counter() {
        object_count++;
    }

    static void showCount() {
        cout << "Number of objects created: " << object_count << endl;
    }
};

int Counter::object_count = 0;

int main() {
    Counter obj1; 
    Counter obj2; 

    Counter::showCount();
    

    Counter obj3; 

    Counter::showCount();
    obj2.showCount();

    return 0;
}

